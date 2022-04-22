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

void AdicionarRegistro(void *agenda){

    //anterior,proximo,char,idade,telefone
    void *aux=malloc(cellsize());
    if(aux==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    //int *num=buffer;
    //ponteiros entrada
    char **pnome=aux+(sizeof(void*)*2);
    int *leituraIdade=aux+(sizeof(void*)*2)+sizeof(char*);
    int *leituraTelefone=aux+(sizeof(void*)*2)+sizeof(char*)+sizeof(int);
    void **prox=aux+sizeof(void*);
    *prox=NULL;

    char *nome=malloc(sizeof(char)*30);
    if(nome==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    //leitura do nome
    fflush(stdin);
    printf("\nInsira um nome: ");
    scanf("%s",nome);
    *pnome=realloc(nome, strlen(nome)+1);

    //leitura da idade
    fflush(stdin);
    printf("\nInsira uma idade: ");
    scanf("%d", leituraIdade);

    //leitura do telefone
    fflush(stdin);
    printf("\nInsira o Telefone: ");
    scanf("%d", leituraTelefone);

    /**
    if(num[0]==0){
        agenda=aux;
    } else{
        void **agendaProximo;
        agendaProximo=agenda+sizeof(void*);
        while (*agendaProximo!=NULL){
            agendaProximo=*agendaProximo+sizeof(void*);
        }
        *agendaProximo=aux;
    }*/

    /*
    void **agendaProximo;
    agendaProximo=agenda+sizeof(void*);
    while (*agendaProximo!=NULL){
        agendaProximo=*agendaProximo+sizeof(void*);
    }
    *agendaProximo=aux;*/

    void **agendaProximo,*temp,*ant;
    agendaProximo=agenda+sizeof(void*);

    while (*agendaProximo!=NULL){
        ant=agendaProximo;
        agendaProximo=*agendaProximo+sizeof(void*);
        temp=agendaProximo;
        if(Precedencia(pnome,temp+sizeof(void*))){
         *prox=*agendaProximo;
         void **pant=ant;
         void **pat=ant+sizeof(void*);

        }
    }
    *agendaProximo=aux;


    //num[0]++;
    //return agenda;
}
void Listar(void *buffer,const void *agenda){

    int *num=agenda;
    /**
    if(num[0]==0){
        printf("\nAgenda vazia\n");
        return;
    }**/

    void **agendaProximo=agenda+sizeof(void*);
    if(*agendaProximo==NULL){
        printf("\nAgenda vazia\n");
        return;
    }
    void *aux;
    char **nome;
    int *idade;
    int *telefone;
    num[0]=1;
    do{
        agendaProximo=*agendaProximo+sizeof(void*);
        aux=agendaProximo;
        nome=aux+sizeof(void*);
        aux=nome;
        idade=aux+sizeof(char*);
        aux=idade;
        telefone=aux+sizeof(int);
        printf("%d\t%s\t%d\t%d\n",num[0]++,*nome,*idade,*telefone);
    }while (*agendaProximo!=NULL);
}

void Buscar(const void *agenda){
    void **agendaProximo=agenda+sizeof(void*);
    if(*agendaProximo==NULL){
        printf("\nAgenda vazia\n");
        return;
    }

    char *str=malloc(30*sizeof(char));
    if(str==NULL){
        printf("\nERRO DE MEMORIA\n");
        return;
    }

    fflush(stdin);
    printf("Nome a ser buscado na lista\n");
    scanf("%s",str);
    void *aux;
    char **nome;

    while (*agendaProximo!=NULL){
        agendaProximo=*agendaProximo+sizeof(void*);
        aux=agendaProximo;
        nome=aux+sizeof(void*);

        if(!strcmp(str,*nome)){
            aux = nome;
            int *idade = aux + sizeof(char *);
            aux = idade;
            int *telefone = aux + sizeof(int);
            printf("\t%s\t%d\t%d\n", *nome, *idade, *telefone);
            return;
        }
    }
    printf("Nome nao encontrado\n");

    free(str);
}
int Precedencia(const char *pala,const char *palb){
    if((int)pala[0]<(int)palb[0]){
        return 0;
    }
    if((int)pala[0]>(int)palb[0]){
        return 1;
    }
    if((int)pala[0]==(int)palb[0]){
        return Precedencia(pala[1],palb[1]);
    }
}
