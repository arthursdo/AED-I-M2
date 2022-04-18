#ifndef SEMANA5_ARTLIB_H
#define SEMANA5_ARTLIB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

inline int cellsize();
int menu(void *buffer);
void *AdicionarRegistro(void *buffer, void *agenda);
void Listar(void *buffer,const void *agenda);

#endif //SEMANA5_ARTLIB_H
