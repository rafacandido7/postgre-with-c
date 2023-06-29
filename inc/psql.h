#ifndef PSQL_H_
#define PSQL_H_

#include "psql.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/opt/homebrew/opt/libpq/include/libpq-fe.h"

//! Essa struct é uma estrutura que armazena as informações necessárias para criar uma conexão com um banco de dados.
typedef struct _connectionInfo ConnectionInfo;

//! Essa função cria uma struct com as informações necessárias para a conexão do banco de dados utilizando a struct de informações.
ConnectionInfo* getConnectionInfo();

//! Função para mockar os dados de conexão
ConnectionInfo* mockConnectionInfo();

//! Essa função faz a conexão com o banco de dados e retorna o status da conexão.
PGconn* connectDB();

//! Essa função encerra a conexão com o banco de dados.
void closeConnection(PGconn* conn);

//! Essa função busca as tabelas públicas do banco de dados registrado.
PGresult* getTablesQuery(PGconn* conn);

//! Função que recebe a conexão do banco de dados e uma query, executa essa query nessa conexão e retorna.
PGresult* exeQuery(PGconn* conn, const char* query);

//! Verifica a criação da tabela
void verifyCreateTable(PGresult* result, PGconn* connection);

//! Pega as especificações de uma tabela,recebendo a conexão e o nome da tabela
PGresult* getTableSpecifications(PGconn* conn, const char* tableName);


/**
 * Insere dados em uma tabela do banco de dados.
 *
 * Solicita ao usuário que insira valores para cada campo da tabela, mostrando o nome e tipo correspondente.
 * Os valores inseridos são concatenados em uma query de inserção e executados no banco de dados.
 * Exibe mensagem de erro em caso de falha na inserção.
 */
void insertData(PGconn* conn, PGresult* res, const char* tableName);

#endif
