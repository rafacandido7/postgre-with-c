#ifndef SERVICES_H_
#define SERVICES_H_

#include "psql.h"
#include "helpers.h"
#include "/opt/homebrew/opt/libpq/include/libpq-fe.h"

//! Essa é a função responsável por iniciar o programa.
void start(void);
//! A função options recebe o status da conexão do banco de dados e da ao usuário as opções de execução do programa.
void options(PGconn* conn);

/**
 * @brief Exibe a lista de tabelas do banco de dados.
 *
 * Executa uma consulta SQL para obter os nomes das tabelas do esquema "public" e exibe-os.
 *
 * @param conn Ponteiro para uma conexão com o banco de dados.
 *
 */
void showTables(PGconn* conn);

//! Recebe como parâmetro a conexão e o nome da tabela e printa na tela as colunas da tabela e as devidas especificações.
void showTableSpecifications(PGconn* conn, const char* tableName);

//! Cria uma nova tabela.
void createNewTable(PGconn* conn);
// void insert(void);
// void deleteRow(void);

// void insertIntoTable(const char * table, const char * values);
// void showTableDataWithFilters();

#endif
