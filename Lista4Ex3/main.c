#include "artlib.h"
#include "naofiz.h"


int main() {

    int teste[] = {20, 4, 3, 9, 26, 15};

    //case 3A @ https://stackoverflow.com/questions/3955680/how-to-check-if-my-avl-tree-implementation-is-correct
    int especial[] = {20,4,3,9,2,7,11,26,21,30};

    int nNodos = 19;
    Nodo *head = NULL;

    srand(time(NULL));

    printf("Quantos nodos a arvore deve ter:");
    scanf("%d", &nNodos);
    head = gerar(nNodos, head);

    //head= Teste(NULL, teste, 6);

    //imprimir(head);
    printf("\nA impressao acontece da esquerda para a direita");
    print2D(head);

    printf("\nEh avl? %s", (EhArvoreArvl(head)) ? "Sim" : "Não");
}
