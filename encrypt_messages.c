#include <stdio.h>


char convertir (char caracter){
	int encriptado;
	encriptado = caracter++;
	return encriptado;
}


int main(int argc, char *argv[]) {
	char mensaje[100],encrypt[100],caracter;
	int i=0,f=0;
	printf("ESCRIBE EL MENSAJE A ENCRIPTAR:\n");
	fgets(mensaje,100,stdin);
	
	do{
		if(mensaje[i]=='f'&& mensaje[i+1]=='i'&& mensaje[i+2]=='n'){
			f==0;
		}else{
			
				if(mensaje[i]!=' ' && mensaje[i]!='.'&& mensaje[i]!=','){
					caracter = convertir(mensaje[i]);
				}else{
					caracter = mensaje[i];
				}
				encrypt[i] = caracter;
				i++;
			}
	}while(f==1);
	int j=0;
	while(encrypt[j]!='\0'){
	printf("%c",encrypt[j]);
	j++;
	}
	return 0;
}

