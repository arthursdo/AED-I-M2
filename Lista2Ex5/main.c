#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    int idade;
    int altura;
} Pessoa;

int main() {
    Pessoa *buffer=(Pessoa*) malloc(sizeof(Pessoa));

    if(buffer==NULL){
        printf("\nErro para alocar memoria!\n");
        exit(1);
    }

    char opt;
    int tam=0;
    printf("Super agenda infinita 2000\n\n");
    do{
        printf("\nInforme os dados\nNome: ");
        scanf("%s",buffer[tam].nome);
        fflush(stdin);
        printf("\nIdade: ");
        scanf("%d",buffer[tam].idade);
        fflush(stdin);
        printf("\nAltura em CM: ");
        scanf("%d",buffer[tam].altura);
        fflush(stdin);
        printf("\nVoce gostaria de adicionar mais uma pessoa? (s/n)\n");
        scanf("%c",&opt);
        fflush(stdin);
        tam++;
        buffer=(Pessoa*) realloc(buffer,tam*sizeof(Pessoa));
        if(buffer==NULL){
            printf("\nErro para alocar memoria!\n");
            exit(1);
        }

    } while (opt=='s'||opt=='S');

    printf("\ndados na memoria!!\n");

    for(int i=0;i<tam;i++){
        printf("%d\t%s\t%d\t%d\n",i+1,buffer[i].nome,buffer[i].idade,buffer[i].altura);
    }

}
