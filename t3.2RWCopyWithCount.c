// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main() {
    FILE* file;
    FILE* numbers;

    file = fopen("./t3.2Input.txt", "r");

    if (file != NULL) {
        char temp[256];
        for (int i = 0; i < 256; i++){
            temp[i] = 0;
        }

        numbers = fopen("./t3.2Numbers.txt", "a");
        while (fscanf(file, "%s", temp) != EOF) {
            int lowercase = 0;
            for (int i = 0; i < 256; i++){
                if (temp[i] > 96 && temp[i] < 123) { lowercase++;}
            }
            
            fprintf(numbers, "%s\n", temp);
            fprintf(numbers, "%d\n", lowercase);
        }

    } else {
        printf("Error: Failed to read a file.\n");
    }

    return 0;
}
