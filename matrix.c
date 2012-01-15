/*
 * matrix.c
 *
 *  Created on: Jan 15, 2012
 *      Author: andre
 */

#include "matrix.h"

double determinant3x3(double M[3][3]) {
	return (M[0][0]*M[1][1]*M[2][2] + M[0][1]*M[1][2]*M[2][0] + M[0][2]*M[1][0]*M[2][1] - M[0][2]*M[1][1]*M[2][0] - M[2][1]*M[1][2]*M[0][0] - M[2][2]*M[1][0]*M[0][1]);
}
