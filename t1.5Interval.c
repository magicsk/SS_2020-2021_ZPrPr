// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main(){
    int n;

    printf("Enter a number:");
    scanf("%d", &n);

    if ( n < 1 || n > 15 ){
        printf("Number is not from interval!\n");
    } else {
        for (int i = 0; i < n; i++){
            printf("%d:   ", i+1);
            for (int d = n-i; d > 0; d--){
                printf("%d   ",d);
            }
            printf("\n");
        }
        
    }
    
    return 0;
}
