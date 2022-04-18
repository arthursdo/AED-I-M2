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

void *AdicionarRegistro(void *buffer, void *agenda){

    //anterior,proximo,char,idade,telefone
    void *aux=malloc(cellsize());
    if(aux==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    int *num=buffer;
    char *pnome=aux+(sizeof(void*)*2);
    char **nome=malloc(sizeof(char)*30);
    int *leituraIdade=aux+(sizeof(void*)*2)+sizeof(char**);
    int *leituraTelefone=leituraIdade+sizeof(int);
    void *prox=aux+sizeof(void*);
    prox=NULL;
    pnome=nome;

    if(nome==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    //leitura do nome
    fflush(stdin);
    printf("\nInsira um nome: ");
    scanf("%s",&(*nome));
    *pnome=realloc(&(*nome), strlen(&(*nome))+1);

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
        agenda= realloc(agenda,cellsize()*(num[0]+1));
        void **pt=agenda+(cellsize()*num[0])+sizeof(void*);
        pt=&aux;
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

    void *aux=agenda;
    void *prox;
    char *nome;
    int *idade;
    int *telefone;
    num[1]=1;

    do {
        prox=aux+sizeof(void*);
        nome=aux+(sizeof(void*)*2);
        idade=nome+sizeof(char**);
        telefone=idade+sizeof(int);
        aux=prox;

        printf("%d\t%s\t%d\t%d\n",num[1]++,&(*nome),idade,telefone);
    } while (prox!=NULL);
}
