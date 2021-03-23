// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <stdlib.h>

int even(int x[], int sx, int y[]){
    int sy = sx;
    for (int i = 0; i < sx; i++) {
        (x[i] % 2 == 0) ? y[i] = x[i] : sy--;
    }
    return (sy);
}

int main(){
    int sx = 7;
    int sy;

    int x[] = {4, 7, 1, 3, 2, 5, 6};
    int y[sx];
    sy = even(x, sx, y);

    printf("size of y: %d\n", sy);
    
    return 0;
}