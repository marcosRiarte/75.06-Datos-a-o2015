//============================================================================
// Name        : TP-7506.cpp
// Author      : Marcos Riarte
// Version     : actual
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "compress/zlib.h"
#include "Compresor.h"
#include "tsvParser.h"
#include "compresedReview.h"
#include "NDCMatrix.h"
#include "stringtokeniterator.h"
#include <iterator>
#include <stdlib.h>
#include <string>


using namespace std;

vector<string> fileToVector(const char *fileName);
float calcPromedio(vector<int> sentimientos);

typedef char Char;


//proceso
void process() {
	ofstream salidaKaggle;
		salidaKaggle.open("SALIDA_KAGGLE.csv");
		salidaKaggle << "id,sentiment"<<endl;


		vector<string> labeledVector = fileToVector("labeledTrainData.tsv");
		vector<string> testVector = fileToVector("testData.tsv");
		vector<string> tokens;
		vector<string> salidaVector;
		vector<compresedReview> baseConocimientos;
		vector<int> sentPorReview;

		unsigned int i=0;

		tsvParser *parser = new tsvParser();
		Compresor *compresor = new Compresor();

		for(i=0; i <100/*labeledVector.size()*/ ;i++)//Cantidad de reviews que va a comparar
		{
			parser->parseLabeledTsv(labeledVector[i]);
			string str = parser->getReview();
			string sentiment = parser->getSentiment();
			string compresString = compresor->compress_string((const string&)str,Z_BEST_SPEED);

			compresedReview cmpReview;

			cmpReview.setReview(str); //Modifico la base de conocimientos para que reciba strings sin comprimir
			cmpReview.setSentiment(sentiment);
			cmpReview.setCompLength(compresString.length());

			baseConocimientos.push_back(cmpReview);
		}

		string testString;
		string salida;
		float distMinNCD, distanciaNCD,promedio;
		int sentCercano;


		for(i=1;i<testVector.size();i++) //
		{
			parser->parseUnLabeledTsv(testVector[i]);
			testString = parser->getReview();
			string testStringCompresed = compresor->compress_string((const string&)testString,Z_BEST_SPEED);
			salida = parser->getId();
			distMinNCD = 1;
			sentCercano = 2;
			cout << "Review: "<< i << endl;

			for(int j=0;j < baseConocimientos.size();j++)
				{
					distanciaNCD = compresor->obtenerNCD(baseConocimientos[j].getReview(),baseConocimientos[j].getCompLength(),testString,testStringCompresed.length());
					if(distanciaNCD<0.9)
					{
						sentPorReview.push_back(baseConocimientos[j].getSentiment());
					}
					if(distanciaNCD<distMinNCD)
					{
						distMinNCD = distanciaNCD;
						sentCercano = baseConocimientos[j].getSentiment();
					}
				}
			promedio = calcPromedio(sentPorReview);
			cout<< "Cant sentimientos: "<< sentPorReview.size() <<endl;
			cout<< "NCD: "<< promedio<<endl;
			cout<< "distancia NCD minima: " << distMinNCD<< endl;
			cout<< "Sentimiento mas cercano: " << sentCercano<< endl<< endl;

			salida.append(",");
			ostringstream ss;
			ss << sentCercano;
			salida.append(ss.str());

			salidaKaggle <<salida<<endl;

			sentPorReview.clear();
		}


		delete compresor;
		delete parser;
		salidaKaggle.close();
		return;
}

void pruebaMatriz() {
	NDCMatrix *matriz = new NDCMatrix(3, 3);
		matriz->setValue(0.1,0,0);
		matriz->setValue(0.2,0,1);
		matriz->setValue(0.3,0,2);
		matriz->setValue(0.4,1,0);
		matriz->setValue(0.4,1,1);
		matriz->setValue(0.4,1,2);
		matriz->setValue(0.3,2,1);
		matriz->setValue(0.5,2,2);
		matriz->setValue(0.9,2,0);


		if (matriz->saveMatrix("matrizNDC.dat")) {
			cout<< "SE guardo la matriz"<<endl;
			NDCMatrix *nMatriz = new NDCMatrix(3, 3);
			if (nMatriz->loadMatrix("matrizNDC.dat",3,3)) {
				cout<< "SE cargo la nueva matriz"<<endl;
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						cout<< "NCD pos ("<<i<<","<<j<<"): "<<nMatriz->getValue(i,j)<<endl;
					}

				}
			} else {
				cout<< "NO se cargo la nueva matriz"<<endl;
			}

		} else {
			cout<< "NO se guardo la matriz"<<endl;
		}
}


void limpiarReview(){


	vector<string> labeledVector = fileToVector("labeledTrainData.tsv");
	vector<string> testVector = fileToVector("testData.tsv");
	vector<string> tokens;
	vector<string> salidaVector;
	vector<compresedReview> baseConocimientos;
	vector<int> sentPorReview;

	unsigned int i=0;

	tsvParser *parser = new tsvParser();




	for(i=0; i <=labeledVector.size();i++){
		parser->parseLabeledTsv(labeledVector[i]);
		string review = parser->getReview();
		string sentiment = parser->getSentiment();


		//cout<<review<<endl;
		string reviewLimpia = "";
		for (int x=0;x<review.size();x++){
	        if (!ispunct(review.at(x)) && !isdigit(review.at(x)))
	        	reviewLimpia+=review.at(x);
		}



		stringstream nuevaReview;
		nuevaReview.str(""); //Vacia le buffer
		copy(string_token_iterator(reviewLimpia),string_token_iterator(),ostream_iterator <std::string> (nuevaReview," "));

	    cout<<nuevaReview.str()<<endl;
	}


}



//test
int main() {
	//process();
	//pruebaMatriz();
	limpiarReview(); //Pruebo limpieza de html
	return 0;
}



float calcPromedio(vector<int> sentimientos)
{
	float promedio = 0;
	int total = 0;
	int i=0;
	for(i=0;i<sentimientos.size();i++)
	{
		total += sentimientos[i];
	}
	promedio = (float)total / (float)i;
	return promedio;
}
//Carga todo el archivo en un vector de strings
vector<string> fileToVector(const char *fileName)
{
	 string line;
	 vector<string> fileVector;
	 ifstream file (fileName);
	 if (file.is_open())
	 {
		 while ( getline (file,line) )
		 {
			 fileVector.push_back(line);
	    }
	    file.close();
	 }
	 return fileVector;
}
