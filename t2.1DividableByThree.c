// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main(){
    int f, g;
    printf("Enter two numbers separated by space:\n");
    scanf("%d %d", &f, &g);

    for (int i = f; i <= g; i++){
        if (i%3 == 0){
            printf("%d ", i);
        }
    }
    
    return 0;
}
