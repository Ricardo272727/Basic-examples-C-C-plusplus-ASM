#include <stdio.h>
int main (){
	//variables
	int a,b,c,mayor,menor;
	
	printf("Escribe tres numeros cualesquiera:\n");
	scanf("%d %d %d",&a,&b,&c);
	//numero mayor
	mayor=a;
	if(mayor<b){
		mayor=b;
	}
	if(mayor<c){
		mayor=c;
	}
	//numero menor
	menor=a;
	if(menor>b){
		menor=b;
	}
	if(menor>c){
		menor=c;
	}
	if(a==b&&b==c){
		printf("Los numeros son iguales");
	}
	else{
	printf("\nEl numero mayor es:%d",mayor);
	printf("\nEl numero menor es:%d",menor); 
	}
}
