#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int passwd(char str_passwd) {

    printf("<- Naive & Rudimentary implementation of dictionary attacks ->\n");

    char    *filepath = "pass.txt";
    bool    infile = false;
    char    *line = NULL;
    size_t  len = 0;
    ssize_t read;

    FILE    *fp = fopen(filepath, "r");

    if (str_passwd == NULL) {
        printf("Pass in a string\n");
        return 0;
    }

    if (!fp) {
        fprintf(stderr, "Failed to open %s\n", filepath);
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\n")] = 0;
        if (!strcmp(line, str_passwd)) {
            infile = true;
            printf("MATCH:      %s  = %s \n", str_passwd, line);
            break;
        }
        else {
            printf("NO MATCH:   %s  != %s \n", str_passwd, line);
        }
    }
    fclose(fp);

    if (line)
        free(line);

    return str_passwd;
}

int main() {
    
    
    return 0;
}
