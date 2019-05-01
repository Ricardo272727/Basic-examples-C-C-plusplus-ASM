#include <stdio.h>


void leerArray(int n, int numeros[]);
int obtenerMayor(int n,int numeros[]);
int pos_menor(int n,int numeros[]);
int sumarArray(int n, int numeros[]);
int datos_por(int n,int numeros[],int por,float media);

int main(int argc, char *argv[]) {
	int numeros[100],n,mayor,pos_men,suma,datos_up,datos_down;
	float promedio;
	do{
	printf("\n\t==============================================================");
	printf("\n\t*\t\tEscribe el numero de n:");
	scanf("%d",&n);
	leerArray(n,numeros);
	mayor = obtenerMayor(n,numeros);
	pos_men = pos_menor(n,numeros); 
	suma = sumarArray(n,numeros);
	promedio = (float)suma/n;
	
	datos_up = datos_por(n,numeros,1,promedio);
	datos_down = datos_por(n,numeros,0,promedio);
	
	printf(" \n\t#\t\tnumero mayor:%d",mayor);
	printf(" \n\t#\t\tposicion del numero menor:%d",pos_men+1);
	printf("\n\t#\t\tpromedio:%.2f",promedio);
	printf("\n\t#\t\tdatos por arriba del promedio:%d",datos_up);
	printf("\n\t#\t\tdatos por abajo del promedio:%d",datos_down);
	}while(numeros[0] != -27);
	return 0;
}

void leerArray(int n, int numeros[]){
	int i;
	for(i=0;i<n;i++){
		printf("\t*\t\tEscribe el numero[%d]: ",i+1);
		scanf("%d",&numeros[i]);
	}
}

int obtenerMayor(int n,int numeros[]){
	int i,mayor;
	mayor = numeros[0];
	for(i=1;i<n;i++){
		if(mayor < numeros[i]){
			mayor = numeros[i];
		}
	}
	return mayor;
}

int pos_menor(int n,int numeros[]){
	int i,pos_menor;
	pos_menor = 0;
	for(i=1;i < n;i++){
		if(numeros[i] < numeros[pos_menor] ){
			pos_menor = i;
		}
	}
	return pos_menor;
}

int sumarArray(int n,int numeros[]){
	int i,suma=0;
	
	for(i=0;i < n ;i++) suma +=numeros[i]; 
	
	return suma;
}

int datos_por(int n,int numeros[],int por,float media){
	int i,count=0;
	if(por == 1){
		for(i=0;i<n;i++){
			if(media < (float)numeros[i])count++;
		}
	}else{
		if(por == 0){
			for(i=0;i<n;i++){
				if(media > (float)numeros[i])count++;
			}
		}
	}
	return count;
}
