/*
 * list.c
 *
 *  Created on: Mar 24, 2011
 *      Author: andre
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

NODELISTPTR getNode() {
	NODELISTPTR aux;
	aux = (NODELISTPTR)malloc(sizeof(struct nodeList));
	if (aux) return aux;
	else return NULL;
}

list initList() {
	list aux = (list)malloc(sizeof(struct list));
	aux->head=NULL;
	aux->tail=NULL;
	return aux;
}

void addNode(list l,NODELISTPTR node) {
	if(!l||!l->head) {
		l->head = node;
		l->tail = node;
		return;
	};
	if(l->head == l->tail) {
		l->head->next = node;
		l->tail = node;
		return;
	}
	l->tail->next = node;
	l->tail = node;
}

int nList(list l) {
	if(!l||!l->head) return 0;
	NODELISTPTR aux = l->head;
	int i=0;
	while(aux) {i++; aux = aux->next;}
	return i;
}

NODELISTPTR copyNode(NODELISTPTR p) {
	NODELISTPTR aux;
	aux = (NODELISTPTR)malloc(sizeof(struct nodeList));
	aux->element = p->element;
	return aux;
}


void destroyList(list l,void (*destroyFunc)(void*)) {
	NODELISTPTR aux = l->head;
	while (aux) {
		//debug();
		//printf("%s\n",((reference*)(aux->element)))
		destroyFunc(aux->element);
		free(aux);
		aux=aux->next;
		//aux2=NULL;
	};
	free(l);
	l=NULL;
}

void insertSorted(list l,NODELISTPTR p,int (*cmp)(NODELISTPTR,NODELISTPTR)) {
	if(!l->head) {
		l->head = p;
		l->tail = p;
		return;
	};
	if(l->head == l->tail) {

		if(cmp(p,l->tail)<0) {

			p->next = l->head;
			l->head = p;
			return;
		}
		else {
			printf("sered ta aqui\n");
			p->next = NULL;
			l->head->next = p;
			l->tail = p;
			return;
		}
	};

	NODELISTPTR aux = l->head;
	if(cmp(p,l->head)<0) {
		
		p->next = aux;
		l->head = p;
		return;
	}
	//aux = aux->next;
	while(aux) {
		if(cmp(p,aux->next) < 0) {
		//printf("t: %d\nr2: %d\n",t,r);
		//if(r==0) {t++; continue;}
			p->next = aux->next;
			aux->next = p;
			if(aux==l->tail) l->tail = p;
			//if(aux==l->head) l->head =
			return;
		};
		aux = aux->next;
	}
}
