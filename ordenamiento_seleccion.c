#include <stdio.h>

int main(int argc, char *argv[]) {
	//programa que recibe 3 numeros y los imprime de forma descendente
	int n[3],i,menor,j,aux;
	
	for(i = 0 ; i < 3;i++){
		printf("Escribe un numero: ");scanf("%d",&n[i]);
	}
	
	for(i = 0;i < 2;i++){
		menor = i;
		for(j = i+1;j < 3;j++){
			if(n[j] < n[menor]){
				aux = n[j];
				n[j] = n[menor];
				n[menor] = aux;
			}
		}
	}
	for(i = 0; i < 3;i++)printf("%d",n[i]);
	return 0;
}

