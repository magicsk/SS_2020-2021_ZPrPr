// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

void read(double* pa, double* pb) {
    printf("Enter length of two sides of rectangle: ");
    scanf("%lf %lf", pa, pb);
}

void sum(double *pa, double *pb, double *po, double *ps) {
    *po = 2 * *pa + 2 * *pb;
    *ps = *pa * *pb;
}

int main() {
    double a, b, o, S;
    double *pa = &a;
    double *pb = &b;
    double *po = &o;
    double *pS = &S;

    read(pa, pb);

    sum(pa, pb, po, pS);

    printf("Perimeter: %.3lf\nContent: %.3lf\n", o, S);

    return 0;
}