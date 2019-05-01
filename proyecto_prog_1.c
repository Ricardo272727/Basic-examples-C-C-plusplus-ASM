#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "my_library.h"

typedef struct Conjunto{
	int tam;
	int dato[100];
}Conjunto;


void leerConjunto( Conjunto * A,char name);
void imprimirConjunto( Conjunto * A);
Conjunto * unionConjuntos(Conjunto * A,Conjunto * B);
int buscar(Conjunto * A,int dato);
Conjunto * interseccionConjuntos(Conjunto * A, Conjunto * B);
Conjunto * diferenciaConjuntos(Conjunto * A, Conjunto * B);
int mostrarMenu();
void ordernarCOnjunto(Conjunto * A);

int mostrarMenu()
{
	fflush(stdin);
	int op;
	int f = 0;
	do{
		linea();
		printf("\n\t1.Union de conjuntos");
		printf("\n\t2.Interseccion de conjuntos");
		printf("\n\t3.Diferencia de conjuntos");
		printf("\n\t4.Salir\n\t");
		scanf("%d",&op);
		
		if( op <=  0 || op > 4)
			printf("\n\tIntenta de nuevo\n");
		else{
			f = 1;
		}
	}while(f == 0);
	return op;
}


Conjunto * unionConjuntos(Conjunto * A,Conjunto * B)
{
	int i,j,op;
	Conjunto * C = (Conjunto *)malloc(sizeof(Conjunto));
	//C = A
	for(i = 0;i < A->tam;i++)
	{
		C->dato[i] = A->dato[i];
		//printf("c->dat[%d] (%d) = A->dat[%d] (%d) ",i,C->dato[i],i,A->dato[i]);
	}
	C->tam = i;
	//tomar el conjunto B y buscar sus elementos en C
	for(j = 0;j < B->tam;j++)
	{
		//agregar los elementos de B que no estan en C == A
		if((op = buscar(C,B->dato[j])) == 0){
			C->dato[i] = B->dato[j];
			i++;
		}
	}	
	C->tam = i;
	
	return C;
}

Conjunto * interseccionConjuntos(Conjunto * A,Conjunto * B)
{
	int i,op,j;
	Conjunto * C  = (Conjunto *)malloc(sizeof(Conjunto));
	j = 0;
	for(i = 0;i < A->tam;i++)
		if((op = buscar(B,A->dato[i])) == 1){
			C->dato[j] = A->dato[i];
			j++;
		}  
	C->tam = j;
	return C;
}

Conjunto * diferenciaConjuntos(Conjunto * A, Conjunto * B)
{
	Conjunto * C = (Conjunto *)malloc(sizeof(Conjunto));
	//elementos de A menos los elementos de B
	int i,j,op;
	j = 0;
	for(i = 0;i < A->tam;i++)
		if((op = buscar(B,A->dato[i])) == 0){
			C->dato[j] = A->dato[i];
			j++;
		} 
	C->tam = j;
	return C;
}


int buscar(Conjunto * A,int dato)
{
	//busqueda binaria
	int inicio = 0;
	int fin = A->tam - 1;
	int mitad = (inicio+fin)/2;
	int b = 0;
	while(b != 1){
		if(A->dato[mitad] == dato){
			b = 1;
			return 1;
		}else{
			if(A->dato[mitad] > dato){
				fin = mitad - 1;
				mitad = (inicio+fin)/2;
			}else{
				inicio = mitad + 1;
				mitad = (inicio+fin)/2;
			}
		}
		if( inicio > fin){
			return 0;
		}
	}
	return -1;
}


void leerConjunto(Conjunto * A,char name)
{
	int i,e,f,f2,op;
	char c[10];
	A->tam = 0;
	printf("\n\tElementos del conjunto %c: (# para terminar )\n",name);
	linea();
	i = 0;
	f2 = 1;
	do{
		f = 0;
		do{
			printf("\n\t[%d] ",i);
			fgets(c,10,stdin);
			if(c[0] != '#'){
				e = atoi(c);
				if((op = buscar(A,e)) == 0){
					A->dato[i] = e;
					A->tam += 1;
					i ++;
					f = 1;
				}else printf("\n\tEste elemento ya esta en el conjunto\n");
			} 
			else{
				f2 = 0;
				f = 1;
			}  
		}while(f == 0);
	}while(f2 == 1);
	//A->tam = i;
}

void ordenarConjunto(Conjunto * A)
{
	int aux,posM,i,j;
	//ordenamiento por seleccion:
	for(i = 0;i < A->tam - 1;i++){
		posM = i;
		for(j = i;j < A->tam;j++){
			if(A->dato[posM] > A->dato[j]) posM = j;
		}
		if(A->dato[posM] != A->dato[i]){
			aux = A->dato[posM];
			A->dato[posM] = A->dato[i];
			A->dato[i] = aux;
		}
	}
}

void imprimirConjunto( Conjunto * A){
	int i;
	printf("\n\t{");
		for(i = 0; i < A->tam;i++){
			if(i+1 == A->tam)
				printf("%d",A->dato[i]);
			else
				printf("%d,",A->dato[i]);
		}
	printf("}\n");
}



int main(int argc, char *argv[]) {
	Conjunto A;
	Conjunto B;
	Conjunto * C = NULL;
	Conjunto * D = NULL;
	Conjunto * E = NULL;
	int f = 1;
	int op;
	
	linea();
	printf("\n\tIngresa dos conjuntos: \n");
	linea();
	leerConjunto(&A,'A');
	ordenarConjunto(&A);
	linea();
	leerConjunto(&B,'B');
	ordenarConjunto(&B);
	linea();
	
	do{
		op = mostrarMenu();
		switch(op){
		case 1:
			linea();
			printf("\n\tConjunto A: ");imprimirConjunto(&A);
			printf("\n\tConjunto B: ");imprimirConjunto(&B);
			C = unionConjuntos(&A,&B);
			printf("\n\tUnion:\n");
			imprimirConjunto(C);
			linea();
			break;
		case 2:
			linea();
			printf("\n\tConjunto A: ");imprimirConjunto(&A);
			printf("\n\tConjunto B: ");imprimirConjunto(&B);
			D = interseccionConjuntos(&A,&B);
			printf("\n\tInterseccion:\n");
			imprimirConjunto(D);
			linea();
			break;
		case 3:
			linea();
			printf("\n\tConjunto A: ");imprimirConjunto(&A);
			printf("\n\tConjunto B: ");imprimirConjunto(&B);
			printf("\n\tDiferencia A - B\n");
			E = diferenciaConjuntos(&A,&B);
			imprimirConjunto(E);
			linea();
			break;
		case 4:
			f = 0;
			break;
		}
	}while( f == 1);
	mi_nombre();
	return 0;
}

