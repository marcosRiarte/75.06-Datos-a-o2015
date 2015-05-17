/*
 * NDCMatriz.h
 *
 *  Created on: May 8, 2015
 *      Author: ruben
 */

#ifndef NDCMATRIZ_H_
#define NDCMATRIZ_H_

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "FileHandler.h"

namespace std{

class NCDMatrix {
public:
	NCDMatrix();
	NCDMatrix(int alto, int ancho);
	virtual ~NCDMatrix();

	int getAncho();
	int getAlto();
	void setValue(float value,int posX, int posY);
	float getValue(int posX, int posY);
	void guardarMatrizDeFormaLinear();
	bool saveMatrix(string direccion);
	bool loadMatrix(string direccion, int alto, int ancho);
private:
	int alto, ancho;
	float **matriz;
};
}

#endif /* NDCMATRIZ_H_ */
