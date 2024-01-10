#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSV_PARSER_QUOTE_FLAG 0x001
#define CSV_PARSER_MAX_FIELDS 30
#define CSV_PARSER_MAX_FIELD_LEN 1024

/*
  Read a line from a file. Subsequent calls of this function on the same
  file will read its next lines until EOF.

  Returns NULL when file is a null file pointer
  Returns NULL when reach EOF

  @param file A pointer to a file.
  @returns `char *` containing the line read from the file. 
  Don't forget to `free`the result after usage.
*/
char *readline(FILE *file) {
  if (file == NULL) {
    return NULL;
  }
  char *line = (char *)malloc(sizeof(char)*CSV_PARSER_MAX_LINE_LENGTH);
  if (line == NULL) {
    return NULL;
  }
  if (fgets(line, CSV_PARSER_MAX_LINE_LENGTH, file) == NULL) {
    free(line);
    return NULL;
  }
  return line;
}

char **parseline(char *line, char* col_separator) {
    if (line == NULL) {
      return NULL;
    }
    char *col_sep = col_separator;
    if (col_sep == NULL) {
      col_sep = ",";
    }
    char **fields = malloc(CSV_PARSER_MAX_FIELDS * sizeof(char*));
    if (fields == NULL) {
      return NULL;
    }

    for (int i=0; i<CSV_PARSER_MAX_FIELDS; i++) {
      fields[i] = malloc(CSV_PARSER_MAX_FIELD_LEN * sizeof(char));
      if (fields[i] == NULL) {
        for (int j=0; j<i; j++) {
            free(fields[j]);
        }
        free(fields);
        return NULL;
      }
    }

    int flag = 0, current_index = 0;
    char *current_item = fields[0], current_char;

    if (current_item == NULL || current_char == NULL) {
      return NULL;
    }



    return fields;
}

void freeparsedline(char **line) {
  for (int i=0; i<CSV_PARSER_MAX_FIELDS; i++) {
    free(line[i]);
  }
  free(line);
}
