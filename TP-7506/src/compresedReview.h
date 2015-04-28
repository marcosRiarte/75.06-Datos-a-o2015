/*
 * compresedReview.h
 *
 *  Created on: Apr 21, 2015
 *      Author: fran
 */

#ifndef COMPRESEDREVIEW_H_
#define COMPRESEDREVIEW_H_

#include <iostream>
#include <string>

namespace std {

class compresedReview {
private:
	string review;
	int sentiment;
	int compLength;
public:
	compresedReview();
	virtual ~compresedReview();
	void setReview(string);
	void setSentiment(string);
	void setCompLength(int);
	string getReview();
	int getSentiment();
	int getCompLength();
};

}

#endif
