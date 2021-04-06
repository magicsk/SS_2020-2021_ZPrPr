// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <string.h>

int find(char* s, char c) {
    if (*s == '\0') {
        return 0;
    } else if (*s == c) {
        return 0;
    } else {
        return 1 + find(s + 1, c);
    }
}

int main() {
    char s[256], c;
    int pos;

    while (!(strchr(s, '*')) || c != '*') {
        scanf("%s %c", s, &c);
        pos = find(s, c);
        if (strchr(s, '*') || c == '*') break;
        pos >= strlen(s) ? printf("Character %c is not in %s.\n",c ,s) : printf("Character %c is on position %d in %s.\n", c, pos, s);
    }

    return 0;
}