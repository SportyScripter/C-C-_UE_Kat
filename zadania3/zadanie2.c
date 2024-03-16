#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main(){
    int a = 5;
    int **p = malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++){
        p[i] = malloc(a * sizeof(int));
        for (int j = 0; j <= a; j++) {
            p[i][j] = generateRandomNumber(1, 100);
        }
    }

    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++) {
            printf("%2d ", p[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < a; i++){
        free(p[i]);
    }
    free(p);

    printf("Memory has been freed\n");
 return 0;
}
    