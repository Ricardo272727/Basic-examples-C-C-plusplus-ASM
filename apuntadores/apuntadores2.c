#include <stdio.h>

int main() 
{
	int A[7]={65,23,43,12,9,86,4};
	int *p,i;
	p=&A[0];
   for (i=0;i<7;i++)
	printf("%d  ",*p++);
	return 0;
}


