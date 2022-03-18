#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//testar funços com parametro como void
int menu();
void AdicionarRegistro(char *buffer);
char *RemoverRegistro(void *buffer);
void Buscar(char *buffer);
void Listar(char *buffer);
int GetPSize();
void *BuscarSinal(char *buffer,char sinal);

void test(char*buffer);
