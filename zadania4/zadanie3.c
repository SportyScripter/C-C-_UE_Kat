#include <stdio.h>

//wyswietlanie tablicy 
void printarray(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

//zamiana wartosci 
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//permutacja
void permutation(int *arr, int start, int end)
{
    if(start==end)
    {
        printarray(arr, end+1);
        return;
    }
    for(int i = start; i<=end; i++)
    {
        swap((arr+i), (arr+start));
    
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}

int main()
{
    
    int i;
    int arr[3] = {1,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    permutation(arr, 0, size-1);
    return 0;
}