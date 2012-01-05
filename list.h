/*
 * list.h
 *
 *  Created on: Mar 24, 2011
 *      Author: andre
 */

#ifndef LIST_H_
#define LIST_H_

struct nodeList {
	void* element;
	struct nodeList* next;
};
typedef struct nodeList* NODELISTPTR;

struct list {
	NODELISTPTR head;
	NODELISTPTR tail;
};
typedef struct list* list;

list initList();
void addNode(list l, NODELISTPTR node);
NODELISTPTR getNode();
NODELISTPTR copyNode(NODELISTPTR p);
int referenceNumber(list l,NODELISTPTR p);
void destroyList(list l,void (*destroyFunc)(void*));
void insertSorted(list l,NODELISTPTR p,int (*cmp)(NODELISTPTR,NODELISTPTR));

#endif /* LIST_H_ */
