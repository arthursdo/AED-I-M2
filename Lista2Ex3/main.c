#include <locale.h>
#include "artlib.h"

int main() {
    //acentuação em PT
    setlocale(LC_ALL, "");
    //Ajuda a imprimir no terminar da minha IDE
    setbuf(stdout, 0);
    //Inicializa o ponteiro
    void *pBuffer=IniciaPBuffer();
    pBuffer=carregar(pBuffer);

    while (1)
    {
        switch (menu())
        {
            case 1:
                pBuffer=AdicionarRegistro(pBuffer);
                break;
            case 2:
                pBuffer=RemoverRegistro(pBuffer);
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
