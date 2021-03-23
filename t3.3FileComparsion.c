// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main() {
    FILE* first;
    FILE* second;

    first = fopen("./t3.3First.txt", "r");
    second = fopen("./t3.3Second.txt", "r");

    if (first != NULL || second != NULL) {
        char charfirst;
        char charsecond;
        int diff = 0;
        int length = 0;

        while (fscanf(first, "%c", &charfirst) != EOF && fscanf(second, "%c", &charsecond) != EOF) {
            if (charfirst == EOF || charsecond == EOF) {
                length++;
            } else {
                if (charfirst != charsecond) { diff++; }
            }
        }
        while (fscanf(first, "%c", &charfirst) != EOF) {
                length++;
        }
        while (fscanf(second, "%c", &charsecond) != EOF) {
                length++;
        }
        printf("%d, %d", diff, length);
    } else {
        printf("Error: Failed to read a file.\n");
    }

    return 0;
}
