#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//testar funços com parametro como void
int menu();
void AdicionarRegistro(char *buffer);
void RemoverRegistro(char *buffer);
void Buscar(char *buffer);
void Listar(char *buffer);
int GetPSize();
void *BuscarSinal(char *buffer,char sinal);

void test(char*buffer);
void carregar(void *buffer);