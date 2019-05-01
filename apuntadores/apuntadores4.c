#include <stdio.h>



int main() 
{

int x=1;
int y=2;
int *ip;
ip=&x;
printf("\n Antes de los operadores ");
printf("\n x= %d  y= %d  *ip = %d",x,y,(*ip));
ip=&x;
y=(*ip)+3;
*ip=y;
printf("\n Despues de los operadores ");
printf("\n x= %d  y= %d  *ip = %d",x,y,(*ip)*2);
	return 0;
}

