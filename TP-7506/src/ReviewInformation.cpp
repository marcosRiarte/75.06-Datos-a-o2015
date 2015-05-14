/*
 * ReviewInformation.cpp
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#include "ReviewInformation.h"

namespace std {

ReviewInformation::ReviewInformation() {
	compLength = 0;
}

ReviewInformation::~ReviewInformation() {
	// TODO Auto-generated destructor stub
}

void ReviewInformation::setReview(string cmpReview)
{
	this->review = cmpReview;
}


void ReviewInformation::setCompLength(int length)
{
	this->compLength = length;
}

string ReviewInformation::getReview()
{
	return review;
}


int ReviewInformation::getCompLength()
{
	return compLength;
}

} /* namespace std */
