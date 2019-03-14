// Implement your cycle count tool here.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strlwr(char *s)
{
    char *p;
    for (p=s; *p; p++)
    {
        if (*p >= 'A' && *p <= 'Z')
            *p = *p - 'A' + 'a';
    }
    return s;
}


int main(int argc, char** argv){
    int counter[9];
    int k;
    for (k = 0; k < 9; k++){
        counter[k] = 0;
    }
    
    char** ins = (char**)malloc(sizeof(char*) * 9);
    ins[0] = "add";
    ins[1] = "sub";
    ins[2] = "mul";
    ins[3] = "div";
    ins[4] = "mov";
    ins[5] = "lea";
    ins[6] = "pop";
    ins[7] = "ret";
    ins[8] = "push";
    
    FILE* targetFile  = fopen(argv[1], "r");
    char* letter = (char *) malloc(sizeof (char) * 100);
    char* letters = (char*) malloc(sizeof(char) * 4);
    char* lowerLetters = (char*) malloc(sizeof(char) * 4);
    char* lts = (char*) malloc(sizeof(char) * 3);
    char* lowerLts = (char*) malloc(sizeof (char) * 3);
    while(!feof(targetFile)){
        letter = fgets(letter, sizeof (char) * 100, targetFile);
        if (letter == NULL){
	    break;
	}
	int i;
        for (i = 0; i < 4; i ++){
            letters[i] = letter[i + 1];
        }
        lowerLetters= strlwr(letters);
        if (strcmp(lowerLetters, "push") == 0){
            counter[8] ++;
}
        else{
            int i;
            for (i = 0; i < 3; i ++){
                lts[i] = letter[i+1];
            }
            lowerLts = strlwr(lts);
            int j;
            for (j = 0; j < 8; j++){
                if (strcmp(lowerLts, ins[j]) == 0){
                    counter[j] ++;
                    break;
                }
            }
        }

    }
    fclose(targetFile);
    free(letters);
    free(lts);
    free(letter);
    free(lowerLetters);
    free(lowerLts);
    int n;
    int sum =0;
    int cycles = 0;
    
    for (n = 0; n < 9;n ++){
        printf("%s: %d\n", ins[n], counter[n]);
        sum = sum + counter[n];
        switch (n) {
            case 0:
            case 1:
            case 4:
            case 8:
                cycles += counter[n];
                break;
            case 2:
            case 7:
            case 5:
                cycles += counter[n] * 3;
                break;
            case 6:
                cycles += counter[n] * 2;
                break;
            case 3:
                cycles += counter[n] * 24;
                break;
        }
    }
    free(ins);
    printf("Total instructions: %d\n",sum);
    printf("Total cycles: %d\n",cycles);
    
    return 0;
}

