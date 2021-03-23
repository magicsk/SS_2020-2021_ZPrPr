// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

#include <stdio.h>
#include <stdlib.h>

int numberOfLines(FILE* file) {
    char temp;
    int lines = 0;

    while ((temp = fgetc(file)) != EOF) {
        if (temp == '\n')
            lines++;
    }

    if (lines > 0) {
        return ++lines;
    } else {
        return lines;
    }
}

int compare(const void* a, const void* b) {
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    FILE* unordered;
    FILE* ordered;
    int lines;

    unordered = fopen("./t5.7Unordered.txt", "r");
    ordered = fopen("./t5.7Ordered.txt", "w");

    if (unordered != NULL && ordered != NULL) {
        lines = numberOfLines(unordered);
        rewind(unordered);
        double* uno = (double*)malloc(lines * sizeof(double));
        double* o = (double*)malloc(lines * sizeof(double));

        for (int i = 0; i < lines; i++) {
            fscanf(unordered, "%lf", &uno[i]);
            // printf("%lf\n", uno[i]);
        }

        for (int i = 0; i < lines; i++) {
            o[i] = uno[i];
        }

        qsort(o, lines, sizeof(double), compare);

        for (int i = 0; i < lines; i++) {
            fprintf(ordered, "%.2lf\n", o[i]);
        }
    } else {
        printf("Error: Failed to read/write a file.\n");

    }

    fclose(unordered);
    fclose(ordered);

    // printf("%d\n", lines);
    // printf("Done\n");

    return 0;
}