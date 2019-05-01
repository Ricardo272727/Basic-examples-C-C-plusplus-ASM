#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *p_archivo;
FILE *p_archivo2;
FILE *p_arch;
FILE *p_file1,*p_file2,*p_file;

int main(){
	/*COMPROBAR SI EXISTE UN ARCHIVO
	char direccion[] = "prueba/texto.txt";
	
	p_archivo = fopen(direccion,"r");// r =read
	
	if(p_archivo == NULL){
		printf("El archivo no existe");
	}else{
		printf("Se encontro el archivo:%s",direccion);
	}
	*/
	
	/*COmo crear un txt!!!
	char adress[] = "prueba/archivo_nuevo.txt";
	p_archivo2 = fopen(adress,"w");
	if(p_archivo2 == NULL){
		printf("\nNo se puede crear el archivo");
	}else{
		printf("\nse creo el archivo en:%s",adress);
	}
	*/
	/*CREAR ARCHIVO 
	char carpeta[100];
	char archivo[] = "/hola_mundo.txt";
	printf("Escribe el nombre de l carpeta para crear el archivo:");
	scanf("%s",carpeta);
	strcat(carpeta,archivo);
	p_arch = fopen(carpeta,"w");
	printf("El archivo se ha creado en la ruta: %s",carpeta);
	FOPEN:
	r read
	w create or(die if exists)
	a anade al final
	r+ abre el archivo para modificar (leer/escribir)
	w+ crea un archivo para escribir leer (si existe cabum)
	a+ abre para modificar (escribir/leer) alfinal si no existe lo crea
	t = modo texto
	b = binario
	rt wt at a+t r+t
	rb wb ab ...
	*/
	//ABRIR Y CERRAR ARCHIVOS
	/*
	p_file1 = fopen("prueba/texto.txt","a+");
	p_file2 = fopen("prueba/hola_mundo.txt","a+");
	
	if(p_file1==NULL || p_file2 == NULL){
		printf("YA BAILARON LOS ARCHIVOS KRNAL :V");
	}else{
		printf("YA SE ABRIERON LOS ARCHIVOS :V");
	}
	fclose(p_file1);//cerrando...
	fclose(p_file2);
	*/
	//INTRODUCIR TEXTO
	/*
	int c;
	char direccion[] = "prueba/escribir_en_archivo.txt";
	p_file = fopen(direccion,"wt");
	if(p_file==NULL){
		printf("EL archivo babalu");
		return 1;
	}
	while((c = getchar())!=EOF && c!='0'){
		
		fputc(c,p_file);
		
	}
	fclose(p_file);
	*/
	//LEER CONTENIDO 
	/*
	int c;
	char direccion[] = "prueba/escribir_en_archivo.txt";
	p_file = fopen(direccion,"rt");
	if(p_file == NULL){
		return 1;
	}
	while((c = fgetc(p_file))!=EOF){
		if(c == '\n'){
			printf("\n");
		}else{
			putchar(c);
		}
	}
	fclose(p_file);
	*/
	//AGREGAR MAS TEXTO
	int c;
	char direccion[] = "prueba/escribir_en_archivo.txt";
	p_file = fopen(direccion,"at");//at = agregar texto
	if(p_file == NULL){
		printf("error al crear el archivo");
	}
	int f=1;
	while((c = getchar())!=EOF && f==1){
		if(c=='*'){
			f = 0;
		}else{
		fputc(c,p_file);
		}
	}
	fclose(p_file);
	
	return 0;
}
