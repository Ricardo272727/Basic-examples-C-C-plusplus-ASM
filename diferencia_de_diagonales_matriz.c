
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ** matriz;
typedef int * p_entero;

matriz generar_matriz(int m, int n){
	int i;matriz p;
	if((p = (matriz)malloc(m*sizeof(p_entero))) == NULL ) return p;
	for(i=0;i<m;i++){
		if((p[i] = (p_entero)malloc(n*sizeof(int))) ==  NULL) return p;
	}
	return p;
}

void leer_matriz(matriz A, int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("P[%d][%d]",i,j);
			scanf("%d", &A[i][j]);
		}
	}
}

void mostrar_matriz(matriz A,int m, int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("\tp[%d][%d]:%d",i,j,A[i][j]);
		}
		printf("\n");
	}
}

int diferencia_diagonales(matriz A,int m,int n,int *diag1,int *diag2){
	int i,j,dif;
	*diag1 = 0;
	*diag2 = 0;
	//suma de la primera diagonal
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(i == j){
				*diag1 += A[i][j];
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if((i+j+2) == n+1){
				*diag2 += A[i][j];
			}
		}
	}
	dif  = *diag1 - *diag2;
	if(dif < 0) dif *=-1;
	return dif;
}

int main(int argc, char *argv[]) {
	//programa que obtiene la diferencia de la suma de las dos diagoonales de una matriz
	matriz A;
	int m,n,dif,suma1,suma2;
	printf("\nIntroduce el numero de filas: ");scanf("%d",&m);
	printf("\nIntroduce el numero de columnas: ");scanf("%d",&n);
	A = generar_matriz(m,n);
	leer_matriz(A,m,n);
	mostrar_matriz(A,m,n);
	dif = diferencia_diagonales(A,m,n,&suma1,&suma2);
	printf("\n\tValor absoluto de la diferencia de sus diagonales:\n\t %d - %d = %d",suma1,suma2,dif);
	return 0;
}

