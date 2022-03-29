#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char nome[30];
    int idade;
    int altura;
} Pessoa;

int menu(void *buffer);
void AdicionarRegistro(void *buffer);
void RemoverRegistro(void *buffer);
void Buscar(void *buffer);
void Listar(void *buffer);