// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <string.h>

int main() {
    char input[64][256];
    char output[64][256];
    char x;
    int i = 0, j = 0, line = 0;

    while (x = getchar()) {
        if (x == '*') {
            input[line][i++] = '^';
        } else if (x == ' ') {
            break;
        } else if (x == '\n') {
            line++;
            i = 0, j = 0;
        } else {
            input[line][i++] = ' ';
        }
        output[line][j++] = x;
    }

    for (i = 0; i < 64; i++) {
        if (strchr(output[i], '*') && strchr(input[i], '^')) {
            printf("%s\n", output[i]);
            printf("%s", input[i]);
        }
    }

    printf("\n");

    return 0;
}