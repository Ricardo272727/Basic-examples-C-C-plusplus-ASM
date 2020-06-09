#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_library.h"
int main(int argc, char *argv[]) {
	
	
	
	char cad1[100],cad2[100],op;
	int x = 1;
	while(x == 1){
		
		printf("\nDa la primer cadena: ");fgets(cad1,100,stdin);
		printf("\nDa la segunda cadena: ");fgets(cad2,100,stdin);
		
		int i = 0, f = 1;
		
		while(cad1[i] != '\0' && cad2[i] != '\0' && f == 1){
			if(cad1[i] == cad2[i]) i ++;
			else f = 0;
		}
		
		if(cad1[i] ==  cad2[i]) printf("\nLas cadenas son iguales");
		else printf("\nLas cadenas son distintas");
	
		/*
			int i = 0;
			int f = 1;
		while(cad1[i] != '\0' && cad2[i] != '\0' && f == 1){
		
		
		if(cad1[i] == cad2[i]){
		i++;
		}else{
		f = 0;
		}
		
		
		}
		if(cad1[i] == cad2[i]){
		printf("\nLas cadenas son iguales");
		}else{
		printf("\nLas cadenas son diferentes");
		}
		
		*/
		
		
		do{
			printf("\n\nOtra vez? S/N ");
			scanf("%c",&op);
			while(getchar() != '\n');
			op = toupper(op);
		}while(op != 'S' && op != 'N');
		
		
		 
		
		if(op == 'N') x =0;
	}
	
	
	mi_nombre();
	
	return 0;
}

