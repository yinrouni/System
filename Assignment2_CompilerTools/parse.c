// Implement a working parser in this file that splits text into individual tokens.

#include <stdio.h>
#include <string.h>
int main(int argc, const char * argv[]) {
    char str[strlen(argv[1])];
    int i;
    for (i = 0; i < strlen(argv[1]); i ++){
        str[i] = argv[1][i];
        
    }
    char* pch;
    pch = strtok(str, " ");
    while(pch != NULL){
        printf("%s\n", pch);
        pch = strtok(NULL, " ");
    }
    return 0;
}

