/*
 * StopWord.cpp
 *
 *  Created on: May 15, 2015
 *      Author: martin
 */

#include "StopWord.h"

namespace std{


	StopWord::StopWord() {


	}

	StopWord::~StopWord() {
		// TODO Auto-generated destructor stub
	}

	void cargarStopWords(){

	}

	vector<string> StopWord::trim(vector<string> stopwords){
		const string& delimiters = " \f\n\r\t\v";

		for (int x=0;x<stopwords.size();x++){
			stopwords[x].erase( stopwords[x].find_last_not_of( delimiters ) + 1 ).erase( 0, stopwords[x].erase( stopwords[x].find_last_not_of( delimiters ) + 1 ).find_first_not_of( delimiters ) );
		}

		return stopwords;

	}

	bool StopWord::esUnaStopWord(string candidatoStopWord){
		bool esUnaStopWord = false;
		for (int x=0;x<stopwords.size() && !esUnaStopWord;x++){
			if (candidatoStopWord == stopwords[x] || candidatoStopWord == "a"){
					esUnaStopWord = true;
			}
		}

		return esUnaStopWord;
	}
}


