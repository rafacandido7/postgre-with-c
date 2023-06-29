#include <stdio.h>
#include <stdlib.h>
#include "../inc/helpers.h"
#include "../inc/psql.h"
#include "../inc/services.h"
#include "/opt/homebrew/opt/libpq/include/libpq-fe.h"

void start() {
  print("connPSQL.exe v1.0", "blue");

  PGconn* connection = connectDB();

  if (connection != NULL) {
    print("Connected!", "success");
    printLine("success");
    options(connection);
  } else {
    print("Erro ao conectar ao banco de dados, tente novamente!", "error");
  }

  return;
}

void options(PGconn* conn) {
  int loop = -1;

  print("Options:", "blue");

  while (loop != 0) {
    print("0 - Encerrar programa", "blue");
    print("1 - Exibir a lista de tabelas do BD", "blue");
    print("2 - Exibir as especificações de campos e tipos de uma determinada tabela", "blue");
    print("3 - Criar uma nova tabela", "blue");
    print("4 - Inserir dados em uma tabela", "blue");
    print("5 - Exibir dados de uma tabela", "blue");
    print("6 - Remover os dados de uma tabela", "blue");

    scanf("%d", &loop);

    printLine("green");

    if (loop == 0) {
      print("Encerrando programa...", "success");
      closeConnection(conn);
    }
    if (loop == 1) {
      showTables(conn);
      printLine("green");
    }
    if (loop == 2) {
      char* table = getString();
      showTableSpecifications(conn, table);
      free(table);
      printLine("green");
    }
    if (loop == 3) {
      print("Criar Tabela", "green");
      createNewTable(conn);
      printLine("green");
    }
    if (loop == 4) {
      print("Inserir dados na tabela", "green");
      insert(conn);
    }
    if (loop == 5) {
      showTable(conn);
    }
    if (loop == 6) {
      delete(conn);
    }
  }
}

void showTables(PGconn* conn) {
  PGresult* result = getTablesQuery(conn);
  if (PQresultStatus(result) == PGRES_TUPLES_OK) {
    int rowsQuantity = PQntuples(result);

    if (rowsQuantity > 0) {
      print("Lista de tabelas:", "success");
      for (int i = 0; i < rowsQuantity; i++) {
        printf("- %s\n", PQgetvalue(result, i, 0));
      }
      printf("\n");
    } else {
      print("Não há tabelas no banco de dados.", "error");
    }
  } else {
    print("Erro ao executar a consulta:", "error");
    print(PQerrorMessage(conn), "error");
  }

  PQclear(result);
}

void showTableSpecifications(PGconn* conn, const char* tableName) {
  PGresult* result = getTableSpecifications(conn, tableName);

  if (PQresultStatus(result) == PGRES_TUPLES_OK) {
    int rowsQuantity = PQntuples(result);

    if (rowsQuantity > 0) {
      printf("Especificações da tabela '%s':\n", tableName);
      for (int i = 0; i < rowsQuantity; i++) {
        printf("- Campo: %s, Tipo: %s\n", PQgetvalue(result, i, 0), PQgetvalue(result, i, 1));
      }
    } else {
      const char error[100];
      snprintf(error, sizeof(error), "A tabela '%s' não foi encontrada.", tableName);

      print(error, "error");
    }
  } else {
    printf("Erro ao executar a consulta: %s\n", PQerrorMessage(conn));
  }

  PQclear(result);
}

void createNewTable(PGconn* conn) {
  char* tableName = getString();

  clearBuffer();

  int rowNumber = getRowNumber();

  print("Digite o nome dos campos e os tipos desses campos:", "green");

  char tableColumns[rowNumber][2][100];

  getColumns(tableColumns, rowNumber);

  char* query = makeQuery(tableName, tableColumns, rowNumber);

  PGresult* result = exeQuery(conn, query);

  verifyCreateTable(result, conn);

  PQclear(result);

  free(query);
  free(tableName);
}

void insert(PGconn* conn) {
  const char* tableName = getString();

  PGresult* res = getTableSpecifications(conn, tableName);

  int numColumns = PQntuples(res);

  insertData(conn, res, tableName);

  free(tableName);
}

void showTable(PGconn* conn) {
  const char* tableName = getString();

  print("Select", "green");

  const char* query = buildQueryWithFilter(tableName);

  print(query, "blue");

  PGresult* res = exeQuery(conn, query);

  displayQueryResult(res);

  free(query);
  free(tableName);
}

void delete(PGconn* conn) {
  const char* tableName = getString();

  print("Select", "green");

  const char* query = buildDeleteQueryWithFilter(tableName);

  print(query, "blue");

  PGresult* res = exeQuery(conn, query);

  checkDeleteResult(res);

  free(query);
  free(tableName);
}
