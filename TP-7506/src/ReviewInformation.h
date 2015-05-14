/*
 * ReviewInformation.h
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#ifndef SRC_REVIEWINFORMATION_H_
#define SRC_REVIEWINFORMATION_H_

#include <iostream>
#include <string>

namespace std {

class ReviewInformation{
public:
	ReviewInformation();
	virtual ~ReviewInformation();
	void setReview(string);
	void setCompLength(int);
	string getReview();
	int getCompLength();
private:
	string review;
	int compLength;

};

} /* namespace std */

#endif /* SRC_REVIEWINFORMATION_H_ */
