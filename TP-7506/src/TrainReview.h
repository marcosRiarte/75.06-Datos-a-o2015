/*
 * compresedReview.h
 *
 *  Created on: Apr 21, 2015
 *      Author: fran
 */

#ifndef COMPRESEDREVIEW_H_
#define COMPRESEDREVIEW_H_

#include <string>
#include "ReviewInformation.h"

namespace std {

class TrainReview  : public ReviewInformation{
private:
	int sentiment;
public:
	void setSentiment(string);
	int getSentiment();
};

}

#endif
