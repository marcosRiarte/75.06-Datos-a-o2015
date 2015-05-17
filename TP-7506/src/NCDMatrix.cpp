/*
 * NDCMatriz.cpp
 *
 *  Created on: May 8, 2015
 *      Author: ruben
 */

#include "NCDMatrix.h"



namespace std {

NCDMatrix::NCDMatrix() {
	// TODO Auto-generated constructor stub

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

float NCDMatrix::getValue(int posX, int posY) {
	return this->matriz[posX][posY];
}

void NCDMatrix::setValue(float value, int posX, int posY) {
	this->matriz[posX][posY] = value;
}

bool NCDMatrix::saveMatrix(string direccion) {
	ofstream os(direccion.c_str(), ios::binary | ios::out);
	if ( !os.is_open() ) {
		return false;
	}

	os.write(reinterpret_cast<const char*>(matriz), streamsize(alto*ancho*sizeof(float)));
	os.close();
	return true;
}

bool NCDMatrix::loadMatrix(string direccion, int alto, int ancho) {
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

void NCDMatrix::guardarMatrizDeFormaLinear(){


	FileHandler filehandler;
	vector<string> distancias;
	cout<<"Grabo Matriz de NCD linea por linea: "<<endl;
	for(int i=0;i<this->getAlto();i++){
		string lineaNCD = "";
		for(int j=0;j<this->getAncho();j++){
			ostringstream ss;
			ss << this->matriz[i][j];
			lineaNCD.append("#");
			lineaNCD.append(ss.str());
		}
		distancias.push_back(lineaNCD);
	}

	filehandler.writeFile("Distancias.txt",distancias);
}

}

