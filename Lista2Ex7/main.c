#include <stdio.h>
#include "artlib.h"

int main() {
    setbuf(stdout, 0);
    void *pBuffer=NULL;
    pBuffer= malloc(2*sizeof(int));
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
                AdicionarRegistro(pBuffer);
                break;
            case 2:
                RemoverRegistro(pBuffer);
                break;
            case 3:
                Buscar(pBuffer);
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
