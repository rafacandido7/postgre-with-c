#ifndef PSQL_H_
#define PSQL_H_

#include "psql.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/opt/homebrew/opt/libpq/include/libpq-fe.h"

typedef struct _connectionInfo ConnectionInfo;
ConnectionInfo* getConnectionInfo();

PGconn* connectDB();

#endif
