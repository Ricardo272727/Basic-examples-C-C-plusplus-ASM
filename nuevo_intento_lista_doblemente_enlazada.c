#include <stdio.h>
#include <stdlib.h>
#include "my_library.h"


typedef struct nodo{
	int dato;
	struct nodo * sgte;
	struct nodo * ant;
}nodo;

nodo * primero = NULL;
nodo * ultimo = NULL;

//13 16 2 5

// <-13-><-16->

void insertarNodo(){
	nodo * nuevo = (nodo*)malloc(sizeof(nodo));
	printf("Ingrese el dato del nuevo nodo \n");scanf("%d",&nuevo->dato);
	if(primero == NULL){
		primero = nuevo;
		primero->sgte = NULL;
		primero->ant = NULL;
		ultimo = primero;
	}else{
		ultimo->sgte = nuevo;
		nuevo->sgte = NULL;
		nuevo->ant = ultimo;
		ultimo = nuevo;
	}
	printf("\nnodo ingresado\n");
}

void desplegarListaPU(){
	nodo * actual = (nodo *)malloc(sizeof(nodo));
	actual = primero;
	if(primero != NULL){
		while(actual != NULL){
			printf("%d",actual->dato);
			actual = actual->sgte;
		}
	}else{
		printf("la lista se encuentra vacia");
	}
}

void desplegarListaUP(){
	nodo * actual = (nodo*)malloc(sizeof(nodo));
	actual = ultimo;
	if(ultimo != NULL){
		while(actual != NULL){
			printf("%d",actual->dato);
			actual = actual->ant;
		}
	}else{
		printf("la lista se encuentra vacia");
	}
}

int main(int argc, char *argv[]){
	
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	desplegarListaPU();
	desplegarListaUP();
	
	
	return 0;
}

