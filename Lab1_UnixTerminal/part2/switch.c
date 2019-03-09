// Write a C program using a switch statement

#include <stdio.h>

int main () {
    int grade = 90; 
    switch(grade) {
        case 100 :
            printf("Excellent!\n" );
            break;
        case 90 :
            printf("Well done\n" ); 
            break;
        case 80 :
            printf("Well done\n" );
            break;
        case 60 :
            printf("You passed\n" );
            break;
        case 40 :
            printf("Better try again\n" );
            break;
        default :
            printf("Invalid grade\n" );
    }
    
    printf("Your grade is  %d\n", grade );
    
    return 0;
}

