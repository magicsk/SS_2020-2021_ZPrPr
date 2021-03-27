// created by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <math.h>

int main(){
    int m;
    double bmi, v;
    printf("Enter your weigth in kg:");
    scanf("%d", &m);

    printf("Enter your height in cm:");
    scanf("%lf", &v);

    v = pow(v/100.0, 2);
    bmi = m/v;

    printf("Your BMI index is: %lf", bmi);

    return 0;
}
