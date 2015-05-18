/*
 * PosNCD.cpp
 *
 *  Created on: May 17, 2015
 *      Author: fran
 */

#include "PosNCD.h"

namespace std {

PosNCD::PosNCD(int pos, float ncd) {
	position =  pos;
	NCD = ncd;
}

PosNCD::~PosNCD() {
	// TODO Auto-generated destructor stub
}

bool PosNCD::operator()(PosNCD x, PosNCD y){
	return (x.NCD<y.NCD);
}

} /* namespace std */
