#include <stdio.h>
#include <stdlib.h>
#include "my_library.h"
#include <ctype.h>
int suma_divisores(int n){
	int i,suma = 0;
	for(i = 1;i < n;i++){
		if(n%i == 0) suma += i; 
	}
	return suma;
}


int main(int argc, char *argv[]) {
	int n,suma;
	char op;
	do{
		
		linea();
		printf("\n\tEscribe un numero: ");scanf("%d",&n);
		if(n > 0){
			suma = suma_divisores(n);
			linea();
			if(suma == n) printf("\n\tEl numero %d es perfecto\n",n);
			else printf("\n\tEl numero %d tiene un amigo: %d\n",n,suma);
			
		}else printf("\n\tIntenta de nuevo con un numero positivo");
		
		linea();
		while(getchar() != '\n');
		printf("\n\tOtra vez? S/N ");
		scanf("%c",&op);
		op = toupper(op);
		
	}while(op != 'N');
	
	mi_nombre();
	
	
	return 0;
}

