/*
 * til.h
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
 
#ifndef __TIL_COMPILER__H
#define __TIL_COMPILER__H

#include <stdio.h>
#include <stdint.h>

#define TIL_VERSION "1.0"

#define TYPEID_SBYTE                0x0
#define TYPEID_UBYTE                0x1
#define TYPEID_SHORT                0x2
#define TYPEID_USHORT               0x3
#define TYPEID_INT                  0x4
#define TYPEID_UINT                 0x5
#define TYPEID_LONG                 0x6
#define TYPEID_ULONG                0x7
#define TYPEID_FLOAT                0x8
#define TYPEID_DOUBLE               0x9
#define TYPEID_VOID                 0xA
#define TYPEID_VOID_PTR             0xB

#define TYPEID_NATIVE_CHAR          0xC
#define TYPEID_NATIVE_UCHAR         0xD
#define TYPEID_NATIVE_SHORT         0xE
#define TYPEID_NATIVE_USHORT        0xF
#define TYPEID_NATIVE_INT           0x10
#define TYPEID_NATIVE_UINT          0x11
#define TYPEID_NATIVE_LONG          0x12
#define TYPEID_NATIVE_ULONG         0x13
#define TYPEID_NATIVE_LONGLONG      0x14
#define TYPEID_NATIVE_ULONGLONG     0x15
#define TYPEID_NATIVE_FLOAT         0x16
#define TYPEID_NATIVE_DOUBLE        0x17
#define TYPEID_NATIVE_LONGDOUBLE    0x18

#define TYPEID_POINTER              0x19
#define TYPEID_STRUCT               0x1A
#define TYPEID_LIB_STRUCT           0x1B

struct _til_bytes;
typedef struct _til_bytes* til_bytes_t;

til_bytes_t til_bytes_create();

void til_bytes_add
	(til_bytes_t bytes, unsigned char b);

void til_bytes_add_str
	(til_bytes_t bytes, unsigned char* a, size_t l);

void til_bytes_add_short
	(til_bytes_t bytes, int16_t n);

void til_bytes_add_ushort
	(til_bytes_t bytes, uint16_t n);

void til_bytes_add_int
	(til_bytes_t bytes, int32_t n);

void til_bytes_add_uint
	(til_bytes_t bytes, uint32_t n);

void til_bytes_add_long
	(til_bytes_t bytes, int64_t n);

void til_bytes_add_ulong
	(til_bytes_t bytes, uint64_t n);

void til_bytes_add_float32
	(til_bytes_t bytes, float n);

void til_bytes_add_float64
	(til_bytes_t bytes, double n);

void til_bytes_cat
	(til_bytes_t bytes, til_bytes_t b);

void til_bytes_print
	(til_bytes_t bytes, FILE* file);

unsigned char *til_bytes_get_buffer
	(til_bytes_t bytes);

size_t til_bytes_get_buffer_size
	(til_bytes_t bytes);

void til_bytes_free
	(til_bytes_t bytes);

int til_serialize_type
	(char *type, til_bytes_t bytes);

til_bytes_t til_compile
	(char *source, char** err_ptr);

til_bytes_t assembler
	(char* assembly, int initial_line, til_bytes_t err);

#endif
