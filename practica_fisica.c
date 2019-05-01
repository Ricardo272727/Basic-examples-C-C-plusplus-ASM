#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


#define PI 3.14159



int main(int argc, char *argv[]) {
	float ang,m1,m2,cf,t,a,g,normal,ff,sen_0;
	char op;
	g = 9.81;
	int f = 0;
	printf("\nUna bola de masa m1 y un bloque de masa m2 se unen mediante una cuerda \n");
	printf("ligera que pasa sobre una polea si friccion de masa despreciable, como en\n");
	printf("figura(1.1). El bloque se encuentra sobre un plano inclinado sin friccion\n");
	printf("de angulo tetha.\n");
	
	do{
	//pedir datos
	printf("\nMasa 1: ");scanf("%f",&m1);
	printf("\nMasa 2: ");scanf("%f",&m2);
		do{
			printf("\nAngulo: ");scanf("%f",&ang);
			if(ang < 0) ang *= -1;
			if(ang >= 90 || ang == 0) printf("\nPor favor escribe un angulo valido");
			else f = 1;
		}while(f == 0);		
	printf("\nCoeficiente de friccion: ");scanf("%f",&cf);
	//encontrar la normal de m2 para sacar la fuerza de friccion
	//provisional
	//ang = -70;
	//m1 = 30;
	//m2 = 200;
	//cf = 0.20;
	normal = m2 * g;
	//friccion
	ff = cf * normal;
	//falta hacer que funcione con angulos negativos...
	//if(ang < 0){
		//ang += 360;
	//}
	//convertir grados a radianes
	ang = ang * (PI/180);
	//sen_0
	sen_0 = sin(ang);
	//aceleracion:
	a = (m2 * g * sen_0 - m1 * g  - ff)/(m1+m2);
	float prov1,prov2,prov3;
	prov1 = m1*m2*g*(sen_0 + 1);
	prov2 = m1 * ff;
	prov3 = m1 + m2;
	t = (prov1 - prov2) / prov3; 
	//t = (m1*m2*g*(sen_0 + 1)-(m1 * ff)) / (m1 * m2);
	printf("\nMasa 1: %.2f",m1);
	printf("\nMasa 2: %.2f",m2);
	printf("\nAngulo(radianes): %.2f",ang);
	printf("\nCoeficiente de friccion: %.2f",cf);
	printf("\nSen_0: %.3f",sen_0);
	printf("\nFuerza de friccion: %.2f",ff);
	printf("\nTension: %.2f",t);
	printf("\nAceleracion: %.2f",a);
	
	while(getchar() != '\n');
	printf("\n\nOtra vez? S/N ");scanf("%c",&op);
	op = toupper(op);
	}while(op != 'N');
	
	return 0;
}

