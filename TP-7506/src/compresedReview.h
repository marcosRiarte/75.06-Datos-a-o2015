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
public:
	compresedReview();
	virtual ~compresedReview();
	void setReview(string);
	void setSentiment(string);
	string getReview();
	int getSentiment();
};

}

#endif
