// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#define STEP 0.001


double f1(double i) {
    return ((10 * i) - 19);
}

double f2(double i) {
    return (5 / (i * i));
}

double derivate(double (*f)(double), double i) {
    return (f(i + 0.001) - f(i)) / 0.001;
}

int main() {
    double r1, r2, i;

    scanf("%lf %lf", &r1, &r2);
    printf("   x  f1(x) f1'(x) f2(x) f2'(x)\n");

    for (i = r1; i < r2 + 0.000000001; i += STEP) {
        printf("%5.2lf %5.2lf %5.2lf %5.2lf %5.2lf\n", i, f1(i), derivate(f1, i), f2(i), derivate(f2, i));
    }

    return 0;
}