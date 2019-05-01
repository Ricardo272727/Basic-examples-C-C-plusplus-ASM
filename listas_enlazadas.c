#include <stdio.h>
#include <stdlib.h>

//crear un nodo:
/*
typedef struct{
int dato;
struct Nodo * sgte;
}Nodo;

typedef struct SelfReferential {
int i;
SelfReferential* sr; // Head spinning yet?
} SelfReferential;

*/
struct Nodo{
	int dato;
	struct Nodo * sgte;
};

struct Nodo *primer = NULL;
struct Nodo *ultimo = NULL;

//5->6
void agregar(struct Nodo *nodo){
	nodo -> sgte = NULL;
	//hay que ver si la lista esta vacia o no
	if(primer == NULL){
		primer = nodo;
		ultimo = nodo;
	}else{
		
		ultimo -> sgte = nodo;
		//printf("%p",nodo->sgte);
		ultimo = nodo;
	}
	
}


int main(int argc, char *argv[]) {
	//coleccion o secuencia de elemento dispuestos uno detras de otro (esctructura de datos dinamica) en la que cada elemento se conecta al siguiente 
	//con un puntero
	
	//listas simplemente enlazadas:
	//cada nodo contiene un unico enlace eficiente en recorridos directos
	struct Nodo *primerNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	primerNodo -> dato = 5;
	
	struct Nodo *segundoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	segundoNodo -> dato = 8;
	
	agregar(primerNodo);
	agregar(segundoNodo);
	
	struct Nodo *i = primerNodo; 
	
	while(i != NULL){
		printf("%d\n",i->dato);
		i = i -> sgte;
	}
	//doblemente enlazadas:
	//dos enlaces: uno hacia adelante y uno hacia atras
	
	
	//circular simplemente enlazada
	//el ultimo elemento se enlaza al primer elemento
	
	//doblemente enlazada
	//el ultimo elemento se enlaza al primer elemento y viceversa
	//ademas de que tiene 2 enlaces en cada elemento uno hacia adelante y uno hacia atras
	
	//operaciones:
	
	
	
	
	return 0;
}

