//============================================================================
// Name        : TP-7506.cpp
// Author      : Marcos Riarte
// Version     : actual
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "compress/zlib.h"
#include "Compresor.h"
#include "DataSet.h"

#include "FileHandler.h"
#include "NCDMatrix.h"
#include "Parser.h"
#include "TrainReview.h"

#define CANTTEST 25000
#define CANTTRAIN 25000
#define CANTSENTIMENTS 300;


using namespace std;

string getTime(){
time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
  std::string str(buffer);

  return str;
}

int main() {

	string tiempoComienzo = getTime();
	cout<<"Comienzo: "<<tiempoComienzo<<endl;


	FileHandler *fileHandler = new FileHandler();
	vector<string> trainRawData = fileHandler->readFile("labeledTrainData.tsv");
	cout<<"Lectura train: "<<getTime()<<endl;
	vector<string> testRawData = fileHandler->readFile("testData.tsv");
	cout<<"Lectura test: "<<getTime()<<endl;

	Parser *parser = new Parser();

	ReviewCleaner *reviewCleaner = new ReviewCleaner();

	Compresor *compresor = new Compresor(Z_BEST_COMPRESSION);

	DataSet *dataSet = new DataSet(parser,reviewCleaner,compresor);

	dataSet->setTrainData(trainRawData);
	cout<<"Data train cargada: "<<getTime()<<endl;

	dataSet->setTestData(testRawData);
	cout<<"Data test cargada: "<<getTime()<<endl;


	//dataSet.generateNCDMatrix(25000,25000);
	dataSet->loadNCDMatrix("MatrizBinaria-0-25000.dat", CANTTEST, CANTTRAIN);

	cout<<"Matriz cargada: "<<getTime()<<endl;

	vector<string> idSentiment;
	int cantSentiments = CANTSENTIMENTS;

	ostringstream sentString;
	string nombreSalida = "Salida_Kaggle_";
	sentString << cantSentiments << ".csv";
	nombreSalida.append(sentString.str());

	idSentiment = dataSet->generateIdSentimentVector(cantSentiments);
	cout<<"Sentimientos calculados con K = "<<cantSentiments<<" : "<<getTime()<<endl;

	fileHandler->writeFile(nombreSalida.c_str(),"id,sentiment", idSentiment);
	idSentiment.clear();

	cout<<"Comienzo del programa: "<<tiempoComienzo<<endl;
	cout<<"Fin del programa: "<<getTime()<<endl;

	return 0;
}

