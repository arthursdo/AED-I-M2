//
// Created by arthur on 27/05/22.
//

#include "tempo.h"


void medir(){
    long tempos[IMPLEMENTADOS][QTD_TESTES];
    struct timespec inicio,fim;
    int *v=NULL;
    for (int i = 0; i < IMPLEMENTADOS; ++i) {
        for (int j = 0; j < QTD_TESTES; ++j) {
            v=gerar(TAMANHO_VET, GMOD);
            clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&inicio);
            v=escolha(j, v);
            clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&fim);
            tempos[i][j]=(fim.tv_sec - inicio.tv_sec)+(fim.tv_nsec - inicio.tv_nsec);
            imprimirVetor(v, TAMANHO_VET);
        }
    }
    double *media=calcular(tempos);

    for (int i = 0; i < IMPLEMENTADOS; ++i) {
        printf("%.10lf\n",media[i]*1e-9);
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
            return merge(v, TAMANHO_VET);
            break;
    }
}

double *calcular(void *_tempos){
    double media[IMPLEMENTADOS];
    long soma;
    long (*tempos)[QTD_TESTES]=_tempos;
    for (int i = 0; i < IMPLEMENTADOS; ++i) {
        soma=0;
        for (int j = 0; j < QTD_TESTES; ++j) {
            soma+=tempos[i][j];
        }
        media[i]= soma / QTD_TESTES;
    }
    double *tes=media;
    return tes;
}
