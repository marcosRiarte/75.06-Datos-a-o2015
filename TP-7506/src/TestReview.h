/*
 * TestReview.h
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#ifndef SRC_TESTREVIEW_H_
#define SRC_TESTREVIEW_H_

#include <string>
#include "ReviewInformation.h"


namespace std {

class TestReview : public ReviewInformation{
private:
	string id;
public:
	void setId(string);
	string getId();
};

} /* namespace std */

#endif /* SRC_TESTREVIEW_H_ */
