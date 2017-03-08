# TIL-Compiler
Tripel Intermediate Language Compiler - Compile an XML based assembly language to bytecode for the Tripel Virtual Machine.

## Dependencies
Needed libraries:
+ libxml2 - http://xmlsoft.org/

Build tool:
+ cmake (version >= 3.0.2) - https://cmake.org/

## How to install
```
cd <build-dir>
cmake <source-dir>
make
sudo make install
```

## Usage
```
tilc [options] <source-file>
```
Options:
+ --help          Show help about usage
+ --info          Print compiler build info
+ --stdout        Print compiled bytecode to standard output
+ --stdin         Get source code from standard ipnut
+ -o <file>       Set output file name
