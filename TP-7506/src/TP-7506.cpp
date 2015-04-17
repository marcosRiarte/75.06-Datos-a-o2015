//============================================================================
// Name        : TP-7506.cpp
// Author      : Marcos Riarte
// Version     : actual
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "bzip2.c"


using namespace std;

vector<string> fileToVector(const char *fileName);
vector<string> parseTsvLine(string textLine);
typedef char Char;

//test
int main() {

	int i=0;

	vector<string> fileVector = fileToVector("labeledTrainData.tsv");
	vector<string> tokens;

	for(i=0; i < fileVector.size()-1;i++) //Sin contar los headers
	{
		tokens = parseTsvLine(fileVector[i]);

		//Tokens[0] = id; tokens[1] = sentiment; tokens[2] = review;


		//Pasa de string a char *

		string strTemp = tokens[2];https://github.com/MartinAndu/75.06-Datos-a-o2015
		Char* writable = new Char[strTemp.size() + 1];
		std::copy(strTemp.begin(), strTemp.end(), writable);
		writable[strTemp.size()] = '\0';

		//Esto comprimiria strings pero es para ficheros
		compress(writable);
		cout << writable<< endl;


		delete[] writable;
	}
	return 0;
}

//Carga todo el archivo en un vector de strings
vector<string> fileToVector(const char *fileName)
{
	 string line;
	 vector<string> fileVector;
	 ifstream file (fileName);
	 if (file.is_open())
	 {
		 while ( getline (file,line) )
		 {
			 fileVector.push_back(line);
	    }
	    file.close();
	 }
	 return fileVector;
}

//Parsea un string por tabulaciones y devuelve un vector
vector<string> parseTsvLine(string textLine)
{
	   istringstream ss(textLine);
	   string token;
	   vector<string> tokens;

	   while(std::getline(ss, token, '\t')) {
	       tokens.push_back(token);
	   }
	   return tokens;
}

