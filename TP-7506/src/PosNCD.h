/*
 * PosNCD.h
 *
 *  Created on: May 17, 2015
 *      Author: fran
 */

#ifndef SRC_POSNCD_H_
#define SRC_POSNCD_H_

namespace std {

class PosNCD {
public:
	int position;
	float NCD;
public:
	PosNCD(int pos, float ncd);
	virtual ~PosNCD();
	bool operator()(PosNCD i, PosNCD j);
};

} /* namespace std */

#endif /* SRC_POSNCD_H_ */
