#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
NOTAS:
char *fgets(char *cadena, int n, FILE *stream);
Esta función lee como máximo uno menos que el número de caracteres indicado por n desde el stream apuntado por stream al array apuntado por cadena. 
Ningún carácter adicional es leído después del carácter de nueva línea (el cual es retenido) o después de un final de fichero (EOF). 
Un carácter nulo es escrito inmediatamente después del último carácter leído en el array.
*/
bool copiar(char * cadena1, int init, int end, char * cadena2){
	int j,i;
	j = 0;
	for(i= init;i<end;i++){
		cadena2[j] = cadena1[i];
		j++;
	}
	return true;
}
int main(int argc, char *argv[]) {
	//obtener la hora en un string	
		char hora[20] = "11:24:48:PM";
		printf("Escribe la hora en formato(hh:mm:ss:AM/PM): ");scanf("%s",hora);
		
		int hora_int;
		bool p1,p2,p3,p4;
		
		char * hora_h, *hora_m, * hora_s,*hora_mer;
		 if((hora_h = (char *)malloc(3 * sizeof(char))) == NULL) exit(-1);
		 if((hora_m = (char *)malloc(3 * sizeof(char))) == NULL) exit(-1);
		 if((hora_s = (char *)malloc(3 * sizeof(char))) == NULL) exit(-1);
		 if((hora_mer = (char *)malloc(3 * sizeof(char))) == NULL) exit(-1);
	
		p1 = copiar(hora,0,2,hora_h);
		p2 = copiar(hora,3,5,hora_m);
		p3 = copiar(hora,6,8,hora_s);
		p4 = copiar(hora,9,11,hora_mer);
		
		hora_int = atoi(hora_h);
		if(hora_mer[0] == 'P'){
			hora_int += 12;
			if(hora_int == 24){
				hora_int = 0;
			}
		}
		if(hora_int == 0) sprintf(hora_h,"00");
		else sprintf(hora_h,"%d",hora_int);
		
		if(p1 && p2 && p3 && p4) printf("%s:%s:%s\n",hora_h,hora_m,hora_s);
		
	return 0;
}

/*
for(i= 0;i<2;i++){
hora_h[j] = hora[i];
j++;
}
j= 0;
for(i = 3;i<5;i++){
hora_m[j] = hora[i];
j++;
}
j= 0;
for(i= 6;i<8;i++){
hora_s[j] = hora[i];
j++;
}
j= 0;
for(i= 9;i<11;i++){
hora_mer[j] = hora[i];
j++;
}

hora_int = atoi(hora_h);
if(hora_mer[0] == 'P'){
hora_int += 12;
if(hora_int == 24){
hora_int = 0;
}
}

if(hora_int == 0) sprintf(hora_h,"00");
else sprintf(hora_h,"%d",hora_int);
printf("%s:%s:%s\n",hora_h,hora_m,hora_s);














*/

