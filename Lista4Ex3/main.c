#include "artlib.h"
#include "naofiz.h"


int main() {

    int teste[] = {20, 4, 3, 9, 26, 15};
    //head= Teste(NULL, teste, 6);

    int nNodos = 19;
    Nodo *head = NULL;

    srand(time(NULL));

    printf("Quantos nodos a arvore deve ter:");
    scanf("%d", &nNodos);
    head = gerar(nNodos, head);

    //imprimir(head);
    print2D(head);

    printf("\nEh avl? %s", (EhArvoreArvl(head)) ? "Sim" : "Não");
}
