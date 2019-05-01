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


void insertarNodo(int dato){
	nodo * nuevo = NULL;
	if((nuevo = (nodo*)malloc(sizeof(nodo)) == NULL)) exit(-1);
	
	if(primero == NULL){
		primero = nuevo;
		primero->ant = NULL;
		primero->sgte = NULL;
		primero->dato = dato;
		ultimo = nuevo;
	}else{
		ultimo->sgte = nuevo;
		nuevo->ant = ultimo;
		nuevo->sgte = NULL;
		nuevo->dato = dato;
		ultimo = nuevo;
		
	}
	
}


int main(int argc, char *argv[]) {
	
	
	
	return 0;
}

