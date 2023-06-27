#include <stdio.h>
#include <stdlib.h>
#include "../inc/helpers.h"
#include "../inc/psql.h"
#include "../inc/services.h"
#include "/opt/homebrew/opt/libpq/include/libpq-fe.h"

void start() {
  print("connPSQL.exe v0.0.3", "blue");

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

    printLine("blue");

    if (loop == 0) {
      print("Encerrando programa...", "success");
      closeConnection(conn);
    }
    if (loop == 1) {
      // showTables();
    }
    if (loop == 2) {
      char* table;
      // print("Qual o nome da tabela?", "blue");
      // scanf("%s", table);
      // showTableSpecifies(table);
    }
    if (loop == 3) {
      // createNewTable();
    }
    if (loop == 4) {
      // insert();
    }
    if (loop == 5) {
      // showTable();
    }
    if (loop == 6) {
      // deleteRow();
    }
  }
}

// void showTables() {
//   const char tables;
//   //show tables
// }

// void showTypesOfTable(const char * table) {
//   //show types of table
// }

// void insertIntoTable(const char * table, const char * values) {
//   //insert into table
// }

// void showTable() {
//   //show table
// }

// char* specifyColumn() {
//   // especificar colunas que serão mostradas na showTable
// }
