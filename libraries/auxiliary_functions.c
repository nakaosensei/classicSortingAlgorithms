#include <stdio.h>
#include <stdlib.h>

int maior(int *vet, int tam){
    int i, maior = 0, indice = 0;
    for(i = 0; i < tam; i++){
        if(vet[i] > maior){
            maior = vet[i];
            indice = i; 
        }
    }
    return indice;
}


void troca(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}


int maximo(int *vet, int tam){
    if(tam == 0){
        return vet[tam];
    }
    else{
        int maior = maximo(vet, tam - 1);
        if(maior > vet[tam]){
            return maior;
        }
        else{
            return vet[tam];
        }
    }
}


int z(int n, int k){
    return ((n / k) % 10);
}