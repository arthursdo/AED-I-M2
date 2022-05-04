#include "artlib.h"

int main() {

    int nNodos=19;
    Nodo *head=NULL;

    srand(time(NULL));

    printf("Quantos nodos a arvore deve ter:");
    //scanf("%d",&nNodos);

    head=gerar(nNodos,head);

    //imprimir(head);
    print2D(head);

    printf("\nEh avl? %s", (EhArvoreArvl(head))?"Sim":"Não");
}
