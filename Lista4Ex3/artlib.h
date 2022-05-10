//
// Created by arthur on 04/05/22.
//

#ifndef LISTA4EX3_ARTLIB_H
#define LISTA4EX3_ARTLIB_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 10
#define ValorMaximo 100

typedef struct nod{
    int altura;
    int valor;
    struct nod *esq;
    struct nod *dir;
}Nodo;

Nodo *inserir(int valor, Nodo *head);
Nodo *gerar(int nNodos, Nodo *head);
Nodo *criarNodo(int valor, Nodo *head);
Nodo * rotacaoD(Nodo *head);
Nodo * rotacaoE(Nodo *head);
int FB(Nodo *head);
int getValor(Nodo *head);

Nodo *Teste(Nodo *head, int *V, int nNodos);

#endif //LISTA4EX3_ARTLIB_H
