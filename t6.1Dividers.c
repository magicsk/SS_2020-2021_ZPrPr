// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <stdlib.h>

int dividers(int x[], int sx, int y[], int k) {
    int sy = sx;
    for (int i = 0; i < sx; i++) {
        (k % x[i] == 0) ? y[i] = x[i] : sy--;
    }
    return (sy);
}

int main() {
    int sx = 10;
    int sy;

    int x[] = { 4, 7, 10, 2, 3, 9, 6, 3, 8, 12 };
    int y[sx];
    sy = dividers(x, sx, y, 24);

    printf("size of y: %d\n", sy);

    return 0;
}