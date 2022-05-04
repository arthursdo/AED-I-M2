//
// Created by arthur on 04/05/22.
//

#include "artlib.h"

Nodo *gerar(int nNodos, Nodo *head) {
    for (int i = 0; i < nNodos; ++i) {
        head = inserir(rand() % ValorMaximo, head, 0);
    }
    return head;
}

Nodo *inserir(int valor, Nodo *head, int altura) {
    altura++;
    if (head == NULL) {
        return criarNodo(valor, head, altura);
    } else {
        if(valor==head->valor){
            printf("\n Valor ja estat na lista");
        }else {
            if (valor < head->valor) {
                head->esq = inserir(valor, head->esq, altura);
            }

            if (valor > head->valor) {
                head->dir = inserir(valor, head->dir, altura);
            }
        }
        return head;
    }
}

Nodo *criarNodo(int valor, Nodo *head, int altura) {
    head = malloc(sizeof(Nodo));
    if (head == NULL) {
        printf("Erro de memoria");
        exit(1);
    }
    head->valor = valor;
    head->altura = altura;
    head->esq = NULL;
    head->dir = NULL;
    return head;
}

int FB(Nodo *head) {
    if (head->esq == NULL && head->dir == NULL) {
        return 0;
    } else if (head->esq == NULL) {
        return 0-head->dir->valor;
    } else if (head->dir == NULL) {
        return head->esq->valor-0;
    } else{
        return head->esq->valor-head->dir->valor;
    }
}

/**
************************************
***DESSA LINHA PARA BAIXO NENHUMA***
***FOI ESCRITA POR MIM**************
************************************
**/

//Fonte: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(Nodo *head, int space) {
    // Base case
    if (head == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process dir child first
    print2DUtil(head->dir, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", head->valor);

    // Process esq child
    print2DUtil(head->esq, space);
}

// Wrapper over print2DUtil()
void print2D(Nodo *head) {
    // Pass initial space count as 0
    print2DUtil(head, 0);
}


//SLIDE AULA 8
int EhArvoreArvl(Nodo *head) {
    int fb;
    if (head == NULL)
        return 1;
    if (!EhArvoreArvl(head->esq))
        return 0;
    if (!EhArvoreArvl(head->dir))
        return 0;
    fb = FB(head);
    if ((fb > 1) || (fb < -1))
        return 0;
    else
        return 1;
}

