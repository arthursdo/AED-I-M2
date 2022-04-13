#include "artlib.h"

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

void *AdicionarRegistro(void *buffer){
    int *num=buffer;
    buffer=realloc(buffer,gbh()+sizeof(Pessoa)*(num[0]+1));
    if(buffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    Pessoa *p=buffer+gbh()+(sizeof(Pessoa)*num[0]);
    char *leitura=buffer+2*sizeof(int);

    //leitura do nome
    fflush(stdin);
    printf("\nInsira um nome: ");
    scanf("%s",leitura );

    p->nome=NULL;
    p->nome=(char *)malloc((strlen(leitura)+1)*sizeof(char));
    if(p->nome==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }
    strcpy(p->nome,leitura);

    //leitura da idade
    fflush(stdin);
    printf("\nInsira uma idade: ");
    scanf("%d", &p->idade);

    //leitura da altura
    fflush(stdin);
    printf("\nInsira altura: ");
    scanf("%d", &p->altura);

    num[0]++;

    return buffer;
}

void* RemoverRegistro(void *buffer){
    int *num=buffer;
    Pessoa *p=NULL;

    Listar(buffer);
    //Solicita e trata a entrada do usuario
    printf("Qual registro voce gostaria de remover?");
    do
    {
        fflush(stdin);
        scanf("%d",&num[1]);
        if (num[1] < 1 || num[1] > num[0])
        {
            printf("opção invalida! Tente novamente\n");
        }
    } while (num[1] < 1 || num[1] > num[0]);

    Pessoa *p1=buffer+gbh()+sizeof(Pessoa)*(num[1]-1);
    Pessoa *p2=buffer+gbh()+sizeof(Pessoa)*(1+num[1]);

    memcpy(p1,p2,sizeof(Pessoa)*(num[0]-num[1]));

    num[0]--;

    buffer= realloc(buffer,gbh()+sizeof(Pessoa)*num[0]);
    if(buffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    return buffer;
}

void Listar(void *buffer){
    int *num=buffer;

    if(num[0]==0){
        printf("Não foi encontrado nenhuma registro na agenda!\n");
        return;
    }
    Pessoa *p=NULL;
    for(num[1]=0;num[1]<num[0];num[1]++){
        p=buffer+gbh()+sizeof(Pessoa)*num[1];
        printf("%d\t%s\t%d\t%d\n",num[1]+1,p->nome,p->idade,p->altura);
    }
}

void* Buscar(void *buffer){
    int *num=buffer;

    if(num[0]==0){
        printf("Não foi encontrado nenhuma registro na agenda!\n");
        return buffer;
    }
    Pessoa *p=NULL;
    char *nome=buffer+2*sizeof(int);
    fflush(stdin);
    printf("Qual nome voce esta buscando? ");
    scanf("%s",nome);

    for(num[1]=0;num[1]<num[0];num[1]++){
        p = buffer+gbh() + sizeof(Pessoa) * num[1];
        if(!strcmp(nome,p->nome)) {
            printf("%d\t%s\t%d\t%d\n", num[1] + 1, p->nome, p->idade, p->altura);
            num[1]=num[0];
        }
    }

    buffer= realloc(buffer,2*sizeof(int));
    if(buffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    return buffer;
}

int gbh(){
    return 2*sizeof(int)+30*sizeof(char);
}