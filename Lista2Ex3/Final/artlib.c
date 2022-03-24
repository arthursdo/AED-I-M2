#include "artlib.h"

//tamanho em Bytes do buffer
int pSize=sizeof(int);

int menu()
{
    printf("Agenda massa, escolha uma opção\n");
    printf("\t 1-Adicionar registro\n");
    printf("\t 2-Remover registro\n");
    printf("\t 3-Buscar na agenda\n");
    printf("\t 4-Listar\n");
    printf("\t 5-Sair\n");

    int opt;
    do
    {
        fflush(stdin);
        scanf("%d", &opt);
        if (opt < 1 || opt > 5)
        {
            printf("opção invalida! Tente novamente\n");
        }
    } while (opt < 1 || opt > 5);

    return opt;
}
void *AdicionarRegistro(void *buffer){
    fflush(stdin);
    //Variavel auxiliar para leitura do nome
    char TempNome[15];
    printf("\nInsira um nome: ");
    scanf("%s", TempNome);
    strcat(TempNome,"$");

    //Variavel auxiliar para leitura da idade
    char TempIdade[4];
    printf("\nInsira uma idade: ");
    scanf("%s", TempIdade);
    strcat(TempIdade,"*");

    //Variavel auxiliar para leitura do Telefone
    char TempTel[20];
    printf("\nInsira um telefone: ");
    scanf("%s", TempTel);
    strcat(TempTel,"@");

    //Variavel auxiliar para concatenar as strings
    char TempConc[40];
    TempConc[0]='\0';
    strcat(TempConc,TempNome);
    strcat(TempConc,TempIdade);
    strcat(TempConc,TempTel);

    //Realoca pBuffer
    int TempPSize;
    if(pSize>sizeof(int)+sizeof(char)){
        TempPSize=pSize;
    } else{
        TempPSize=pSize-sizeof(char);
    }
    pSize=sizeof(int)+((strlen(TempConc)+ strlen(buffer+sizeof(int)))*sizeof(char));
    buffer=realloc(buffer, pSize);
    if(buffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    //Atualiza nPessoas
    int nPessoas;
    memcpy(&nPessoas,buffer,sizeof(int));
    nPessoas++;
    memcpy(buffer,&nPessoas,sizeof(int));
    char *aux=buffer+TempPSize;
    strcpy(aux,TempConc);
    return buffer;
}
void *RemoverRegistro(void *buffer){
    //converte n pessoas pra int
    int nPessoas= ChecaPopulacao(buffer);
    if(nPessoas==0){
        return buffer;
    }

    //Ponteiro auxiliar
    char *aux=buffer+sizeof(int);

    //reproveitamento da função listar
    Listar(buffer);

    //Solicita e trata a entrada do usuario
    int rem;
    printf("Qual registro voce gostaria de remover?");
    do
    {
        fflush(stdin);
        scanf("%d",&rem);
        if (rem < 1 || rem > nPessoas)
        {
            printf("opção invalida! Tente novamente\n");
        }
    } while (rem < 1 || rem > nPessoas);

    //caso queira remover a primeira entrada o ponteiro segue no mesmo endereço
    if(rem!=1){
        //enconttra o primeiro @ na strring
        for(int i=0;i<rem-1;i++){
            aux=BuscarSinal(aux,'@');
        }
        aux+=sizeof(char);
    }

    //calcula posição do proximo @
    char *temp = BuscarSinal(aux, '@');

    if(rem==1&&nPessoas==1) {
        temp[0] = '\0';
        temp[1] = '\0';
    } else if(rem!=nPessoas) {
        temp+=sizeof(char);
        char *aux2 = (char *) malloc(strlen(temp) * sizeof(char) + 1);

        strcpy(aux2,temp);
        strcpy(aux,aux2);

        free(aux2);
    } else if(rem==nPessoas){
        temp[1]='\0';
    }

    nPessoas--;
    if(nPessoas!=0) {
        pSize = (strlen(buffer + sizeof(int)) * sizeof(char)) + sizeof(int) + 1;
    } else{
        pSize=sizeof(int)+sizeof(char);
        //strcpy(buffer+sizeof(int),"\0");
    }

    buffer= realloc(buffer,pSize);
    if(buffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    memcpy(buffer,&nPessoas,sizeof(int));
    return buffer;
}
void Buscar(void *buffer){
    //converte n pessoas pra int
    int nPessoas= ChecaPopulacao(buffer);
    if(nPessoas==0){
        return;
    }

    //Variavel auxiliar para leitura do nome
    char TempNome[15];
    printf("\nInsira um nome que voce deseja encontrar");
    scanf("%s", TempNome);
    strcat(TempNome,"$");

    //realoca o ponteiro para o inicio da string
    buffer+=sizeof(int);

    char* local = strstr(buffer, TempNome);
    if(local==NULL){
        printf("Nao foi possivel encontrar o nome na agenda!\n");
        return;
    }
    int tam= ((int)BuscarSinal(local,'@')-(int)local)/sizeof(char);

    //impressão dos dados
    for(int i=0;i<tam;i++){
        if(local[i]=='@'){
            if(local[i+1]=='\0'){
                printf("\n");
            }else {
                printf("\n\t%d\t",++nPessoas);
            }
        }
        else if(local[i]=='$' || local[i]=='*'){
            printf("\t");
        } else{
            printf("%c",local[i]);
        }
    }
    printf("\n");

}
void Listar(void *buffer){
    //converte n pessoas pra int
    int nPessoas=ChecaPopulacao(buffer);
    if(nPessoas==0){
        return;
    }

    //reposiciona o ponteiro passando o primeiro int
    char *aux=buffer+sizeof(int);

    //impressão de cabeçario da função
    printf("\nForam encontrado(s) %d registro(s) na agenda:\n",nPessoas);
    nPessoas=1;
    printf("\t%d\t",nPessoas);

    //impressão dos dados
    for(int i=0;aux[i]!='\0';i++){
        if(aux[i]=='@'){
            if(aux[i+1]=='\0'){
                printf("\n");
            }else {
                printf("\n\t%d\t",++nPessoas);
            }
        }
        else if(aux[i]=='$' || aux[i]=='*'){
            printf("\t");
        } else{
            printf("%c",aux[i]);
        }
    }
    printf("\n \t\tFIM\n");
}
void *BuscarSinal(char *buffer,char sinal){
    //retorna o endereço no buffer do char solicitado
   for(int i=0;buffer[i]!='\0';i++) {
       if(buffer[i]==sinal){
           return &buffer[i];
       }
    }
   printf("Erro!");
   return NULL;
}
int ChecaPopulacao(void *buffer){
    //converte n pessoas pra int
    int nPessoas=65;
    memcpy(&nPessoas,buffer,sizeof(int));

    //testa se agenda já foi populada
    if(nPessoas==0){
        printf("Não foi encontrado nenhuma registro na agenda!\n");
    }

    return nPessoas;
}
void *IniciaPBuffer(){
    int nPessoas=0;
    pSize=sizeof(int)+sizeof(char);
    void *pBuffer= malloc(pSize);
    if(pBuffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }
    memcpy(pBuffer,&nPessoas,sizeof(int));
    char *ini=pBuffer+sizeof(int);
    ini[0]='\0';

    return pBuffer;
}

//tentativa de facilitar os testes
void *carregar(void *buffer){
    int i=3;
    memcpy(buffer,&i,sizeof(int));
    char string[]={"Arthur$23*53999748534@Isabele$23*5399796777@Caroline$23*5399919723@"};
    //+1 para o /0
    pSize= strlen(string)+sizeof(int)+sizeof(char);
    buffer=realloc(buffer,pSize);

    //testa disponibilidade de memoria
    if(buffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    //move o ponteiro em para o inicio da string
    //buffer+=sizeof(int);
    char *aux=buffer+sizeof(int);
    //memcpy(aux,string,strlen(string)*sizeof(char));
    strcpy(aux,string);

    return buffer;
}