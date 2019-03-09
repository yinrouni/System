// Write a C program using the goto command and a label.


#include<stdio.h>
int main() {
	int n = 0;
   	printf("input a string: ");
        	loop: if (getchar()!='\n') {
        	n++;
        	goto loop;
   	 }	
  	printf("output: %d\n",n);
	return 0;
}
