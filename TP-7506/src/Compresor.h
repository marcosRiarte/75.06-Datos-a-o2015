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
private:
	int compressionlevel;
public:
	Compresor(int compressionlevel);
	string compress_string(const string& str);
	string decompress_string(const string& str);
	float obtenerNCD(string strA,int numa,string strB, int numb);
	virtual ~Compresor();
};

#endif /* COMPRESOR_H_ */
