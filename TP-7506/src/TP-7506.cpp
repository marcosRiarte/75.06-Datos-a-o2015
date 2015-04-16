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


using namespace std;

vector<string> fileToVector(const char *fileName);
vector<string> parseTsvLine(string textLine);

//test
int main() {

	int i=0;

	vector<string> fileVector = fileToVector("labeledTrainData.tsv");
	vector<string> tokens;

	for(i=0; i < 10;i++)
	{
		tokens = parseTsvLine(fileVector[i]);
		//Tokens[0] = id; tokens[1] = sentiment; tokens[2] = review;
		cout << tokens[2] << endl;
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
