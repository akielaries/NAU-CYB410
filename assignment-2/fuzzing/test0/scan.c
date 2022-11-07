#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *passwd(char *str_passwd) {
    char    *filepath = "pass.txt";
    bool    infile = false;
    char    *line = NULL;
    size_t  len = 0;
    ssize_t read;
    FILE    *fp = fopen(filepath, "r");
    printf("Comparing %s \n", str_passwd);
    if (str_passwd == NULL) {
        printf("Pass in a string\n");
    }
    if (!fp) {
        fprintf(stderr, "Failed to open %s\n", filepath);
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
    printf("<- Naive & Rudimentary implementation of dictionary attacks ->\n");
    char t0[100] = "password";
    char t1[100] = "password123";
    char t2[100] = "init";
    passwd(t0);
    passwd(t1);
    passwd(t2);
    
    return 0;
}
