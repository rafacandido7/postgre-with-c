#include "../inc/helpers.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

extern int errno;

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

void print(char *text, char *color) {
  if (strIsEqual(color, "success")) {
    printf("%s%s%s\n", GRN, text, RESET);
  } else if (strIsEqual(color, "error")) {
    printf("%s%s%s\n", RED, text, RESET);
  } else if (strIsEqual(color, "red")) {
    printf("%s%s%s\n", RED, text, RESET);
  } else if (strIsEqual(color, "green")) {
    printf("%s%s%s\n", GRN, text, RESET);
  } else if (strIsEqual(color, "yellow")) {
    printf("%s%s%s\n", YEL, text, RESET);
  } else if (strIsEqual(color, "blue")) {
    printf("%s%s%s\n", BLU, text, RESET);
  } else if (strIsEqual(color, "magenta")) {
    printf("%s%s%s\n", MAG, text, RESET);
  } else if (strIsEqual(color, "cyan")) {
    printf("%s%s%s\n", CYN, text, RESET);
  } else if (strIsEqual(color, "white")) {
    printf("%s%s%s\n", WHT, text, RESET);
  } else {
    printf("%s\n", text);
  }
  printf("\n");
  return;
}

bool strIsEqual(const char *str1, const char *str2) {
  bool res = strcmp(str1, str2) == 0 ? true : false;
  return res;
}

