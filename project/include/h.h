void h(FILE** goods, FILE** suppliers, int** goodsL, int** suppliersL, char*** name, int** stock, double** price, double** weight, int** goodsSupplierID, int** supplierID, char*** supplierName, char*** supplierAddress) {
    int fillter[10] = { 0 };

    if (*supplierID == NULL) {
        printf("Arrays not created!\n");
    } else {
        int i = 0;
        while (stock[0][i] != '\0') {
            if (stock[0][i] <= 9) {
                fillter[0]++;
            } else if (stock[0][i] <= 19) {
                fillter[1]++;
            } else if (stock[0][i] <= 29) {
                fillter[2]++;
            } else if (stock[0][i] <= 39) {
                fillter[3]++;
            } else if (stock[0][i] <= 49) {
                fillter[4]++;
            } else if (stock[0][i] <= 59) {
                fillter[5]++;
            } else if (stock[0][i] <= 69) {
                fillter[6]++;
            } else if (stock[0][i] <= 79) {
                fillter[7]++;
            } else if (stock[0][i] <= 89) {
                fillter[8]++;
            } else if (stock[0][i] <= 99) {
                fillter[9]++;
            }
            i++;
        }
        printf("<0,9>: %d\n<10,19>: %d\n<20,29>: %d\n<30,39>: %d\n<40,49>: %d\n<50,59>: %d\n<60,69>: %d\n<70,79>: %d\n<80,89>: %d\n<90,99>: %d\n", fillter[0], fillter[1], fillter[2], fillter[3], fillter[4], fillter[5], fillter[6], fillter[7], fillter[8], fillter[9]);
    }
    getchar();
    menu(goods, suppliers, goodsL, suppliersL, name, stock, price, weight, goodsSupplierID, supplierID, supplierName, supplierAddress);
}