#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#define QUOTE_FLAG 0x001
#define MAX_LINE_LENGTH 4096

char *readline(FILE *file) {
  if (file == NULL) {
    return NULL;
  }
  char *line = (char *)malloc(sizeof(char)*MAX_LINE_LENGTH);
  if (line == NULL) {
    return NULL;
  }
  if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
    free(line);
    return NULL;
  }
  return line;
}
