// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main() {
    int n;

    printf("Enter a number:\n");
    scanf("%d", &n);

    float d[n];

    for (int i = 0; i < n; i++) {
        printf("Enter another number:\n");
        scanf("%f", &d[i]);
    }

    int smallest = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] < d[smallest]) {
            smallest = i;
        }
    }

    int biggest = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] > d[biggest]) {
            biggest = i;
        }
    }

    printf("Smallest: %.2f\n", d[smallest]);
    printf("Biggest: %.2f", d[biggest]);

    return 0;
}
