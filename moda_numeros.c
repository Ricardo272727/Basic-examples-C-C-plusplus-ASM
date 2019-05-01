#include <stdio.h>
#include<stdlib.h>


int buscar_moda(int n,int * num){
	int moda,i,count[10];
	
	for(i = 0;i<10;i++){
		count[i]  = 0;
	}
		for(i = 0;i<n;i++){
			count[num[i]] ++;
		}
	
	int mayor = 0;
		for(i=1;i<10;i++){
			if(count[i] > count[mayor]) mayor = i;
		}
	moda = mayor;
	return moda;
}



int main(){
	int n,i,moda;
	int * num;
	printf("Cuantos numeros escribiras? (numeros del 1 al 10)");
	scanf("%d",&n);
	
	if((num = (int *)malloc(n * sizeof(int))) == NULL) exit(-1);
	else
		for(i=0;i<n;i++){
			printf("num[%d]",i);
			scanf("%d",&num[i]);
		}
	
	moda = buscar_moda(n,num);
		printf("\nmoda:%d",moda);
	
	
	return 0;
}
