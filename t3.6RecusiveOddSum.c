// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int oddSum(int n, int sum) {
    if (n % 2) {
        sum += n;
        n--;
    }
    n--;
    if (n > 0) {
        return oddSum(n, sum);
    } else {
        return sum;
    }
}

int main() {
    int n;
    int sum = 0;

    printf("Enter number:");
    scanf("%d", &n);


    // for (int i = n; i > 0; i--) {
    //     if (i % 2){
    //         sum += i;
    //     }
    // }

    printf("%d\n", oddSum(n, sum));

    return 0;
}