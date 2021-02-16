// created by Rastislav Brna
// Licence is available on https://github.com/magicsk/ex02
// IDE: Visual Studio Code
// Compiler: gcc-7  args:-lm

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
