#include <locale.h>
#include "artlib.h"

int main() {
    setlocale(LC_ALL, "");
    setbuf(stdout, 0);

    int nPessoas=0;

    void *pBuffer= malloc(GetPSize());
    memcpy(pBuffer,&nPessoas,sizeof(int));

    carregar(pBuffer);

    while (1)
    {
        switch (menu())
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
            case 6:
                carregar(pBuffer);
                break;
        }
    }
}
