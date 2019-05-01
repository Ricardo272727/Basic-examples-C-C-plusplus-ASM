#include <stdio.h>

int fx(int a, int *b)
{
 int res;
 res= a *2;
 *b=(*b)*3;
 return res;
}

int main() 
{
	int x,z;
	int y;
	x=3;
	y=4;
	z=fx(x,&y);
	printf(" X = %d",x);
	printf(" Y = %d",y);
	printf(" Z = %d",z);
	return 0;
}


