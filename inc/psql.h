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

#endif
