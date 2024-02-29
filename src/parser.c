#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Read a line from a file. Subsequent calls of this function on the same
  file will read its next lines until EOF. If line is NULL, memory will
  be allocated for it. If not, line will be overwritten. Recommended to
  use a char *line on function calling instead of NULL for better 
  performance.

  Returns NULL when file is a null file pointer
  Returns NULL when reach EOF

  @param file A pointer to a file.
  @param line A pointer to a char
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
char **parseline(char *line, char* col_separator, char **buffer) {
  if (line == NULL) {
    return NULL;
  }
  if (buffer == NULL) {
    buffer = malloc(CSV_PARSER_MAX_FIELDS * sizeof(char *));
    if (buffer == NULL) {
      return NULL;
    }
    allocateparsedarray(buffer);
  }
  char *col_sep = (col_separator == NULL) ? "," : col_separator;
  int flag = 0, current_index = 0, field_index = 0;
  char *current_item = buffer[0];

  for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
    if (line[i] == '\"' && !flag) {
      flag |= CSV_PARSER_QUOTE_FLAG;
    } else if (line[i] == '\"' && flag) {
      flag &= ~CSV_PARSER_QUOTE_FLAG;
    }
    if (flag) {
      current_item[current_index] = line[i];
      current_item[current_index + 1] = '\0';
      current_index++;
    } else if (line[i] == *col_sep && !flag) {
      buffer[field_index] = current_item;
      field_index++;
      current_index = 0;
      current_item = buffer[field_index];
    } else {
      current_item[current_index] = line[i];
      current_item[current_index + 1] = '\0';
      current_index++;
    }
  }
  return buffer;
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
