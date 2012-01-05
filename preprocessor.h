/*
 * preprocessor.h
 *
 *  Created on: Jan 4, 2012
 *      Author: andre
 */

#ifndef PREPROCESSOR_H_
#define PREPROCESSOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include "element.h"
#include "contourFunction.h"
#include "node.h"

void generateMesh();
node* scanNodes(char *nodeFile,int *nNodes);
void applyContour(int cid,int nNodes,node *nodeVector,void(*func)(node *n));
element* scanElements(char *elementFile,int *nElements);


#endif /* PREPROCESSOR_H_ */
