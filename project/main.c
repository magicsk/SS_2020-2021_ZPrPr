// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99 -I./include

#include <stdio.h>
#include <stdlib.h>

#include <v.h>
#include <o.h>
#include <n.h>
#include <s.h>
#include <h.h>
#include <p.h>
#include <z.h>

void k(FILE** goods, FILE** suppliers, int** goodsL, int** suppliersL, char*** name, int** stock, double** price, double** weight, int** goodsSupplierID, int** supplierID, char*** supplierName, char*** supplierAddress) {
    if (*stock != NULL) {
        free(*name);
        free(*stock);
        free(*price);
        free(*weight);
        free(*goodsSupplierID);
        free(*supplierID);
        free(*supplierName);
        free(*supplierAddress);
    }
    fclose(*goods);
    fclose(*suppliers);
    exit(0);
}

void menu(FILE** goods, FILE** suppliers, int** goodsL, int** suppliersL, char*** name, int** stock, double** price, double** weight, int** goodsSupplierID, int** supplierID, char*** supplierName, char*** supplierAddress) {
    char command;

    system("clear || cls");
    printf("[v] Read files and list of all values\n");
    printf("[o] Most expensive item by ID\n");
    printf("[n] Reallocate arrays\n");
    printf("[s] List supplier's goods by ID\n");
    printf("[h] Histogram of number of items in stock\n");
    printf("[p] Change the stock of an item\n");
    printf("[z] List items by size from interval <x, y>\n");
    printf("----------\n");
    printf("[k]Exit\n");
    printf("Enter a command: ");

    scanf("%c", &command);
    getchar();

    switch (command) {
    case 'v':
        v(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
        break;

    case 'o':
        o(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
        break;

    case 'n':
        n(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
        break;

    case 's':
        s(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
        break;

    case 'h':
        h(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
        break;

    case 'p':
        p(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
        break;

    case 'z':
        z(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
        break;

    case 'k':
        k(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
        break;

    default:
        menu(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);;
        break;
    }
}

int main() {
    FILE* goods;
    FILE* suppliers;

    int* goodsL;
    int* suppliersL;

    char** name;
    int* stock;
    double* price;
    double* weight;
    int* goodsSupplierID;

    int* supplierID;
    char** supplierName;
    char** supplierAddress;

    menu(&goods, &suppliers, &goodsL, &suppliersL, &name, &stock, &price, &weight, &goodsSupplierID, &supplierID, &supplierName, &supplierAddress);
    return 0;
}