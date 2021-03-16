// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int prime(int n) {
    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (p > 2) {
            break;
        } else if (n % i == 0) {
            p++;
        }
    }

    if (p <= 2) {
        return n;
    } else {
        return 0;
    }
}

int divide(int* pone, int* ptwo) {
    // printf("%d %d\n", *pone, *ptwo);
    for (int i = 2; i < 100; i++) {
        int p = prime(i);
        // printf("%d\n", p);
        if (p != 0 && (p <= *pone && p <= *ptwo)) {
            if (!(*pone % p) && !(*ptwo % p)) {
                *pone = *pone / p;
                *ptwo = *ptwo / p;
                // printf("prime %d %d %d\n", *pone, *ptwo, p);
                divide(pone, ptwo);
                break;
            } else if (!(*pone % *pone) && !(*ptwo % *pone)) {
                // printf("self1 %d %d\n", *pone, *ptwo);
                *ptwo = *ptwo / *pone;
                *pone = *pone / *pone;
                divide(pone, ptwo);
                break;
            } else if (!(*pone % *ptwo) && !(*ptwo % *ptwo)){
                // printf("self2 %d %d\n", *pone, *ptwo);
                *pone = *pone / *ptwo;
                *ptwo = *ptwo / *ptwo;
                divide(pone, ptwo);
                break;
            }
        }
    }
    return 0;
}

int main() {
    int one;
    int two;

    printf("Enter two numbers separated by space: ");
    scanf("%d %d", &one, &two);

    int* pone = one;
    int* ptwo = two;


    divide(&pone, &ptwo);
    printf("Reduced fraction %d/%d\n", pone, ptwo);
    return 0;
}
