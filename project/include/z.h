int compare_ints(const void* a, const void* b) {
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;

    return (arg1 > arg2) - (arg1 < arg2);
}

void z(FILE** goods, FILE** suppliers, int** goodsL, int** suppliersL, char*** name, int** stock, double** price, double** weight, int** goodsSupplierID, int** supplierID, char*** supplierName, char*** supplierAddress) {
    double x, y;
    int q = 0, i;
    double filter[50] = { 0 };

    if (*supplierID == NULL) {
        printf("Arrays not created!\n");
    } else {
        do {
            printf("Enter to numbers to create an interval <x, y>: ");
            scanf("%lf", &x);
            scanf("%lf", &y);
            getchar();
        } while (x > y || x < 0);

        while (weight[0][q] != '\0') {
            if (weight[0][q] > x && weight[0][q] < y) {
                filter[q] = weight[0][q];
            }
            q++;
        }

        qsort(filter, 50, sizeof(double), compare_ints);

        for (q = 0; q < 50; q++) {
            for (i = 0; i < 50; i++) {
                if (filter[q] == weight[0][i] && filter[q] != 0) {
                    printf("%s\n", name[0][i]);
                }
            }
        }
    }
    getchar();
    menu(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
}