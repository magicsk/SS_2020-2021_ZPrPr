// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <stdlib.h>

int multiply(int x[], int sx, int y[], int k){
    int sy = sx;
    for (int i = 0; i < sx; i++) {
        (x[i] % k == 0) ? y[i] = x[i] : sy--;
    }
    return (sy);
}

int main(){
    int sx = 10;
    int sy;

    int x[] = {4, 7, 10, 1, 3, 9, 2, 5, 8, 6};
    int y[sx];
    sy = multiply(x, sx, y, 2);

    printf("size of y: %d\n", sy);
    
    return 0;
}