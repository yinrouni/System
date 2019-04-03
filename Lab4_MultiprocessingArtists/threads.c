// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


// Global array
// This is our 'canvas' we are painting on.
// It is 64 rows by 64 columns (each pixel stores 3 color components, R,G,B)
int colors[64][64*3];
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;
void paint(int workID);
void *thread(void *vargp){
	pthread_mutex_lock(&mutex1);
 	paint(counter);
	counter ++;
	pthread_mutex_unlock(&mutex1);
}
void paint(int workID){

        printf("Artist %d is painting\n",workID);
	int i;
	for(i =0; i < 64*3; i++){
                colors[workID][i] = workID; // Try doing something more interesting with the colors!
        }
}

int main(int argc, char** argv){
	int numberOfArtists = 64;
	pthread_t tids[numberOfArtists];
	//for(int i =0; i < numberOfArtists; i++){
          //      pid = vfork();
	//	if(pid==0){
//                        paint(i);
    //                    exit(0);
  //              }
//		printf("Child created: %d\n",pid);
  //      }
  	int i;
 	for (i = 0; i< numberOfArtists; ++i){
		pthread_create(&tids[i], NULL, thread, NULL);
	}
	int j;
	for (j = 0; j < numberOfArtists; ++j){
		pthread_join(tids[j], NULL);
	}
	printf("Masterpiece(vfork.ppm) is being assembled\n");
	FILE *fp;
	fp = fopen("threads.ppm","w+");
	fputs("P3\n",fp);
	fputs("64 64\n",fp);
	fputs("255\n",fp);
	int m;
	int n;
	for(m =0; m < 64;m++){
		for(n =0; n < 64*3; n++){
			fprintf(fp,"%d",colors[m][n]);
			fputs(" ",fp);		
		}
		fputs("\n",fp);
	}
	fclose(fp);
	
	return 0;
}
