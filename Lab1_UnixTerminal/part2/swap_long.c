// Now modify your program to swap two long's.
# include <stdio.h>

int main(){
	long a = 12345678;
	long b = -12345678;
	printf("a: %ld\n", a);
	printf("b: %ld\n", b);
	long temp;
	temp = a;
	a = b;
 	b = temp;
	printf("===== swap =====\n");
	printf("a: %ld\n", a);
	printf("b: %ld\n", b);
	return 0;
}

