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
	matriz p;int i;
	if(( p = (matriz)malloc(m*sizeof(p_entero)) ) == NULL) return p;
	for(i=0;i<m;i++){
		if((p[i] = (p_entero)malloc(n*sizeof(int))) == NULL) return p;
	}
	return p;
}

void liberar_matriz(matriz p,int m, int n){
	int i;
	for(i=0;i<m;i++){
		free(p[i]);
	}
	free(p);
}

void leer_matriz(matriz p,int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("p[%d][%d]",i,j);
			scanf("%d", &(p[i][j]));
			//otras formas de hacer lo mismo
			//scanf("%d", p[i]+j);
			//scanf("%d", *(p+i)+j );
		}
	}
}

void mostrar_matriz(matriz p,int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d \t", p[i][j]);
			//otras formas de hacer lo mismo
			//scanf("%d", p[i]+j);
			//scanf("%d", *(p+i)+j );
		}
		printf("\n");
	}
}

void sumar_matrices(matriz A,matriz B, int m, int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			A[i][j] = A[i][j] + B[i][j];
		}
	}
}

int diagonal_diference(matriz A,int m, int n
					   ){
	int i,j,d1 = 0,d2 = 0,dif = 0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if((i+j)%2 == 0){
				if(i == j){
						d1 += A[i][j]; 
				}else{
						d2 +=A[i][j];
				}
			}
		}
	}
	d2 += A[1][1];
	dif = d1 - d2;
	if(dif<0) dif *= -1;
	return dif;
}

int main(){
	int m,n,diference;matriz A,B;
	printf("Filas:");
	scanf("%d",&m);
	printf("Columnas:");
	scanf("%d",&n);
	A = generar_matriz(m,n);
	B = generar_matriz(m,n);
	printf("Escribe la matriz A:\n");
	leer_matriz(A,m,n);
	printf("Escribe la matriz B:\n");
	leer_matriz(B,m,n);
	sumar_matrices(A,B,m,n);
	printf("La suma de A Y B es\n");
	mostrar_matriz(A,m,n);
	diference = diagonal_diference(A,m,n);
	printf("\nDiferencia de diagonal matriz 1 de 2x2...%d\n",diference);
	printf("Liberando matrices...");
	liberar_matriz(A,m,n);
	A = NULL;
	liberar_matriz(B,m,n);
	B = NULL;
	
	return 0;
}
/*
p-> [puntero_a_entero]->[int][int][int][int][int]
	[puntero_a_entero]->[int][int][int][int][int]
	[puntero_a_entero]->[int][int][int][int][int]
	[puntero_a_entero]->[int][int][int][int][int]
	[puntero_a_entero]->[int][int][int][int][int]
*/

