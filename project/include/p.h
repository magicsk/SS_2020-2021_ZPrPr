#include <string.h>

void p(FILE** goods, FILE** suppliers, int** goodsLP, int** suppliersLP, char*** name, int** stock, double** price, double** weight, int** goodsSupplierID, int** supplierID, char*** supplierName, char*** supplierAddress) {
    char itemName[50];

    if (*supplierID == NULL) {
        printf("Arrays not created!\n");
    } else {
        printf("Enter name of item: ");
        scanf("%s", itemName);
        getchar();

        int q = 0;
        while (name[0][q] != NULL) {
            if (!strcmp(name[0][q], itemName)) {
                break;
            }
            q++;
        }

        if (q < 50) {
            do {
                printf("Enter number of items: ");
                scanf("%d", &stock[0][q]);
                getchar();
            } while (stock[0][q] > 99999);

            freopen("./goods.txt", "w", *goods);

            if (*goods != NULL) {
                for (int i = 0; i < **goodsLP; i++) {
                    fprintf(*goods, "%s\n", name[0][i]);
                    fprintf(*goods, "%d\n", (*stock)[i]);
                    fprintf(*goods, "%.2lf\n", (*price)[i]);
                    fprintf(*goods, "%.4lf\n", (*weight)[i]);
                    i == (**goodsLP - 1) ? fprintf(*goods, "%d", (*goodsSupplierID)[i]) : fprintf(*goods, "%d\n\n", (*goodsSupplierID)[i]);
                }
                printf("Current number of items in stocked of %s is: %d\n", name[0][q], stock[0][q]);
                freopen("./goods.txt", "r", *goods);
            } else {
                printf("File not opened!\n");
            }
        } else {
            printf("Item not found!\n");
        }
    }
    getchar();
    menu(goods, suppliers, goodsLP, suppliersLP, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
}