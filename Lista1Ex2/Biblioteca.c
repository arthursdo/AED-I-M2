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
    int opt,busca=0,PosicaoFinal,PossicaoInicial;
    printf("Qual nome voce gostaria de remover?");
    Listar(nomes);
    scanf("%d",&opt);

    if(nomes[0] == '\0'){
        printf("Lista vazia!\n");
        return nomes;
    }

    int i=0;
    do{
        if(nomes[i++]=='$'){
            busca++;
        }
    } while (busca!=opt);

    char *tempFim=(char*) malloc(sizeof(char)*(strlen(nomes)-i)+2);
    tempFim=&nomes[i];
    //ate aqui funciona
    do{
        i--;
        if(nomes[i]=='$'){
            nomes[i]='\0';
        }
    } while (nomes[i]!='$');

    char *tempIni=(char*) malloc(sizeof(char)*(strlen(nomes)));
    tempIni=nomes;

    nomes=(char*) malloc((strlen(tempIni)+ strlen(tempFim))*sizeof(char));
    nomes[0]='\0';
    strcat(nomes,tempIni);
    strcat(nomes,tempFim);
    return nomes;
}
void Listar(char *nomes)
{
    if(nomes[0] == '\0'){
        printf("Lista vazia!\n");
    }else{
        int pos=1;
        printf("Nomes:\n%d - ",pos);
        for(int i=0;nomes[i]!='\0';i++){
            if(nomes[i]!='$'){
                printf("%c",nomes[i]);
            }
            else{
                if(nomes[i+1]=='\0'){
                    printf("\n");
                }else{
                    printf("\n%d - ",++pos);
                }
            }

        }
    }
    printf("\n");
}
