#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Zajazd {
    int id;
    char* osoba;
    char* mesto;
    int rok_nar;
    int poc_dni;
};


typedef struct zajazd1 {
    int id;
    char* osoba;
    char* mesto;
    int rok_nar;
    int poc_dni;
}ZAJAZD1;


int main() {
    struct Zajazd z[10];
    int pozicia = 0;
    char buf[200];
    int id;

    printf("\nZadaj ID:");
    while (scanf("%d", &id) > 0) 	{
        if (id < 0) break;

        getchar();
        z[pozicia].id = id;
        printf("Zadaj meno-priezvysko-titul: ");
        fflush(stdin);
        fgets(buf, 200, stdin);
        z[pozicia].osoba = (char*)malloc(strlen(buf) * sizeof(char));
        buf[strlen(buf) - 1] = '\0';
        strcpy(z[pozicia].osoba, buf);

        printf("Zadaj Adresu: ");
        fflush(stdin);
        fgets(buf, 200, stdin);
        z[pozicia].mesto = (char*)malloc(strlen(buf) * sizeof(char));
        buf[strlen(buf) - 1] = '\0';
        strcpy(z[pozicia].mesto, buf);

        printf("Zadaj rok narodenia a pocet dni zajazdu: ");
        scanf("%d %d", &z[pozicia].rok_nar, &z[pozicia].poc_dni);

        (pozicia)++;
        printf("Zadaj ID:");
    }

    printf("\nZoznam ludi na zajazde.");
    printf("\nID \t Meno \t Adresa \t Rok_nar  Poc.Dni");
    for (int i = 0; i < pozicia; i++) {
        printf("\n%d \t %s \t %s \t %d  %d\n", z[i].id, z[i].osoba, z[i].mesto, z[i].rok_nar, z[i].poc_dni);
    }


    return 0;
}