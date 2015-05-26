/*
 * FileReader.cpp
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#include "FileHandler.h"

namespace std {

FileHandler::FileHandler() {
	// TODO Auto-generated constructor stub

}

FileHandler::~FileHandler() {
	// TODO Auto-generated destructor stub
}

vector<string> FileHandler::readFile(const char* fileName){
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

void FileHandler::writeFile(const char* fileName, const char* header, vector<string> lines){
	ofstream file;
	file.open(fileName);
	file << header <<endl;
	for(int i=0; i< lines.size();i++){
		file<<lines[i]<<endl;
	}
	file.close();
}

} /* namespace std */
