// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 0;

    printf("Enter a number:\n");
    scanf("%d", &x);

    char* n = (char*)malloc(x * sizeof(char));

    printf("Enter a word:\n");
    scanf("%s", n);
    for (int i = (x-1); i >= 0; i--) {
        printf("%c", n[i]);
    }
    printf("\n");

    return 0;
}