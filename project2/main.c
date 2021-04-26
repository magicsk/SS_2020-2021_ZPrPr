// writtern by Rastislav Brna
// Source: https://github.com/magicsk/SS_2020-2021_ZPrPr
// IDE: Visual Studio Code
// Compiler: gcc  args: -lm -std=c99

// room No. 0 is not allowed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct guests {
    char* guestName;
    char* guestAddress;
    int reservationStart;
    int reservationEnd;
    struct guests* nextGuest;
} Guests;

typedef struct hotel {
    int roomID;
    int beds;
    double price;
    Guests* roomGuests;
    struct hotel* nextOne; // just 'next' slowing down intelliSense
} Hotel;

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    return (arg1 > arg2) - (arg1 < arg2);
}

int compare_ids(int* ids, int id) {
    int isTrue = 0;
    int i = 0;
    while (ids[i] != 0) {
        if (ids[i] == id) isTrue = 1;
        i++;
    }
    return isTrue;
}

int write(Hotel* myHotel) {
    FILE* fileHotel = fopen("./hotel.txt", "w");

    if (fileHotel == NULL) {
        return 1;
    } else {
        Hotel* tempHotel = myHotel;

        char startOfRoom[] = "---\n";
        char startOfGuest[] = "#\n";
        if (tempHotel == NULL) {
            return 1; // should never heppen
        } else {
            while (tempHotel != NULL) {
                fprintf(fileHotel, "%s", startOfRoom);
                fprintf(fileHotel, "%d\n", tempHotel->roomID);
                fprintf(fileHotel, "%d\n", tempHotel->beds);
                fprintf(fileHotel, "%.2lf\n", tempHotel->price);
                Guests* guestList = tempHotel->roomGuests;
                if (tempHotel == NULL) {
                    return 1; // should never heppen
                } else {
                    while (guestList != NULL) {
                        fprintf(fileHotel, "%s", startOfGuest);
                        fprintf(fileHotel, "%s", guestList->guestName);
                        fprintf(fileHotel, "%s", guestList->guestAddress);
                        fprintf(fileHotel, "%d\n", guestList->reservationStart);
                        fprintf(fileHotel, "%d\n", guestList->reservationEnd);
                        guestList = guestList->nextGuest;
                    }
                }
                tempHotel = tempHotel->nextOne;
            };
        }
    }
    fclose(fileHotel);
    return 0;
}

Hotel* n(Hotel* myHotel) {
    FILE* fileHotel = fopen("./hotel.txt", "r");

    if (fileHotel == NULL) {
        printf("Unable to read file 'hotel.txt'!");
    } else if (myHotel == NULL) {
        Guests* actualGuest = NULL;
        Guests* newGuest = NULL;

        Hotel* actualRoom = NULL;
        Hotel* newRoom = NULL;

        int i = 0;
        char* buff = (char*)malloc(100 * sizeof(char));
        char startOfRoom[] = "---\n";
        char startOfGuest[] = "#\n";
        while (!feof(fileHotel)) {
            newRoom = (Hotel*)malloc(sizeof(Hotel));
            fseek(fileHotel, -4, SEEK_CUR);
            fgets(buff, 100, fileHotel);
            if (!strcmp(buff, startOfRoom)) {
                fscanf(fileHotel, "%d", &(newRoom->roomID));
                fscanf(fileHotel, "%d", &(newRoom->beds));
                fscanf(fileHotel, "%lf\n", &(newRoom->price));
                fgets(buff, sizeof buff, fileHotel);
                actualGuest = newRoom->roomGuests;
                i++;
                while (!strcmp(buff, startOfGuest)) {
                    newGuest = (Guests*)malloc(sizeof(Guests));

                    fgets(buff, 100, fileHotel);
                    newGuest->guestName = buff;
                    buff = (char*)malloc(100 * sizeof(char));

                    fgets(buff, 100, fileHotel);
                    newGuest->guestAddress = buff;
                    buff = (char*)malloc(100 * sizeof(char));

                    fscanf(fileHotel, "%d", &(newGuest->reservationStart));
                    fscanf(fileHotel, "%d\n", &(newGuest->reservationEnd));
                    if (actualGuest == NULL) {
                        actualGuest = newGuest;
                        newRoom->roomGuests = actualGuest;
                    } else {
                        actualGuest->nextGuest = newGuest;
                        actualGuest = actualGuest->nextGuest;
                    }
                    fgets(buff, 100, fileHotel);
                }

            }
            actualRoom = myHotel;
            if (actualRoom == NULL) {
                actualRoom = newRoom;
                myHotel = actualRoom;
            } else {
                while (actualRoom->nextOne != NULL) {
                    actualRoom = actualRoom->nextOne;
                }
                actualRoom->nextOne = newRoom;
            }
        }

        actualGuest = NULL;
        newGuest = NULL;
        actualRoom = NULL;
        newRoom = NULL;
        free(buff);
        buff = NULL;
        printf("Loaded %d records.\n", i);
    } else {
        printf("Records already loaded.\n");
    }
    fclose(fileHotel);
    fileHotel = NULL;
    return myHotel;
}

