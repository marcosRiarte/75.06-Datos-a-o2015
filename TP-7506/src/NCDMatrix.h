/*
 * NDCMatriz.h
 *
 *  Created on: May 8, 2015
 *      Author: ruben
 */

#ifndef NDCMATRIZ_H_
#define NDCMATRIZ_H_

#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <stdlib.h>
#include <stdio.h>
#include "FileHandler.h"
#include "stringtokeniterator.h"

namespace std{

class NCDMatrix {
public:
	NCDMatrix();
	NCDMatrix(int alto, int ancho);
	virtual ~NCDMatrix();

	int getAncho();
	int getAlto();
	float* getFila(int fila);
	void setValue(float value,int posX, int posY);
	float getValue(int posX, int posY);
	void guardarMatrizDeFormaLinear();
	void levantarMatrizDeFormaLinear();
	bool saveMatrix(string direccion);
	bool loadMatrix(string direccion, int alto, int ancho);
	void find_k_max(int fila, int k, int indices[]);
private:
	int alto, ancho;
	float **matriz;
};
}

#endif /* NDCMATRIZ_H_ */
