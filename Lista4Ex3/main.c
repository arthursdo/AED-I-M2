#include "artlib.h"
#include "naofiz.h"


int main() {

    int teste[]={20,4,3,9,26,15};

    int nNodos=19;
    Nodo *head=NULL;

    srand(time(NULL));

    printf("Quantos nodos a arvore deve ter:");
    //scanf("%d",&nNodos);

    //head=gerar(nNodos,head);

    //head= Teste(NULL, teste, 6);

    head=inserir(20,head);
    print2D(head);
    head=inserir(4,head);
    print2D(head);
    head=inserir(3,head);
    print2D(head);
    head=inserir(9,head);
    print2D(head);
    head=inserir(26,head);
    print2D(head);
    head=inserir(15,head);


    //imprimir(head);
    print2D(head);

    printf("\nEh avl? %s", (EhArvoreArvl(head))?"Sim":"Não");
}
