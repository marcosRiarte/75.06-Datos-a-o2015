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

class Parser {
private:

public:
	Parser();
	virtual ~Parser();
	vector<string>parseLine(string, char);
};

} /* namespace std */

#endif /* TSVPARSER_H_ */
