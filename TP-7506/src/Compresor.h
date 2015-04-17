/*
 * Compresor.h
 *
 *  Created on: Apr 17, 2015
 *      Author: martin
 */


#ifndef COMPRESOR_H_
#define COMPRESOR_H_



#include <string.h>


using namespace std;

class Compresor {
public:
	Compresor();
	string compress_string(const string& str,int compressionlevel);
	string decompress_string(const std::string& str);
	float obtenerNCD(string strA,string strB);
	virtual ~Compresor();
};

#endif /* COMPRESOR_H_ */
