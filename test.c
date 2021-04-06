// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main(){
    char name = 0;

    printf("Enter something:\n");
    name = getchar();

    printf("%d", name);

    return 0;
}