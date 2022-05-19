#include "ES.h"
#include "sort.h"

int main() {
    srand(time(NULL));

    //opt
    //1-Aleatorio
    //2-Sequencial crescente
    //3-Sequencial decresente
    //4-Sequencial crescente embaralhado
    int opt = 4;
    int tamanho = 10;
    int *v;

    //solicitar tamanho e tal

    v = gerar(tamanho, opt);

    printf("Vetor não ordenado:\n");
    imprimirVetor(v, tamanho);

    v= merge(v,tamanho);


    printf("Vetor ordenado:\n");
    imprimirVetor(v, tamanho);

    return 0;
}
