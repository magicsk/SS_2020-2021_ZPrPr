// writtern by Rastislav Brna
// Licence is available on https://github.com/magicsk/ex00
// IDE: Visual Studio Code
// Compiler: gcc-9  args:-lm

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
