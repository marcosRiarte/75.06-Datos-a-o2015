/*
 * tsvParser.cpp
 *
 *  Created on: Apr 21, 2015
 *      Author: fran
 */

#include "tsvParser.h"

namespace std {

tsvParser::tsvParser()
{
	// TODO Auto-generated constructor stub

}

tsvParser::~tsvParser()
{
	// TODO Auto-generated destructor stub
}

string tsvParser::getId()
{
	return id;
}

string tsvParser::getSentiment()
{
	return sentiment;
}

string tsvParser::getReview()
{
	return review;
}

void tsvParser::parseLabeledTsv(string textLine)
{
	vector<string> tokens;
	tokens = this->parseLine(textLine);
	this->id = tokens[0];
	this->sentiment = tokens[1];
	this->review = tokens[2];

}

void tsvParser::parseUnLabeledTsv(string textLine)
{
	vector<string> tokens;
	tokens = this->parseLine(textLine);
	this->id = tokens[0];
	this->review = tokens[1];

}

vector<string> tsvParser::parseLine(string textLine)
{
	   istringstream ss(textLine);
	   string token;
	   vector<string> tokens;

	   while(getline(ss, token, '\t')) {
	       tokens.push_back(token);
	   }

	   return tokens;
}

}