Hotel* v(Hotel* myHotel) {
    if (myHotel == NULL) {
        myHotel = n(myHotel);
    }
    int tempids[100];
    int i = 0;


    Hotel* temp = myHotel;
    while (temp != NULL) {
        tempids[i++] = temp->roomID;
        temp = temp->nextOne;
    }
    int ids[i];
    for (int j = 0; j < i; j++) {
        ids[j] = tempids[j];
    }

    qsort(ids, i, sizeof(int), compare_ints);

    temp = myHotel;
    for (int j = 0; j < i; j++) {
        while (temp != NULL) {
            if (temp->roomID == ids[j]) {
                printf("Room ID: %d\n", temp->roomID);
                printf("Number of beds: %d\n", temp->beds);
                printf("Price: %.2lf\n", temp->price);
                Guests* guestList = temp->roomGuests;
                if (temp == NULL) {
                    printf("No guests!\n"); // shouldn't be there
                } else {
                    if (guestList != NULL) {
                        printf("Guest list:\n");
                        printf("Name: %s", guestList->guestName);
                        printf("Address: %s", guestList->guestAddress);
                        printf("Start of reservation: %d\n", guestList->reservationStart);
                        printf("End of reservation: %d\n", guestList->reservationEnd);
                        guestList = guestList->nextGuest;
                    }
                    while (guestList != NULL) {
                        printf("############################\n");
                        printf("Name: %s", guestList->guestName);
                        printf("Address: %s", guestList->guestAddress);
                        printf("Start of reservation: %d\n", guestList->reservationStart);
                        printf("End of reservation: %d\n", guestList->reservationEnd);
                        guestList = guestList->nextGuest;
                    }
                }
                if ((j + 1) < i) {
                    printf("----------------------------\n----------------------------\n");
                }
            }
            temp = temp->nextOne;
        }
        temp = myHotel;
    }
    return myHotel;
}

Hotel* r(Hotel* myHotel) {
    Guests* actualGuest = (Guests*)malloc(sizeof(Guests));
    Guests* newGuest;

    Hotel* actualRoom = (Hotel*)malloc(sizeof(Hotel));
    Hotel* newRoom;

    if (myHotel == NULL) {
        myHotel = n(myHotel);
    }

    int guestsInt;
    int tempRoomID = 0;
    char* buff;

    newRoom = (Hotel*)malloc(sizeof(Hotel));

    int ids[100] = { 0 };
    int i = 0;
    Hotel* temp = myHotel;
    while (temp != NULL) {
        ids[i++] = temp->roomID;
        temp = temp->nextOne;
    }

    do {
        printf("Room ID: ");
        scanf("%d", &tempRoomID);
    } while (compare_ids(ids, tempRoomID));

    newRoom->roomID = tempRoomID;
    printf("Number of beds: ");
    scanf("%d", &(newRoom->beds));
    printf("Price: ");
    scanf("%lf", &(newRoom->price));
    do {
        printf("Number of guests: ");
        scanf("%d", &guestsInt);
    } while (guestsInt > newRoom->beds);

    actualGuest = newRoom->roomGuests;

    for (int i = 0; i < guestsInt; i++) {
        newGuest = (Guests*)malloc(sizeof(Guests));

        buff = (char*)malloc(100 * sizeof(char));
        printf("Name of guest %d: ", i + 1);
        scanf(" %[^\n]", buff);
        strcat(buff, "\n");
        newGuest->guestName = buff;

        buff = (char*)malloc(100 * sizeof(char));
        printf("Address of guest %d: ", i + 1);
        scanf(" %[^\n]", buff);
        strcat(buff, "\n");
        newGuest->guestAddress = buff;

        printf("Reservation start of guest %d: ", i + 1);
        scanf("%d", &(newGuest->reservationStart));
        printf("Reservation end of guest %d: ", i + 1);
        scanf("%d", &(newGuest->reservationEnd));
        newGuest->nextGuest = NULL;
        if (actualGuest == NULL) {
            actualGuest = newGuest;
            newRoom->roomGuests = actualGuest;
        } else {
            actualGuest->nextGuest = newGuest;
            actualGuest = actualGuest->nextGuest;
        }
    }
    actualRoom = myHotel;
    if (actualRoom == NULL) {
        actualRoom = newRoom;
        myHotel = actualRoom;
    } else {
        while (actualRoom->nextOne != NULL) {
            actualRoom = actualRoom->nextOne;
        }
        actualRoom->nextOne = newRoom;
    }

    write(myHotel) ? printf("Something went wrong") : 0;

    return myHotel;
}

