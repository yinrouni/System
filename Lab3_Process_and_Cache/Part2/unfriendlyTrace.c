#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

#define BITWIDTH 8      // Our architecture is an 8-bit architecture
#define ADDRESSES 1024  // We will generate 512 instructions
#define RANGE 256       // The range of these instructions is a value 0-32


void Trace(int size, int range){
        FILE* fp = fopen("regular.txt","w");

        for(int i=0; i < size; i++){
                char* bin=intToBinaryString((i%range),BITWIDTH);
                fprintf(fp,"%s\n",bin);
                free(bin);
        }

        fclose(fp);
}


void unfriendlyTrace(int size, int range){
        FILE* fp = fopen("unfriendly.txt","w");

        srand(time(NULL));

        for(int i=0; i < size; i+=2){
                char* bin = intToBinaryString((rand()%range),BITWIDTH);
                char* bin2 = intToBinaryString((rand()%range),BITWIDTH);
                fprintf(fp,"%s\n",bin);
                fprintf(fp,"%s\n",bin2);
                free(bin);
        }

        fclose(fp);
}
int main(){

        unfriendlyTrace(ADDRESSES,RANGE);

char* test1 = intToBinaryString(255,BITWIDTH);
        printf("Example: 255 = %s\n", test1);
        printf("Binary(0,0) of 255: %d\n",binaryStringRangeToInt(test1, 0, 0));
        printf("Binary(0,1) of 255: %d\n",binaryStringRangeToInt(test1, 0, 1));
        printf("Binary(0,2) of 255: %d\n",binaryStringRangeToInt(test1, 0, 2));
        printf("Binary(0,3) of 255: %d\n",binaryStringRangeToInt(test1, 0, 3));
        printf("Binary(0,4) of 255: %d\n",binaryStringRangeToInt(test1, 0, 4));
        printf("Binary(0,5) of 255: %d\n",binaryStringRangeToInt(test1, 0, 5));
        printf("Binary(0,6) of 255: %d\n",binaryStringRangeToInt(test1, 0, 6));
        printf("Binary(0,7) of 255: %d\n",binaryStringRangeToInt(test1, 0, 7));
        free(test1);


        char* test2 = intToBinaryString(0,BITWIDTH);
        printf("\nExample: 0 = %s\n", test2);
        printf("Binary(0,0) of 0: %d\n",binaryStringRangeToInt(test2, 0, 0));
        printf("Binary(1,1) of 0: %d\n",binaryStringRangeToInt(test2, 1, 1));
        printf("Binary(2,2) of 0: %d\n",binaryStringRangeToInt(test2, 2, 2));
        printf("Binary(3,3) of 0: %d\n",binaryStringRangeToInt(test2, 3, 3));
        printf("Binary(4,4) of 0: %d\n",binaryStringRangeToInt(test2, 4, 4));
        printf("Binary(5,5) of 0: %d\n",binaryStringRangeToInt(test2, 5, 5));
        printf("Binary(6,6) of 0: %d\n",binaryStringRangeToInt(test2, 6, 6));
        printf("Binary(7,7) of 0: %d\n",binaryStringRangeToInt(test2, 7, 7));
        free(test2);

        char* test3 = intToBinaryString(42,BITWIDTH);
        printf("\nExample: 42 = %s\n", test3);
        printf("Binary(0,0) of 42: %d\n",binaryStringRangeToInt(test3, 0, 0));
        printf("Binary(1,1) of 42: %d\n",binaryStringRangeToInt(test3, 1, 1));
        printf("Binary(2,2) of 42: %d\n",binaryStringRangeToInt(test3, 2, 2));
        printf("Binary(3,3) of 42: %d\n",binaryStringRangeToInt(test3, 3, 3));
        printf("Binary(4,4) of 42: %d\n",binaryStringRangeToInt(test3, 4, 4));
        printf("Binary(5,5) of 42: %d\n",binaryStringRangeToInt(test3, 5, 5));
        printf("Binary(6,6) of 42: %d\n",binaryStringRangeToInt(test3, 6, 6));
        printf("Binary(7,7) of 42: %d\n",binaryStringRangeToInt(test3, 7, 7));
        free(test3);


        char* test4 = intToBinaryString(81,BITWIDTH);
        printf("\nExample: 81 = %s\n", test4);
        printf("Binary(0,0) of 81: %d\n",binaryStringRangeToInt(test4, 0, 0));
        printf("Binary(0,1) of 81: %d\n",binaryStringRangeToInt(test4, 0, 1));
        printf("Binary(1,1) of 81: %d\n",binaryStringRangeToInt(test4, 1, 1));
        printf("Binary(1,2) of 81: %d\n",binaryStringRangeToInt(test4, 1, 2));
        printf("Binary(1,3) of 81: %d\n",binaryStringRangeToInt(test4, 1, 3));
        printf("Binary(2,5) of 81: %d\n",binaryStringRangeToInt(test4, 2, 5));
        printf("Binary(5,7) of 81: %d\n",binaryStringRangeToInt(test4, 5, 7));
        printf("Binary(6,7) of 81: %d\n",binaryStringRangeToInt(test4, 6, 7));
        printf("Binary(7,7) of 81: %d\n",binaryStringRangeToInt(test4, 7, 7));
        free(test4);

        return 0;
}
