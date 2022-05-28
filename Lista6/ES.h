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

#define ALGO 3//Quantidade de algoritimos implementados;
#define VALOR_MAXIMO 100 //valor maximo a ser gerado nos numeros aleatorios
#define GMOD 4
//GMOD
//1-Aleatorio
//2-Sequencial crescente
//3-Sequencial decresente
//4-Sequencial crescente embaralhado


int *gerar(int s, int opt);

int *PopularRdn(int *v, int s);

int *PopularSqc(int *v, int s);

int *PopularRvc(int *v, int s);

int *embaralhar(int *v, int s);

void imprimirVetor(int *v, int s);

void troca(int *a, int *b);

#endif //LISTA5_ES_H
