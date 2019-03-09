// Write a C program called array2.c that has an array of 400 integers in the function of main that is dynamically allocated.

#include <stdio.h>
#include <stdlib.h>

int main(){
	int* a = (int*) malloc(sizeof (int) * 400);
	a[0] = 70;
	a[100] = 100;
	a[400] = 444;
	free(a);
	return 0;
}

