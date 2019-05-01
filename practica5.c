#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void ordenar_datos(int n,int datos[]){
	int i,j,menor,aux;
	
	for(i=0;i<n-1;i++){
		menor = i;
		for(j=i;j<n;j++){
			if(datos[menor] > datos[j]) menor = j;
		}
		if(datos[menor] != datos[i]){
			aux = datos[menor];
			datos[menor] = datos[i];
			datos[i] = aux;
		}
	}
	/*
	for(i=0;i<n-1;i++){
	menor = i;
	for(j=i;j<n;j++){
	if(datos[menor] > datos[j]){
	menor = j;
	}
	}
	if(datos[menor] != datos[i]){
	aux = datos[menor];
	datos[menor] = datos[i];
	datos[i] = aux;
	}
	}
	*/
}

int buscar_numero(int num, int datos[],int n){
	int pos,f=0,inicio,mitad,fin;
	
	inicio = 0;
	fin = n -1;
	mitad = (inicio + fin)/2;
	
	while(f == 0){
		
		if(datos[mitad] == num){
			pos = mitad;
			f = 1;
		}else{
			if(datos[mitad] > num){
				fin = mitad - 1;
				mitad = (inicio + fin)/2;
			}else{
				inicio = mitad + 1;
				mitad = (inicio + fin)/2;
			}
		}
		
		if(inicio > fin){
			pos = -1;
			f   = -1;
		}
	}
	
	/*inicio = 0;
	fin = n-1;
	mitad = (inicio + fin)/2;
	
	while(f==0){
	if(datos[mitad] == num){
	f = 1;
	pos = mitad; 
	}else{
	if(num > datos[mitad]){
	inicio = mitad + 1;
	mitad = (inicio + fin)/2;
	}else{
	fin = mitad - 1;
	mitad = (inicio + fin)/2;
	}
	}
	if(inicio > fin){
	f = -1;
	pos = -1;
	}
	}*/
	
	return pos;
}

int main(){
	int n,i,datos[1000],aleatorio,bus,pos;
	srand(time(NULL));
	do{
	printf("\n\t==============================================================");
	printf("\n\n\tEscribe el numero de datos a ordenar:");	
	scanf("%d",&n);
	
	if(n <=1000 && n !=0){
	printf("\n\t-----------------------------------");
	printf("\n\n\tDatos:\n");
	for(i=0;i<n;i++){
		aleatorio =  rand() % 100 + 1;
		datos[i] = aleatorio;
		if(i%4 == 0)printf("\n\n");
		printf("\tnum[%d] = %d",i,datos[i]);
	}
	printf("\n");
	ordenar_datos(n,datos);
	printf("\n\t-----------------------------------");
	printf("\n\n\tDatos ordenados:\n");
	for(i=0;i<n;i++){
		if(i%4 == 0)printf("\n\n");
		printf("\tnum[%d] = %d",i,datos[i]);
	}
	printf("\n");
	}else{
		if( n != 0)
		printf("\n\t\tLimite de datos a ordenar:1000");
		
	}
	
	do{
		printf("\n\t-----------------------------------");
		printf("\n\n\tNumero a buscar (0 para terminar): ");
		scanf("%d",&bus);
		if(bus != 0){
			pos = buscar_numero(bus,datos,n);	
			
			if(pos != -1){
				printf("\n\t\tEncontrado! num[%d] = %d\n",pos,bus);
			}else{
				printf("\n\t\tEl numero: %d no se encontro en el conjunto\n",bus);
			}
		}
	}while(bus != 0);
	}while(n != 0);
	
	return 0;
}
