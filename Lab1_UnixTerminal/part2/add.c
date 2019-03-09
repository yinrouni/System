// Write a C program that calls an add function(long add(long a, long b).

#include <stdio.h>
long add (long a, long b){
	long result = a + b;
	return result;
}
int main(){
	long a = 123;
	long b = 321;
	printf("%ld + %ld = %ld\n", a, b, add(a, b));
	return 0;
}
