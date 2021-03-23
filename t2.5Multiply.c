// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main(){
    float x;
    FILE *file;

    file = fopen("./t2.5Multipliers.txt", "w");

    printf("Enter nubmer:\n");
    scanf("%f", &x);

    for (int i = 0; i <= 10; i++) {
        fprintf(file, "%2d * %.2f = %.2f\n", i, x, i*x);
    }

    fclose(file);
    

    return 0;
}
