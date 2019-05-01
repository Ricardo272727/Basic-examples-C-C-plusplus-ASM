#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrar_matriz(int A[][10], int n){
	int i,j;
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("\t%d",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void transpuesta(int A[][10],int B[][10],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			B[i][j] = A[j][i];
		}
	}
}

int comparar(int A[][10],int B[][10],int n){
	int i,j,f = 1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(A[i][j] != B[i][j]) {
				f = 0;
				break;
			};
		}
	}
	return f;
}

int main(int argc, char *argv[]) {
	int A[10][10],B[10][10],n,i,j;
	printf("\n\tEscribe el numero de columnas/renglones de A :");scanf("%d",&n);
	srand(time(NULL));
	if(n <= 10){
		//pedir matriz
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("A[%d][%d]: ",i,j);
				scanf("%d",&A[i][j]);
				//A[i][j] = rand() % 10;
			}
		}
		mostrar_matriz(A,n);
		//sacar transpuesta
		transpuesta(A,B,n);
		mostrar_matriz(B,n);
		//verificar que transpuesta sea igual a la original
		int comp;
		if((comp = comparar(A,B,n)) == 1){
			printf("\n\tLa matriz es simetrica");
		}else{
			printf("\n\tLa matriz NO es simetrica");
		}
		
	}else{
		printf("\n\tMaximo numero de columnas: 10");
	}
	
	
	return 0;
}

