#include <stdio.h>

void f(int *pv1, int *pv2)
{
	int tmp;
	tmp = *pv1;
	*pv1 = *pv2+2;
	*pv2 = tmp-1;
}

int main() 
{
int x=11;
int *p;
int y=9;
p=&y;
f(&x,p);
printf("\n X = %d     Y = %d",x,y);
	return 0;
}

