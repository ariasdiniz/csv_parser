#ifndef CSV_PARSER_PARSER_H
#define CSV_PARSER_PARSER_H

#define CSV_PARSER_MAX_LINE_LENGTH 1024
#define CSV_PARSER_QUOTE_FLAG 0x001
#define CSV_PARSER_MAX_FIELDS 30
#define CSV_PARSER_MAX_FIELD_LEN 1024
#include <stdio.h>

char *readline(FILE *file);
char **parseline(char *line, char *col_separator);
void freeparsedline(char **line);

#endif //CSV_PARSER_PARSER_H