#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/helpers.h"
#include "../inc/psql.h"
#include "/opt/homebrew/opt/libpq/include/libpq-fe.h"

struct _connectionInfo {
  char host[100];
  char port[10];
  char database[100];
  char user[100];
  char password[100];
};

ConnectionInfo* getConnectionInfo() {
  ConnectionInfo* info = malloc(sizeof(ConnectionInfo));

  printf("Informe o host do banco de dados: ");
  scanf("%99s", info->host);

  printf("Informe a porta do banco de dados: ");
  scanf("%9s", info->port);

  printf("Informe o nome do banco de dados: ");
  scanf("%99s", info->database);

  printf("Informe o nome de usuário: ");
  scanf("%99s", info->user);

  printf("Informe a senha: ");
  scanf("%99s", info->password);

  printf("\n");

  return info;
}

ConnectionInfo* mockConnectionInfo() {
  ConnectionInfo* info = malloc(sizeof(ConnectionInfo));

  strcpy(info->host, "localhost");
  strcpy(info->port, "5432");
  strcpy(info->database, "postgres");
  strcpy(info->user, "root");
  strcpy(info->password, "root");

  return info;
}

PGconn* connectDB() {
  // ConnectionInfo* connInfo = getConnectionInfo();
  ConnectionInfo* connInfo = mockConnectionInfo();
  PGconn* conn = PQsetdbLogin(connInfo->host, connInfo->port, NULL, NULL, connInfo->database, connInfo->user, connInfo->password);

  free(connInfo);

  if (PQstatus(conn) != CONNECTION_OK) {
    printf("Erro ao conectar ao banco de dados: %s\n", PQerrorMessage(conn));
    PQfinish(conn);
    return NULL;
  } else {
    return conn;
  }
}

void closeConnection(PGconn* conn) {
  PQfinish(conn);
  if (PQstatus(conn) != CONNECTION_OK) {
    print("Conexão encerrada com sucesso.", "success");
  } else {
    print("Erro ao encerrar a conexão do banco de dados!", "error");
  }
}

PGresult* getTablesQuery(PGconn* conn) {
  PGresult* result = PQexec(conn, "SELECT table_name FROM information_schema.tables WHERE table_schema = 'public';");
  return result;
}

PGresult* exeQuery(PGconn* conn, const char* query) {
  PGresult* result = PQexec(conn, query);
  return result;
}

PGresult* getTableSpecifications(PGconn* conn, const char* tableName) {
  char query[256];
  snprintf(query, sizeof(query), "SELECT column_name, data_type FROM information_schema.columns WHERE table_name = '%s';", tableName);

  PGresult* result = exeQuery(conn, query);
  return result;
}

void verifyCreateTable(PGresult* result, PGconn* connection) {
  if (PQresultStatus(result) == PGRES_COMMAND_OK) {
    print("Tabela criada com sucesso!", "success");
  } else {
    print("Erro ao criar a tabela: ", "error");
    print(PQerrorMessage(connection), "error");
  }
}

void insertData(PGconn* conn, PGresult* res, const char* tableName) {
  char query[500];
  snprintf(query, sizeof(query), "INSERT INTO %s VALUES (", tableName);

  int numColumns = PQntuples(res);

  for (int i = 0; i < numColumns; i++) {
    char value[100];

    printf("Informe o valor para o campo '%s' (%s): ", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1));
    scanf("%99s", value);
    clearBuffer();

    strcat(query, "'");
    strcat(query, value);
    strcat(query, "'");

    if (i < numColumns - 1) {
      strcat(query, ",");
    }
  }

  strcat(query, ");");

  PGresult* result = PQexec(conn, query);

  printf("\n");

  if (PQresultStatus(result) != PGRES_COMMAND_OK) {
    print("Erro ao inserir os dados: %s\n", "error");
    print(PQerrorMessage(conn), "error");
  } else {
    print("Dados adicionados com sucesso!", "success");
  }

  PQclear(result);
}
