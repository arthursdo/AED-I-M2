#include "artlib.h"

int main() {
    setbuf(stdout, 0);
    void *pBuffer=NULL;
    pBuffer=malloc(gbh());
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
                pBuffer=AdicionarRegistro(pBuffer);
                break;
            case 2:
                pBuffer=RemoverRegistro(pBuffer);
                break;
            case 3:
                pBuffer=Buscar(pBuffer);
                break;
            case 4:
                Listar(pBuffer);
                break;
            case 5:
                exit(0);
                break;
        }
    }
}
