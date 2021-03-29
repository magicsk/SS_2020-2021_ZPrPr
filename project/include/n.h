void n(FILE** goods, FILE** suppliers, int** goodsLP, int** suppliersLP, char*** name, int** stock, double** price, double** weight, int** goodsSupplierID, int** supplierID, char*** supplierName, char*** supplierAddress) {
    int goodsL, suppliersL;

    // deallocation
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

    // goods.txt
    if (*goods != NULL) {
        rewind(*goods);

        *name = (char**)malloc(50 * 50 * sizeof(char));
        for (int i = 0; i < 50; i++) {
            (*name)[i] = (char*)malloc(50 * sizeof(char));
        }
        *stock = (int*)malloc(50 * sizeof(int));
        *price = (double*)malloc(50 * sizeof(double));
        *weight = (double*)malloc(50 * sizeof(double));
        *goodsSupplierID = (int*)malloc(50 * sizeof(int));
        *goodsLP = (int*)malloc(sizeof(int));

        goodsL = 0;
        while (!(ferror(*goods) || feof(*goods))) {
            fscanf(*goods, "%s", name[0][goodsL]);
            fscanf(*goods, "%d", &(*stock)[goodsL]);
            fscanf(*goods, "%lf", &(*price)[goodsL]);
            fscanf(*goods, "%lf", &(*weight)[goodsL]);
            fscanf(*goods, "%d", &(*goodsSupplierID)[goodsL++]);
        }

        *goodsLP = &goodsL;
        // printf("%d", **goodsLP); // 4
    }

    // suppliers.txt
    if (*suppliers != NULL) {
        rewind(*suppliers);

        *supplierID = (int*)malloc(50 * sizeof(int));
        *supplierName = (char**)malloc(50 * 50 * sizeof(char));
        for (int i = 0; i < 50; i++) {
            (*supplierName)[i] = (char*)malloc(50 * sizeof(char));
        }
        *supplierAddress = (char**)malloc(50 * 50 * sizeof(char));
        for (int i = 0; i < 50; i++) {
            (*supplierAddress)[i] = (char*)malloc(50 * sizeof(char));
        }
        *suppliersLP = (int*)malloc(sizeof(int));

        suppliersL = 0;
        while (!(ferror(*suppliers) || feof(*suppliers))) {
            fscanf(*suppliers, "%d", &(*supplierID)[suppliersL]);
            fscanf(*suppliers, "%s\n", supplierName[0][suppliersL]);
            fgets(supplierAddress[0][suppliersL++], 1000, *suppliers);
        }

        *suppliersLP = &suppliersL;
    }
    menu(goods, suppliers, goodsLP, suppliersLP, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
}