#include "Biblioteca.h"

int main()
{
    char *nomes=NULL;
    unsigned int tam=0,opt;

    //test();
    while (1) {

        opt=menu();

        switch (opt) {
            case 1:
                AdicionarNome(nomes, &tam);
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