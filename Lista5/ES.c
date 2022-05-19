//
// Created by arthur on 19/05/22.
//
#include "ES.h"


int *gerar(int s, int opt) {
    int *v= (int*)malloc(s*sizeof(int));

    if(v=NULL){
        exit(18);
    }


    switch (opt) {
        case 1:
            return PopularRdn(v,s);
            break;
        case 2:
            return PopularSqc(v,s);
            break;
        case 3:
            return PopularRvc(v,s);
            break;
        case 4:
            return embaralhar(PopularSqc(v,s),s);
            break;
        default:
            printf("erro de escolha");
            exit(17);
    }
}

int *PopularRdn(int *v, int s) {
    //Popula o vetor com valores aleatorios
    for (int i = 0; i < s; ++i) {
        v[i]=rand()%max;
    }
    return v;
}

int *PopularSqc(int *v, int s){
    //Popula o vetor com valores crescentes
    for (int i = 0; i < s; ++i) {
        v[i]=i+1;
    }
    return v;
}
int *PopularRvc(int *v, int s){
    //Popula o vetor com valores decresentes
    for (int i = s; i > 0; --i) {
        v[i]=i;
    }
    return v;
}

int *embaralhar(int *v, int s){
    //embaralha o vetor;
    int temp,rnd;
    for (int i = 0; i < s; ++i) {
        rnd=rand()%s;
        temp=v[i];
        v[i]=v[rnd];
        v[rnd]=temp;
    }
    return v;
}

int imprimirVetor(int *v, int s){
    //imprime o vetor
    for (int i = 0; i < s; ++i) {
        printf("%d,",v[i]);
    }
    printf("\n");
}
