#!/bin/bash

# This script will install the library on your system. Please use this script only if
# your Operating System is Linux based and you have GCC installed.

check_error() {
  if [[ $? -ne 0 ]]; then
    echo "Error: Failed to copy the header file to /usr/include."
    exit 1
  fi
}

echo "Installing the library on your system..."
echo "Compiling the source code..."
gcc -fpic -c src/parser.c -o parser.o -I.
check_error
echo "Creating the shared library..."
gcc -shared -o libcsvparser.so parser.o
check_error
echo "Copying the library to /usr/lib..."
cp libcsvparser.so /usr/lib
check_error
echo "Copying the header file to /usr/include..."
cp csvparser.h /usr/include
check_error
echo "Cleaning up the temporary files..."
rm -rf parser.o libcsvparser.so
echo "The library has been installed successfully."
