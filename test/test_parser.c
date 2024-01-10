#include "../src/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifdef MAX_LINE_LENGTH
#undef MAX_LINE_LENGTH
#define MAX_LINE_LENGTH 1024
#endif

void test_readline_non_empty_file() {
    FILE *file = fopen("test/files/non_empty_file.txt", "r");
    assert(file != NULL);

    char *line;
    line = readline(file);
    assert(strcmp(line, "line1"));

    free(line);
    fclose(file);
    printf("Test readline with non empty file passed\n");
}

// Test with an empty file
void test_readline_empty_file() {
    FILE *file = fopen("test/files/empty_file.txt", "r");
    assert(file != NULL);

    char *line = readline(file);
    assert(line == NULL);

    fclose(file);
    printf("Test readline with empty file passed\n");
}

// Test with a NULL file pointer
void test_readline_null_file_pointer() {
    char *line = readline(NULL);
    assert(line == NULL);
    free(line);
    printf("Test readline with null file pointer passed\n");
}

int main() {
  test_readline_non_empty_file();
  test_readline_empty_file();
  test_readline_null_file_pointer();
  printf("All tests passed!\n");
}
