/*
 * compresedReview.cpp
 *
 *  Created on: Apr 21, 2015
 *      Author: fran
 */

#include "TrainReview.h"

namespace std {

void TrainReview::setSentiment(string sentiment)
{
	//Esto no deberia ser asi pero no logro que fincione el string to int
	if(sentiment.compare("1") == 0) this->sentiment = 1;
	else this->sentiment = 0;
}

int TrainReview::getSentiment()
{
	return sentiment;
}

}
