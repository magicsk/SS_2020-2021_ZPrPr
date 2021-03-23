// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main() {
    FILE* first;
    FILE* second;
    FILE* third;

    first = fopen("./t5.6First.txt", "r");
    second = fopen("./t5.6Second.txt", "r");
    third = fopen("./t5.6Third.txt", "w");

    if (first != NULL && second != NULL && third != NULL) {
        char temp[256];
        int i = 0;
        int f = 0;
        int s = 0;
        while (1) {
            i++;
            if (i % 2 == 0) {
                if (fscanf(second, "%s", temp) != EOF) {
                    fprintf(third, "%s ", temp);
                } else {
                    f++;
                }
            } else {
                if (fscanf(first, "%s", temp) != EOF) {
                    fprintf(third, "%s ", temp);
                } else {
                    s++;
                }
            }
            if (f > 0 && s > 0){
                break;
            }
        }
    } else {
        printf("Error: Failed to read/write a file.\n");
    }

    fclose(first);
    fclose(second);
    fclose(third);

    printf("Done\n");

    return 0;
}