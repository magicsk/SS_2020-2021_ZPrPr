// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

long reverse(long n){
    long result = 0;
    while (n != 0){
        result = result * 10 + (n % 10);
        n = n/10;
    }
    
    return result;
}

int main(){
    long n[256];
    int s = 0;

    printf("Enter number to check for a palindrom:\n");
    while (scanf("%ld", &n[s]) == 1) {
        printf("%ld\n",n[s]);
        if (reverse(n[s]) == n[s]){
            printf("%ld is a palindrom.\n", reverse(n[s]));
        } else {
            printf("%ld is not a palindrom.\n", reverse(n[s]));
        }
        s++;
    }

    return 0;
}
