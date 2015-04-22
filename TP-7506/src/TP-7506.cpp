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
#include "tsvParser.h"
#include "compresedReview.h"

using namespace std;

vector<string> fileToVector(const char *fileName);

typedef char Char;

//test
int main() {

	vector<string> labeledVector = fileToVector("labeledTrainData.tsv");
	vector<string> tokens;
	vector<compresedReview> baseConocimientos;

	unsigned int i=0;

	tsvParser *parser = new tsvParser();
	Compresor *compresor = new Compresor();

	for(i=1; i < 10 /*labeledVector.size()*/ ;i++)
	{
		parser->parseLabeledTsv(labeledVector[i]);
		string str = parser->getReview();
		string sentiment = parser->getSentiment();
		compresedReview cmpReview;

		cmpReview.setReview(str); //Modifico la base de conocimientos para que reciba strings sin comprimir
		cmpReview.setSentiment(sentiment);

		baseConocimientos.push_back(cmpReview);
	}

	//Calculo la ncd de la base de conocimientos con un ejemplo sacado del labeled.tsv
	string ejemploTest = "I dont know why people think this is such a bad movie. Its got a pretty good plot, some good action, and the change of location for Harry does not hurt either. Sure some of its offensive and gratuitous but this is not the only movie like that. Eastwood is in good form as Dirty Harry, and I liked Pat Hingle in this movie as the small town cop. If you liked DIRTY HARRY, then you should see this one, its a lot better than THE DEAD POOL. 4/5";
	for(i=0;i < baseConocimientos.size();i++)
	{
		float distanciaNCD = compresor->obtenerNCD(baseConocimientos[i].getReview(),ejemploTest);
		cout << "NCD: " << distanciaNCD << endl;
	}

	delete compresor;
	delete parser;
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

//Pasa de string a char * (puede ser util, por eso lo deje comentarizado)
/*
string strTemp = tokens[2];
Char* writable = new Char[strTemp.size() + 1];
std::copy(strTemp.begin(), strTemp.end(), writable);
writable[strTemp.size()] = '\0';
*/



