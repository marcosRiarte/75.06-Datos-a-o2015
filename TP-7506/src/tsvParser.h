/*
 * tsvParser.h
 *
 *  Created on: Apr 21, 2015
 *      Author: fran
 */

#ifndef TSVPARSER_H_
#define TSVPARSER_H_

#include <iostream>
#include <vector>
#include <sstream>

namespace std {

class tsvParser {
private:
	vector<string>parseLine(string);
	string id;
	string sentiment;
	string review;
public:
	tsvParser();
	virtual ~tsvParser();
	void parseLabeledTsv(string);
	void parseUnLabeledTsv(string);
	string getId();
	string getSentiment();
	string getReview();


};

} /* namespace std */

#endif /* TSVPARSER_H_ */
