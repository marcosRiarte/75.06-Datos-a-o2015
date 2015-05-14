/*
 * ReviewCleaner.cpp
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#include "ReviewCleaner.h"

namespace std {

ReviewCleaner::ReviewCleaner() {
	// TODO Auto-generated constructor stub

}

ReviewCleaner::~ReviewCleaner() {
	// TODO Auto-generated destructor stub
}

string ReviewCleaner::cleanReview(string review){

	string reviewLimpia = "";
	//string html= "<br /";
	//review = removerSubstringsDeString(html,review);
	for (int x=0;x<review.size();x++){
		if (!ispunct(review.at(x)) && !isdigit(review.at(x)))
			if(review.at(x)>='A' && review.at(x)<= 'Z')
				reviewLimpia+= (review.at(x) + ('a'-'A'));
			else
    			reviewLimpia+= review.at(x);

	}

	stringstream nuevaReview;
	nuevaReview.str(""); //Vacia le buffer
	copy(string_token_iterator(reviewLimpia),string_token_iterator(),ostream_iterator <string> (nuevaReview," "));

	return nuevaReview.str();
	}
} /* namespace std */
