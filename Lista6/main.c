#include "ES.h"
#include "sort.h"
#include "tempo.h"

int main() {
    srand(time(NULL));

    if (0) {//solicitar tamanho e tal
        int *v = gerar(TAMANHO_VET, GMOD);
        printf("Vetor não ordenado:\n");
        imprimirVetor(v, TAMANHO_VET);

        v = quickSort(v, TAMANHO_VET);
        printf("Vetor ordenado:\n");
        imprimirVetor(v, TAMANHO_VET);
    } else {
        medir();
    }

    return 0;
}
