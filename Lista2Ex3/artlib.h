#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int menu();
void *AdicionarRegistro(void *buffer);
void RemoverRegistro(char *buffer);
void Buscar(char *buffer);
void Listar(char *buffer);
int GetPSize();
void *BuscarSinal(char *buffer,char sinal);
int ChecaPopulacao(void *buffer);
void *IniciaPBuffer();

void test(char*buffer);
void carregar(void *buffer);