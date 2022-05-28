//
// Created by arthur on 27/05/22.
//

#include "tempo.h"


void medir(){
    long tempos[IMPLEMENTADOS][NTESTE];
    struct timespec inicio,fim;
    int *v=NULL;
    for (int i = 0; i < IMPLEMENTADOS; ++i) {
        for (int j = 0; j < NTESTE; ++j) {
            v=gerar(GMOD, TESTE_TAM);
            clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&inicio);
            escolha(j, v);
            clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&fim);
            tempos[i][j]=(fim.tv_sec - inicio.tv_sec)+(fim.tv_nsec - inicio.tv_nsec);
        }
    }
    double *media=calcular(tempos);
}

int *escolha(int esc,int *v){
    switch (esc) {
        case 0:
            return insertion(v, TESTE_TAM);
            break;
        case 1:
            return selection(v, TESTE_TAM);
            break;
        case 2:
            return merge(v, TESTE_TAM);
            break;
    }
}

double *calcular(void *_tempos){
    double media[IMPLEMENTADOS];
    long soma;
    long (*tempos)[NTESTE]=_tempos;
    for (int i = 0; i < IMPLEMENTADOS; ++i) {
        soma=0;
        for (int j = 0; j < NTESTE; ++j) {
            soma+=tempos[i][j];
        }
        media[i]=soma/NTESTE;
    }
    return media;
}
