#include "ES.h"
#include "sort.h"
#include "tempo.h"

int main() {
    srand(time(NULL));

    if (0) {
        int opt = 3;
        // 0-Insertion/1-Selection/2-Merge/3-Quick

        int *v = gerar(TAMANHO_VET, GMOD);
        printf("Vetor não ordenado:\n");
        imprimirVetor(v, TAMANHO_VET);

        v = escolha(opt, v);

        printf("Vetor ordenado:\n");
        imprimirVetor(v, TAMANHO_VET);
    } else {
        medir();
    }

    return 0;
}
