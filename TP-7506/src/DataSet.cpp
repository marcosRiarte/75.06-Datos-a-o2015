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

float calcProm(vector<int> sentimientos){
	int sumaTotal=0;
	for(int i=0;i<sentimientos.size();i++){
		sumaTotal+= sentimientos[i];
	}
	return (float)sumaTotal/(float)sentimientos.size();
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
		compressedReview = compresor.compress_string((const string&)cleanReview,Z_BEST_COMPRESSION);
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
		compressedReview = compresor.compress_string((const string&)cleanReview,Z_BEST_COMPRESSION);
		testReview.setReview(cleanReview);
		testReview.setId(tokens[0]);
		testReview.setCompLength(compressedReview.length());
		testDataSet.push_back(testReview);
	}

}

void DataSet::generateNCDMatrix(int cantTest, int cantTrain){
	NCDMatrix *ncdMatrix = new NCDMatrix (cantTest,cantTrain);
	ncdMatrix->prepararMatrizParaGuardar();
	int i,j;
	for(i=0;i<cantTest;i++){
		cout<<i<<" : ";
		for(j=0;j<cantTrain;j++){
			float NCD = compresor.obtenerNCD(testDataSet[i].getReview(),testDataSet[i].getCompLength(),trainDataSet[j].getReview(),trainDataSet[j].getCompLength());
			ncdMatrix->setValue(NCD,i,j);
			ncdMatrix->guardarValorEnString(i,j);
		}
		ncdMatrix->guardarMatrizEnFormaLineal();
		cout<< "OK" << endl;
	}
	ncdMatrix->cerrarArchivoConMatrizGuardada();
	this->ncdMatrix = ncdMatrix;
	this->ncdMatrix->saveMatrix("MatrizBinaria-0-25000.dat"); //Pruebo guardar matriz binaria
}

void DataSet::generateNCDMatrix(){

	NCDMatrix *ncdMatrix = new NCDMatrix (25000,25000);
	//ncdMatrix->levantarMatrizDeFormaLinear();
	//ncdMatrix->loadMatrix("MatrizBinaria-0-25000.dat",25000,25000);
	this->ncdMatrix = ncdMatrix;
	this->ncdMatrix->saveMatrix("MatrizBinaria-0-25000.dat"); //Pruebo guardar matriz binaria
}

vector<string> DataSet::generateIdSentimentVector(int cant){

	vector<string> idSentiment;

	int i=0,j=0,posSentCercano = 0, sentCercano=-1;
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
		for(int k=0;k<cant;k++) sentCercanos.push_back(trainDataSet[posNcdVector[k].position].getSentiment());


		posNcdVector.clear();

	float prom = calcProm(sentCercanos);
	ostringstream ss;
	ss << prom;
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
