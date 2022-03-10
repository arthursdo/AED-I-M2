#include "Biblioteca.h"



void menu() {
    int opt = 0;

    printf("Agenda massa, escolha uma opçãp\n");
    printf("\t 1-Adicionar nome\n");
    printf("\t 2-Remover nome\n");
    printf("\t 3-Listar\n");
    printf("\t 4-Sair\n");

    scanf("%d", &opt);
    

    switch (opt) {
        case 1:
            AdicionarNome();
            break;
        case 2:
            RemoverNome();
            break;
        case 3:
            Listar();
            break;
        case 4:
            exit(0);
            break;
    }
}

void AdicionarNome(){
    printf("AdicionarNome");
}
void RemoverNome(){
    printf("RemoverNome");
}
void Listar(){
    printf("Listar");
}

