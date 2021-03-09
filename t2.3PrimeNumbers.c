// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int check_prime(int n){
    int p = 0;
    for (int i = 1; i <= n; i++){
        if (p > 2) {
            break;
        } else if (n%i == 0){
            p++;
        }
    }

    if (p <= 2) {
        // printf("%d is a prime number\n", n);
        return 1;
    } else {
        // printf("%d is not a prime number\n", n);
        return -1;
    }
}

int main(){
    int f, s;

    printf("Enter two numbers separated by space:\n");
    scanf("%d %d", &f, &s);

    for (int i = f; i <= s; i++){
        if (check_prime(i) == 1){
            printf("%d\n", i);
        };
    }

    return 0;
}
