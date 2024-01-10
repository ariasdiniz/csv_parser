#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#define MAX_LINE_LENGTH 4096

char *readline(FILE *file) {
  char *line = (char *)malloc(sizeof(char)*MAX_LINE_LENGTH);
  if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
    free(line);
    return NULL;
  }
  return line;
}
