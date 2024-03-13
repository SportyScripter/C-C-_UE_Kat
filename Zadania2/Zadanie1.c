#include <stdio.h>

int main(){
    int a = 1;
    int *b = &a;
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    *b+=1;
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    *b+=1;
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    
}