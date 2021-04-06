// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length(char* word) {
    return strlen(word);
}

int main() {
    char* word = (char*)malloc(64 * sizeof(char));
    int len[16] = { 0 };
    int i = 0, j = 0, temp = 0;
    char x;

    while ((x) = getchar()) {
        if (x == '\n') {
            len[j++] = length(word);
            break;
        } else if (x == ' ') {
            len[j++] = length(word);
            i = 0;
            word = NULL;
            word = (char*)malloc(64 * sizeof(char));
        } else {
            word[i++] = x;
        }
    }

    for (int i = 0; i < j; i++) {
        printf("%d ", len[i]);
        if (len[i] > len[temp]) temp = i; 
    }

    printf("\nLongest word have %d characters.\n", len[temp]);

    return 0;
}