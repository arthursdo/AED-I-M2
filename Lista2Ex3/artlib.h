#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void menu(void *Buffer);
void AdicionarRegistro(char *buffer);
void RemoverRegistro(char *buffer);
void Buscar(char *buffer);
void Listar(char *buffer);
int GetPSize();
void *BuscarSinal(char *buffer,char sinal);
int ChecaPopulacao(void *buffer);

void test(char*buffer);
void carregar(void *buffer);