//
// Created by arthur on 27/05/22.
//

#ifndef LISTA5_TEMPO_H
#define LISTA5_TEMPO_H

#include "sort.h"
#include "ES.h"

#define QTD_TESTES 10//Numero de vetores
#define TAMANHO_VET 5//tamanho dos vetores

void medir();

int *escolha(int esc, int *v);

double *calcular(void *_tempos);

#endif //LISTA5_TEMPO_H
