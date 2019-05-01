#include<stdio.h>
int main(){
	int n,i,f=0;
	float suma=0;

while(f==0){
	printf("\n\nEscribe el valor para n (0 para terminar): ");
	scanf("%d",&n);
	printf("\n");
	if(n!=0){
	for(i=1;i<=n;i++){
		if(i%2==0){
			suma -= 1/(float)i;
			printf(" - 1/%d ",i);
		}else{
			suma += 1/(float)i;
			printf(" + 1/%d ",i);
		}
	}
	printf("\n\nLa suma es: %f",suma);
	}
	else{
		f=1;
	}
}
	return 0;
}
