// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int sumOfDigit(int n, int sum) {
    int digit = n % 10;
    sum += digit;
    n = n / 10;
    if (n > 0) {
        return sumOfDigit(n, sum);
    } else {
        return sum;
    }
}

int main() {
    int n;
    int sum = 0;

    printf("Enter number:");
    scanf("%d", &n);

    sumOfDigit(n, sum);

    printf("%d\n", sumOfDigit(n, sum));

    return 0;
}
