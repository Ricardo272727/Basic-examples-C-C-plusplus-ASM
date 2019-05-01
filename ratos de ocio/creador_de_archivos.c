#include <stdio.h>
#include <string.h>

FILE * p_arch;

int main(int argc, char *argv[]) {
	char nombre[100];
	printf("Hola escribe el nombre del archivo que deseas crear: ");
	scanf("%s",nombre);
	
	char ruta_archivo[] = "prueba/";
	strcat(ruta_archivo,nombre);
	
	
	
	return 0;
}

