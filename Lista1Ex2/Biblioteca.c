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

char *AdicionarNome(char *nomes)
{
    int TamNomes=strlen(nomes);
    char *NomesTemp=(char *) malloc(sizeof(char)*TamNomes);
    NomesTemp[0]='\0';
    strcat(NomesTemp,nomes);

    char temp[10];
    printf("\nInsira um nome: ");
    scanf("%s", temp);
    strcat(temp,"$");


    int TamTemp=strlen(temp)+1;
    int NovoTamanho=(TamNomes+TamTemp)*sizeof(char);
    printf("");
    nomes=(char *) malloc(NovoTamanho);
    if(nomes==NULL){
        printf("Impossivel alocar memoria");
        exit(1);
    }

    nomes[0]='\0';
    strcat(nomes,NomesTemp);
    strcat(nomes,temp);
    //free(NomesTemp);
    return nomes;
}

char *RemoverNome(char *nomes)
{
    printf("RemoverNome\n");
}
void Listar(char *nomes)
{
    if(nomes[0] == '\0'){
        printf("Lista vazia!\n");
    }else{
        printf("Nomes:\n");
        for(int i=0;nomes[i]!='\0';i++){
            if(nomes[i]!='$'){
                printf("%c",nomes[i]);
            }
            else{
                printf("\n");
            }

        }
    }
    printf("\n");
}
