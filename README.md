# TIL-Compiler
Tripel Intermediate Language Compiler - Compile an XML based assembly language to bytecode for the Tripel Virtual Machine.

## Dependencies
Needed libraries:
+ libxml2 - http://xmlsoft.org/

Build tool:
+ cmake (version >= 3.0.2) - https://cmake.org/

## How to install
```shell
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
+ ```--help``` Show help about usage
+ ```--info``` Print compiler build info
+ ```--stdout``` Print compiled bytecode to standard output
+ ```--stdin``` Get source code from standard input
+ ```-o <file>``` Set output file name

## License

> Copyright 2017 Andrea Fioraldi <andreafioraldi@gmail.com>
> 
> TIL Compiler is free software; you can redistribute it and/or modify
> it under the terms of the GNU Lesser General Public License as published by
> the Free Software Foundation; either version 3 of the License, or
> (at your option) any later version.
> 
> TIL Compiler is distributed in the hope that it will be useful,
> but WITHOUT ANY WARRANTY; without even the implied warranty of
> MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
> GNU Lesser General Public License for more details.
> 
> You should have received a copy of the GNU Lesser General Public License
> along with this program; if not, write to the Free Software
> Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
> MA 02110-1301, USA.

