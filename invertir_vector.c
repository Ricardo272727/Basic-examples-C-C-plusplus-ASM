#include <stdio.h>
	//2. Escribir un programa que lea del teclado un vector de 10 números enteros, lo invierta y finalmente lo muestre de nuevo.
int main(int argc, char *argv[]) {
	int i;
	int vect[10],vect2[10];
	for(i =0;i<10;i++){
		printf("\nv[%i] = ",i);
		scanf("%d",&vect[i]);
	}
	int k = 0;
	for(i =9;i>-1;i--){
		vect2[k] = vect[i];
		k++;
	}
	
	for(k=0;k<10;k++){
		
		printf("\nV[%i] = %d ",k,vect2[k]); 
		
	}
	
	return 0;
}

