#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 20

struct Contact {
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    char phoneNumber[PHONE_LENGTH];
};

struct Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void AddContact(const char* firstName, const char* lastName, const char* phoneNumber) {
    if (contactCount >= MAX_CONTACTS) {
        printf("Ksiazka adresowa pelna!\n");
        return;
    }
    strncpy(contacts[contactCount].firstName, firstName, NAME_LENGTH);
    contacts[contactCount].firstName[NAME_LENGTH - 1] = '\0';
    strncpy(contacts[contactCount].lastName, lastName, NAME_LENGTH);
    contacts[contactCount].lastName[NAME_LENGTH - 1] = '\0';
    strncpy(contacts[contactCount].phoneNumber, phoneNumber, PHONE_LENGTH);
    contacts[contactCount].phoneNumber[PHONE_LENGTH - 1] = '\0';
    contactCount++;
    printf("Dodano kontakt.\n");
}

struct Contact* FindContact(const char* lastName) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}

void RemoveContact(const char* lastName) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].lastName, lastName) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            printf("Usunieto kontakt.\n");
            return;
        }
    }
    printf("Nie znaleziono kontaktu.\n");
}

void PrintContacts() {
    for (int i = 0; i < contactCount; i++) {
        printf("%s %s, %s\n", contacts[i].firstName, contacts[i].lastName, contacts[i].phoneNumber);
    }
}

int main() {
    char firstName[NAME_LENGTH], lastName[NAME_LENGTH], phoneNumber[PHONE_LENGTH],command[NAME_LENGTH];
    while (1) {
        printf("Komenda (dodaj, znajdz, usun, wyswietl, zakoncz): ");
        scanf("%49s", command);
        
        if (strcmp(command, "dodaj") == 0) {
            printf("Imie: ");
            scanf("%49s", firstName);
            printf("Nazwisko: ");
            scanf("%49s", lastName);
            printf("Numer telefonu: ");
            scanf("%19s", phoneNumber);
            AddContact(firstName, lastName, phoneNumber);
        } else if (strcmp(command, "znajdz") == 0) {
            printf("Nazwisko: ");
            scanf("%49s", lastName);
            struct Contact* found = FindContact(lastName);
            if (found != NULL) {
                printf("Znaleziono: %s %s, %s\n", found->firstName, found->lastName, found->phoneNumber);
            } else {
                printf("Nie znaleziono kontaktu.\n");
            }
        } else if (strcmp(command, "usun") == 0) {
            printf("Nazwisko do usuniecia: ");
            scanf("%49s", lastName);
            RemoveContact(lastName);
        } else if (strcmp(command, "wyswietl") == 0) {
            PrintContacts();
        } else if (strcmp(command, "zakoncz") == 0) {
            break;
        } else {
            printf("Nieznana komenda.\n");
        }
    }
    return 0;
}
