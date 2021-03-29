void n();

void o(FILE** goods, FILE** suppliers, int** goodsL, int** suppliersL, char*** name, int** stock, double** price, double** weight, int** goodsSupplierID, int** supplierID, char*** supplierName, char*** supplierAddress) {
    int enteredID;
    int filterredGoods[50];

    if (*goods != NULL && *suppliers != NULL) {
        printf("Enter supplier ID: ");
        scanf("%d", &enteredID);
        getchar();

        if (*supplierID == NULL) {
            n(name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
        }

        int i = 0, j = 0;
        while (goodsSupplierID[0][i] != '\0') {
            if (enteredID == goodsSupplierID[0][i]) {
                filterredGoods[j++] = i;
            }
            i++;
        }

        if (j == 1) {
            printf("The most expensive is: %s\n", name[0][filterredGoods[0]]);
        } else {
            i = 0;
            int temp = 0;
            for (i = 0; i < j; i++) {
                if (price[0][filterredGoods[i]] > price[0][filterredGoods[temp]]) {
                    temp = i;
                }
            }
            printf("The most expensive is: %s\n", name[0][filterredGoods[temp]]);
        }
    } else {
        printf("Files aren't opened!\n");
    }
    getchar();
    menu(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);

}