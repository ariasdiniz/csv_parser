#include "../src/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void test_readline_non_empty_file() {
  FILE *file = fopen("test/files/non_empty_file.txt", "r");
  assert(file != NULL);

  char *line = NULL;
  line = readline(file, line);
  assert(strcmp(line, "line1"));
  free(line);
  fclose(file);
  printf("Test readline with non empty file passed\n");
}

// Test with an empty file
void test_readline_empty_file() {
  FILE *file = fopen("test/files/empty_file.txt", "r");
  assert(file != NULL);

  char *line = NULL;
  line = readline(file, line);
  assert(line == NULL);

  fclose(file);
  printf("Test readline with empty file passed\n");
}

// Test with a NULL file pointer
void test_readline_null_file_pointer() {
  char *line = NULL;
  line = readline(NULL, line);
  assert(line == NULL);
  printf("Test readline with null file pointer passed\n");
}

void test_parseline_null_input() {
  char **result = parseline(NULL, NULL);
  assert(result == NULL);
  printf("Test parseline with null input passed\n");
}

void test_parseline_default_separator() {
  char line[] = "field1,field2,field3";
  char **result = parseline(line, NULL);
  assert(strcmp(result[0], "field1") == 0);
  assert(strcmp(result[1], "field2") == 0);
  assert(strcmp(result[2], "field3") == 0);
  freeparsedline(result);
  printf("Test parseline with default separator passed\n");
}

void test_parseline_custom_separator() {
  char line[] = "field1;field2;field3";
  char **result = parseline(line, ";");
  assert(strcmp(result[0], "field1") == 0);
  assert(strcmp(result[1], "field2") == 0);
  assert(strcmp(result[2], "field3") == 0);
  freeparsedline(result);
  printf("Test parseline with custom separator passed\n");
}

void test_parseline_with_quotes() {
  char *line = "\"some, words\",field2";
  char **result = parseline(line, NULL);
  assert(strcmp(result[0], "\"some, words\"") == 0);
  assert(strcmp(result[1], "field2") == 0);
  for (int i = 0; i < CSV_PARSER_MAX_FIELDS; i++) {
     free(result[i]);
  }
  free(result);
  printf("Test parseline with quotes passed\n");
}

void test_parseline_empty_input() {
  char *line = "";
  char **result = parseline(line, NULL);
  assert(result[0][0] == '\0');
  for (int i = 0; i < CSV_PARSER_MAX_FIELDS; i++) {
    free(result[i]);
  }
  free(result);
  printf("Test parseline with empty input passed\n");
}

int main() {
  test_readline_non_empty_file();
  test_readline_empty_file();
  test_readline_null_file_pointer();
  test_parseline_null_input();
  test_parseline_default_separator();
  test_parseline_custom_separator();
  test_parseline_with_quotes();
  test_parseline_empty_input();
  printf("All tests passed!\n");
}
