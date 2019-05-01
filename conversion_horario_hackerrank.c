#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool copiar(char * cadena1, int init, int end, char * cadena2){
	int j,i;
	j = 0;
	for(i= init;i<end;i++){
		cadena2[j] = cadena1[i];
		j++;
	}
	return true;
}

char* readline() {
	size_t alloc_length = 1024;
	size_t data_length = 0;
	char* data = malloc(alloc_length);
	
	while (true) {
		char* cursor = data + data_length;
		char* line = fgets(cursor, alloc_length - data_length, stdin);
		
		if (!line) { break; }
		
		data_length += strlen(cursor);
		
		if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }
		
		size_t new_length = alloc_length << 1;
		data = realloc(data, new_length);
		
		if (!data) { break; }
		
		alloc_length = new_length;
	}
	
	if (data[data_length - 1] == '\n') {
		data[data_length - 1] = '\0';
	}
	
	data = realloc(data, data_length);
	
	return data;
}

char* timeConversion(char* s) {
	/*
	* Write your code here. CORREGIR PARA: 12:45:54PM
	*/
	char hora[20];
	strcpy(hora,s);
	int hora_int;
	bool p1,p2,p3,p4;
	char static salida[20];
	char * hora_h, *hora_m, * hora_s,*hora_mer;
	if((hora_h = (char *)malloc(3 * sizeof(char))) == NULL) exit(-1);
	if((hora_m = (char *)malloc(3 * sizeof(char))) == NULL) exit(-1);
	if((hora_s = (char *)malloc(3 * sizeof(char))) == NULL) exit(-1);
	if((hora_mer = (char *)malloc(3 * sizeof(char))) == NULL) exit(-1);
	
	p1 = copiar(hora,0,2,hora_h);
	p2 = copiar(hora,3,5,hora_m);
	p3 = copiar(hora,6,8,hora_s);
	p4 = copiar(hora,8,10,hora_mer);
	
	hora_int = atoi(hora_h);
	if(hora_mer[0] == 'P'){
		if(hora_int != 12)hora_int += 12;
		sprintf(hora_h,"%d",hora_int);
	}else{
		if(hora_int == 12) sprintf(hora_h,"00");
	}
	
	if(p1 && p2 && p3 && p4) sprintf(salida,"%s:%s:%s\n",hora_h,hora_m,hora_s);
	return salida;
}

int main(int argc, char *argv[]) {
	
	char* s = readline();
	char* result = timeConversion(s);
	
	printf("%s",result);
	
	return 0;
}

