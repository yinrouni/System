// Implement your cycle count tool here.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Turn the string into lowercase.
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

// Get the substring of string s, from index start to index end.
void  substring(char* sub, char *s, int start, int end){
    int j = 0;
    int i;
    for (i = start; i < end; i++){
        sub[j] = s[i];
        j ++;
    }
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
    char letter[100];
    while(!feof(targetFile)){
        fgets(letter,100, targetFile);
        if (letter == NULL){
	    break;
	}

        char*cs = (char*)malloc(sizeof(char) * 4);
	substring(cs, letter,1,5);
        if( strcmp(strlwr(cs), ins[8]) == 0){
            counter[8]++;
            free(cs);
	    continue;
        }
	char* c = (char*)malloc(sizeof(char)*3);
	substring(c,cs,0,3);
	int i;
        for (i = 0 ; i < 8; i ++){
            if (strcmp(strlwr(c), ins[i]) == 0){
                counter[i] ++;
                break;
            }
        }
	free(cs);
	free(c);
    }

    fclose(targetFile);
    int n;
    int sum =0;
    int cycles = 0;
    
    for (n = 0; n < 9;n ++){
        printf("%s: %d\n", ins[n], counter[n]);
        sum = sum + counter[n];
        switch (n) {
            // 'add', 'sub', 'mov', 'pop', 'push': latency = 1.
	    case 0:
            case 1:
            case 4:
            case 6:
	    case 8:
                cycles += counter[n];
                break;
	    // 'mul', 'ret': latency = 3
            case 2:
            case 7:
                cycles += counter[n] * 3;
                break;
	    // 'lea': latency = 2
	    case 5:
                cycles += counter[n] * 2;
                break;
	    // 'div': latency = 24
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

