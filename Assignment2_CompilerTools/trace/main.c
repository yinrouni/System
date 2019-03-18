#include <stdio.h>
#include <time.h>

void msg(){
	printf("Hello!\n");
}


int main(){
	time_t start, end;
	start = time(NULL);
	int i;
	for(i= 0;i  < 10; ++i){
		msg();
	}
	end = time(NULL);
	printf("time: %f\n",difftime(end, start)); 
	return 0;
}
