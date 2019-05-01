#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void linea(){
	printf("\n\t--------------------------------------------------------------\n\t");
}

void imprimirHora(int h,int m,int s){
	char hora[3],min[3],seg[3];
	
	if(h < 10)sprintf(hora,"0%d",h);
	else sprintf(hora,"%d",h);
	
	if(m < 10)sprintf(min,"0%d",m);
	else sprintf(min,"%d",m);
	
	if(s < 10)sprintf(seg,"0%d",s);
	else sprintf(seg,"%d",s);
	
	linea();
	
	printf("\n\tHora actual: %s:%s:%s\n",hora,min,seg);
	
	linea();
}

void incrementarHora(int * h){
	if( *h == 23) *h = 0;
	else *h += 1;
}

void incrementarMin(int * h,int * m){
	if(*m == 59) {
		*m = 0;
		incrementarHora(h);
	}
	else *m += 1;
	
}

void incrementarSeg(int * h,int * m,int * s){
	if(*s == 59){
		*s = 0;
		incrementarMin(h,m);
	}
	else *s += 1;
}

void cambiarHora(int * h,int * m,int * s){
	char hora[10],ch[3],cm[3],cs[3];
	int i = 0,f = 0;
	do{
		printf("\n\tEscribe la nueva hora en formato: 00:00:00\n\t");
		fgets(hora,100,stdin);
		while(hora[i] != '\n') i++;
		hora[i] = '\0';
		if(strlen(hora) != 8 || hora[2] != ':' || hora[5] != ':')
			printf("\n\tIntenta de nuevo con el formato: 00:00:00");
		else {
			sprintf(ch,"%c%c",hora[0],hora[1]);
			sprintf(cm,"%c%c",hora[3],hora[4]);
			sprintf(cs,"%c%c",hora[6],hora[7]);
			*h = atoi(ch);
			*m = atoi(cm);
			*s = atoi(cs);
			if(*h >= 0 && *h <= 23 && *m >= 0 && *m <= 59 && *s >= 0 && *s <= 59)
			f = 1;
			else
				printf("\n\tEscribe una hora que exista\n");
		}
	}while(f == 0);
}

char mostrarMenu(){
	char op;
	int f = 0;
	do{
		linea();
		printf("\n\tA.Cambiar hora");
		printf("\n\tB.Incrementar una hora");
		printf("\n\tC.Incrementar un minuto");
		printf("\n\tD.Incrementar un segundo");
		printf("\n\tE.Escribir hora");
		printf("\n\tS.Salir\n\t");
		linea();
		scanf("%c",&op);
		while(getchar() != '\n');
		op = toupper(op);
		if( op != 'A' && op != 'B' && op != 'C' && op != 'D' && op != 'E' && op != 'S' && op != 'L')
			printf("\n\tIntenta de nuevo A-F\n");
		else 
			f = 1;
		
	}while(f == 0);
	return op;
}

int main(int argc, char *argv[]) {
	char op;
	int h = 0,m = 0,s = 0;
	do{
		op = mostrarMenu();
		switch(op){
		case 'A':
			cambiarHora(&h,&m,&s);
			imprimirHora(h,m,s);
			break;
		case 'B':
			incrementarHora(&h);
			imprimirHora(h,m,s);
			break;
		case 'C':
			incrementarMin(&h,&m);
			imprimirHora(h,m,s);
			break;
		case 'D':
			incrementarSeg(&h,&m,&s);
			imprimirHora(h,m,s);
			break;
		case 'E':
			imprimirHora(h,m,s);
			break;
		case 'L':
			system("clear");
			break;
		case 'S':
			break;
		}
	}while(op != 'S');
	return 0;
}






