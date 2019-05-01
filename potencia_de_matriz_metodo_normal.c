#include <stdio.h>
#include "my_library.h"
#include <stdlib.h>



void llenarMatriz(matriz A,int valor,int m,int n)
{
	int i,j;
	for(i = 0;i < m;i++)
		for(j = 0;j < n;j++)
			A[i][j] = valor;
}

matriz potenciaMatriz(matriz A, int exp,int m,int n)
{
	matriz Aux = generar_matriz(m,n);
	matriz Aux2 = generar_matriz(m,n);
	copiarMatriz(A,Aux,m,n);
	int i,j,k,l;
	float suma;
	for(i = 0;i < exp-1;i++){
		llenarMatriz(Aux2,0,m,n);
		for(j = 0;j < m;j++){
			for(k = 0;k < n;k++){
				suma = 0;
				//matriz auxiliar * A
				for(l = 0;l < n;l++) suma += A[j][l] * Aux[l][k];
				Aux2[j][k] = suma;
			}
		}
		copiarMatriz(Aux2,Aux,m,n);
	}
	return Aux;
}


int main(int argc, char *argv[]) {
	
	int r,c,p;
	
	printf("\n\tRenglones de A: ");
	scanf("%d",&r);
	printf("\n\tColumnas de A: ");
	scanf("%d",&c);
	matriz A = generar_matriz(r,c);
	leer_matriz(A,r,c,'A');
	mostrar_matriz(A,r,c);
	printf("\n\tPotencia a elevar la matriz: ");
	scanf("%d",&p);
	
	matriz B = potenciaMatriz(A,p,r,c);
	mostrar_matriz(B,r,c);
	
	
	
	return 0;
}

