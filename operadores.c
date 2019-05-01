#include <stdio.h>

int main(int argc, char *argv[]) {
	int x = 7,y;
	
	y = -2 + --x;
	y += 2;
	y=(y== x);
	y=y++ - x;
	y = (y == 100);
	 y = 5/ 2 + 20 % 6;
	y = 5* 15/ 2/ (4- 2); //37/2 = 18
	 y = (8==16 || 7 != 4) && 4< 1;
	 y=(4*3<6||3> 5- 2) && 3+2<12;
	
	 
	 int i=2,j=-3;
	 y = i%2;
	 printf("%d",y);
	 
	 
	 
	return 0;
}

