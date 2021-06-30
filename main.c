#include <time.h>
#include <stdlib.h>
#include "libraries/sorting_methods.h"

void print_vector(int* vector, int size){
    int i;
    printf("\n");
    for(i = 0; i < size; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int main(){
    int tam = 11;
    int v[] = {19, 1999, 2, 4, 89, 293, 30, 22, 1, 9, 500000};
    SortingMethods sm = sortingMethods();
    
    print_vector(v, tam);
    sm.radix_sort(v, tam);
    print_vector(v, tam);
    return 0;
}