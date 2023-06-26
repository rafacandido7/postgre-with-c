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
  scanf("%s", info->host);

  printf("Informe a porta do banco de dados: ");
  scanf("%s", info->port);

  printf("Informe o nome do banco de dados: ");
  scanf("%s", info->database);

  printf("Informe o nome de usuário: ");
  scanf("%s", info->user);

  printf("Informe a senha: ");
  scanf("%s", info->password);

  return info;
}

PGconn* connectDB() {
  ConnectionInfo* connInfo = getConnectionInfo();
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
