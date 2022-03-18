#include "artlib.h"

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
        if (opt < 1 || opt > 6)
        {
            printf("opção invalida! Tente novamente\n");
        }
    } while (opt < 1 || opt > 6);
    return opt;
}
void AdicionarRegistro(char *buffer){
    int nPessoas;
    memcpy(&nPessoas,buffer,sizeof(int));

    //Variavel auxiliar para leitura do nome
    char TempNome[20];
    printf("\nInsira um nome: ");
    scanf("%s", TempNome);
    strcat(TempNome,"$");

    //Variavel auxiliar para leitura do Telefone
    char TempTel[20];
    printf("\nInsira um telefone: ");
    scanf("%s", TempTel);
    strcat(TempTel,"@");

    //Variavel auxiliar para concatenar as strings
    char TempConc[40];
    TempConc[0]='\0';
    strcat(TempConc,TempNome);
    strcat(TempConc,TempTel);

    //Realoca pBuffer
    int TempPSize=GetPSize();
    pSize+=sizeof(char)* strlen(TempConc);
    buffer= realloc(buffer, pSize+1);
    if(buffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }
    nPessoas++;
    memcpy(buffer,&nPessoas,sizeof(int));

    buffer+=TempPSize;
    memcpy(buffer,&TempConc, strlen(TempConc)+1);
}

void RemoverRegistro(char *buffer){
    Listar(buffer);

    //converte n pessoas pra int
    int nPessoas;
    memcpy(&nPessoas,buffer,sizeof(int));

    void *IniBuffer=buffer;
    //reposiciona o ponteiro passando o primeiro int
    buffer+=sizeof(int);

    //Solicita entrada do usuario
    int rem;
    printf("Qual registro voce gostaria de remover?");
    scanf("%d",&rem);

    //enconttra o primeiro @ na strring
    for(int i=0;i<rem-1;i++){
        buffer= BuscarSinal(buffer,'@');
    }

    char *temp=BuscarSinal(buffer+sizeof(char),'@');

    int pos=(temp-buffer)/sizeof(char);

    memcpy(buffer++,temp++,pos);

    nPessoas--;

    memcpy(IniBuffer,&nPessoas,sizeof(int));
    pSize-=(pos*sizeof(char));
    IniBuffer=realloc(IniBuffer,pSize);
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
        else if(buffer[i]=='$'){
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
   exit(2);
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
    int i=3,size,sizeB;
    char string[]={"Arthur$53999748534@Isabele$5399796777@Caroline$5399919723@"};
    //string[strlen(string)-1]='\0';
    size= strlen(string);
    sizeB=sizeof(char)*size;
    pSize=sizeB+sizeof(int);
    buffer= realloc(buffer,sizeB+sizeof(int));
    memcpy(buffer,&i,sizeof(int));
    buffer+=sizeof(int);
    memcpy(buffer,&string,sizeB);
}