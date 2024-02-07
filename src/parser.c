#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Read a line from a file. Subsequent calls of this function on the same
  file will read its next lines until EOF.

  Returns NULL when file is a null file pointer
  Returns NULL when reach EOF

  @param file A pointer to a file.
  @returns `char *` containing the line read from the file. 
  Don't forget to `free`the result after usage.
*/
char *readline(FILE *file, char *line) {
  if (file == NULL) {
    return NULL;
  }
  line = line == NULL ? (char *)malloc(sizeof(char)*CSV_PARSER_MAX_LINE_LENGTH) : line;
  if (line == NULL) {
    return NULL;
  }
  if (fgets(line, CSV_PARSER_MAX_LINE_LENGTH, file) == NULL) {
    free(line);
    return NULL;
  }
  return line;
}

void allocateparsedarray(char **fields) {
  memset(fields, '\0', CSV_PARSER_MAX_FIELDS * sizeof(char*));

  for (int i = 0; i < CSV_PARSER_MAX_FIELDS; i++) {
    fields[i] = malloc(CSV_PARSER_MAX_FIELD_LEN * sizeof(char));
    if (fields[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(fields[j]);
      }
      free(fields);
    }
    memset(fields[i], '\0', CSV_PARSER_MAX_FIELD_LEN * sizeof(char));
  }
}

/*
  Parse a CSV line and return a pointer with each field.

  @param char *line The unparsed CSV line.
  @param char *col_separator The character separating the columns.
  
  @return char ** The pointer containing every separated field from the line.
*/
char **parseline(char *line, char* col_separator) {
  if (line == NULL) {
    return NULL;
  }
  char *col_sep = (col_separator == NULL) ? "," : col_separator;
  char **fields = malloc(CSV_PARSER_MAX_FIELDS * sizeof(char*));
  if (fields == NULL) {
    return NULL;
  }
  allocateparsedarray(fields);
  int flag = 0, current_index = 0, field_index = 0;
  char *current_item = fields[0];

  for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
    if (line[i] == '\"' && !flag) {
      flag |= CSV_PARSER_QUOTE_FLAG;
    } else if (line[i] == '\"' && flag) {
      flag &= ~CSV_PARSER_QUOTE_FLAG;
    }
    if (flag) {
      current_item[current_index] = line[i];
      current_index++;
    } else if (line[i] == *col_sep && !flag) {
      fields[field_index] = current_item;
      field_index++;
      current_index = 0;
      current_item = fields[field_index];
    } else {
      current_item[current_index] = line[i];
      current_index++;
    }
  }
  return fields;
}

/*
  Free the memory of the parseline function
  @param char **line The pointer returned from parseline function.
*/
void freeparsedline(char **line) {
  for (int i=0; i<CSV_PARSER_MAX_FIELDS; i++) {
    free(line[i]);
  }
  free(line);
}
