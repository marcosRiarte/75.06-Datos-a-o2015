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
#include "NCDMatrix.h"

namespace std {

class DataSet {
private:
	vector<TrainReview> trainDataSet;
	vector<TestReview> testDataSet;
	Compresor compresor;
	ReviewCleaner reviewCleaner;
	Parser parser;
	NCDMatrix *ncdMatrix;

public:
	DataSet();
	virtual ~DataSet();
	void setTrainData(vector<string> dataSet);
	void setTestData(vector<string> dataSet);
	void printExample();
	void printNCDMatrix();
	void generateNCDMatrix(int alto, int ancho);

	vector<string> generateIdSentimentVector();

};

} /* namespace std */

#endif /* SRC_TRAINDATASET_H_ */
