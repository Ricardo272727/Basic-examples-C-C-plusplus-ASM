#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//strcmp retorna un negativo si el orden alfebetico de s1 es mas bajo que el de s2, retorna 0 si son iguales y positivo si s2 es menor a s1
struct info{
	char nombre[100];
	long int matricula;
	char carrera[5];
	float promedio;
};

void fseparador(FILE *fp){
	fprintf(fp,"\n\t--------------------------------------------------------------\n");			
}
float promedio_carrera(struct info alumnos[],int n,char carrera[5],int * n_carrera){
	int i;
	float prom,suma = 0;
	* n_carrera = 0;
	
	for(i=0;i<n;i++){
		if((strcmp(alumnos[i].carrera,carrera)) == 0){
			suma += alumnos[i].promedio;
			* n_carrera = * n_carrera + 1;
		} 
	}
	if(suma > 0) prom = suma/(float)*n_carrera;
	else prom = 0;
	return prom;
}

int validar_carrera(char carrera[5]){
	char ing[] = "ING";
	char lic[] = "LIC";
	char iti[] = "ITI";
	
	if((strcmp(carrera,ing)) == 0) return 1;
	if((strcmp(carrera,lic)) == 0) return 1;
	if((strcmp(carrera,iti)) == 0) return 1;
	
	return 0;
}

void separador(){
	printf("\n\t##############################################################\n");
}
void separador_small(){
	printf("\n\t--------------------------------------------------------------\n");
}
void limpiar(){
	while(getchar() != '\n');
}
int main(){
	FILE *fp;
	
	int n,i,f;
	int n_ing,n_lic,n_iti;
	printf("\n\tEscribe el numero de alumnos a ingresar: ");
	scanf("%d",&n);
	limpiar();
	struct info alumnos[n];
	
	for(i=0;i<n;i++){
		separador_small();
		printf("\n\tNombre: ");
		fgets(alumnos[i].nombre,100,stdin);
		printf("\n\tMatricula: ");
		scanf("%ld",&alumnos[i].matricula);
		limpiar();
		
		f = 0;
		do{
			printf("\n\tCarrera: ");
			scanf("%s",alumnos[i].carrera);
			limpiar();
			if(validar_carrera(alumnos[i].carrera) == 1) f = 1;
			else printf("\n\tCarrera no valida intenta de nuevo");
		}while(f == 0);
		
		printf("\n\tPromedio: ");
		scanf("%f",&alumnos[i].promedio);
		limpiar();
		
	}
	separador_small();
	char ing[5] = "ING";
	char lic[5] = "LIC";
	char iti[5] = "ITI";
	float promedio_ing = promedio_carrera(alumnos,n,ing,&n_ing);
	
	float promedio_lic = promedio_carrera(alumnos,n,lic,&n_lic);
	
	float promedio_iti = promedio_carrera(alumnos,n,iti,&n_iti);
	
	separador_small();
	printf("\n\tING: %d",n_ing);
	printf("\n\tPromedio: %.2f",promedio_ing);
	separador_small();
	printf("\n\tLIC: %d",n_lic);
	printf("\n\tPromedio: %.2f",promedio_lic);
	separador_small();
	printf("\n\tITI: %d",n_iti);
	printf("\n\tPromedio: %.2f",promedio_iti);
	separador_small();
	
	printf("\n\tAlumnos en ING:%d",n_ing);
	printf("\n\tPromedio:%.2f",promedio_ing);
	printf("\n\tAlumnos en ING:%d",n_lic);
	printf("\n\tPromedio LIC:%.2f",promedio_lic);
	printf("\n\tAlumnos en ING:%d",n_iti);
	printf("\n\tPromedio ITI:%.2f",promedio_iti);
	
	fp = fopen("salida.txt","a");
	/*
	r+ (lectura y escritura)
	w+ (lo crea y luego permite lectura y escritura)
	a+ (lee todo el archivo y lo escribe hasta el final)
	*/
	
	for(i=0;i<n;i++){
		fseparador(fp);
		
		fprintf(fp,"\n\tNombre: %s",alumnos[i].nombre);
		fprintf(fp,"\tCarrera: %s",alumnos[i].carrera);
		fprintf(fp,"\n\tMatricula: %ld",alumnos[i].matricula);
		fprintf(fp,"\n\tPromedio: %.2f",alumnos[i].promedio);
		
		fseparador(fp);
	}
	fprintf(fp,"\n\tAlumnos en ING:%d",n_ing);
	fprintf(fp,"\n\tPromedio:%.2f",promedio_ing);
	fprintf(fp,"\n\tAlumnos en LIC:%d",n_lic);
	fprintf(fp,"\n\tPromedio LIC:%.2f",promedio_lic);
	fprintf(fp,"\n\tAlumnos en ITI:%d",n_iti);
	fprintf(fp,"\n\tPromedio ITI:%.2f",promedio_iti);
	
	printf("\n\n\tAlumnos en ING:%d",n_ing);
	printf("\n\tPromedio:%.2f",promedio_ing);
	printf("\n\n\tAlumnos en LIC:%d",n_lic);
	printf("\n\tPromedio LIC:%.2f",promedio_lic);
	printf("\n\n\tAlumnos en ITI:%d",n_iti);
	printf("\n\tPromedio ITI:%.2f",promedio_iti);
	
	fclose(fp);
	
	return 0;
}
