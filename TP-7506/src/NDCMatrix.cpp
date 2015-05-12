/*
 * NDCMatriz.cpp
 *
 *  Created on: May 8, 2015
 *      Author: ruben
 */

#include "NDCMatrix.h"
#include <fstream>
#include <iostream>

NDCMatrix::NDCMatrix() {
	// TODO Auto-generated constructor stub

}

NDCMatrix::NDCMatrix(int alto, int ancho) {
	this->alto = alto;
	this->ancho = ancho;
	matriz = new float*[alto];
	for(int i = 0; i < alto; ++i) {
	    matriz[i] = new float[ancho];
	}
}

NDCMatrix::~NDCMatrix() {
	// TODO Auto-generated destructor stub
	for(int i = 0; i < alto; ++i) {
	    delete [] matriz[i];
	}
	delete [] matriz;
}

float NDCMatrix::getValue(int posX, int posY) {
	return this->matriz[posX][posY];
}

void NDCMatrix::setValue(float value, int posX, int posY) {
	this->matriz[posX][posY] = value;
}

bool NDCMatrix::saveMatrix(string direccion) {
	ofstream os(direccion.c_str(), ios::binary | ios::out);
	if ( !os.is_open() ) {
		return false;
	}

	os.write(reinterpret_cast<const char*>(matriz), streamsize(alto*ancho*sizeof(float)));
	os.close();
	return true;
}

bool NDCMatrix::loadMatrix(string direccion, int alto, int ancho) {
	ifstream is(direccion.c_str(), ios::binary | ios::in);
	if ( !is.is_open() )
	   return false;

	is.read(reinterpret_cast<char*>(matriz), streamsize(alto*ancho*sizeof(double)));
	is.close();
	return true;
}

bool loadArray( double* pdata, size_t length, const string& file_path)
{
    ifstream is(file_path.c_str(), ios::binary | ios::in);
    if ( !is.is_open() )
    	return false;
    is.read(reinterpret_cast<char*>(pdata), streamsize(length*sizeof(double)));
    is.close();
    return true;
}

