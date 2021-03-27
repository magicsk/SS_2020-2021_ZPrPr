// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main(){
    int one = 69;
    int two = 420;

    int *pone;
    int *ptwo;
    int *temp;

    pone = &one;
    ptwo = &two;

    printf("%d %d\n", *pone, *ptwo);

    temp = ptwo;
    ptwo = pone;
    pone = temp;

    printf("%d %d\n", *pone, *ptwo);
    return 0;
}
