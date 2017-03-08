/*
 * til_internal.h
 *
 * Copyright 2017 Andrea Fioraldi <andreafioraldi@gmail.com>
 *
 * This file is part of TIL Compiler.
 *
 * TIL Compiler is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * TIL Compiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#ifndef __TIL_INTERNAL__H
#define __TIL_INTERNAL__H

#include "til.h"
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

//initial buffer size for a til_bytes_t
#define TIL_BYTES_INITIAL_BLOCK 32

//max size for a single error string
#define TMP_ERR_SIZE 256

//easy cast macro
#define XC (const xmlChar*)

//helper to report structure errors caused by xml nodes
#define NODE_ERROR(node, ...) \
do { \
	char tmp[TMP_ERR_SIZE]; \
	sprintf(tmp, "Error: line %d: structure error: ", (node)->line); \
	sprintf(tmp + strlen(tmp), __VA_ARGS__); \
	til_bytes_add_str(err, tmp, strlen(tmp)); \
	til_bytes_add(err, '\n'); \
	return 1; \
} while(0)

//helper to report missing node errors
#define CHECK_MISSING_NODE(node, name) \
if((node) == NULL) \
{ \
	til_bytes_add_str(err, "Error: missing node '" name "'\n", 23 + strlen(name)); \
	return 1; \
}

/* bytes stack data structure definition */
struct _til_bytes
{
	unsigned char *buf;
	size_t len; //buffer length
	size_t allocd; //buffer allocated space
};

int compile_strings
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err);

int compile_structs
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err);

int compile_vars
	(char * node_name, xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err);

int compile_natives
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err);

int compile_signature
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err);

int compile_start
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err);

int compile_functions
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err);

int compile_libs
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err);

/* parameters to pass to the assembler parser
   enclosed in a structure */
struct _assembler_data
{
	til_bytes_t err;
	til_bytes_t bytecode;
	void* lexer; //flex lexer
	char* source;
	char* source_it;
	int initial_line;
	int errors_num;
};

typedef struct _assembler_data assembler_data_t[1];

//init flex lexer and set structure fields
void assembler_data_init	
	(struct _assembler_data* assembler, char* source, int initial_line, til_bytes_t bytecode, til_bytes_t err);

//destroy flex lexer
void assembler_data_destroy
	(struct _assembler_data* assembler);

#endif
