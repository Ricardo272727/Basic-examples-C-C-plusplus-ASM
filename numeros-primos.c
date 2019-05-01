//5. Escribir un programa que determine si un número entero dado es primo o no.
#include<stdio.h>
int main(){
int n,i,count;

printf("escribe un numero: \n");
scanf("%d",&n);

count = 0;
for(i = 2; i < n; i++){
	if(n % i == 0) count ++;
}

if (count == 0) printf("el numero es primo!\n");
else printf("el numero no es primo :(\n");

}
