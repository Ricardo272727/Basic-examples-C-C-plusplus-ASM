#include <stdio.h>
#include <malloc.h>

struct nodo {
	int dato;
	struct nodo * sgte;
}Nodo;

typedef struct nodo * pNodo;

//21->12


void insertarNodoAtras(pNodo * raiz,int dato)
{
	pNodo nuevo;
	 if((nuevo = malloc(sizeof(struct nodo))) != NULL){
		nuevo->dato = dato;
		if(*raiz == NULL){
			nuevo->sgte = NULL;
			*raiz = nuevo;
		}else{
			nuevo->sgte = *raiz;
			*raiz = nuevo;
		}
	 }else{
		 printf("\n\tMemoria llena");
	 }
}

void insertarNodoAdelante(pNodo * raiz,int dato)
{
	pNodo i = *raiz,nuevo;
	if((nuevo = malloc(sizeof(struct nodo))) != NULL){
		nuevo->dato = dato;
		nuevo->sgte = NULL;
		if(*raiz == NULL) *raiz = nuevo;
		else{
			while(i->sgte != NULL){
				i = i->sgte;
			}
			i->sgte = nuevo;
		}
	}else{
		printf("\n\tMemoria llena");
	}
}

void mostrarLista(pNodo inicio){
	pNodo i = inicio;
	while(i != NULL){
		printf("\n\tDato:%d",i->dato);
		i = i->sgte;
	}
}



int main(int argc, char *argv[]) {
	
	pNodo lista = NULL;
	pNodo lista2 = NULL;
	
	insertarNodoAtras(&lista,5);
	insertarNodoAtras(&lista,27);
	
	insertarNodoAdelante(&lista,12);
	insertarNodoAdelante(&lista,1);
	insertarNodoAdelante(&lista,100);
	
	insertarNodoAdelante(&lista2,27);
	
	
	mostrarLista(lista);
	
	mostrarLista(lista2);
	return 0;
}

