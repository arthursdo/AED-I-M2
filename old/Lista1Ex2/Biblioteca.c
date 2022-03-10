#include "Biblioteca.h"



unsigned int menu() {
    printf("Agenda massa, escolha uma opcao\n");
    printf("\t 1-Adicionar nome\n");
    printf("\t 2-Remover nome\n");
    printf("\t 3-Listar\n");
    printf("\t 4-Sair\n");

    unsigned int opt;
    do {
        scanf("%d", &opt);
        if(opt<1||opt>4){
            printf("opcao invalida! Tente novamente\n");
        }
    }while (opt<1||opt>4);
    return opt;

}

void AdicionarNome(char *nomes[], int *tam){
    char temp[10];
    printf("Informe o nome:");
    if (scanf("%s", temp)!=1)
        exit(1);
    nomes=(char*)malloc(++(*tam) * 10 * sizeof(char));
    if (nomes == NULL)
        exit(2);

    for (int i = *tam-10,j=0; i < tam; ++i,++j) {
            *nomes[i]=temp[j];
    }

}
void RemoverNome(){
    printf("RemoverNome\n");
}
void Listar(char* nomes){
    printf("\n%s\n",*nomes);
}

void test(){
    char temp;
    gets(temp);
    printf("%c",temp);
}
