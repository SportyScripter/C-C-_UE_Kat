#include <stdio.h>

typedef struct {
    char * brand;
    char * model;
    int hp;
} (car);

void changehp(car * car1, int newhp){
    car1->hp = newhp;
}

int main(){
    car car1;
    car1.brand = "Fiat";
    changehp(&car1, 100);
    printf("%d\n", car1.hp);
}