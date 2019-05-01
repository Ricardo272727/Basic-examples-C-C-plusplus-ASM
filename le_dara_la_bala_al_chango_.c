#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[]) {
	float d,tetha,v0,t,y_chango,y_cazador,coseno_t,seno_t,tangente_t,pi=3.1415926536,factor;
	printf("\nDame el angulo con el que apunta el cazador (grados): ");scanf("%f",&tetha);
	 
	/*
	printf("\nHola!...\nDame la distancia del cazador al chango (metros): ");scanf("%f",&d);
	printf("\nDame la velocidad de la bala al salir del rifle del cazador (m/s): ");scanf("%f",&v0);//8 40 20 t = 0.522 5.376m
	*/
	coseno_t = cos(tetha);
	factor = 180/pi;
	printf("coseno:%f, factor:%f",coseno_t,factor);
	
	printf("\ntiempo:%f",t);
	printf("\ny_chango:%f",y_chango);
	printf("\ny_cazador:%f",y_cazador);
	if(y_chango == y_cazador){
		printf("\nEl chango sera alcanzado por la bala del cazador!");
	}else{
		printf("\nEl chango se salvo!");
	}
	return 0;
}

