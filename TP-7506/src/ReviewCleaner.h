/*
 * ReviewCleaner.h
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#ifndef SRC_REVIEWCLEANER_H_
#define SRC_REVIEWCLEANER_H_

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include "stringtokeniterator.h"
#include "StopWord.h"

namespace std {

class ReviewCleaner {
public:
	ReviewCleaner();
	virtual ~ReviewCleaner();

	string cleanReview(string);
	string removerSubstringsDeString(string s,string t);

};

} /* namespace std */

#endif /* SRC_REVIEWCLEANER_H_ */
