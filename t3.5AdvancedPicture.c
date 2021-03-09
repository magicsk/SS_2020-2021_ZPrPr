// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <math.h>

int main() {
    int odd;
    int width;
    int height;

    printf("Enter odd number, width, height:");
    scanf("%d %d %d", &odd, &width, &height);

    if (!(odd % 2)) {
        main();
    } else {
        for (int h = 0; h < height; h++) {
            int starOne = 0;
            int starTwo = odd - 1;
            int half = round(odd / 2);
            for (int i = 0; i < odd; i++) {
                if (i == half) {
                    for (int w = 0; w < width; w++) {
                        for (int j = 0; j < odd; j++) {
                            printf("*");
                        }
                    }
                    printf("\n");
                } else {
                    for (int w = 0; w < width; w++) {
                        for (int j = 0; j < half; j++) {
                            if (j == starOne || j == starTwo) {
                                printf("*");
                            } else {
                                printf(" ");
                            }
                        }
                        printf("*");
                        for (int j = half + 1; j < odd; j++) {
                            if (j == starOne || j == starTwo) {
                                printf("*");
                            } else {
                                printf(" ");
                            }
                        }
                    }
                    printf("\n");
                }
                starOne++;
                starTwo--;
            }
        }
    }
    return 0;
}