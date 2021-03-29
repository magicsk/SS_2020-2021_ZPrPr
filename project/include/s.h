void s(FILE** goods, FILE** suppliers, int** goodsL, int** suppliersL, char*** name, int** stock, double** price, double** weight, int** goodsSupplierID, int** supplierID, char*** supplierName, char*** supplierAddress) {
    int enteredID;
    int filterredGoods[50];

    if (*supplierID == NULL) {
        printf("Arrays not created!\n");
    } else {
        printf("Enter supplier ID: ");
        scanf("%d", &enteredID);
        getchar();
        
        int i = 0, j = 0;
        while (goodsSupplierID[0][i] != '\0') {
            if (enteredID == goodsSupplierID[0][i]) {
                filterredGoods[j++] = i;
            }
            i++;
        }

        for (i = 0; i < j; i++) {
            printf("%s (%d pcs in sock)\n", name[0][filterredGoods[i]], stock[0][filterredGoods[i]]);
        }
    }
    getchar();
    menu(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
}