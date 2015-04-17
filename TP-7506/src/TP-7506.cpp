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
#include "zlib.h"
#include "Compresor.h"

using namespace std;

vector<string> fileToVector(const char *fileName);
vector<string> parseTsvLine(string textLine);


typedef char Char;

//test
int main() {

	vector<string> fileVector = fileToVector("labeledTrainData.tsv");
	vector<string> tokens;
	vector<string> stringComprimidos;

	Compresor *compresor = new Compresor();
	//Cuento desde 1 para saltear los headers
	//Tomo los primeros 5 elementos
	for(unsigned int i=1; i <6;i++)
	{
		tokens = parseTsvLine(fileVector[i]);

		//Tokens[0] = id; tokens[1] = sentiment; tokens[2] = review;


		//Pasa de string a char * (puede ser util, por eso lo deje comentarizado)
/*
		string strTemp = tokens[2];
		Char* writable = new Char[strTemp.size() + 1];
		std::copy(strTemp.begin(), strTemp.end(), writable);
		writable[strTemp.size()] = '\0';
*/

		string str = tokens[2];
		stringComprimidos.push_back(compresor->compress_string((const string&)str,Z_BEST_COMPRESSION));

	}


	for(unsigned int i=0; i <5;i++){
		cout<<"Elemento comprimido:"<<stringComprimidos[i]<<endl;
		cout<<endl;
		cout<<"Elemento descomprimido:"<<compresor->decompress_string(stringComprimidos[i])<<endl;
		cout<<endl;
	}


	//Ejemplo: calculo distancia entre el elemento 1 y el 5
	string reviewA = parseTsvLine(fileVector[1])[2];
	string reviewB = parseTsvLine(fileVector[6])[2];

	cout<<endl;
	cout<<"Elemento 1 = "<<reviewA<<endl;
	cout<<"Elemento 5 = "<<reviewB<<endl;

	float distanciaNCD = compresor->obtenerNCD(reviewA,reviewB);
	cout<<"Distancia NCD entre elemento 1 y 5 = "<<distanciaNCD<<endl;

	delete compresor;
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




