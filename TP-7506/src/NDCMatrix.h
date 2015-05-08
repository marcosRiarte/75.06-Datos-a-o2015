/*
 * NDCMatriz.h
 *
 *  Created on: May 8, 2015
 *      Author: ruben
 */

#ifndef NDCMATRIZ_H_
#define NDCMATRIZ_H_

#include <string>
using namespace std;

class NDCMatrix {
public:
	NDCMatrix();
	NDCMatrix(int alto, int ancho);
	virtual ~NDCMatrix();

	void setValue(float value,int posX, int posY);
	float getValue(int posX, int posY);
	bool saveMatrix(string direccion);
	bool loadMatrix(string direccion, int alto, int ancho);
private:
	int alto, ancho;
	float **matriz;
};

#endif /* NDCMATRIZ_H_ */
