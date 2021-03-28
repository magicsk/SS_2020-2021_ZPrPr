// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99 -I./include

#include <stdio.h>
#include <stdlib.h>

#include <v.h>

int main() {
    char** name;
    int* stock;
    double* price;
    double* weight;
    int* goodsSupplierID;

    int* supplierID;
    char** supplierName;
    char** supplierAddress;

    v(&name, &stock, &price, &weight, &goodsSupplierID, &supplierID, &supplierName, &supplierAddress);

    // printf("%s\n", &name[0][0]);
    // printf("%s\n", &supplierName[0][0]);
    // printf("%s\n", &supplierName[1][0]);
    // printf("%s\n", &supplierName[2][0]);
    // printf("%s", &supplierAddress[0][0]);
    // printf("%s", &supplierAddress[2][0]);
    // printf("%s\n", &name[3][0]);
    // printf("%d\n", supplierID[1]);

    return 0;
}