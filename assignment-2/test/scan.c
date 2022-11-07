#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    printf("<- Naive & Rudimentary implementation of dictionary attacks ->\n");

    char    *filepath = "pass.txt";
    bool    infile = false;
    char    *line = NULL;
    size_t  len = 0;
    ssize_t read;

    FILE    *fp = fopen(filepath, "r");

    if (argv[1] == NULL) {
        printf("Pass in a string\n");
        return 0;
    }

    if (!fp) {
        fprintf(stderr, "Failed to open %s\n", filepath);
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\n")] = 0;
        if (!strcmp(line, argv[1])) {
            infile = true;
            printf("MATCH:      %s  = %s \n", argv[1], line);
            break;
        }
        else {
            printf("NO MATCH:   %s  != %s \n", argv[1], line);
        }
    }
    fclose(fp);

    if (line)
        free(line);

    return 0;
}
