#ifndef SEMANA5_ARTLIB_H
#define SEMANA5_ARTLIB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

inline int cellsize();
int menu(void *buffer);
void AdicionarRegistro(void *agenda);
void Listar(void *buffer,const void *agenda);
void Buscar(const void *agenda);
int Precedencia(const char *pala,const char *palb);
S;
#endif //SEMANA5_ARTLIB_H
