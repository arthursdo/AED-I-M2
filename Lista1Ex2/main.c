#include <locale.h>
#include "biblioteca.h"

int main()
{

    char *nomes = NULL;
    int tam = 0,opt;

    setlocale(LC_ALL, "Portuguese");

    // test();

    while (1)
    {
        switch (menu())
        {
        case 1:
            AdicionarNome(&nomes, &tam);
            break;
        case 2:
            RemoverNome();
            break;
        case 3:
            Listar(&nomes, &tam);
            break;
        case 4:
            exit(0);
            break;
        }
    }
}
