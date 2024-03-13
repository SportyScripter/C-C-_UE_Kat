#include <stdio.h>

int main()
{
    char name[100]; 

    printf("Podaj imie:\n");
    scanf("%s", name);
    printf("Twoje imie to: %s\n", name);

    return 0;
}