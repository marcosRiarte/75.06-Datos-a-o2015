/*
 * TrainDataSet.cpp
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#include "DataSet.h"


namespace std {

DataSet::DataSet(Parser *parser,ReviewCleaner *reviewCleaner,Compresor *compresor){
	this->ncdMatrix = NULL;
	this->parser = parser;
	this->reviewCleaner = reviewCleaner;
	this->compresor = compresor;
}

DataSet::~DataSet(){

}

float calcProm(vector<int> sentimientos){
	int sumaTotal=0;
	for(unsigned int i=0;i<sentimientos.size();i++){
		sumaTotal+= sentimientos[i];
	}
	return (float)sumaTotal/(float)sentimientos.size();
}

void DataSet::setTrainData(vector<string> dataSet) {

	vector<string> tokens;
	string cleanReview;
	string compressedReview;

	for(unsigned int i=1;i<dataSet.size();i++){
		TrainReview trainReview;
		tokens = parser->parseLine(dataSet[i],'\t');
		cleanReview = reviewCleaner->cleanReview(tokens[2]);
		compressedReview = compresor->compress_string((const string&)cleanReview);
		trainReview.setSentiment(tokens[1]);
		trainReview.setReview(cleanReview);
		trainReview.setCompLength(compressedReview.length());
		trainDataSet.push_back(trainReview);
	}
}

void DataSet::setTestData(vector<string> dataSet) {

	vector<string> tokens;
	string cleanReview;
	string compressedReview;

	for(unsigned int i=1;i<dataSet.size();i++){
		TestReview testReview;
		tokens = parser->parseLine(dataSet[i],'\t');
		cleanReview = reviewCleaner->cleanReview(tokens[1]);
		compressedReview = compresor->compress_string((const string&)cleanReview);
		testReview.setReview(cleanReview);
		testReview.setId(tokens[0]);
		testReview.setCompLength(compressedReview.length());
		testDataSet.push_back(testReview);
	}

}

void DataSet::generateNCDMatrix(int cantTest, int cantTrain){

	NCDMatrix *ncdMatrix = new NCDMatrix (cantTest,cantTrain);

	int i=0,j=0;

	for(i=20000;i<cantTest;i++){
		cout<<i<<" : ";
		for(j=0;j<cantTrain;j++){
			float NCD = compresor->obtenerNCD(testDataSet[i].getReview(),testDataSet[i].getCompLength(),trainDataSet[j].getReview(),trainDataSet[j].getCompLength());
			ncdMatrix->setValue(NCD,i,j);
		}
		cout<< "OK" << endl;
	}

	this->ncdMatrix = ncdMatrix;
	this->ncdMatrix->saveMatrix("MatrizBinaria-0-25000.dat");
}

void DataSet::loadNCDMatrix(const char* matrixName, int filas, int columnas){

	NCDMatrix *ncdMatrix = new NCDMatrix (filas,columnas);
	ncdMatrix->loadMatrix(matrixName,filas,columnas);
	this->ncdMatrix = ncdMatrix;
}

vector<string> DataSet::generateIdSentimentVector(int cant){

	vector<string> idSentiment;

	int i=0,j=0;
	int cantTest = ncdMatrix->getAlto();
	int cantTrain = ncdMatrix->getAncho();

	for(i=0; i<cantTest; i++){
		string line;
		line = testDataSet[i].getId();
		line.append(",");

		vector<PosNCD> posNcdVector;
		float *ncdArray = ncdMatrix->getFila(i);

		for(j=0; j<cantTrain; j++){
			posNcdVector.push_back(PosNCD(j,ncdArray[j]));
		}

		sort(posNcdVector.begin(),posNcdVector.end(),posNcdVector[0]);

		vector<int> sentCercanos;
		for(int k=0;k<cant;k++)
			sentCercanos.push_back(trainDataSet[posNcdVector[k].position].getSentiment());

		posNcdVector.clear();

	float prom = calcProm(sentCercanos);
	ostringstream ss;
	ss << prom;
	line.append(ss.str());
	idSentiment.push_back(line);
	}
	return idSentiment;
}

}
