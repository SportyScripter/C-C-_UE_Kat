#include <stdio.h>
#include <stdlib.h> 

int* sort_table(int *begin, int *end) {
    int *p, *q;
    int temp;
    int *sorted_table = (int*)malloc((end - begin) * sizeof(int)); // Alokuje pamięć dla nowej tablicy

    // Kopiowanie danych z oryginalnej tablicy do nowej tablicy
    for (p = begin, q = sorted_table; p < end; p++, q++)
        *q = *p;

    // bubble sort 
    for (p = sorted_table; p < sorted_table + (end - begin) - 1; p++) {
        for (q = sorted_table; q < sorted_table + (end - begin) - 1; q++) {
            if (*q > *(q + 1)) {
                temp = *q;
                *q = *(q + 1);
                *(q + 1) = temp;
            }
        }
    }

    // return posortowanej tablicy 
    return sorted_table;
}


int binarySearch(int *array, int left, int right, int value) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Sprawdź, czy szukany element znajduje się w środku
        if (array[mid] == value)
            return mid;

        // Jeśli element jest mniejszy niż środek, to może być tylko w lewej podtablicy
        if (array[mid] > value)
            return binarySearch(array, left, mid - 1, value);

        // W przeciwnym razie element może być tylko w prawej podtablicy
        return binarySearch(array, mid + 1, right, value);
    }

    // Element nie został znaleziony
    return -1;
}

int main() {
    int table[10] = {5, 33, 6, 43, 12, 23, 7, 45, 3, 27};
    int *begin = table;  // wskaźnik na początek tablicy 
    int *end = table + sizeof(table) / sizeof(table[0]);  // wskaźnik na koniec tablicy

    printf("Original table: "); //wyprintowanie oryginalnej tablicy
    for (int *p = begin; p < end; p++)
        printf("%d ", *p);
    printf("\n");

    int *sorted_table = sort_table(begin, end); //wskaźnik do posortowanej tablicy 

    printf("Sorted table: ");
    for (int *p = sorted_table; p < sorted_table + (end - begin); p++)
        printf("%d ", *p);
    printf("\n");

    int target = 27;
    int result = binarySearch(sorted_table, 0, (sizeof(table) / sizeof(table[0]))-1, target);

      if (result != -1)
        printf("Element %d znaleziony na indeksie %d.\n", target, result);
    else
        printf("Element %d nie został znaleziony.\n", target);

    free(sorted_table); // Zwolnienie pamięci po tablicy

    return 0;
}
