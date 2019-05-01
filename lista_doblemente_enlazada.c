#include <stdio.h>
#include <stdlib.h>
#include "my_library.h"

typedef struct nodo{
	int dato;
	struct nodo * sgte;
	struct nodo * ant;
	
}NODO;

NODO * CrearNodo(int dato);
int insertar_inicio(NODO ** cabeza,int dato);
void imprimir_lista(NODO * cabeza);



int insertar_inicio(NODO ** cabeza,int dato){
	NODO * nuevo = NULL;
	nuevo = CrearNodo(dato);
	
	if(nuevo != NULL){
		nuevo->sgte = *cabeza;
		nuevo->ant = NULL;
		
		if(*cabeza != NULL){
			(*cabeza) -> ant = nuevo;
			*cabeza = nuevo;
			return 1;
		}
	}
	return 0;
}

void imprimir_lista(NODO * cabeza){
	NODO * nAux = cabeza;
	while(nAux != NULL){
		printf("%d",nAux->dato);
		nAux = nAux->sgte;
	}
}


NODO * CrearNodo(int dato){
	NODO * nuevo = NULL;
	nuevo = (NODO*)malloc(sizeof(NODO));
	nuevo->dato = dato;
	nuevo->sgte = NULL;
	nuevo->ant = NULL;
	return nuevo;
	
}

int main(int argc, char *argv[]){
	NODO *cabeza = NULL;
	insertar_inicio(&cabeza,1);

	imprimir_lista(cabeza);
	//system("pause");
	
	return 0;	
}

/*
typedef struct Nodo{
	char nombre[10];
	struct Nodo * sgte;
	struct Nodo * ant;
}Nodo;

Nodo * first = NULL;
Nodo * last = NULL;

void agregar(Nodo * nodo){
	if(first == NULL){
		first = nodo;
		nodo -> sgte = NULL;
		nodo -> ant = NULL;
		last = nodo;
	}else{
		last -> sgte = nodo;
		last -> ant  = last;
		last = nodo;
	}
}



int main(int argc, char *argv[]){
	//crear una estructura de una lista doblemente enlazada en 10 minutos:
	Nodo * i;
	if((i = (Nodo *)malloc(sizeof(struct Nodo)) == NULL)) exit(-1);
	
	printf("Nombre: ");fgets(i->nombre,10,stdin);
	
	agregar(i);
	
	
	
	return 0;
}
*/
