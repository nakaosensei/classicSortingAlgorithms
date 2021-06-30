#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct sorting_methods{
    void (*quick_sort) (int* vet, int tam);
    void (*merge_sort) (int* vet, int tam);
    void (*counting_sort) (int* vet, int tam);
    void (*radix_sort) (int* vet, int tam);
    void (*bucket_sort) (int * vet, int tam);
}SortingMethods;

SortingMethods sortingMethods();