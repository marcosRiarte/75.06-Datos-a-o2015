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
#include "zlib.h"
#include "Compresor.h"
#include "tsvParser.h"
#include "compresedReview.h"

using namespace std;

vector<string> fileToVector(const char *fileName);
float calcPromedio(vector<int> sentimientos);

typedef char Char;

//test
int main() {

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

	for(i=0; i < 200 /*labeledVector.size()*/ ;i++)//Cantidad de reviews que va a comparar
	{
		parser->parseLabeledTsv(labeledVector[i]);
		string str = parser->getReview();
		string sentiment = parser->getSentiment();
		compresedReview cmpReview;

		cmpReview.setReview(str); //Modifico la base de conocimientos para que reciba strings sin comprimir
		cmpReview.setSentiment(sentiment);

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
		salida = parser->getId();
		distMinNCD = 1;
		sentCercano = 2;
		cout << "Review: "<< i << endl;
		for(int j=0;j < baseConocimientos.size();j++)
			{
				distanciaNCD = compresor->obtenerNCD(baseConocimientos[j].getReview(),testString);
				if(distanciaNCD<0.85)
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

//Pasa de string a char * (puede ser util, por eso lo deje comentarizado)
/*
string strTemp = tokens[2];
Char* writable = new Char[strTemp.size() + 1];
std::copy(strTemp.begin(), strTemp.end(), writable);
writable[strTemp.size()] = '\0';
*/



