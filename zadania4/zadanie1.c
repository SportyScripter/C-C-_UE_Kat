#include <stdio.h>

int factorial(int a){
    if (a == 0){
        return 1;
    }
    return a * factorial(a-1);
}

int main(){
    int num =10;
   printf("Factorial of %d is %d\n", num, factorial(num));
}