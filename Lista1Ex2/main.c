#include <locale.h>
#include "biblioteca.h"

int main()
{

    setbuf(stdout, 0);
    //char *nomes = (char *)malloc(sizeof(char));
    char *nomes = NULL;
    //int tam = 0;

    setlocale(LC_ALL, "Portuguese");

    // test();

    while (1)
    {
        switch (menu())
        {
        case 1:
            nomes=AdicionarNome(&nomes);
            break;
        case 2:
            RemoverNome();
            break;
        case 3:
            Listar(&nomes);
            break;
        case 4:
            exit(0);
            break;
        }
    }
}
