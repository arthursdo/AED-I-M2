#include "artlib.h"

Pessoa pessoas[10];

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

void AdicionarRegistro(void *buffer){
    int *num=buffer;

    if(num[0]>9){
        printf("Maximo de entradas atingido!!\n");
        return;
    }

    Pessoa *p=pessoas+(sizeof(Pessoa)*num[0]);

    //leitura do nome
    fflush(stdin);
    printf("\nInsira um nome: ");
    scanf("%s",p->nome );

    //leitura da idade
    fflush(stdin);
    printf("\nInsira uma idade: ");
    scanf("%d", &p->idade);

    //leitura da altura
    fflush(stdin);
    printf("\nInsira altura: ");
    scanf("%d", &p->altura);

    num[0]++;
}

void RemoverRegistro(void *buffer){
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

    Pessoa *p1=pessoas+sizeof(Pessoa)*(num[1]-1);
    Pessoa *p2=pessoas+sizeof(Pessoa)*(1+num[1]);

    memcpy(p1,p2,sizeof(Pessoa)*(num[0]-num[1]));

    num[0]--;
}

void Listar(void *buffer){
    int *num=buffer;

    if(num[0]==0){
        printf("Não foi encontrado nenhuma registro na agenda!\n");
        return;
    }
    Pessoa *p=NULL;
    for(num[1]=0;num[1]<num[0];num[1]++){
        p=pessoas+sizeof(Pessoa)*num[1];
        printf("%d\t%s\t%d\t%d\n",num[1]+1,p->nome,p->idade,p->altura);
    }
}

void Buscar(void *buffer){
    printf("Buscar\n");
}