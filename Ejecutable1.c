#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	
	float m1, m2, cf, theta, gravity=9.81, acceleration, tension;
	
	printf("\tEjecutable 1 de F�sica\n\n");
	printf(" ! Es necesario ver la figura adjunta para entender el planteamiento.\n\n");
	printf(" - Una bola de masa m_1 y un bloque de masa m_2 se unen mediante una\n");
	printf("cuerda ligera que pasa sobre una polea sin fricci�n de �ngulo \\theta.\n");
	printf("Cabe mencionar que existe un coeficiente de fricci�n de C_f del plano\n");
	printf("inclinado sobre la masa m_2.\n");
	printf(" - Este programa sirve para hallar la aceleraci�n de las dos masas y\n");
	printf("adem�s hallar la tensi�n de la cuerda.\n\n");
	
	printf(" - Ingrese el valor de la masa m_1 en kg: ");
	do{
		scanf("%f",&m1);
		if (m1 < 0) printf(" ! La masa no puede tomar valores negativos.\n - Ingrese otro valor para m_1: ");
	}while(m1 < 0);
	printf(" - Ingrese el valor de la masa m_2 en kg: ");
	do{
		scanf("%f",&m2);
		if (m2 < 0) printf(" ! La masa no puede tomar valores negativos.\n - Ingrese otro valor para m_2: ");
	}while(m2 < 0);
	printf(" - Ingrese el valor del coeficiente de fricci�n: ");
	do{
		scanf("%f",&cf);
		if(cf < 0) printf(" ! El coeficiente de fricci�n no puede ser negativo.\n - Ingrese otro valor para C_f: ");
	}while(cf < 0);
	printf(" - Ingrese el valor del �ngulo \\theta en grados: ");
	do{
		scanf("%f",&theta);
		if (theta < 0 || theta > 180) printf(" ! El sistema solo soporta �ngulos de 0 a 180 grados.\n - Ingresa otro �ngulo \\theta: ");
	}while(theta < 0 || theta > 180);
	
	if(m1 == 0 && m2 == 0) printf(" ! El valor tanto de la aceleraci�n como de la tensi�n es cero.\n");
	else{
		acceleration = ( m2*gravity*sin(theta) - m1*gravity - m2*gravity*cos(theta)*cf )/( m1 + m2 );
		tension = ( m1*m2*gravity*( sin(theta) + 1 - cos(theta) ) )/( m1 + m2 );
		printf(" - La aceleraci�n es: %0.2f\n - La tensi�n es: %0.2f",acceleration,tension);
	}
	getchar();
	getchar();
	return 0;
}

