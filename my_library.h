#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float ** matriz;
typedef float * p_float;

matriz generar_matriz(int m, int n);
void liberar_matriz(matriz p,int m, int n);
void leer_matriz(matriz p,int m,int n);
void mostrar_matriz(matriz p,int m,int n);
void rellenar_aleatoriamente(matriz A,int r,int c);
void linea();
void mi_nombre();
void marca();

void mi_nombre(){
	printf("\n\t--------------------------------------------------------------\n");
	printf("\t#### \t####\t ####\t ### \t#### \t#### \t ### \n");
	printf("\t#   #\t ## \t#    \t#   #\t#   #\t#   #\t#   #\n");
	printf("\t#### \t ## \t#    \t#####\t#### \t#   #\t#   #\n");
	printf("\t#   #\t ## \t#    \t#   #\t#   #\t#   #\t#   #\n");
	printf("\t#   #\t####\t ####\t#   #\t#   #\t#### \t ### \n");
	printf("\n\n");
	printf("\t ####\t#   #\t ### \t#    #\t ### \t#    \t ### \n");
	printf("\t#    \t#   #\t#   #\t# #  #\t#   #\t#    \t#   #\n");
	printf("\t#    \t#   #\t#####\t#  # #\t#####\t#    \t#   #\n");
	printf("\t#    \t#   #\t#   #\t#   ##\t#   #\t#    \t#   #\n");
	printf("\t ####\t ### \t#   #\t#    #\t#   #\t#####\t ### \n");
	printf("\n\t--------------------------------------------------------------\n");
}

void linea(){
	printf("\n\t--------------------------------------------------------------\n\t");
}

matriz generar_matriz(int m, int n){
	matriz p;int i;
	if(( p = (matriz)malloc(m*sizeof(p_float)) ) == NULL) return p;
	for(i=0;i<m;i++){
		if((p[i] = (p_float)malloc(n*sizeof(int))) == NULL) return p;
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
			scanf("%f", &(p[i][j]));
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
			printf("%.3f\t", p[i][j]);
			//otras formas de hacer lo mismo
			//scanf("%d", p[i]+j);
			//scanf("%d", *(p+i)+j );
		}
		printf("\n\n\t");
	}
}

void marca(){
	printf("\n**");
}

void rellenar_aleatoriamente(matriz A,int r,int c){
	int i,j,aleatorio;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++){
		aleatorio = rand() % 10;
		A[i][j] = aleatorio;
	}
}
