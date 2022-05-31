//
// Created by arthur on 27/05/22.
//

#include "tempo.h"


void medir(){
    long tempos[IMPLEMENTADOS][QTD_TESTES];
    struct timespec inicio,fim;
    double medias[IMPLEMENTADOS];
    int *v=NULL;
    for (int i = 0; i < IMPLEMENTADOS; ++i) {
        for (int j = 0; j < QTD_TESTES; ++j) {
            v=gerar(TAMANHO_VET, GMOD);
            clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&inicio);
            escolha(j, v);
            clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&fim);
            tempos[i][j]=(fim.tv_sec - inicio.tv_sec)+(fim.tv_nsec - inicio.tv_nsec);
        }
        medias[i]= calcular(tempos[i]);
    }
    int mr=0;
    for (int i = 0; i < IMPLEMENTADOS-1; ++i) {
        if(medias[i+1]<medias[i]){
            mr=i+1;
        }
    }

    for (int i = 0; i < IMPLEMENTADOS; ++i) {
        printf("%.10lf %c\n",medias[i]*1e-9,(i==mr)?'<':' ');
    }
}

int *escolha(int esc,int *v){
    switch (esc) {
        case 0:
            return insertion(v, TAMANHO_VET);
            break;
        case 1:
            return selection(v, TAMANHO_VET);
            break;
        case 2:
            return mergeSorte(v, TAMANHO_VET);
            break;
        case 3:
            return quickSort(v, TAMANHO_VET);
            break;
    }
}

double calcular(long *tempos){
    double media;
    long long soma=0;

    for (int i = 0; i < QTD_TESTES; ++i) {
        soma+=tempos[i];
    }
    media= (long long)soma / (int)QTD_TESTES;
    return media;
}
