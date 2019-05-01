#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "my_library.h"

//typedef int ** matriz;
//typedef int * p_entero;
void reducir_triangular_superior(matriz A,int r,int c);
void permutar_filas(matriz A,int fila1,int fila2,int c);
void multiplicar_fila(matriz A,float esc,int fila,int c);
void transformacion(matriz A,int fila1,int fila2,float esc,int c);



void permutar_filas(matriz A,int fila1,int fila2,int c){
	
	int i,aux;
	
	for(i = 0;i < c;i++){
		aux = A[fila1][i];
		A[fila1][i] = A[fila2][i];
		A[fila2][i] = aux;
	}
	
}
void multiplicar_fila(matriz A,float esc,int fila,int c){
	int i;
	for(i=0;i<c;i++) {
		A[fila][i] *= esc;	
	}
}

void transformacion(matriz A,int fila1,int fila2,float esc,int c){
	int i;float aux;
	for(i = 0;i<c;i++){
		aux = A[fila1][i] * esc;
		A[fila2][i] += aux;
	}
}


void reducir_triangular_superior(matriz A,int r,int c){
	int k,i;
	int count;
	float esc;
	
	for(k = 0;k<c;k++){
			//1.permutar filas hasta que el pivote sea != 0
			count = 1;
			while(A[k][k] == 0 && count < r){
				permutar_filas(A,k,r-count,c);
				count ++;
			}
			if(count == r) printf("\n\tLa matriz no tiene sentido!");
			//2.hacer 1 el pivote 
			if(A[k][k] != 1){
				esc = 1/(float)A[k][k];
				multiplicar_fila(A,esc,k,c);
			}
			linea();
			mostrar_matriz(A,r,c);
			
			//3.buscar escalar que hace 0 al numero de abajo del pivote
			for(i=1;i<r;i++){
				if(A[i][k] != 0){
					//3.buscar escalar que hace 0 al numero de abajo del pivote
					esc = -1 * A[i][k];
					//3.1multiplicar la fila del pivote por el escalar y sumar a la fila de abajo
					transformacion(A,k,i,esc,c);
				}
			}
			//4.moverse al siguiente pivote y regresar al paso 1
				
	}
	
	
}

int main(int argc, char *argv[]) {
	int ra,ca;
	char op;
	srand(time(NULL));
	matriz A;
	
	do{
		//ra = 4;
		//ca = 4;
		printf("\n\tRenglones de A:");
		scanf("%d",&ra);
		printf("\n\tColumnas de A:");
		scanf("%d",&ca);
		
		A = generar_matriz(ra,ca);
		
		//rellenar_aleatoriamente(A,ra,ca);
		leer_matriz(A,ra,ca);
		linea();
		mostrar_matriz(A,ra,ca);
		
		reducir_triangular_superior(A,ra,ca);
		linea();
		mostrar_matriz(A,ra,ca);
		
		printf("\n\tOtra vez? ");
		scanf("%c",&op);
		while(getchar() != '\n');
		op = toupper(op);
	}while( op != 'N');
	
	return 0;
}

