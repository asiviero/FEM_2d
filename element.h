/*
 * element.h
 *
 *  Created on: Jan 4, 2012
 *      Author: andre
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include "node.h"
typedef struct {
	int eid,n1,n2,n3;
} element;

void calculateJMatrix(int eid,node *nodeVector,element *elementVector,double JMatrix[2][2]);
void calculateKeMatrix(int eid,node *nodeVector,element *elementVector,double KeMatrix[3][3],double KTensor[2][2]);
void buildCoordMatrix(int eid,node *nodeVector,element *elementVector,double coordMatrix[3][3]);
void buildAuxMatrix(double coordMatrix[3][3],double auxMatrix[2][3]);

#endif /* ELEMENT_H_ */
