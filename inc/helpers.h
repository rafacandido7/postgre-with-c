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

//! Função para pegar uma string do usuário
char* getString();

//! Função para poder limpar o buffer de entrada
void clearBuffer();

//! Função para poder pegar um inteiro do usuário
int getRowNumber();

//! Pega o nome e o tipo da coluna
void getColumns(char tableColumns[][2][100], int rowNumber);

//! Cria a query SQL
char* makeQuery(char* tableName, char tableColumns[][2][100], int fieldQuantity);

//! Cria a query SQL com os filtros necessários para o SELECT
char* buildQueryWithFilter(const char* tableName);

#endif

