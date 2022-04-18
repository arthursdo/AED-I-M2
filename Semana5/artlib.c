#include "artlib.h"

int cellsize(){
    return (sizeof(int)*2)+(sizeof(char**))+(sizeof(void*)*2);
}

int menu(void *buffer) {
    printf("Agenda massa, escolha uma opção\n");
    printf("\t 1-Adicionar registro\n");
    printf("\t 2-Remover registro\n");
    printf("\t 3-Buscar na agenda\n");
    printf("\t 4-Listar\n");
    printf("\t 5-Sair\n");

    int *p=buffer;
    p[1]=0;
    do{
        fflush(stdin);
        scanf("%d", &p[1]);
        if (p[1] < 1 || p[1] > 5)
        {
            printf("opção invalida! Tente novamente\n");
        }
    } while (p[1] < 1 || p[1] > 5);

    return p[1];
}

void AdicionarRegistro(void *buffer, void *agenda){

    //anterior,proximo,char,idade,telefone
    void *aux=malloc(cellsize());
    if(aux==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    int *num=buffer;
    char *leituraNome=buffer+(sizeof(int)*2);
    char *nome=aux+(sizeof(void*)*2);
    char *nometemp=NULL;
    int *leituraIdade=nome+sizeof(char**);
    int *leituraTelefone=leituraIdade+sizeof(int);

    //leitura do nome
    fflush(stdin);
    printf("\nInsira um nome: ");
    scanf("%s",leituraNome );

    //leitura da idade
    fflush(stdin);
    printf("\nInsira uma idade: ");
    scanf("%d", leituraIdade);

    //leitura do telefone
    fflush(stdin);
    printf("\nInsira o Telefone: ");
    scanf("%d", leituraTelefone);

    nometemp=(char)malloc(sizeof(char)*(strlen(leituraNome)+1));
    //*nome=(char) calloc(strlen(leituraNome)+1,sizeof(char));
    printf("\nOK\n");
    if(nome==nometemp){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }
    *nome=&nometemp;
    strcpy(nome,leituraNome);


    num[0]++;
}
