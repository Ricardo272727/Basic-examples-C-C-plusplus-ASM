#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
* Complete the gradingStudents function below.
*/

/*
* Please store the size of the integer array to be returned in result_count pointer. For example,
* int a[3] = {1, 2, 3};
*
* *result_count = 3;
*
* return a;
*
*/
int* gradingStudents(int grades_count, int* grades, int* result_count) {
	/*
	* Write your code here.
	*/
	int i,aux,result[grades_count];
	for(i=0;i<grades_count;i++){
		if(grades[i] >= 38){
			aux = grades[i];
			while(aux %5 != 0)aux++;
			if((aux-grades[i]) < 3) result[i] = aux;
			else result[i] = grades[i];
		}else{
			result[i] = grades[i];
		}
	}
	*result_count = grades_count;
	return result;
}

int * readline(int count){
	int i;
	int * grades;
	if((grades = (int*)malloc(count * sizeof(int))) == NULL) return NULL;
	
	for(i=0;i<count;i++){
		printf("grades[%d] = ",i);
		scanf("%d",&grades[i]);
	}
	return grades;
}

int main()
{	int grades_count;
	int result_count;
	int i;
	scanf("%d",&grades_count);
	int * grades = readline(grades_count);
	printf("aqui");
	printf("%d",grades[1]);
	int * result = gradingStudents(grades_count, grades, &result_count);
	
	for(i= 0;i<grades_count;i++){
		printf("\n%d",result[i]);
		
	}
	
	

	
	return 0;
}


