// Write a C program that swaps two integers(in the main body of code).

#include <stdio.h>

int main(){
	int a = 1;
	int b = -1;
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("====== swap ======\n");
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	return 0;
}
