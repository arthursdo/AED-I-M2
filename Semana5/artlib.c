#include "artlib.h"

int cellsize(){
    return (sizeof(int)*2)+(sizeof(char*))+(sizeof(void*)*2);
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

void *AdicionarRegistro(void *buffer, void *agenda){

    //anterior,proximo,char,idade,telefone
    void *aux=malloc(cellsize());
    if(aux==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    int *num=buffer;
    //ponteiros entrada
    char **pnome=aux+(sizeof(void*)*2);
    int *leituraIdade=aux+(sizeof(void*)*2)+sizeof(char*);
    int *leituraTelefone=aux+(sizeof(void*)*2)+sizeof(char*)+sizeof(int);
    void **prox=aux+sizeof(void*);
    *prox=NULL;

    char *nome=malloc(sizeof(char)*30);
    //*pnome=malloc(sizeof(char)*30);
    //if(&(*pnome)==NULL){
    if(nome==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    //leitura do nome
    fflush(stdin);
    printf("\nInsira um nome: ");
    scanf("%s",nome);
    *pnome=realloc(nome, strlen(nome)+1);
    //scanf("%s",*pnome);
    //*pnome=realloc(&(*pnome), strlen(&(*pnome))+1);

    //leitura da idade
    fflush(stdin);
    printf("\nInsira uma idade: ");
    scanf("%d", leituraIdade);

    //leitura do telefone
    fflush(stdin);
    printf("\nInsira o Telefone: ");
    scanf("%d", leituraTelefone);


    if(num[0]==0){
        agenda=aux;
    } else{
        void **agendaProximo;
        agendaProximo=agenda+sizeof(void*);
        while (*agendaProximo!=NULL){
            agendaProximo=*agendaProximo+sizeof(void*);
        }
        *agendaProximo=aux;
    }
    num[0]++;
    return agenda;
}
void Listar(void *buffer,const void *agenda){
    int *num=buffer;
    if(num[0]==0){
        printf("\nAgenda vazia\n");
        return;
    }

    void **agendaProximo=agenda+sizeof(void*);
    void *aux;
    char **nome;
    int *idade;
    int *telefone;
    num[1]=1;
    do{
        aux=agendaProximo;
        nome=aux+sizeof(void*);
        aux=nome;
        idade=aux+sizeof(char*);
        aux=idade;
        telefone=aux+sizeof(int);
        printf("%d\t%s\t%d\t%d\n",num[1]++,*nome,*idade,*telefone);
        agendaProximo=*agendaProximo+sizeof(void*);
    }while (*agendaProximo!=NULL);
}
