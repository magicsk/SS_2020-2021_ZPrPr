// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>

int main(){
    FILE *file;

    file = fopen("./t2.6Text.txt", "r");

    if (file != NULL){
        char temp;
        int count = 0;

        while (fscanf(file, "%c", &temp)) {

            if (temp == 120 || temp == 88) printf("I've read x\n");
            if (temp == 121 || temp == 89) printf("I've read y\n");
            if (temp == 35 || temp == 36 || temp == 38) printf("I've read control character\n");
            if (temp == 32) count++;
            if (temp == 42) break;
        }
        
        if (temp == 42) printf("The end\n");
        printf("Read spaces: %d\n", count);

        fclose(file);
    } else {
        printf("Error: Failed to read a file.\n");
    }

    return 0;
}
