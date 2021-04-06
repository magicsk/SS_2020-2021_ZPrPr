// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  

int wowels(char* word){
    int length = 0;
    for (int i = 0; i < 64; i++) {
        word[i] = tolower(word[i]);
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'y' ){
            length++;
        }
    }    
    return length;
}

int main(){
    char* word = (char*)malloc(64 * sizeof(char));
    int len[16] = { 0 };
    int i = 0, j = 0;
    char x;

    while ((x) = getchar()) {
        if (x == '\n') {
            len[j++] = wowels(word);
            break;
        } else if (x == ' ') {
            len[j++] = wowels(word);
            i = 0;
            word = NULL;
            word = (char*)malloc(64 * sizeof(char));
        } else {
            word[i++] = x;
        }
    }

    for (int i = 0; i < j; i++) {
        printf("%d\n", len[i]);
    }

    return 0;
}