#include <stdio.h>
#include <stdlib.h>

typedef char * URL;

typedef struct nodo{
	URL url;
	struct nodo * sgte;
}Nodo;

typedef struct pila{
	Nodo * cima;
	int longitud;

}Pila;

Pila * CrearPila()
{
	Pila * pila = (Pila *)malloc(sizeof(Pila));
	pila->cima = NULL;
	pila->longitud = 0;
	return pila;
}

void DestruirNodo(Nodo * nodo){
	nodo->sgte = NULL;
	free(nodo);
}
void Desapilar(Pila * pila)
{
	if(pila->cima == NULL){
		Nodo * eliminar = pila->cima;
		pila->cima = pila->cima->sgte;
		DestruirNodo(eliminar);
		pila->longitud--;
	}
}
void DestruirPila(Pila * pila)
{
	while(pila->cima != NULL){
		Desapilar(pila);
	}
	free(pila);
}

int Longitud(Pila * pila)
{
	return pila->longitud;
}

int EstaVacia(Pila * pila)
{
	return pila->longitud == 0;
}

Nodo * CrearNodo(URL url){
	Nodo * nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->url = url;
	nodo->sgte = NULL;
	return nodo;
}




void Apilar(Pila * pila,URL url){
	Nodo * nodo = CrearNodo(url);
	nodo->sgte = pila->cima;
	pila->cima = nodo;
	pila->longitud++;
}



URL Cima(Pila * pila)
{
	if(pila->cima == NULL)
		return NULL;
	else
		return pila->cima->url;
}


int main(int argc, char *argv[]) {
	char elemento[20];
	Pila * pila;
	URL url;
	printf("Hola escribe un elemento para apilar:");
	fgets(elemento,20,stdin);
	
	pila = CrearPila();
	Apilar(pila,elemento);
	
	url = Cima(pila);
	
	printf("%s",url);
	return 0;
}

