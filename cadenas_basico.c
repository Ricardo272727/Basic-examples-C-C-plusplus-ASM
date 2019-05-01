#include <stdio.h>

int main(int argc, char *argv[]) {
	char cad1[100],cad2[100];
	
	printf("Escribe una palabra:");
	scanf("%s",cad1);
	printf("\nEscribe una palabra:");
	scanf("%s",cad2);
	int i = 0,k;
	while(cad1[i] != '\0')i++;
	k = 0;
	while(cad2[k] != '\0'){
		cad1[i] = cad2[k];
		i++;
		k++;
	}
	
	printf("%s",cad1);
	
	return 0;
}

