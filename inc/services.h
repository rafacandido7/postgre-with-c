#ifndef SERVICES_H_
#define SERVICES_H_

#include "psql.h"
#include "helpers.h"
#include "/opt/homebrew/opt/libpq/include/libpq-fe.h"

//! Essa é a função responsável por iniciar o programa.
void start(void);
//! A função options recebe o status da conexão do banco de dados e da ao usuário as opções de execução do programa.
void options(PGconn* conn);

// void showTables(void);
// void showTableSpecifies(const char* table);
// void createNewTable(void);
// void insert(void);
// void showTable(void);
// void deleteRow(void);

// void insertIntoTable(const char * table, const char * values);
// void showTableDataWithFilters();

#endif
