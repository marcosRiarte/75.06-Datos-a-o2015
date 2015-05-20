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

	dataSet.generateNCDMatrix(25000,1000);//La cantidad de reviews que vamos a generar la NCD para pruebas.
	cout<<"Matriz generada: "<<printTime()<<endl;

	vector<string> idSentiment = dataSet.generateIdSentimentVector(50/*Cantidad de sentimientos para promediar*/);
	cout<<"Sentimientos calculados: "<<printTime()<<endl;

	fileHandler.writeFile("Salida_Kaggle.csv","id,sentiment", idSentiment);

	cout<<"Comienzo del programa: "<<tiempoComienzo<<endl;
	cout<<"Fin del programa: "<<printTime()<<endl;

	/*
	  //Prueba de lectura sobre archivo de 25000 x 10
	  NCDMatrix ncdmatrix(25000,10);
	  ncdmatrix.levantarMatrizDeFormaLinear();


	 */

	return 0;
}






/*void pruebaMatriz() {
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
*/
