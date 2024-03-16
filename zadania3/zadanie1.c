#include <stdio.h> 
#include <stdlib.h> 

int factorial(int n) 
{ 
    if (n == 0) 
        return 1; 
    return n * factorial(n - 1); 
}
int calculate(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n - k));
}


  
int main() 
{ 
    // define memory for pascal_table
    printf("Enter the number of rows: ");
    int n;
    scanf("%d", &n);
    
    int **pascal_table = malloc(n * sizeof(int *));
    for (int i = 0 ; i<= n ; i++){
        pascal_table[i] = malloc((i+1) * sizeof(int));
    }

    // add vaule to pascal_table
    for (int line = 0; line <= n; line++) { 
        for (int i = 0; i <= line; i++) { 
            pascal_table[line][i] = calculate(line, i);
        } 
    }

    // print pascal_table
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= i; j++){
            printf("%d ", pascal_table[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i <= n; i++){
        free(pascal_table[i]);
    }
    free(pascal_table);

    return 0;
  
}