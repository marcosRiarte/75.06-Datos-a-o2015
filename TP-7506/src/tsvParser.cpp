/*
 * tsvParcer.cpp
 *
 *  Created on: Apr 14, 2015
 *      Author: fran
 */


#include "tsvParser.h"

tsvParser::tsvParser()
{

}

void tsvParser::parse(string textLine)
{
	   istringstream ss(textLine);
	   string token;
	   vector<string> tokens;

	   unsigned int i=0;

	   while(std::getline(ss, token, '\t')) {
	       tokens.push_back(token);
	       i++;
	   }

	   this->id = tokens[0];
	   this->sentiment = tokens[1];
	   this->review = tokens[2];
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
