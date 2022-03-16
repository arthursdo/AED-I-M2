#include <locale.h>
#include "biblioteca.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    setbuf(stdout, 0);

    char *nomes = (char *)malloc(sizeof(char)*2);
    nomes[0]='\0';

    while (1)
    {
        switch (menu())
        {
        case 1:
            nomes=AdicionarNome(nomes);
            break;
        case 2:
            nomes=RemoverNome(nomes);
            break;
        case 3:
            Listar(nomes);
            break;
        case 4:
            exit(0);
            break;
        }
    }
}
