#include <stdio.h>

int sumaWielokrotnosci(int limit) {
    int suma = 0;

    if (limit < 0) {
        return 0;
    }
    for (int i = 0; i < limit; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            suma += i; 
        }
    }
    return suma;
}

int main() {
    int limit;
    printf("Podaj limit: ");
    scanf("%d", &limit);
    int wynik = sumaWielokrotnosci(limit);
    printf("Suma wszystkich wielokrotności 3 lub 5 poniżej %d wynosi: %d\n", limit, wynik);

    return 0;
}
