#include <stdio.h>

int main(int argc, char *argv[]) {
	char cad1[100];
	int i;
	printf("\nEscribe una palabra:");
	scanf("%s",cad1);
 
	i = 0;
	while(cad1[i] != '\0') i++;
	
	printf("\nLa palabra %s tiene: %d caracteres",cad1, i);
	
	return 0;
}

