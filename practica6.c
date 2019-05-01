#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int ** matriz;
typedef int * p_entero;


void rellenar_aleatoriamente(matriz A,int r,int c){
	int i,j,aleatorio;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++){
			aleatorio = rand() % 10;
			A[i][j] = aleatorio;
		}
}

void separador(){
	printf("\n\t##############################################################\n");
}
void separador_small(){
	printf("\n\t--------------------------------------------------------------\n");
}
void multiplicar_matrices(matriz A,int ra,int ca,matriz B, int rb, int cb, matriz C){
	int i,j,k,suma;
	
	for(i=0;i<ra;i++){
		for(j=0;j<cb;j++){
			suma = 0;
			for(k=0;k<ca;k++){
				suma += A[i][k] * B[k][j];
			}
			C[i][j] = suma;
			
		}
	}
}

matriz generar_matriz(int m,int n){
	matriz A;
	int i;

	if((A = (matriz)malloc(m * sizeof(p_entero))) == NULL) return A;

	for(i = 0;i<m;i++){
		if((A[i] =  (p_entero)malloc(n * sizeof(int))) == NULL) return A;
	}

	return A;
}

void leer_matriz(matriz A,int m,int n,char name){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("\t%c[%d][%d] = ",name,i,j);
			scanf("%d",&A[i][j]);
		}
		
	}
}

void diferencia(matriz A,matriz B,matriz C,int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

void mostrar_matriz(matriz p,int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("\t%d", p[i][j]);
			//otras formas de hacer lo mismo
			//scanf("%d", p[i]+j);
			//scanf("%d", *(p+i)+j );
		}
		printf("\n\n");
	}
}

int main(){
	int ra,rb,ca,cb,f,op;
	f = 1;
	srand(time(NULL));
	while(f == 1){
	separador();
	printf("\n\t1.Diferencia de matrices");
	printf("\n\t2.Producto de matrices\n\t");
	printf("0.Terminar\n\t");
	scanf("%d",&op);
	switch(op){
	case 1:
			
				separador_small();
				printf("\n\tRenglones de A:");
				scanf("%d",&ra);
				printf("\n\tColumnas de A:");
				scanf("%d",&ca);
				separador_small();
				printf("\n\tRenglones de B:");
				scanf("%d",&rb);
				printf("\n\tColumnas de B:");
				scanf("%d",&cb);
			
				if(ra ==  rb && ca == cb){
					matriz A,B,C;
					
					A = generar_matriz(ra,ca);
					B = generar_matriz(rb,cb);
					C = generar_matriz(ra,cb);
					
					separador_small();
					printf("\n\t1.Dar valores a cada matriz");
					printf("\n\t2.Rellenar valores aleatoriamente\n\t");
					scanf("%d",&op);
					
					switch(op){
						case 1:
							separador_small();
							leer_matriz(A,ra,ca,'A');
							
							separador_small();
							leer_matriz(B,rb,cb,'B');
							break;
						case 2:
							rellenar_aleatoriamente(A,ra,ca);
							rellenar_aleatoriamente(B,rb,cb);
							break;
					default: op = -1;
					}
					
					if(op != -1){
						diferencia(A,B,C,ra,rb);
						separador_small();
						printf("\n\tMatriz A:\n\n");
						mostrar_matriz(A,ra,ca);
						separador_small();
						printf("\n\tMatriz B:\n\n");
						mostrar_matriz(B,rb,cb);
						separador_small();
						printf("\n\tA - B:\n\n");
						mostrar_matriz(C,ra,cb);
					}else{
						separador();
						printf("\n\tOpcion incorrecta intenta de nuevo");
					}
				}else{
					separador();
					printf("\n\tLas matrices no se pueden sumar/restar\n");
				}
		break;
	case 2:
		separador_small();
		printf("\n\tRenglones de A:");
		scanf("%d",&ra);
		printf("\n\tColumnas de A:");
		scanf("%d",&ca);
		separador_small();
		printf("\n\tRenglones de B:");
		scanf("%d",&rb);
		printf("\n\tColumnas de B:");
		scanf("%d",&cb);
		
		if(ca == rb){
			matriz A,B,C;
			A = generar_matriz(ra,ca);
			B = generar_matriz(rb,cb);
			C = generar_matriz(ra,cb);
			
			separador_small();
			printf("\n\t1.Dar valores a cada matriz");
			printf("\n\t2.Rellenar valores aleatoriamente\n\t");
			scanf("%d",&op);
			separador_small();
			
			switch(op){
			case 1:
				leer_matriz(A,ra,ca,'A');
				
				separador_small();
				leer_matriz(B,rb,cb,'B');
				break;
			case 2:
				rellenar_aleatoriamente(A,ra,ca);
				rellenar_aleatoriamente(B,rb,cb);
				break;
			default: op = -1;
			}
			
			if(op != -1){
				multiplicar_matrices(A,ra,ca,B,rb,cb,C);
				
				separador_small();
				printf("\n\n\tMatriz A:\n\n");
				mostrar_matriz(A,ra,ca);
				
				separador_small();
				printf("\n\n\tMatriz B:\n\n");
				mostrar_matriz(B,rb,cb);
				
				separador_small();
				printf("\n\n\tA x B:\n\n");
				mostrar_matriz(C,ra,cb);
			}else{
				separador();
				printf("\n\tOpcion incorrecta intenta de nuevo");
			}
			
		}else{
			separador();
			printf("\n\n\tEl producto entre estas dos matrices no esta definido\n\n");
			
		}
		break;
	case 0:
		f = 0;
		break;
	default: printf("\n\n\tOpcion incorrecta intenta de nuevo\n\n"); 
	}//switch
	}//while
	return 0;
}
