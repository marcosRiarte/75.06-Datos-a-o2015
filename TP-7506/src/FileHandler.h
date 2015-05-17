/*
 * FileReader.h
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#ifndef SRC_FILEHANDLER_H_
#define SRC_FILEHANDLER_H_

#include <string>
#include <vector>
#include <fstream>


namespace std {

class FileHandler {
public:
	FileHandler();
	virtual ~FileHandler();
	vector<string> readFile(const char* filename);
	void writeFile(const char* fileName, const char* header, vector<string> lines);
	void writeFile(const char* fileName, vector<string> lines);
};

} /* namespace std */

#endif /* SRC_FILEHANDLER_H_ */
