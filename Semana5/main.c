//Cada pessoa tem nome[10], idade e telefone
//Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
//Implementar a base de dados da agenda usando lista duplamente ligada
// void *anterior,*proximo; char *nome; int telfone,idade;

#include "artlib.h"

int main() {
    setbuf(stdout, 0);
    void *agenda=NULL;
    void *pBuffer=NULL;
    pBuffer= malloc((2*sizeof(int))+(sizeof(char)*30));
    if(pBuffer==NULL){
        printf("\nERRO NA ALOCAÇÃO DE MEMORIA!\n");
        exit(1);
    }
    int *p=pBuffer;
    p[0]=0;
    while (1)
    {
        switch (menu(pBuffer))
        {
            case 1:
                agenda=AdicionarRegistro(pBuffer,agenda);
                break;
            case 2:
                //RemoverRegistro(pBuffer);
                break;
            case 3:
                //pBuffer=Buscar(pBuffer);
                break;
            case 4:
                Listar(pBuffer,agenda);
                break;
            case 5:
                exit(0);
                break;
        }
    }
}
