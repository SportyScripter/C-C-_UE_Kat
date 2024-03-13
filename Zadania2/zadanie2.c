#include <stdio.h>

void duplikate (float *a)
{
    *a = *a * *a;
}

int main(){
    float a = 2.0;
    float *b = &a;
    printf("a: %f\n", a);
    printf("b: %d\n", b);
    duplikate(b);
    printf("a: %f\n", a);
    printf("b: %d\n", b);
    duplikate(b);
    printf("a: %f\n", a);
    printf("b: %d\n", b);

}