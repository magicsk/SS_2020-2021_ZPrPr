// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;

    printf("Enter members of quadratic equation in the form of a b c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double x1 = ((-b) + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
    double x2 = ((-b) - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);

    printf("x1 = %.2lf \n", x1);
    printf("x2 = %.2lf \n", x2);
    return 0;
}