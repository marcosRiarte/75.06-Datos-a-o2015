/*
 * tsvParcer.h
 *
 *  Created on: Apr 14, 2015
 *      Author: fran
 */

#ifndef TSVPARSER_H_
#define TSVPARSER_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class tsvParser {

private:
	string id;
	string sentiment;
	string review;


public:
	tsvParser();
	void parse(string);
	string getId();
	string getSentiment();
	string getReview();
};

#endif /* TSVPARSER_H_ */
