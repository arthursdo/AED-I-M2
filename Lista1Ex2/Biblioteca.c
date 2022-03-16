#include "biblioteca.h"

int menu()
{
    printf("Agenda massa, escolha uma opção\n");
    printf("\t 1-Adicionar nome\n");
    printf("\t 2-Remover nome\n");
    printf("\t 3-Listar\n");
    printf("\t 4-Sair\n");

    int opt;
    do
    {
        fflush(stdin);
        scanf("%d", &opt);
        if (opt < 1 || opt > 4)
        {
            printf("opção invalida! Tente novamente\n");
        }
    } while (opt < 1 || opt > 4);
    return opt;
}

void AdicionarNome(char **nomes, int *tam)
{
    nomes = (char *)realloc((char *)*nomes, ++(*tam));
    if (nomes == NULL)
    {
        exit(69);
    }
    nomes[(*tam) - 1] = (char)malloc(sizeof(char) * 10 + 1);
    printf("\nQual o nome do FDP?%d",*tam);

    char temp[10];
    scanf("%s",temp);

    printf("ok");

    strcpy(&nomes[(*tam)-1],temp);
}
void RemoverNome()
{
    printf("RemoverNome\n");
}
void Listar(char **nomes, int *tam)
{
    printf("listar nomes\n");
    for (int i = 0; i < *tam; i++)
    {
        printf("%s\n", &nomes[i]);
    }
}
