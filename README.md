# Aria's CSV Parser

## Overview
Aria's CSV Parser is a lightweight, easy-to-use CSV file parsing library written in C. It is designed to efficiently parse CSV files, handling different field separators and quote characters. The library provides functions to read and parse lines from CSV files, making it a suitable choice for applications requiring CSV processing in C. As the project evolves, I will implement functions to write and append CSV files.

## Features
- Read lines from CSV files.
- Parse CSV lines into fields.
- Handle custom column separators.
- Memory management to prevent leaks.
- Support for quoted fields.

## Getting Started

### Prerequisites
- A C compiler (GCC, Clang, etc.)
- Basic knowledge of C and file handling in C.

### Installation
1. Clone the repository or download the source code to your software's `lib` folder.
2. Include `csvparser.h` in your project.
3. Compile your project with the CSV parser source files.

### Usage

#### Reading a Line from a CSV File
```c
#include "csvparser.h"
#include <stdio.h>

int main() {
    FILE *file = fopen("yourfile.csv", "r");
    char *line = NULL;
    while ((line = readline(file, line)) != NULL) {
        // Your code
        printf("%s", line);
    }
    free(line);
    fclose(file);
    return 0;
}
```

#### Parsing a CSV Line
```c
#include "csvparser.h"

int main() {
    char *csvLine = "Field1,Field2,Field3";
    char **fields = NULL;
    fields = parseline(csvLine, ",", fields);
    if (fields != NULL) {
        // Process fields
        for (int i = 0; fields[i] != NULL; i++) {
            printf("%s\n", fields[i]);
        }
    }
    freeparsedline(fields);
    return 0;
}
```

#### Changing default size of constants

In order to facilitate usage, some constants are defined to parse the lines and fields of the files.
Their default values are:

```c
#define CSV_PARSER_MAX_LINE_LENGTH 1024
#define CSV_PARSER_MAX_FIELDS 30
#define CSV_PARSER_MAX_FIELD_LEN 1024
```

If you are working in a setting with limited memory, or just want to adjust the constants to your files,
you can redefine them as you like.

`CSV_PARSER_MAX_LINE_LENGTH` and `CSV_PARSER_MAX_FIELD_LEN` are `int` representing the maximum number of bytes, while `CSV_PARSER_MAX_FIELDS` is an `int` representing the maximum number of CSV columns it will handle.

## Contributing
Contributions are welcome! Feel free to submit pull requests, open issues, or suggest new features.

## License
This project is builded under the MIT License

---

Note: This README is a work in progress and will be updated as the library evolves.