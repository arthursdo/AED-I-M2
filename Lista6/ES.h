//
// Created by arthur on 19/05/22.
// Algoritimos de entrada e saida de dados
//

#ifndef LISTA5_ES_H
#define LISTA5_ES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "define.h"




int *gerar(int s, int opt);

int *PopularRdn(int *v, int s);

int *PopularSqc(int *v, int s);

int *PopularRvc(int *v, int s);

int *embaralhar(int *v, int s);

void imprimirVetor(int *v, int s);

void troca(int *a, int *b);

#endif //LISTA5_ES_H
