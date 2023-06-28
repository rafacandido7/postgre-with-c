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
