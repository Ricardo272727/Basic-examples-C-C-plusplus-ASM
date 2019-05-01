#include <stdio.h>

int main() {
	/*Escribir un programa para cada uno de los siguientes ejercicios:
	\uf0b7 Pedir la base y la altura de un rectángulo, calcular su área y su perímetro, y mostrar los resultados
	por pantalla.
	int base,altura,area,perimetro;
	printf("\nescribe la base del rectangulo: ");scanf("%d",&base);
	printf("\nescribe la altura del rectangulo: ");scanf("%d",&altura);
	
	area = base * altura;
	perimetro = 2*base + 2*altura;
	printf("\nel area es: %d \nel perimetro es: %d",area,perimetro);
	=====================================================================
	//uf0b7 Pedir una cantidad de segundos y mostrar por pantalla a cuántas horas, minutos y segundos corresponden.
	int s,h,m,seg,com;
	printf("escribe el numero de segundos: ");
	scanf("%d",&s);
	
	h = s / 3600;
	com = s % 3600;
	m = com / 60;
	com = com % 60;
	seg = com;
	
	printf("\nhoras:%d minutos:%d segundos:%d",h,m,seg);
	=====================================================================
	
	//3. Escribir un programa que lea N números enteros y muestre el mayor y el menor de todos ellos
	Para pasar de carácter a número: int n = (int) (c - 48);
	Para pasar de número a carácter: char c = (char) (n + 48);
	
	//ideas: leer primero los numeros y luego buscar el menor y mayor

	int mayor,menor,num,cont;
	char n;
		
	
	cont = 0;
	
	do{
	printf("\nEscribe un numero:(* para terminar)");
	scanf("%c",&n);
	cont++;
	if(n != '*'){
		num = (int) ( n - 48 );
		if(cont == 1){
			mayor = num;
			menor = num;
		}else{
			if(num > mayor) mayor = num;
		}	if(num < menor) menor = num;
	}
	}while(n != '*');
		
	printf("NUMERO MAYOR : %d",mayor);
	printf("NUMERO MENOR : %d",menor);
	
	int nums,mayor,menor,i,num;
	printf("cuantos numeros deseas leer?\n");
	scanf("%d",&nums); 

	for(i = 1; i <= nums; i++){
		printf("escribe un numero:\n");
		scanf("%d",&num);
		if(i == 1){
			mayor = num;
			menor = num;
		}else{
			if(num < menor) menor = num;
			if(num > mayor) mayor = num;
		}

	}
	//programa que imprrime la tabla de multiplicar del numero que le digas
	printf("numero mayor: %d\n",mayor);
	printf("numero menor: %d\n",menor);

	int n,i,lim;

	printf("cual tabla te imprimo?\n");
	scanf("%d",&n);
	printf("hasta que multiplo?\n");
	scanf("%d",&lim);

	for(i = 1; i <= lim; i++){
		printf("\t %d x %d = %d \n",n,i,i*n);
	}
	*/
	/*=============================================
	5. Escribir un programa que determine si un número entero dado es primo o no.
		int n,i,count;

	printf("escribe un numero: \n");
	scanf("%d",&n);

	count = 0;
	for(i = 2; i < n; i++){
		if(n % i == 0) count ++;
	}

	if (count == 0) printf("el numero es primo!\n");
	else printf("el numero no es primo :(\n");
	6. Escribir un programa que calcule el factorial de un número entero leído por teclado.
	int i,n,f;
	f = 1;
	printf("escribe un numero:");scanf("%d",&n);
	for( i = 1; - <= n; i++) f *=i;
	printf("el factorial de %d es %d",n,f);
	7. Escribir un programa que calcule la suma de todos los números múltiplos de 5 comprendidos entre dos
	enteros leídos por teclado.
	int lim1,lim2,suma,aux,i;
	printf("escribe el primer valor del intervalo:");scanf("%d",&lim1);
	printf("escribe el segundo valor del intervalo:");scanf("%d",&lim2);
	suma =0;
	if(lim1>lim2) {
	aux = lim1;
	lim1 = lim2;
	lim2 = aux;
}
	for( i = lim1; i <= lim2; i++){
	if(i%5 == 0)suma+=i;
}
	printf("la suma de los numeros divisibles por 5 en ese internalo es de:%d",suma);
	==============================================*/
	
	

	
	return 0;
}

