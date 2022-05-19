//
// Created by arthur on 04/05/22.
//

#include "artlib.h"

Nodo *Teste(Nodo *head, int *V, int nNodos) {
    for (int i = 0; i < nNodos; ++i) {
        head = inserir(V[i], head);
    }
    return head;
}

Nodo *gerar(int nNodos, Nodo *head) {
    for (int i = 0; i < nNodos; ++i) {
        head = inserir((rand() % ValorMaximo) + 1, head);
    }
    return head;
}

Nodo *inserir(int valor, Nodo *head) {
    if (head == NULL) {
        return criarNodo(valor, head);
    } else {
        if (valor == head->valor) {
            printf("\n Valor ja estat na lista");
        } else {
            if (valor > head->valor) {//direita
                head->dir = inserir(valor, head->dir);
                //head->altura = head->dir->altura + 1;
            } else {//esquerda
                //caso getValor seja menor
                head->esq = inserir(valor, head->esq);
                //head->altura = head->esq->altura + 1;
            }
        }

        head->altura = altura(head);

        //inclusão concluida
        int fb = FB(head);
        if (abs(fb) > 1) {
            //Arvora desbalanceada

            if (fb < -1) {
                //fb -1 Esquerda
                if (getValor(head) < getValor(head->esq)) {
                    //Direita esquerda
                    head->dir = rotacaoD(head->dir);
                    return rotacaoE(head);
                } else if (getValor(head) > getValor(head->esq)) {
                    //Simples a esquerda
                    return rotacaoE(head);
                }
            } else if (fb > 1) {
                //fb 1 Direita
                if (getValor(head) < getValor(head->dir)) {
                    //Esquerda Direita
                    head->esq = rotacaoE(head->esq);
                    return rotacaoD(head);
                } else {
                    //simples a Direita
                    return rotacaoD(head);
                }
            }
        }
        return head;
    }
}

Nodo *criarNodo(int valor, Nodo *head) {
    head = malloc(sizeof(Nodo));
    if (head == NULL) {
        printf("Erro de memoria");
        exit(1);
    }
    head->valor = valor;
    head->altura = 1;
    head->esq = NULL;
    head->dir = NULL;
    return head;
}

int FB(Nodo *head) {
    return ((head->esq != NULL) ? head->esq->altura : 0) - ((head->dir != NULL) ? head->dir->altura : 0);
}

Nodo *rotacaoD(Nodo *head) {
    if (head->esq != NULL) {
        Nodo *pEsc = head->esq;
        Nodo *pEDir = pEsc->dir;

        //rotacao
        pEsc->dir = head;
        head->esq = pEDir;

        //atualiza altura
        head->altura = altura(head);
        pEsc->altura = altura(pEsc);

        return pEsc;
    }
    return head;
}

Nodo *rotacaoE(Nodo *head) {
    if (head->dir != NULL) {

        Nodo *pDir = head->dir;
        Nodo *pDEsq = pDir->esq;

        //rotacao
        pDir->esq = head;
        head->dir = pDEsq;

        //atualiza altura
        head->altura = altura(head);
        pDir->altura = altura(pDir);

        return pDir;
    }
    return head;
}

int getValor(Nodo *head) {
    return (head != NULL) ? head->valor : 0;
}

int altura(Nodo *head) {

    if (head == NULL) {
        return 0;
    }

    return 1 + maior(altura(head->esq), altura(head->dir));
}

int maior(int a, int b) {
    return (a > b) ? a : b;
}
