// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <stdlib.h>


void lol(double*** data) {
    *data = (double**)malloc(330 * sizeof(double*));
    for (int h = 0; h < 330; h++) {
        (*data)[h] = (double*)malloc(3 * sizeof(double));
    }
    int y = 0;
    for (int x = 0; x < 12; x++) {
        (*data)[x][y] = x;
        printf("%.2lf\n", (*data)[x][y++]);
    }
}
int main() {
    double** data;
    lol(&data);
    int y = 0;
    for (int x = 0; x < 12; x++) {
        printf("%.2lf\n", data[x][y++]);
    }
}
