#include <stdio.h>
int main() {
for (int i = 1; i <= 200; i++) {
    if (i%5==0 && i%7==0){
        printf("foobar\n");
    }
    else if (i%5==0){
        printf("foo\n");
    }
    else if (i%7==0){
        printf("bar\n");
    }
    else{
        printf("%d\n", i);
    }
}
}