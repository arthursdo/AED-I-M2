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

    //ponteiros entrada
    char **pnome=aux+(sizeof(void*)*2);
    int *leituraIdade=aux+(sizeof(void*)*2)+sizeof(char*);
    int *leituraTelefone=aux+(sizeof(void*)*2)+sizeof(char*)+sizeof(int);
    void **prox=aux+sizeof(void*);
    void **ant=aux;
    *prox=NULL;
    *ant=NULL;

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

    incluir(aux, posicao(*pnome,agenda),agenda);

    /**
    void **agendaProximo;
    agendaProximo=agenda+sizeof(void*);
    while (*agendaProximo!=NULL){
        agendaProximo=*agendaProximo+sizeof(void*);
    }
    *agendaProximo=aux;
    **/
}

void Listar(void *buffer,const void *agenda){

    int *num=agenda;

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

int precedencia(const char *pala, const char *palb){
    if(pala[0]<palb[0]){
        return 1;
    }
    if(pala[0]>palb[0]){
        return 0;
    }
    if(pala[0]==palb[0]){
        return precedencia(pala + sizeof(char), palb + sizeof(char));
    }
}

void* posicao(const char *nome,const void *agenda){

    void **test=agenda+sizeof(void*);
    void **aux;
    void **prox=agenda+sizeof(void*);
    void *temp;

    if(*test!=NULL){
        char **pnome=NULL;
        do{
            prox=*prox+sizeof(void*);
            temp=prox;
            pnome=temp+sizeof(void*);
            if(precedencia(nome, *pnome)){
                temp=prox;
                aux=temp-sizeof(void*);
                return *aux;
            }
        } while (*prox!=NULL);
    } else{
        return NULL;
    }
    temp=prox;
    return temp-sizeof(void*);
}

void incluir(void *B, void *A, void *agenda){
    //null primeira inclusão
    //A -> nodo retornado(A)
    //B -> nodo a ser incluido
    //C -> nodo seguinte ao nodo A

    if(A != NULL){
        void **AProx=A+sizeof(void*); //pega proxima endereco do nodo anterior
        void **BProx=B+sizeof(void*);//pega proximo endereco do nodo sendo incluido

        if(*AProx != NULL){
            void **C=*AProx;
            *AProx=B;//atribui nodo atual como proximo do anterior
            *BProx=C;
            *C=B;
        }else{
            *AProx=B;
            *BProx=NULL;
        }

        void **BAnt=B;
        *BAnt=A;

    } else{
        void **BAnt=B;
        *BAnt=agenda;
        void **temp=agenda+sizeof(void*);
        *temp=B;
    }
}

void RemoverRegistro(void *agenda){
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
    printf("Nome a ser removido da lista\n");
    scanf("%s",str);
    void *aux;
    char **nome;

    while (*agendaProximo!=NULL){
        agendaProximo=*agendaProximo+sizeof(void*);
        aux=agendaProximo;
        nome=aux+sizeof(void*);

        if(!strcmp(str,*nome)){
            aux = nome;
            aux-=(sizeof(void*)*2);
            void **A=aux;
            aux=*A;
            A=aux+sizeof(void*);
            aux=nome;


            aux-=sizeof(void*);
            void **C=aux;
            if(*C!=NULL){
                C=*C;
                *A=C;
                aux=A;
                A=aux+sizeof(void*);
                *C=A;
            } else{
                *A=NULL;
            }

            aux=nome;
            aux-=(sizeof(void*)*2);

            free(*nome);
            free(aux);

            printf("Exlucao bem sucedida!\n");
            return;
        }
    }
    printf("Nome nao encontrado\n");

    free(str);
}
