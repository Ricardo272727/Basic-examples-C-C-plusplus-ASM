#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main(int argc, char *argv[]) {
	int aux_int;
	float d,tetha,v0,t,y_chango,y_cazador,g = 9.81,aux;
	printf("\nDistancia del objeto al canon: ");
	scanf("%f",&d);
	printf("\nAngulo del canon (grados): ");
	scanf("%f",&tetha);
	printf("\nVelocidad inicial del proyectil (m/s): ");
	scanf("%f",&v0);//8 40 20 t = 0.522 5.376m 
	//d = 27; //con estos parametros el objeto es alcanzado por el proyectil
	//tetha = 30;
	//v0 = 25;
	
	tetha = tetha * (PI/180);
	aux = cos(tetha);
	t = d / (v0*(aux));

	aux = tan(tetha);
	y_chango = (d*(aux)) - (0.5*g*t*t);
	
	aux = sin(tetha);
	y_cazador = ((v0*aux)*t)-((0.5)*g*(t*t));
	
	//redondear a dos decimales
	aux = y_cazador*100;
	aux_int = aux;
	aux = (float)aux_int/100;
	y_cazador = aux;
	
	aux = y_chango*100;
	aux_int = aux;
	aux = (float)aux_int/100;
	y_chango = aux;
	
	if(y_chango == y_cazador && y_chango > 0 && y_cazador > 0)
		printf("\nEl proyectil alcanzara al objeto");
	else
		printf("\nEl objeto no sera alcanzado por el proyectil");
	
	return 0;
}

