/*
 * TrainDataSet.h
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#ifndef SRC_TRAINDATASET_H_
#define SRC_TRAINDATASET_H_

#include "Parser.h"
#include "Compresor.h"
#include "ReviewCleaner.h"
#include "compress/zlib.h"
#include "TrainReview.h"
#include "TestReview.h"
#include <vector>
#include "PosNCD.h"
#include "NCDMatrix.h"
#include <algorithm>

namespace std {

class DataSet {
private:
	vector<TrainReview> trainDataSet;
	vector<TestReview> testDataSet;
	vector<float> sentiments;
	Compresor *compresor;
	ReviewCleaner *reviewCleaner;
	Parser *parser;
	NCDMatrix *ncdMatrix;


public:
	DataSet(Parser*,ReviewCleaner*,Compresor*);
	virtual ~DataSet();
	void setTrainData(vector<string>);
	void setTestData(vector<string>);
	void printExample();
	void printNCDMatrix();
	void generateNCDMatrix(int alto, int ancho);
	void loadNCDMatrix(const char* matrixName, int filas, int columnas);
	void generateSentimentVector(int cantidadSentimientos);
	vector<string> getIdSentimentVector();
	vector<string> getSentimentVector();


};

} /* namespace std */

#endif /* SRC_TRAINDATASET_H_ */
