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
        menu(pBuffer);
    }
}
