// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int* max(int *pone, int *ptwo){
    if (pone > ptwo) {
        return pone;
    } else {
        return ptwo;
    }
}

int main(){
    int one = 69;
    int two = 420;

    int *pone = &one;
    int *ptwo = &two;

    printf("%d %d\n", *pone, *ptwo);

    printf("%d\n", *max(pone, ptwo));
    return 0;
}
