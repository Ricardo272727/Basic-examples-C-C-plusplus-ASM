#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void mostrar_vector(int * vect,int n){
	int i;
	for(i = 0;i<n;i++){
		printf("\n%d",vect[i]);
	}
}

int buscar_numero(int * nums,int num, int n){
	int inicio,fin,mitad,f;
	int pos;
	inicio = 0;
	fin = n-1;
	mitad = (inicio + fin)/2;
	f = 0;
	while(f == 0){
		
		if(nums[mitad] == num){
			pos = mitad;
			f = 1;
		}else{
			if(nums[mitad] < num){
				inicio = mitad + 1;
				mitad = (inicio+fin)/2;
				
			}else{
				fin = mitad - 1;
				mitad = (inicio+fin)/2;
			}
		}
		
		if(inicio > fin){
			f = -1;
			pos = -1;
		}
		
	}
	return pos;
}

int mostrar_menu(){
	int op,f;
	do{
		printf("\n\t1.Ordenamiento por seleccion y busqueda binaria");
		printf("\n\t2.Operaciones con matrices");
		printf("\n\t3.Salir\n\t");
		scanf("%d",&op);
		if(op == 1 || op == 2 || op == 3) f = 0;
		else printf("\n\tPor favor elige un opcion valida");
	}while(f != 0);
	return op;
}

int mostrar_menu_matrices(){
	int op, f = 0;
	
	printf("\n\t1.Sumar matrices");
	printf("\n\t2.Restar matrices");
	printf("\n\t3.Multiplicar matrices\n");
	//printf("\n\t4.Inversa de una matriz");
	//printf("\n\t5.Transpuesta de una matriz");
	//printf("\n\t6.Reducir a la forma escalonda una matriz");
	//printf("\n\t7.Determinante de una matriz");
	//printf("\n\t8.Resolver sistema de ecuaciones lineales");
	do{
		scanf("%d",&op);
		if(op == 1 || op == 2 || op == 3) f = 1;
		else printf("\n\tElige una opcion valida\n");
	}while(f == 0);

	return op;
}	

void pedir_orden(int * m, int *n,char name){
	printf("\n\t\tRenglones de %c ",name);scanf("%d",m);
	printf("\n\t\tColumnas de %c ",name);scanf("%d",n);
}

int main(int argc, char *argv[]) {
	int n,i,aux,j,aux2,b,op,op2;
	srand(time(NULL));
	int * nums;
	int ra,ca,rb,cb;
	
	
do{
	
	op = mostrar_menu();
	switch(op){
	case 1:
		printf("\nEscribe cuantos numeros deseas generar: ");scanf("%d",&n);
		if((nums = (int*)malloc(n*sizeof(int))) == NULL)return -1;
		for(i = 0;i<n;i++){
			aux = rand() % 100;
			nums[i] = aux;
		}
		//ordenamiento por seleccion:
		for(i = 0;i<n-1;i++){
			aux = i;
			for(j=i+1;j<n;j++){
				if(nums[j] < nums[aux]) aux = j; 
			}
			if(nums[aux] != nums[i]){
				aux2 = nums[aux];
				nums[aux] = nums[i];
				nums[i] = aux2;
			}
		}
		
		mostrar_vector(nums,n); 
		
		//busqueda
		printf("\nQue numero deseas buscar? ");scanf("%d",&b);
		int pos = buscar_numero(nums,b,n);
		if(pos != -1)printf("\nNumero encontrado en la posicion: %d ",pos);
		else printf("\nNumero no encontrado");
		break;
	case 2:
		
		op2 = mostrar_menu_matrices();
		
		
		
		switch(op2){
		case 1:
			pedir_orden(&ra,&ca,'A');
			pedir_orden(&rb,&cb,'B');
			break;
		default : printf("***************Error********************************");
		}
		
		break;
	
	case 3:
		break;
	
	default: printf("\n\t******************Error******************************");
	}
	
}while(op != 3);	
	
	return 0;
}

