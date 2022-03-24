#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int menu();
void *AdicionarRegistro(void *buffer);
void *RemoverRegistro(void *buffer);
void Buscar(void *buffer);
void Listar(void *buffer);
void *BuscarSinal(char *buffer,char sinal);
int ChecaPopulacao(void *buffer);
void *IniciaPBuffer();

void *carregar(void *buffer);