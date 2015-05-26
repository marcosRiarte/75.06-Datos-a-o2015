/*
 * tsvParser.cpp
 *
 *  Created on: Apr 21, 2015
 *      Author: fran
 */

#include "Parser.h"

namespace std {

Parser::Parser()
{
	// TODO Auto-generated constructor stub

}

Parser::~Parser()
{
	// TODO Auto-generated destructor stub
}

vector<string> Parser::parseLine(string textLine, char delimiter)
{
	   istringstream ss(textLine);
	   string token;
	   vector<string> tokens;

	   while(getline(ss, token, delimiter)) {
	       tokens.push_back(token);
	   }
	   return tokens;
}

}
