#include <stdio.h>
#include <stdlib.h>
#include "../inc/helpers.h"
#include "../inc/psql.h"
#include "../inc/services.h"
#include "/opt/homebrew/opt/libpq/include/libpq-fe.h"

void start() {
  print("socketPSQL.exe v1.0.0", "blue");

  PGconn* connection = connectDB();

  if (connection != NULL) {
    print("Connected!", "success");
    // options();
  } else {
    print("Erro ao conectar ao banco de dados, tente novamente!", "error");
  }

  return;
}

// void options(void) {
//   int loop = 0;

//   print("Options:", "blue");

//   while (loop != 0) {
//     print("0 - Encerrar programa", "blue");
//     print("1 - Exibir a lista de tabelas do BD", "blue");
//     print("2 - Exibir as especificações de campos e tipos de uma determinada tabela", "blue");
//     print("3 - Criar uma nova tabela\n", "blue");
//     print("4 - Exibir a lista de tabelas do BD", "blue");
//     print("5 - Exibir a lista de tabelas do BD", "blue");
//     print("6 - Exibir a lista de tabelas do BD", "blue");

//     scanf("%d", &loop);

//     if (loop == 0) {
//       print("Encerrando programa...", "success");
//       exit(1);
//       return;
//     }
//     if (loop == 1) {
//       showTables();
//       return;
//     }
//     if (loop == 2) {
//       char* table;
//       print("Qual o nome da tabela?", "blue");
//       scanf("%s", table);
//       showTableSpecifies(table);
//       return;
//     }
//     if (loop == 3) {
//       createNewTable();
//       return;
//     }
//     if (loop == 4) {
//       insert();
//       return;
//     }
//     if (loop == 5) {
//       showTable();
//       return;
//     }
//     if (loop == 6) {
//       deleteRow();
//       return;
//     }
//   }
// }

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
