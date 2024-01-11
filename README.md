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
1. Clone the repository or download the source code.
2. Include `parser.h` in your project.
3. Compile your project with the CSV parser source files.

### Usage

#### Reading a Line from a CSV File
```c
#include "parser.h"
#include <stdio.h>

int main() {
    FILE *file = fopen("yourfile.csv", "r");
    char *line;
    char **parsedline;
    while ((line = readline(file)) != NULL) {
        parsedline = parseline(line, ",");
        printf("%s", line);
        free(line);
        free(parsedline)
    }
    fclose(file);
    return 0;
}
```

#### Parsing a CSV Line
```c
#include "parser.h"

int main() {
    char *csvLine = "Field1,Field2,Field3";
    char **fields = parseline(csvLine, ",");
    if (fields != NULL) {
        // Process fields
        for (int i = 0; fields[i] != NULL; i++) {
            printf("%s\n", fields[i]);
        }
        freeparsedline(fields);
    }
    return 0;
}
```

## Contributing
Contributions are welcome! Feel free to submit pull requests, open issues, or suggest new features.

## License
This project is builded under the MIT License

---

Note: This README is a work in progress and will be updated as the library evolves.