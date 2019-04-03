// Implement your part 1 solution here
// gcc vfork.c -o vfork
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int colors[64][64*3];

void paint(int workID){
        printf("Artist %d is painting\n",workID);

 for(int i =0; i < 64*3; i++){
                colors[workID][i] = workID; // Try doing something more interesting with the colors!
        }
}


int main(int argc, char** argv){
	int numberOfArtists = 64;
	pid_t pid;
//	pid_t wpid;
	int status;
	for(int i =0; i < numberOfArtists; i++){
                pid = vfork();

		if(pid==0){
                        paint(i);
                        exit(0);
                }

	//wpid = wait(&status);
	//while(wpid > 0);
	printf("Child created: %d\n", pid);
	}	
	printf("Masterpiece(vfork.ppm) is being assembled\n");

	FILE *fp;
	fp = fopen("vfork.ppm","w+");
	fputs("P3\n",fp);
	fputs("64 64\n",fp);
	fputs("255\n",fp);
	for(int i =0; i < 64;i++){
		for(int j =0; j < 64*3; j++){
			fprintf(fp,"%d",colors[i][j]);
			fputs(" ",fp);		
		}
		fputs("\n",fp);
	}
	fclose(fp);
 	return 0;
}
