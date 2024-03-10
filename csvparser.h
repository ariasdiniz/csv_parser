#ifndef CSV_PARSER_H
#define CSV_PARSER_MAX_LINE_LENGTH 1024
#define CSV_PARSER_QUOTE_FLAG 0x001
#define CSV_PARSER_MAX_FIELDS 50
#define CSV_PARSER_MAX_FIELD_LEN 1024
#include <stdio.h>

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
char *readline(FILE *file, char *line);

/*
  Parse a CSV line and return a pointer with each field.

  @param char *line The unparsed CSV line.
  @param char *col_separator The character separating the columns.
  
  @return char ** The pointer containing every separated field from the line.
*/
char **parseline(char *line, char *col_separator, char **buffer);

/*
  Free the memory of the parseline function
  @param char **line The pointer returned from parseline function.
*/
void freeparsedline(char **line);
#endif