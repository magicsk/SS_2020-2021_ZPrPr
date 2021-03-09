// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <math.h>

void power(double x, int n){
    for (int i = 1; i <= n; i++){
        double result = pow(x, i);
        printf("%.2lf^%d = %.2f\n", x, i, result);
    }
}

int main(){
    double x;
    int n;
    
    printf("Enter two numbers separated by space (number power):\n");
    scanf("%lf %d", &x, &n);

    power(x, n);

    return 0;
}
