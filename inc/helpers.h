#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/helpers.h"

//! Função responsável por dar cor a um printf
void print(char* text, char* color);

//! Faz uma comparação de strings e retorna um boolean
bool strIsEqual(const char *str1, const char *str2);

//! Printa uma linha com a cor escolhida
void printLine(char* color);
#endif

