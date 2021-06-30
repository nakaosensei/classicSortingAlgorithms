#include <stdio.h>
#include <stdlib.h>
#include "auxiliary_functions.h"
#include "sorting_methods.h"


void quick(int* vet, int esq, int dir){
    int pivo = vet[(esq + dir) / 2];
    int i = esq;
    int j = dir;
    while(i <= j){
        while(vet[i] < pivo && i < dir){
            i++;
        }
        while(vet[j] > pivo && j > esq){
            j--;
        } 
        if(i <= j){
            troca(&vet[i], &vet[j]);
            i++;
            j--;
        }
    }
    if(esq < j){
        quick(vet, esq, j);
    }
    if(dir > i){
        quick(vet, i, dir);
    }
}


void quick_sort(int* vet, int tam){
    quick(vet, 0, tam);
}


void merge(int* v, int tamanho){
    int *novo = (int*) calloc(tamanho, sizeof(int));
    int meio = tamanho / 2;
    int i = 0, j = meio, k = 0;
    while((i < meio) && (j < tamanho)){//junto os vetores
        if(v[i] < v[j]){
            novo[k++] = v[i++];
        }
        else{
            novo[k++] = v[j++];
        }
    }
    if(i == meio){//Caso ainda haja elementos na primeira metade
        while(j < tamanho){
            novo[k++] = v[j++];
        }
    }
    else{
        while(i < meio){ //Caso ainda haja elementos na segunda metade
            novo[k++] = v[i++];
        }
    }
    for(i = 0; i < tamanho; i++){//Move os elementos de volta para o vetor original
        v[i] = novo[i];
    }
    free(novo);
}


void merge_sort(int* v, int tam){
    if(tam >= 2){
        int meio = tam / 2;
        merge_sort(v, meio);
        merge_sort(v + meio, tam - meio);
        merge(v, tam);
    }
}


void counting_sort(int* vet, int tam){
    int maior = maximo(vet, tam);
    int vetorB[maior + 1];
    int vetorC[tam];
    int i;
    for(i = 0; i < maior + 1; i++){
        vetorB[i] = 0;
    }
    for(i = 0; i < tam; i++){
        vetorB[vet[i]]++;
        vetorC[i] = 0;
    }
    for(i = 1; i < maior + 1; i++){
        vetorB[i] = vetorB[i - 1] + vetorB[i];
    }
    for(i = tam - 1; i >= 0; i--){
        vetorB[vet[i]]--;
        vetorC[vetorB[vet[i]]] = vet[i];
    }
    for(i = 0; i < tam; i++){  
        vet[i] = vetorC[i];
    }
}

void radix_sort(int a[], int len){
    int bucket[10][len], bucket_cnt[10];
    int i, j, k, r, numberOperations = 0, divisor = 1, maxElement, pass;
    maxElement = maximo(a, len);
    while (maxElement > 0){//Conta numero de operações
        numberOperations++;
        maxElement /= 10;
    }
    for (pass = 0; pass < numberOperations; pass++){
        for (i = 0; i < 10; i++)
            bucket_cnt[i] = 0;//contador de elementos salvos por slot(0 a 9) na matrix auxiliar
        for (i = 0; i < len; i++){
            r = (a[i] / divisor) % len; //Pega o digito correto do numero em a[i]
            bucket[r][bucket_cnt[r]] = a[i];//Salva a[i] na posicao correta da matriz
            bucket_cnt[r] += 1;//delimita quantos elementos existem por indice na matriz
        }
        i = 0;
        for (k = 0; k < 10; k++){
            for (j = 0; j < bucket_cnt[k]; j++){
                a[i] = bucket[k][j];//Realoca vetor para proxima iteração
                i++;
            }
        }
        divisor *= 10;
    }
}

void insertion_sort(int* vet, int tam){
    int i, j;
    for(i = 1; i < tam; i++){
        int aux = vet[i];
        for(j = i - 1; j >= 0 && aux < vet[j]; j--){
            vet[j + 1] = vet[j];
        }
        vet[j + 1] = aux;
    }
}


void bucket_sort (int a[], int len){
    int bucket[10][len], bucket_cnt[10];
    int i, j, k, r, divisor = 10;      
    for (i = 0; i < 10; i++)
        bucket_cnt[i] = 0;//contador de elementos salvos por slot(0 a 9) na matrix auxiliar
    for (i = 0; i < len; i++){
        r = a[i] / divisor; //Pega o digito correto do numero em a[i]
        if (r<1)
            r=0;
        if (r>9)
            r=9;
        bucket[r][bucket_cnt[r]] = a[i];//Salva a[i] na posicao correta da matriz
        bucket_cnt[r] += 1;//delimita quantos elementos existem por indice na matriz
    }
    i = 0;
    for (k = 0; k < 10; k++){
        if (bucket_cnt[k]==0) continue;
        insertion_sort(bucket[k],bucket_cnt[k]);
        for (j = 0; j < bucket_cnt[k]; j++){          
            a[i] = bucket[k][j];//Armazena no array original
            i++;
        }
    }    
}
 

/**
 * method constructor
 *
 * @returns a new Sorting Methods
 */
SortingMethods sortingMethods(){
    SortingMethods new_SM;
    new_SM.quick_sort = &quick_sort;
    new_SM.merge_sort = &merge_sort;
    new_SM.counting_sort = &counting_sort;
    new_SM.radix_sort = &radix_sort;
    new_SM.bucket_sort = &bucket_sort;
    return new_SM;
}
