/*
 * compresedReview.cpp
 *
 *  Created on: Apr 21, 2015
 *      Author: fran
 */

#include "compresedReview.h"

namespace std {

compresedReview::compresedReview() {
	sentiment = 0;
	compLength = 0;
}

compresedReview::~compresedReview() {
	// TODO Auto-generated destructor stub
}

void compresedReview::setReview(string cmpReview)
{
	this->review = cmpReview;
}

void compresedReview::setSentiment(string sentiment)
{
	//Esto no deberia ser asi pero no logro que fincione el string to int
	if(sentiment.compare("1") == 0) this->sentiment = 1;
	else this->sentiment = 0;
}

void compresedReview::setCompLength(int length)
{
	this->compLength = length;
}

string compresedReview::getReview()
{
	return review;
}

int compresedReview::getSentiment()
{
	return sentiment;
}

int compresedReview::getCompLength()
{
	return compLength;
}

}
