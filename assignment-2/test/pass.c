#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void) {
    FILE *fp = fopen("pass.txt","r");
    char guess[100];
    char secret[100];
    int i;

    if(fgets(secret, sizeof(secret), fp) == NULL) {
        printf("Error while reading file\n");
        return -1;
    }
    
    fclose(fp);

    for (i=0; i < 5; i++) {
        printf("i = %c \n", secret);
        printf("Guess a password: \n");
        scanf("%s", guess);
        
        if (strcmp(secret,guess) == 0) {
            printf("Your guess was correct");
            return 0;
        }
        
        else
            printf("Your guess was incorrect. Please try again\n");
    }

    return 0;

}

