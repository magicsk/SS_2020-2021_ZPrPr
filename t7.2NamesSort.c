// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minsort(const void* a, const void* b)
{
    const char* aa = *(const char**)a;
    const char* bb = *(const char**)b;
    return strcmp(aa,bb);
}

int main(){
    int lines = 0;
    char** name = NULL;
    FILE* names = NULL;
    names = fopen("./t7.2Names.txt", "r");

    if (names != NULL){
        name = (char**)malloc(50 * 50 * sizeof(char));
        for (int i = 0; i < 50; i++) {
            name[i] = (char*)malloc(50 * sizeof(char));
        }

        while (!(ferror(names) || feof(names))) {
            fscanf(names, "%s", name[lines++]);
        }

        // for (int i = 0; i < lines; i++) {
        //     printf("%s\n", name[i]);
        // }

        qsort(name, lines, sizeof(char*), minsort);

        for (int i = 0; i < lines; i++) {
            printf("%s\n", name[i]);
        }
    } else {
        printf("File not opened!");
    }

    return 0;
}