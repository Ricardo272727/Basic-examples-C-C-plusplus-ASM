#include <stdio.h>

int suma_divisores(int num);

int main(){
	//PROGRAMA QUE DETERMINA SI DOS NUMEROS SON AMIGOS
	int n1,n2,suma_n1,suma_n2;
	
	do{
	printf("\n\nEscribe el primer numero: ");scanf("%d",&n1);
	printf("\nEscribe el segundo numero: ");scanf("%d",&n2);
	
	//sacar divisores sin considerar el mismo numero:
	suma_n1 = suma_divisores(n1);
	suma_n2 = suma_divisores(n2);
	//verificar que son amigos
	if(suma_n1 == n2 && suma_n2 == n1){
		printf("\nSuma de los divisores de %d = %d",n1,suma_n1);
		printf("\nSuma de los divisores de %d = %d",n2,suma_n2);
		printf("\n\nLos numeros %d y %d son amigos",n1,n2);
		printf("\n======================================");
	}
	else{
		printf("\nSuma de los divisores de %d = %d",n1,suma_n1);
		printf("\nSuma de los divisores de %d = %d",n2,suma_n2);
		printf("\n\nLos numeros %d y %d  NO son amigos",n1,n2);
		printf("\n======================================");
	}
	}while(n2 != -1);
	return 0;
}

int suma_divisores(int num){
	int i,suma = 0;
	for(i = 1;i<num;i++){
		if(num % i == 0){
			suma += i;
		}
	}
	return suma;
}
