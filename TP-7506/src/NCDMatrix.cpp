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


void NCDMatrix::levantarMatrizDeFormaLinear(){
	FileHandler filehandler;

	vector<string> distancias= filehandler.readFile("Distancias.txt");

	cout<<"Leo Matriz de NCD linea por linea: "<<endl;


	int x=0;
	for(int i=0;i<distancias.size();i++){
		string delimiter = "#";

		size_t pos = 0;
		string token;

		pos = distancias[i].find(delimiter);
		distancias[i].erase(0, pos + delimiter.length());


		int y = 0;
		while ((pos = distancias[i].find(delimiter)) != string::npos) {
		    token = distancias[i].substr(0, pos);
		    this->matriz[x][y] = ::atof(token.c_str());
		    distancias[i].erase(0, pos + delimiter.length());
			y++;
		}

		this->matriz[x][y] = ::atof(distancias[i].c_str());
		x++;
	}

	//Prueba

	for (int x=0;x<this->alto;x++){
		for (int y=0;y<this->ancho;y++)
			cout<<matriz[x][y]<< " ";
		cout<<endl;
	}

}

typedef float FT;
void swap(FT *a, FT *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

void minHeapify(FT a[], int size, int i) {
  int l = 2* i ;
  int r = 2* i + 1;
  int smallest = i;
  if (l < size && a[l] < a[smallest])
    smallest = l;
  if (r < size && a[r] < a[smallest])
    smallest = r;
  if (smallest != i) {
    swap(&a[i], &a[smallest]);
    minHeapify(a, size, smallest);
  }

}

void buildMinHeap(FT a[], int size) {
  int i;
  for (i = size / 2; i >= 0; i--)
    minHeapify(a, size, i);

}

int kthLargest(FT a[], int size, int k) {
  FT minHeap[k];
  int i;
  for (i = 0; i < k; i++)
    minHeap[i] = a[i];
  buildMinHeap(minHeap, k);
  for (i = k; i < size; i++) {
    if (a[i] > minHeap[0]) {
      minHeap[0] = a[i];
      minHeapify(minHeap, k, 0);
    }
  }
  return minHeap[0];
}

void NCDMatrix::find_k_max(int fila, int k, int indices[]) {
  FT kth = kthLargest(this->matriz[fila], this->ancho, k);
  int j = 0, i = 0;
  for (; i < this->ancho; ++i)
    if (this->matriz[fila][i] >= kth)
      indices[j++] = i;
}
void NCDMatrix::prepararMatrizParaGuardar(){
	this->fileHandlerMatrix.openFile("Distancias.txt");
	this->lineaNCD = "";
}

void NCDMatrix::cerrarArchivoConMatrizGuardada(){
	this->fileHandlerMatrix.closeFile();
}
void NCDMatrix::guardarValorEnString(int i,int j){
	ostringstream ss;
	ss << this->matriz[i][j];
	this->lineaNCD.append("#");
	this->lineaNCD.append(ss.str());
}
void NCDMatrix::guardarMatrizEnFormaLineal(int cantidadDeBloquesParaGuardar,int cantidadActualDeReviews){
	int numeroMod =(cantidadActualDeReviews % (cantidadDeBloquesParaGuardar-1));
	if (numeroMod == 0){
		(this->fileHandlerMatrix).writeMatrixLine(lineaNCD);
		lineaNCD = "";
	}
}


}

