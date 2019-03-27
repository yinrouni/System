// Take a look at some of the previous examples to create your own program!
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

	char* myargv[16];	// We can store up to 16 arguments.
	myargv[0]="/bin/ls";	// Our first argument is the program we want to launch.
	myargv[1]="-F";		// Any additional arguments (i.e. flags) we want to make use of.
	myargv[2]=NULL; 	// Terminate the argument list--similar to how we would terminate a character string.
				// (i.e. Set the last argument to NULL if we have no more flags.)
	char* myargv1[16];
	myargv1[0] = "/bin/tree";
	myargv1[1] = "-C";
	myargv1[2] = NULL;

	char* myargv2[16];
        myargv2[0] = "/bin/echo";
        myargv2[1] = "This is the exection of the command 'tree' and 'ls'\n";
        myargv2[2] = NULL;
	if (fork() == 0){
		execve(myargv[0],myargv,NULL);
		printf("Child: Should never get here\n");
		exit(1);
	}else{
		if (fork() == 0){
			execve(myargv1[0],myargv1,NULL);
			printf("Child: Should never get here\n");
               		exit(1);}
		else{
			if (fork() == 0){
				 execve(myargv2[0],myargv2,NULL);
				 printf("Child: Should never get here\n");
              			 exit(1);
			}
			else{
				wait(NULL);
                       		printf("==========\n");
			}
			wait(NULL);
			printf("==========\n");
		}
		wait(NULL); // handy synchronization function again!
		printf("This always prints last\n");
}
return 0;}
