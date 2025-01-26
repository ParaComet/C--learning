#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    const char *filename = "out.c"; 

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    return 0;
}
