/*
 * NDCMatriz.cpp
 *
 *  Created on: May 8, 2015
 *      Author: ruben
 */

#include "NCDMatrix.h"



namespace std {

NCDMatrix::NCDMatrix() {
	matriz = NULL;
	alto = 0;
	ancho = 0;
}

NCDMatrix::NCDMatrix(int alto, int ancho) {
	this->alto = alto;
	this->ancho = ancho;
	matriz = new float*[alto];
	for(int i = 0; i < alto; ++i) {
	    matriz[i] = new float[ancho];
	}
}

NCDMatrix::~NCDMatrix() {
	// TODO Auto-generated destructor stub
	for(int i = 0; i < alto; ++i) {
	    delete [] matriz[i];
	}
	delete [] matriz;
}

int NCDMatrix::getAncho() {
	return this->ancho;
}

int NCDMatrix::getAlto() {
	return this->alto;
}

float* NCDMatrix::getFila(int fila){
	return this->matriz[fila];
}

float NCDMatrix::getValue(int posX, int posY) {
	return this->matriz[posX][posY];
}

void NCDMatrix::setValue(float value, int posX, int posY) {
	this->matriz[posX][posY] = value;
}

bool NCDMatrix::saveMatrix(string direccion) {
	// Write data to file
	FILE* file = fopen (direccion.c_str(), "w");
	if (file == NULL) {
		return false;
	}

	for(int i = 0; i< alto; i++){
		for(int j = 0; j< ancho; j++){
			float f = (float) matriz[i][j];
			fwrite(&f, sizeof(float), 1, file);
		 }
	   // We are just storing the indices, so value at i is equal to i
	}
	fclose(file);


	return true;
}



bool NCDMatrix::loadMatrix(string direccion, int alto, int ancho) {
		FILE* file = fopen(direccion.c_str(), "r");
		if (file == NULL) {
			return false;
		}

		for(int i = 0; i< alto; i++){
			for(int j = 0; j< ancho; j++){
				float f;
				fread(&f, sizeof(float), 1, file);
				matriz[i][j] = f;
			}
		}

		fclose(file);

	return true;
}

}

