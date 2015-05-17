/*
 * TrainDataSet.cpp
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#include "DataSet.h"


namespace std {

DataSet::DataSet(){

}

DataSet::~DataSet(){

}

void DataSet::setTrainData(vector<string> dataSet) {
	int i=0;
	vector<string> tokens;
	string cleanReview;
	string compressedReview;
	for(i=1;i<dataSet.size();i++){
		TrainReview trainReview;
		tokens = parser.parseLine(dataSet[i],'\t');
		cleanReview = reviewCleaner.cleanReview(tokens[2]);
		compressedReview = compresor.compress_string((const string&)cleanReview,Z_BEST_SPEED);
		trainReview.setSentiment(tokens[1]);
		trainReview.setReview(cleanReview);
		trainReview.setCompLength(compressedReview.length());
		trainDataSet.push_back(trainReview);
	}
}

void DataSet::setTestData(vector<string> dataSet) {
	int i=0;
	vector<string> tokens;
	string cleanReview;
	string compressedReview;
	for(i=1;i<dataSet.size();i++){
		TestReview testReview;
		tokens = parser.parseLine(dataSet[i],'\t');
		cleanReview = reviewCleaner.cleanReview(tokens[1]);
		compressedReview = compresor.compress_string((const string&)cleanReview,Z_BEST_SPEED);
		testReview.setReview(cleanReview);
		testReview.setId(tokens[0]);
		testReview.setCompLength(compressedReview.length());
		testDataSet.push_back(testReview);
	}

}

void DataSet::generateNCDMatrix(int cantTest, int cantTrain){
	NCDMatrix *ncdMatrix = new NCDMatrix (cantTest,cantTrain);
	int i,j;
	for(i=0;i<cantTest;i++){
		cout<<i<<" : ";
		for(j=0;j<cantTrain;j++){
			float NCD = compresor.obtenerNCD(testDataSet[i].getReview(),testDataSet[i].getCompLength(),trainDataSet[j].getReview(),trainDataSet[j].getCompLength());
			ncdMatrix->setValue(NCD,i,j);
		}
		cout<< "OK" << endl;
	}
	this->ncdMatrix = ncdMatrix;
	this->ncdMatrix->guardarMatrizDeFormaLinear();
}


vector<string> DataSet::generateIdSentimentVector(){

	vector<string> idSentiment;

	int i=0,j=0,posSentCercano = 0, sentCercano=-1;
	float distMinNCD = 1;
	int cantTest = ncdMatrix->getAlto();
	int cantTrain = ncdMatrix->getAncho();

	for(i=0; i<cantTest; i++){
		string line;
		line = testDataSet[i].getId();
		line.append(",");

		distMinNCD = 1;
		posSentCercano = 0;

		for(j=0; j<cantTrain; j++){
			if(distMinNCD > ncdMatrix->getValue(i,j)){
			distMinNCD = ncdMatrix->getValue(i,j);
			posSentCercano = j;
		}
	}
	sentCercano = trainDataSet[posSentCercano].getSentiment();
	ostringstream ss;
	ss << sentCercano;
	line.append(ss.str());
	idSentiment.push_back(line);
	}
	return idSentiment;
}

void DataSet::printNCDMatrix(){

	cout<<"Matriz de NCD: "<<endl;
	for(int i=0;i<ncdMatrix->getAlto();i++){
		for(int j=0;j<ncdMatrix->getAncho();j++){
			cout<<ncdMatrix->getValue(i,j)<<'\t';
		}
		cout<<endl;
	}
}

void DataSet::printExample(){

	cout<<"Train example: "<<endl;
	cout<<"Sentiment: "<<trainDataSet[7].getSentiment()<<endl;
	cout<<"Review: "<<trainDataSet[7].getReview()<<endl;
	cout<<"CompressLength: "<<trainDataSet[7].getCompLength()<<endl<<endl;

	cout<<"Test example: "<<endl;
	cout<<"Id: "<<testDataSet[7].getId()<<endl;
	cout<<"Review: "<<testDataSet[7].getReview()<<endl;
	cout<<"CompressLength: "<<testDataSet[7].getCompLength()<<endl;
}

} /* namespace std */
