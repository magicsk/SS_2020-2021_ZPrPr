void v(char*** name, int** stock, double** price, double** weight, int** goodsSupplierID, int** supplierID, char*** supplierName, char*** supplierAddress) {
    FILE* goods;
    FILE* suppliers;
    int goodsL;
    int suppliersL;

    goods = fopen("./goods.txt", "r");
    suppliers = fopen("./suppliers.txt", "r");

    // goods.txt
    if (goods != NULL) {
        *name = (char**)malloc(50 * 50 * sizeof(char));
        for (int i = 0; i < 50; i++) {
            (*name)[i] = (char*)malloc(50 * sizeof(char));
        }
        *stock = (int*)malloc(50 * sizeof(int));
        *price = (double*)malloc(50 * sizeof(double));
        *weight = (double*)malloc(50 * sizeof(double));
        *goodsSupplierID = (int*)malloc(50 * sizeof(int));

        goodsL = 0;
        while (!(ferror(goods) || feof(goods))) {
            fscanf(goods, "%s", name[0][goodsL]);
            fscanf(goods, "%d", &(*stock)[goodsL]);
            fscanf(goods, "%lf", &(*price)[goodsL]);
            fscanf(goods, "%lf", &(*weight)[goodsL]);
            fscanf(goods, "%d", &(*goodsSupplierID)[goodsL++]);
        }

        for (int i = 0; i < goodsL; i++) {
            printf("Name of goods: %s\nItems in stock: %2d\nPrice: %5.2lf\nWeight: %4.4lf\nSuplier ID: %2d\n\n",name[0][i], stock[0][i], price[0][i], weight[0][i], goodsSupplierID[0][i]);
        }
    } else {
        printf("Unable to open file goods.txt!\n");
    }

    printf("----------------------------------------------------------------------------------------\n----------------------------------------------------------------------------------------\n");

    // suppliers.txt
    if (suppliers != NULL) {
        *supplierID = (int*)malloc(50 * sizeof(int));
        *supplierName = (char**)malloc(50 * 50 * sizeof(char));
        for (int i = 0; i < 50; i++) {
            (*supplierName)[i] = (char*)malloc(50 * sizeof(char));
        }
        *supplierAddress = (char**)malloc(50 * 50 * sizeof(char));
        for (int i = 0; i < 50; i++) {
            (*supplierAddress)[i] = (char*)malloc(50 * sizeof(char));
        }

        suppliersL = 0;
        while (!(ferror(suppliers) || feof(suppliers))) {
            fscanf(suppliers, "%d", &(*supplierID)[suppliersL]);
            fscanf(suppliers, "%s\n", supplierName[0][suppliersL]);
            fgets(supplierAddress[0][suppliersL++], 1000, suppliers);
        }

        for (int i = 0; i < suppliersL; i++) {
            printf("Suplier ID: %2d\nSuplier name: %s\nSuplier address: %s\n\n", supplierID[0][i], supplierName[0][i], supplierAddress[0][i]);
        }
    } else {
        printf("Unable to open file suppliers.txt!\n");
    }
}