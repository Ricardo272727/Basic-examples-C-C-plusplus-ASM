#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int buscar_numero(int num,int moda[][2],int n){
	int i;
	for(i=0;i<n;i++){
		if(moda[i][0] == num) return i;
	}
	return -1;
}

void agregar_numero(int num,int moda[][2],int n){
	int i = 0;
	while(moda[i][1] != 0) i++;
	moda[i][0] = num;
	moda[i][1] ++;
}

int buscar_moda(int arr[],int n){
	int moda[n][2],i,j,count = 0;
		//contadores a 0
		for(j=0;j<n;j++) moda[j][1] = 0;
		for(j=0;j<n;j++) moda[j][0] = 0;
	int b;
	for(i=0;i<n;i++){
		if( ( b = buscar_numero(arr[i],moda,n)) != -1 ) moda[b][1]++;
		else{
			agregar_numero(arr[i],moda,n);//y ademas aumentar contador a 1
			count ++;
		} 
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<2;j++)
			printf(" %d ",moda[i][j]);
		printf("\n");
	}
	
	
	int mayor = moda[0][1];
	int pos = 0;
	for(j = 0;j<n;j++){
		if(moda[j][1] > mayor){
			mayor = moda[j][1]; 
			pos = j;
		} 
	}
	
	return moda[pos][0];
}

void mostrar_vector(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
	printf(" %d",arr[i]);
	}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int n;char op;
	int moda,f;
	
	while(op != 'N'){
		printf("\n\tCuantos numeros enteros deseas generar? ");
		scanf("%d",&n);
		int arr[n],i,aleatorio;
		
		for(i=0;i<n;i++){
			aleatorio = rand() % 10;
			arr[i] = aleatorio;	
		}
		moda = buscar_moda(arr,n);
		
		mostrar_vector(arr,n);
		
		printf("\n\tLa moda es: %d",moda);
		f = 0;
		while(f != 1){
			printf("\n\tOtra vez? S/N ");
			scanf("%c",&op);
			op = toupper(op);
			if(op == 'N' || op == 'S') f =1; 
			
		}
		
		if(op == 'N') exit(0);
			
		
	}
	
	
	return 0;
}

