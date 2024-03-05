#include <stdio.h>
int main() {
    int myltiplyArray  = 1;
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < 10; i++) {
        myltiplyArray *= array[i];
    }
    printf("Silnia wszystkich elementów wynosi: %d\n", myltiplyArray);
}
