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
void AdicionarRegistro(char *buffer){
    //Variavel auxiliar para leitura do nome
    char TempNome[15];
    printf("\nInsira um nome: ");
    scanf("%s", TempNome);
    strcat(TempNome,"$");

    //Variavel auxiliar para leitura da idade
    char TempIdade[4];
    printf("\nInsira uma idade: ");
    scanf("%s", TempIdade);
    strcat(TempNome,"*");

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
    int TempPSize=GetPSize();
    pSize+=sizeof(char)* strlen(TempConc);
    buffer= realloc(buffer, pSize+1);
    if(buffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    //Atualiza nPessoas
    int nPessoas;
    memcpy(&nPessoas,buffer,sizeof(int));
    nPessoas++;
    memcpy(buffer,&nPessoas,sizeof(int));

    buffer+=TempPSize;
    memcpy(buffer,&TempConc, strlen(TempConc)+1);

}

void RemoverRegistro(char *buffer){
    //salva primeiro endereço do ponteiro
    void *IniBuffer=buffer;

    //converte n pessoas pra int
    int nPessoas;
    memcpy(&nPessoas,buffer,sizeof(int));

    //testa se agenda já foi populada
    if(nPessoas==0){
        printf("Não foi encontrado nenhuma registro na agenda!\n");
        return;
    }

    //reproveitamento da função listar
    Listar(buffer);

    //reposiciona o ponteiro passando o primeiro int
    buffer+=sizeof(int);

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
            buffer=BuscarSinal(buffer,'@');
        }
        buffer+=sizeof(char);
    }

    //calcula posição do proximo @
    char *temp = BuscarSinal(buffer, '@');

    if(rem!=nPessoas) {
        temp+=sizeof(char);
        char *aux = (char *) malloc(strlen(temp) * sizeof(char) + 1);
        int strTam = strlen(temp);


        memcpy(aux, temp, strTam * sizeof(char) + 1);
        memcpy(buffer, aux, strTam * sizeof(char) + 1);

        free(aux);
    }else{
        temp[1]='\0';
    }


    nPessoas--;
    if(nPessoas!=0) {
        pSize = (strlen(IniBuffer + sizeof(int)) * sizeof(char)) + sizeof(int) + 1;
    } else{
        pSize=sizeof(int);
    }

    memcpy(IniBuffer,&nPessoas,sizeof(int));
    IniBuffer= realloc(IniBuffer,pSize);

}
void Buscar(char *buffer){
    printf("buscar\n");
}
void Listar(char *buffer){
    //converte n pessoas pra int
    int nPessoas;
    memcpy(&nPessoas,buffer,sizeof(int));

    //testa se agenda já foi populada
    if(nPessoas==0){
        printf("Não foi encontrado nenhuma registro na agenda!\n");
        return;
    }

    //reposiciona o ponteiro passando o primeiro int
    buffer+=sizeof(int);

    //impressão de cabeçario da função
    printf("\nForam encontrado(s) %d registro(s) na agenda:\n",nPessoas);
    nPessoas=1;
    printf("\n\t%d\t",nPessoas);

    //impressão dos dados
    for(int i=0;buffer[i]!='\0';i++){
        if(buffer[i]=='@'){
            if(buffer[i+1]=='\0'){
                printf("\n");
            }else {
                printf("\n\t%d\t",++nPessoas);
            }
        }
        else if(buffer[i]=='$' || buffer[i]=='*'){
            printf("\t");
        } else{
            printf("%c",buffer[i]);
        }
    }
    printf("\n \t\tFIM\n");
}

int GetPSize(){
    return pSize;
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

//apenas alguns testes com ponteiros
void test(char*buffer){
    printf("\n Address of a = %u ", buffer) ;
    buffer+=sizeof(int);
    printf("\n Address of a = %u ", buffer) ;
    printf("\n Value of a = %u ",  BuscarSinal(buffer,'@')) ;
    printf("\n Value of b = %c \n",  BuscarSinal(buffer,'@')) ;
}

//tentativa de facilitar os testes
void carregar(void *buffer){
    int i=3;
    memcpy(buffer,&i,sizeof(int));
    char string[]={"Arthur$53999748534@Isabele$5399796777@Caroline$5399919723@"};
    //+1 para o /0
    pSize= strlen(string)+sizeof(int)+1;
    buffer= realloc(buffer,pSize);

    //testa disponibilidade de memoria
    if(buffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }

    //move o ponteiro em para o inicio da string
    buffer+=sizeof(int);
    memcpy(buffer,&string,strlen(string)*sizeof(char));
}