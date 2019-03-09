// Write a C program that swaps two integers in a function
#include <stdio.h>

void swap(int* a, int* b){
	int aa = *a;
	int bb = *b;
	*a = bb;
	*b = aa;
}

int main (){
	int a = 1;
	int b = -1;
	printf("a: %d, b: %d\n", a, b);
	printf("===== swap =====\n");
	swap(&a, &b);
	printf("a: %d, b: %d\n",a, b);
	return 0;
}
