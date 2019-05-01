#include <stdio.h>
#include <stdlib.h>
#include "my_library.h"
#include <ctype.h>
typedef struct Persona{
	char tel[11];
	char nombre[100];
	char direccion[100];
	struct Persona * sgte;
}Persona;

Persona * first = NULL;
Persona * last = NULL;

void agregar(Persona * persona){
	
	if(first == NULL){
		first = persona;
		last = persona;
	}else{
		last -> sgte = persona;
		last = persona;
	}
}

int main(int argc, char *argv[]) {
	int f = 1;
	char op;
	
	Persona * i;
	
	do{
		linea();
		printf("\n\tAgregar contacto: \n");
		linea();
		printf("\n\tTelefono: ");fgets(i->tel,100,stdin);
		printf("\n\tNombre: ");fgets(i->nombre,100,stdin);
		printf("\n\tDireccion: ");fgets(i->direccion,100,stdin);
		agregar(i);
		printf("\n\tOtra vez? ");scanf("%c",&op);
		while(getchar() != '\n');
		op = toupper(op);
		if(op == 'N')f = 0;
	}while(f == 1);
	
	i = first;
	
	while(i != NULL){
		printf("persona");
		i = i -> sgte;
	}
	
	
	
	
	return 0;
}

