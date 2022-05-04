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

Nodo *inserir(int valor, Nodo *head, int altura);
Nodo *gerar(int nNodos, Nodo *head);
Nodo *criarNodo(int valor, Nodo *head, int altura);
int FB(Nodo *head);
void imprimir(Nodo *head);
void print2DUtil(Nodo *head, int space);
void print2D(Nodo *head);
int EhArvoreArvl(Nodo *head);

#endif //LISTA4EX3_ARTLIB_H
