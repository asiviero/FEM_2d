/*
 * element.c
 *
 *  Created on: Jan 14, 2012
 *      Author: andre
 */

#include "element.h"
#include "matrix.h"
#include <math.h>
/*
 * This function calculates the J Matrix, which corresponds to the map that performs
 * a coordinate change from global to local, in order to do calculations in a standard
 * element, which should be assembled in the global linear system
 */
void calculateJMatrix(int eid,node *nodeVector,element *elementVector,double JMatrix[2][2]) {
	//double JMatrix[2][2];
	printf("Element is composed by the nodes: %d %d %d\n",elementVector[eid].n1,elementVector[eid].n2,elementVector[eid].n3);
	JMatrix[0][0] = nodeVector[elementVector[eid].n1].x - nodeVector[elementVector[eid].n3].x;
	JMatrix[0][1] = - (nodeVector[elementVector[eid].n3].x - nodeVector[elementVector[eid].n2].x);
	JMatrix[1][0] = - (nodeVector[elementVector[eid].n3].y - nodeVector[elementVector[eid].n1].y);
	JMatrix[1][1] = nodeVector[elementVector[eid].n2].y - nodeVector[elementVector[eid].n3].y;
	//return JMatrix;
}

/*
 * This function calculates the elementary Ke matrix, whise elements will be assembled in the global
 * stiffness matrix K of the global linear system.
 */

void calculateKeMatrix(int eid,node *nodeVector,element *elementVector,double KeMatrix[3][3],double KTensor[2][2]) {
	double coordMatrix[3][3],auxM[2][3],elementArea,auxV[2];
	buildCoordMatrix(eid,nodeVector,elementVector,coordMatrix);

	elementArea = fabs(determinant3x3(coordMatrix)/2);
	printf("Area do Elemento: %lf\n",elementArea);

	buildAuxMatrix(coordMatrix,auxM);
	for(int i=0;i<2;i++) {
		for(int j=0;j<3;j++) printf("%lf ",auxM[i][j]);
		printf("\n");
	}

	auxV[0] = KTensor[0][0]*auxM[0][0] + KTensor[0][1]*auxM[1][0];
	auxV[1] = KTensor[1][0]*auxM[0][0] + KTensor[1][1]*auxM[1][0];
	KeMatrix[0][0] = auxM[0][0]*auxV[0] + auxM[1][0]*auxV[1];
	KeMatrix[1][0] = auxM[0][1]*auxV[0] + auxM[1][1]*auxV[1];
	KeMatrix[2][0] = auxM[0][2]*auxV[0] + auxM[1][2]*auxV[1];

	auxV[0] = KTensor[0][0]*auxM[0][1] + KTensor[0][1]*auxM[1][1];
	auxV[1] = KTensor[1][0]*auxM[0][1] + KTensor[1][1]*auxM[1][1];
	KeMatrix[0][1] = auxM[0][0]*auxV[0] + auxM[1][0]*auxV[1];
	KeMatrix[1][1] = auxM[0][1]*auxV[0] + auxM[1][1]*auxV[1];
	KeMatrix[2][1] = auxM[0][2]*auxV[0] + auxM[1][2]*auxV[1];

	auxV[0] = KTensor[0][0]*auxM[0][2] + KTensor[0][1]*auxM[1][2];
	auxV[1] = KTensor[1][0]*auxM[0][2] + KTensor[1][1]*auxM[1][2];
	KeMatrix[0][2] = auxM[0][0]*auxV[0] + auxM[1][0]*auxV[1];
	KeMatrix[1][2] = auxM[0][1]*auxV[0] + auxM[1][1]*auxV[1];
	KeMatrix[2][2] = auxM[0][2]*auxV[0] + auxM[1][2]*auxV[1];

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) KeMatrix[i][j] /= 4*elementArea;
	}
}

void buildCoordMatrix(int eid,node *nodeVector,element *elementVector,double coordMatrix[3][3]) {
	coordMatrix[0][0] = nodeVector[elementVector[eid].n1].x;
	coordMatrix[0][1] = nodeVector[elementVector[eid].n1].y;
	coordMatrix[0][2] = 1;

	coordMatrix[1][0] = nodeVector[elementVector[eid].n2].x;
	coordMatrix[1][1] = nodeVector[elementVector[eid].n2].y;
	coordMatrix[1][2] = 1;

	coordMatrix[2][0] = nodeVector[elementVector[eid].n3].x;
	coordMatrix[2][1] = nodeVector[elementVector[eid].n3].y;
	coordMatrix[2][2] = 1;
}

void buildAuxMatrix(double coordMatrix[3][3],double auxMatrix[2][3]) {
	auxMatrix[0][0] = coordMatrix[1][1] - coordMatrix[2][1]; // y23
	auxMatrix[0][1] = coordMatrix[1][1] - coordMatrix[0][1]; // y21
	auxMatrix[0][2] = coordMatrix[0][1] - coordMatrix[1][1]; // y12

	auxMatrix[1][0] = coordMatrix[2][0] - coordMatrix[1][0]; // x32
	auxMatrix[1][1] = coordMatrix[0][0] - coordMatrix[2][0]; // x13
	auxMatrix[1][2] = coordMatrix[1][0] - coordMatrix[0 ][0]; // x21

}
