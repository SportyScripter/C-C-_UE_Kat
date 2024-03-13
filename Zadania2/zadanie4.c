#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Student{
    char name[100];
    float finalGrade;
};

void SortStudentsByGrade(struct Student *students, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (students[j].finalGrade > students[j+1].finalGrade){
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}
int main(){
    srand(time(NULL));
    struct Student students[100] = {
        {"Jan", 4.5},
        {"Anna", 3.5},
        {"Piotr", 5.0},
        {"Kasia", 4.0},
        {"Marek", 3.0}
    };
    for(int i = 0; i < 100; i++) {
        sprintf(students[i].name, "Student %d", i + 1); 
         students[i].finalGrade = 2.0 + (rand() % (int)(5.0 - 2.0 + 1) * (1.0 / RAND_MAX));
    }
    SortStudentsByGrade(students, 100);
    for (int i = 0; i <100; i++) {
        printf("Student: %s, Final Grade: %.1f\n", students[i].name, students[i].finalGrade);
    }

    return 0;
}