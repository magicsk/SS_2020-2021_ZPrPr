// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main() {
    FILE* file;
    FILE* new;
    char input = 0;

    printf("Enter character:\n");
    input = getchar();

    file = fopen("./znak.txt", "r");

    if (file != NULL) {
        char temp[90];

        if (input == 115 || input == 83) {
            new = fopen("./new.txt", "w");
            while (fscanf(file, "%s", temp) != EOF) {
                fprintf(new, "%s\n", temp);
            }
        } else {
            while (fscanf(file, "%s", temp) != EOF) {
                printf("%s\n", temp);
            }
        }
    } else {
        printf("Error: Failed to read a file.\n");
    }

    return 0;
}
