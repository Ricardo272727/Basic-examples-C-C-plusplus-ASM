#include <stdio.h>
#include "my_library.h"

//Recordatorio...despues de que me salga liberar toda la memoria que no se ocupa

typedef struct arrayMatrices 
{
	matriz matrices[10];
	int numMat;
	int m;
	int n;
}arrayMatrices;

matriz multiplicarMatrices(struct arrayMatrices * Mat,int m,int n)
{	
	matriz Aux = generar_matriz(m,n);
	matriz Aux2 = generar_matriz(m,n);
	int i,j,k,l;
	float suma;
	for(i=0;i<Mat->numMat-1;i++){
		//multiplicar las primeras dos, y guardar en Aux,multiplicar Aux * 3era, guardar, Aux * 4ta ,guardar...
		if(i == 0){
			matriz A = Mat->matrices[i];
			matriz B = Mat->matrices[i+1];
			for(j = 0;j < m;j++){
				for(k = 0;k < n;k++){
					suma = 0;
					//matriz auxiliar * A
					for(l = 0;l < n;l++) suma += A[j][l] * B[l][k];
					Aux[j][k] = suma;
				}
			}
		}else{
			matriz A = Mat->matrices[i+1];
			for(j = 0;j < m;j++){
				for(k = 0;k < n;k++){
					suma = 0;
					//matriz auxiliar * A
					for(l = 0;l < n;l++) suma += Aux[j][l] * A[l][k];
					Aux2[j][k] = suma;
				}
			}
			copiarMatriz(Aux2,Aux,m,n);
		}
	}
	return Aux;
}


int main(int argc, char *argv[]) {
	
	int n,numMat,i;
	
	printf("\n\tNumero de columnas y renglones de las matrices: ");
	scanf("%d",&n);
	printf("\n\tCuantas matrices multiplicaras?: ");
	scanf("%d",&numMat);

	arrayMatrices * Mat = (arrayMatrices*)malloc(sizeof(struct arrayMatrices));
	Mat->numMat = numMat;
	Mat->m = n;
	Mat->n = n;
	//matriz matrices[numMat];
	for(i=0;i<Mat->numMat;i++){
		printf("\n\tElementos de la matriz: %d",i+1);
		Mat->matrices[i] = generar_matriz(Mat->m,Mat->n); 
		leer_matriz(Mat->matrices[i],Mat->m,Mat->n,(char)i);
	}
	
	for(i=0;i<numMat;i++){
		printf("\n\tMatriz: %d",i+1);
		mostrar_matriz(Mat->matrices[i],n,n);
	}
	
	matriz result = multiplicarMatrices(Mat,n,n);
	printf("\n\tResultado:\n");
	mostrar_matriz(result,n,n);
	
	
	return 0;
}

