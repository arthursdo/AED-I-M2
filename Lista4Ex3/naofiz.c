//
// Created by arthur on 04/05/22.
//

#include "naofiz.h"

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
    printf("%d-(%d)\n", head->valor,head->altura);

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
/**
void clear_screen()
{
    char buf[1024];
    char *str;

    tgetent(buf, getenv("TERM"));
    str = tgetstr("cl", NULL);
    fputs(str, stdout);
}**/