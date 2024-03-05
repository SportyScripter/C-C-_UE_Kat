#include <stdio.h>

int main() {
    int grades[2][5] = {
        {5, 4, 3, 4, 5}, 
        {3, 4, 5, 2, 3}  
    };

    double sumMath = 0, sumPhysics = 0; 

    for(int i = 0; i < 5; i++) {
        sumMath += grades[0][i];
        sumPhysics += grades[1][i];
    }

    double avgMath = sumMath / 5;
    double avgPhysics = sumPhysics / 5;

    printf("Srednia ocen z matematyki: %.2f\n", avgMath);
    printf("Srednia ocen z fizyki: %.2f\n", avgPhysics);

    return 0;
}
