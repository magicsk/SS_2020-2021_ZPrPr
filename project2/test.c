#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Reprezentacia jednej polozky zretazeneho zoznamu
typedef struct nieco {
	int Pocet;
	struct nieco* next;
} Nieco;

typedef struct tovar {
	char* Nazov_tovaru;
	char* Nazov_vyrobcu;
	int Pocet_Kusov;
	float Cena_Kus;
	Nieco* uSZ_nieco;
	struct tovar* next;
} Tovar;

void vypis(Tovar* list) {
	//Tovar* tmp = list;
	if (list == NULL) {
		printf("\nZoznam je prazdny!");
	}
	else {
		do {
			printf("\n Nazov: %s", list->Nazov_tovaru);
			printf("\n Vyrobca: %s", list->Nazov_vyrobcu);
			printf("\n Pocet kusov: %d", list->Pocet_Kusov);
			printf("\n Cena za kus: %.3f", list->Cena_Kus);
			list = list->next;
		} while (list != NULL);
	}
}


int main() {
	char znak;
	char nazov[100], *pomchar;
	int cislo;
	float cislofloat;

	Tovar* Lidl = NULL;
	Tovar* tmp = (Tovar*)malloc(sizeof(Tovar));
	printf("Vytvorenie prazdneho zoznamu.\n");

	while (1) {
		printf("\n\nMenu\n p - pridanie\n o - odobranie\n v - vypis\n k - koniec \n");
		scanf(" %c", &znak);
		fflush(stdin);
		switch (znak) {
		case 'p': {
			// zaznam mam uz vytvoreny, pridavam na koniec   
			Tovar* pom_novy = (Tovar*)malloc(sizeof(Tovar));

			printf("\nZadaj nazov tovaru:");
			// gets(nazov);
			scanf(" %[^\n]s", nazov);                                   //nacitanie nazvu tovaru
			pomchar = (char*)malloc(strlen(nazov) * sizeof(char));   //vytvorim si miesto v pamati
			strcpy(pomchar, nazov);                                 //nakopirujem do pomocnej premennej     
			pom_novy->Nazov_tovaru = pomchar;							   //ukazovatel pridam do LL

			printf("\nZadaj nazov vyrobcu:");
			scanf(" %[^\n]s", &nazov);                                   //nacitanie nazvu tovaru
			pomchar = (char*)malloc(strlen(nazov) * sizeof(char));   //vytvorim si miesto v pamati
			strcpy(pomchar, nazov);                                 //nakopirujem do pomocnej premennej     
			pom_novy->Nazov_vyrobcu = pomchar;         				   //ukazovatel pridam do LL

			printf("\nZadaj pocet kusov tovaru:");
			//scanf(" %d", &cislo);
			//pom_novy->Pocet_Kusov = cislo;                         //nacitanie poctu kusov priamo do premennej
			scanf(" %d", &(pom_novy->Pocet_Kusov));

			printf("\nZadaj jednotkovu cenu tovaru:");
			scanf(" %f", &cislofloat);
			pom_novy->Cena_Kus = cislofloat;                         //nacitanie ceny priamo do premennej
			
			pom_novy->uSZ_nieco = NULL;
			pom_novy->next = NULL;

			
			for (int i = 0; i < 4; i++) {
				Nieco* pom_nieco = (Nieco*)malloc(sizeof(Nieco));
				pom_nieco->Pocet = i;
				pom_nieco->next = NULL;

				if (pom_novy->uSZ_nieco == NULL)
					pom_novy->uSZ_nieco = pom_nieco;
				else {
					Nieco* tmp ;
					tmp = pom_novy->uSZ_nieco;
					while (tmp->next != NULL)
						tmp = tmp->next;
					tmp->next = pom_nieco;
				}

					


			}






			tmp = Lidl;  // nemozem si prepisat ukazovatel na prvy zaznam !!!
			if (tmp == NULL) {
				tmp = pom_novy;
				Lidl = tmp;
			}
			else {
				while (tmp->next != NULL) {
					tmp = tmp->next;
				}
				tmp->next = pom_novy;  // mojmu listu priradim prvy zaznam
			}



		} break;
		case 'o': {
			printf("\nFunkciu nemam pripravenu!");
			vypis(Lidl);

		} break;
		case 'v': {

			tmp = Lidl;  // nemozem si prepisat ukazovatel na prvy zaznam !!!
			if (tmp == NULL) {
				printf("\nZoznam je prazdny!");
			}
			else {
				do {
					printf("\n Nazov: %s", tmp->Nazov_tovaru);
					printf("\n Vyrobca: %s", tmp->Nazov_vyrobcu);
					printf("\n Pocet kusov: %d", tmp->Pocet_Kusov);
					printf("\n Cena za kus: %.3f", tmp->Cena_Kus);
					tmp = tmp->next;
				} while (tmp != NULL);
			}


		} break;
		case 'k': {return(0); } break;
		default: printf("\nZla volba\n");


		}//koniec switchu

	} //koniec while
}