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
private:
	ofstream fileMatrix;
public:
	FileHandler();
	virtual ~FileHandler();
	vector<string> readFile(const char* filename);
	void writeFile(const char* fileName, const char* header, vector<string> lines);
	void writeFile(const char* fileName, vector<string> lines);
	void writeMatrixLine(string lines);
	void openFile(const char* fileName);
	void closeFile();
};

} /* namespace std */

#endif /* SRC_FILEHANDLER_H_ */
