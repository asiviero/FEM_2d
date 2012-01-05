/*
 * node.h
 *
 *  Created on: Jan 4, 2012
 *      Author: andre
 *
 *      Arquivo para definir a struct de um node
 */

#ifndef NODE_H_
#define NODE_H_

typedef struct {
	int id;
	double x;
	double y;
	double z;
	struct node *next;
} node;


#endif /* NODE_H_ */
