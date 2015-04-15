//============================================================================
// Name        : TP-7506.cpp
// Author      : Marcos Riarte
// Version     : actual
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "tsvParser.h"


using namespace std;

int main() {
	tsvParser parser;
	//Un ejemplo de como funciona el parser
	parser.parse("1234567\t0\tmuy mala la pelicula");

	cout << parser.getId() << endl;
	cout << parser.getSentiment() << endl;
	cout << parser.getReview() << endl;

	return 0;
}
