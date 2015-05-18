/*
 * StopWord.h
 *
 *  Created on: May 15, 2015
 *      Author: martin
 */

#ifndef SRC_STOPWORD_H_
#define SRC_STOPWORD_H_

#include <string>
#include <vector>
#include <algorithm>
#include "FileHandler.h"

namespace std{

class StopWord {

	public:
		StopWord();
		virtual ~StopWord();
		vector<string> trim(vector<string>);

		bool esUnaStopWord(string);

	private:


		FileHandler fileHandler;
		vector<string> stopwords = trim(fileHandler.readFile("stop-words.txt"));


	};


}

#endif /* SRC_STOPWORD_H_ */
