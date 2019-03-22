#include <stdio.h>
#include <time.h>

void msg(){
	printf("Hello!\n");
}


int main(){
	extern int counter;
	time_t start, end;
	start = time(NULL);
	int i;
	for(i= 0;i  < 10; ++i){
		msg();
	}
	end = time(NULL);
	printf("functions called:%d\n", counter);
	printf("time: %f\n",difftime(end, start)); 
	return 0;
}