Hotel* z(Hotel* myHotel) {
    int toRemove;

    if (myHotel == NULL) {
        myHotel = n(myHotel);
    }

    int ids[100] = { 0 };
    int i = 0;
    Hotel* temp = myHotel;
    while (temp != NULL) {
        ids[i++] = temp->roomID;
        temp = temp->nextOne;
    }

    do {
        printf("Enter room ID for removal: ");
        scanf("%d", &toRemove);
        getchar();
    } while (!compare_ids(ids, toRemove));

    temp = myHotel;
    Hotel* temp2 = myHotel;

    for (int j = 0; j < i; j++) {
        if (temp->roomID == toRemove) {
            if (j == 0) {
                myHotel = temp->nextOne;
            } else {
                for (int k = 0; k < j - 1; k++) {
                    temp2 = temp2->nextOne;
                }
                free(temp->roomGuests->guestName);
                free(temp->roomGuests->guestAddress);
                free(temp->roomGuests);
                free(temp);
                temp2->nextOne = temp->nextOne;
            }
        }
        temp = temp->nextOne;
    }

    write(myHotel) ? printf("Something went wrong!\n") : printf("Reservation of room no. %d was canceled.\n", toRemove);
    return myHotel;
}

Hotel* h(Hotel* myHotel) {
    int date;
    int valid = 0;

    if (myHotel == NULL) {
        myHotel = n(myHotel);
    }

    printf("Enter date in format RRRRMMDD: ");
    scanf("%d", &date);
    getchar();

    Hotel* temp = myHotel;
    Guests* tempGuests;

    int i = 0;
    int ids[100] = { 0 };

    while (temp != NULL) {
        tempGuests = temp->roomGuests;
        while (tempGuests != NULL) {
            if (date >= tempGuests->reservationStart && date <= tempGuests->reservationEnd) {
                ids[i] = temp->roomID;
                valid = 1;
            }
            tempGuests = tempGuests->nextGuest;
        }
        temp = temp->nextOne;
        i++;
    }

    qsort(ids, i, sizeof(int), compare_ints);

    if (valid) {
        for (i = 0; i < 100; i++) {
            ids[i] > 0 ? printf("%d ", ids[i]) : 0;
        }
    } else {
        printf("There is no reservation to date %d.", date);
    }

    printf("\n");
    return myHotel;
}

Hotel* a(Hotel* myHotel) {
    int toChangeID, toChangeValue;

    if (myHotel == NULL) {
        myHotel = n(myHotel);
    }

    int ids[100] = { 0 };
    int i = 0;
    Hotel* temp = myHotel;
    while (temp != NULL) {
        ids[i++] = temp->roomID;
        temp = temp->nextOne;
    }

    do {
        printf("Enter room ID: ");
        scanf("%d", &toChangeID);
        printf("Enter new capacity: ");
        scanf("%d", &toChangeValue);

    } while (!compare_ids(ids, toChangeID));


    temp = myHotel;
    for (int j = 0; j < i; j++) {
        if (temp->roomID == toChangeID) {
            temp->beds = toChangeValue;
        }
        temp = temp->nextOne;
    }

    write(myHotel) ? printf("Something went wrong!\n") : printf("Room no. %d have room capacity %d.\n", toChangeID, toChangeValue);

    return myHotel;
}

void k(Hotel* myHotel) {
    Guests* guestList = NULL;
    Hotel* temp = myHotel;
    if (myHotel != NULL) {
        while (temp != NULL) {
            guestList = temp->roomGuests;
            while (guestList != NULL) {
                free(guestList->guestName);
                free(guestList->guestAddress);
                free(guestList);
                guestList = guestList->nextGuest;
            }
            free(temp);
            temp = temp->nextOne;
        }
        myHotel->roomGuests = NULL;
        myHotel->nextOne = NULL;
        myHotel = NULL;
    }
    exit(0);
}

int main() {
    Hotel* myHotel = NULL;
    char command;

    while (1) {
        system("clear || cls");
        printf("[n] Load records from file\n");
        printf("[v] List all rooms and reservations\n");
        printf("[r] Reservation of a room\n");
        printf("[z] Cancel reservation by room ID\n");
        printf("[h] List all reserved rooms in specific date\n");
        printf("[a] Update room capacity\n");
        printf("----------\n");
        printf("[k] Exit\n");
        printf("Enter a command: ");

        scanf("%c", &command);
        getchar();
        system("clear || cls");

        switch (command) {
        case 'n':
            myHotel = n(myHotel);
            getchar();
            break;

        case 'v':
            myHotel = v(myHotel);
            getchar();
            break;

        case 'r':
            myHotel = r(myHotel);
            getchar();
            break;

        case 'z':
            myHotel = z(myHotel);
            getchar();
            break;

        case 'h':
            myHotel = h(myHotel);
            getchar();
            break;

        case 'a':
            myHotel = a(myHotel);
            getchar();
            break;

        case 'k':
            k(myHotel);
            break;

        case 'x':
            k(myHotel);
            break;

        default:
            break;
        }
    }
    return 0;
}