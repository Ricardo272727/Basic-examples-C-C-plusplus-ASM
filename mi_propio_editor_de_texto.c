#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char * txt;
	//1.Escribir texto y poder dar formato despues de un salto de linea
	if((txt = (char*)malloc(10000* sizeof(char))) == NULL) return -1;
	else{
		printf("*******************************CUFUAFANAFALOFO*********************************\n");
		fgets(txt,10000,stdin);
	}
	
	
	
	//mover el cursor con las teclas sobre el texto
	
	//reconoces las teclas de guardar,cortar,pegar,copiar
	
	
	return 0;
}

