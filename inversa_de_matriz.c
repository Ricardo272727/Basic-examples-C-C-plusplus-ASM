#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int buscar(int arr[],int n,int num);
void mostrar_matriz(int A[][10],int m, int n);
void leer_matriz(int A[][10],int r, int c);
void aumentar_matriz(int A[][10],int n);
void apl_gauss(int A[][10],int r,int c);
void permutar_filas(int A[][10],int fila1,int fila2,int c);
int buscar_en_columna(int A[][10],int r,int c,char op);
int determinante(int A[][10],int r,int c);
void reducir_escalonada(int A[][10],int r,float c);

void mostrar_matriz(int A[][10],int m, int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
}


void leer_matriz(int A[][10],int r, int c){
	int i,j,aleatorio;
	srand(time(NULL));
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			//printf("A[%d][%d]: ",i,j);
			//scanf("%d",&A[i][j]);
			aleatorio = rand() % 10;
			A[i][j] = aleatorio;
		}
		printf("\n");
	}
}

void aumentar_matriz(int A[][10],int n){
	
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			A[i][j] = 0;
		}
	}
	j =n;
	for(i=0;i<n;i++){
		A[i][j] = 1;
		j++;
	}	
}

void apl_gauss(int A[][10],int r,int c){
	int r_1,r_0,r_d;
	//permutar las filas(poner 0s en las ultimas filas y de peferencia 1 en las primeras filas)
	mostrar_matriz(A,r,c);
	r_1 = buscar_en_columna(A,r,0,'1');
	
	printf("\n");
	if(r_1 != -1 && r_1 != 0){
		permutar_filas(A,r_1,0,c);
	}
	r_0 = buscar_en_columna(A,r,0,'0');
	if(r_0 != -1 && r_0 == 0){
		r_d = buscar_en_columna(A,r,0,'*');
		permutar_filas(A,r_d,0,c);
	}
	printf("\n");
	mostrar_matriz(A,r,c);
	
	//ciclo de gauss...
		//hacer uno en la fila i
		//buscar numero para que la fila i haga 0 a la primera posicion de la fila i+1
		//multiplicar y sumar a la fila i+1
		//repetir hasta: que la fila i = n
		
	//hasta aqui ya es una matriz triangular superior
	
	//ciclo de gauus jordan
		//hacer 1 en la fila n
		//buscar un numero tq la fila n-i haga cero arriba de la diagonal
		//multiplicar y sumar a la fila i n-i
		//repetir hasta fila 0
	//aqui ya es la identidad la primera matriz 

}



void permutar_filas(int A[][10],int fila1,int fila2,int c){
	int i,aux[c];
	for(i=0;i<c;i++){
		aux[i] = A[fila1][i];
		A[fila1][i] = A[fila2][i];
		A[fila2][i] = aux[i];
	}
}


int buscar_en_columna(int A[][10],int r,int c,char op){
	//Arreglo[][],renglones de A,columna a buscar, numero a buscar
	int num,i,pos = -1;
		
	if(op != '*'){
		num = op - '0';
		for(i=0;i<r;i++){
			if(A[i][c] == num) pos = i; 
		}
	}else{
		for(i=0;i<r;i++){
			if(A[i][c] != 0 && A[i][c] != 1 ) pos = i; 
		}
	}
	return pos;
}

int determinante(int A[][10],int r,int c){
	int aux[r][c],i,j,det;
	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			aux[i][j] = A[i][j];
		}
	}
	reducir_escalonada(aux,r,c);
	
	det = 0;
	for(i=0;i<c;i++){
		det += aux[i][i];
	}
	
	return det;
}

void reducir_escalonada(int A[][10],int r,int c){
	int i,j,f,esc;
	float mult;
	//permutar las filas para que A[0][0] != 0 nota: si esto falla es porque el ciclo se esta deteniendo antes
	f = 0;
	i = 0;
	while(f == 0 && i < r){
		if(A[0][0] == 0){
			i++;
			permutar_filas(A,0,i,c);
		}else{
			f == 1;
		}
	}
	
	//ciclo completo
	for(i=0;i<r;i++){
		
		//hacer uno en la fila en turno
		if(A[i][i] != 1){
			mult = 1/(float)A[i][i];
			mutiplicar_fila(A,c,i,mult);
		}
		//encontrar escalar para hacer 0 abajo del pivote
		esc = -1 * A[i][j];
		//aqui me quede
		
	}
	
	
}

void multiplicar_fila(int A[][10],int n,int fila,float mult){
	int i;
	for(i=0;i<n;i++){
		A[fila][i] *= mult;
	}
}
	
int main(int argc, char *argv[]) {
	int A[10][10],c,r,det;
	r = 1;
	while(r !=0){
	printf("Maximo 5x5");
	printf("\n\tRenglones: ");scanf("%d",&r);
	c = r;
	//leer
	leer_matriz(A,r,c);
	//buscar determinante para ver si tiene inversa
	det = determinante(A,r,c);
	printf("\n\tDeterminate: %d",det);
	//aumentar_matriz con la identidad
	aumentar_matriz(A,r);
	//gauss jordan
	apl_gauss(A,r,2*c);
	//aplicar_gauss_jordan
		
	//mostrar_matriz inversa
	}
	
	
	return 0;
}

