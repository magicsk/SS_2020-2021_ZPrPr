// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n3;
    // int n[malloc(sizeof int)];
    int* np;
    np = (int*) malloc(2*sizeof(int));

    printf("Enter 3 numbers separated by space:\n");
    scanf("%d %d %d", &np[0], &np[1], &n3);
    printf("%d + %d + %d = %d", np[0], np[1], n3, (np[0]+np[1]+n3));

    return 0;
}