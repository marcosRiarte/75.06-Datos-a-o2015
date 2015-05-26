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
#include "stringtokeniterator.h"
#include "DataSet.h"
#include <iterator>
#include <stdlib.h>
#include <string>

#include "FileHandler.h"
#include "NCDMatrix.h"
#include "Parser.h"
#include "TrainReview.h"


using namespace std;

void testFileReader(vector<string> testVector){
	cout<<"File string example: ";
	cout<<testVector[7]<<endl;

}

void testDataSet(DataSet data){
	data.printExample();
}

void testPrintMatrix(DataSet dataSet){

	dataSet.printNCDMatrix();
}

void testPrintIdSentiment(vector<string> idSentiment){
	for(int i=0;i<50;i++){
		cout<<idSentiment[i]<<endl;
	}
}

string printTime(){
time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
  std::string str(buffer);

  return str;
}


//test
int main() {

	cout<<"Comienzo: "<<printTime()<<endl;
	string tiempoComienzo = printTime();

	FileHandler fileHandler;
	vector<string>trainRawData = fileHandler.readFile("labeledTrainData.tsv");
	cout<<"Lectura train: "<<printTime()<<endl;
	vector<string>testRawData = fileHandler.readFile("testData.tsv");
	cout<<"Lectura test: "<<printTime()<<endl;
	Parser parser;
	ReviewCleaner reviewCleaner;

	Compresor compresor;

	DataSet dataSet;

	dataSet.setTrainData(trainRawData);

	cout<<"Data train cargada: "<<printTime()<<endl;
	dataSet.setTestData(testRawData);
	cout<<"Data test cargada: "<<printTime()<<endl;


	//dataSet.generateNCDMatrix(25000,25000);//La cantidad de reviews que vamos a generar la NCD para pruebas.
	dataSet.generateNCDMatrix(); //Genera una matriz a partir de levantar los archivos
	cout<<"Matriz generada: "<<printTime()<<endl;

	vector<string> idSentiment;


	idSentiment = dataSet.generateIdSentimentVector(10000/*Cantidad de sentimientos para promediar*/);
	cout<<"Sentimientos calculados con K= "<<10000<<":"<<printTime()<<endl;
	fileHandler.writeFile("Salida_Kaggle_10000.csv","id,sentiment", idSentiment);
	idSentiment.clear();


	/*
	cout<<"Comienzo del programa: "<<tiempoComienzo<<endl;
	cout<<"Fin del programa: "<<printTime()<<endl;
*/

	return 0;
}





/*
void pruebaMatriz() {
	NCDMatrix *matriz = new NCDMatrix(25000, 25000);
	for (int i = 0; i < 25000; ++i) {
		for (int j = 0; j < 25000; ++j) {
			matriz->setValue(0.505,i,j);
		}

	}
		if (matriz->saveMatrix("matrizNCD.dat")) {
			delete(matriz);
			cout<< "SE guardo la matriz"<<endl;

		} else {
			delete(matriz);
			cout<< "NO se guardo la matriz"<<endl;
		}
		*/
	/*cout<< "INICIO de la nueva matriz"<<endl;
	NCDMatrix *nMatriz = new NCDMatrix(25000, 25000);
	if (nMatriz->loadMatrix("matrizNCD.dat",25000,25000)) {
		cout<< "SE cargo la nueva matriz"<<endl;
		double res = 0;
		for (int i = 0; i < 25000; ++i) {
			for (int j = 0; j < 25000; ++j) {
				res += nMatriz->getValue(i,j);
			}
		}
		cout<< "RESULTADO de la suma de matriz: "<<res<<endl;
	} else {
		cout<< "NO se cargo la nueva matriz"<<endl;
	}
}

*/


