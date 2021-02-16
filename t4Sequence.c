// created by Rastislav Brna
// Licence is available on https://github.com/magicsk/ex03
// IDE: Visual Studio Code
// Compiler: gcc-9  args:-lm -fno-stack-protector

#include <stdio.h>
#include <math.h>

int main() {

    int n;

    printf("Enter a number:\n");
    scanf("%d", &n);

    int d[n];
    int isError = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter a number sequence: ");
        scanf("%d", &d[i]);
    }

 
    if (d[0] >= 0 && d[0] < 11 ) {
        for (int i = 1; i < 5; i++) {
            if(!(d[i] > 1) && ((d[i-1]*2) < d[i] || (d[i-1]/2.0) > d[i] )) {
                isError = 1;
                printf("Sequence is against the rules!");
                break;
            }
        }
    } else {
        isError = 1;
        printf("First number needs to be between 0 and 10!");
    }

    if (isError == 0) printf("Sequence meet the rules");

    return isError;
}
