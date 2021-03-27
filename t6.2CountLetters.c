// writtern by Rastislav Brna
// Licence is available on https://github.com/magicsk/ex06
// IDE: Visual Studio Code
// Compiler: gcc-9  args:-lm

#include <stdio.h>

int main(){
    char fileName[50];
    char letters[25][256];
    int lineNum = 0;

    for (int q = 0; q <= 25; q++){
        for (int ql = 0; ql <= 20; ql++){
            letters[q][ql] = 0;
        }
    }
    

    // printf("Enter a file name:");
    // scanf("%s", fileName);

    // FILE *input = fopen(fileName, "r");
    FILE *input = fopen("t6.2File.txt", "r");

    if (input != NULL){
        char temp;
        int tempNum;

        //sorry fo ASCI numbers but its easier for me this way
        while (fscanf(input, "%c", &temp) != EOF) {
            // < 13 is looking for end of line 
            if (temp < 13) {
                lineNum++;
            // if it's a lowercase letter
            } else if (temp-97 >= 0) {
                tempNum = temp;
                tempNum -= 97;
                letters[tempNum][lineNum] += 1;
            // if it's an uppercase letter
            } else if (temp-65 >= 0) {
                tempNum = temp;
                tempNum -= 65;
                letters[tempNum][lineNum] += 1;
            }
        }

        for (int i = 0; i <= lineNum; i++){
            if (i == 0) {
                printf("   ");
                for (char l = 0; l <= 25; l++){
                    printf(" %c ", l+65);
                }
            }
            printf("\n%2d ", i+1);
            for (int j = 0; j <= 25; j++){
                printf("%2d ", letters[j][i]);        
            }
        }
        

        printf("\n");
        fclose(input);
    } else {
        printf("Error: Failed to read a file.\n");
        printf("Make sure that \"%s\" is in same folder as this program.", fileName);
    }

    return 0;
}
