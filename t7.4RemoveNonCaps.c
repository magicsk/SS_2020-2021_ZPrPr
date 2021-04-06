// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
int remove_small_letters(char* s){
    int removed = 0, i = 0,j = 0;
    while (s[i] != '\0'){
        if (s[i] >= 'a' && s[i] <= 'z'){
            removed++;
            s[i] = '\0';
        } else {
            s[j++] = s[i];
        }
        i++;
    }
    return removed;
}

int main(){
    char s[256];

    scanf("%s", s);

    int n = remove_small_letters(s);
    printf("String after adjustment: %s\n", s);
    printf("Removed %d characters.\n", n);

    return 0;
}