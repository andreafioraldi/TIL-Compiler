/*
 * types.c
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

#include "til_internal.h"

int til_serialize_type(char *type, til_bytes_t bytes)
{
	if(strlen(type) == 0)
		return 1;
	while(*type == '^')
	{
		til_bytes_add(bytes, TYPEID_POINTER);
		++type;
	}
	if(*type == '#') //struct type: #[num]
	{
		++type;
		char* e;
		uint16_t idx = strtol(type, &e, 0);
		if(*e != 0)
			return 1;
		
		til_bytes_add(bytes, TYPEID_STRUCT);
		til_bytes_add_ushort(bytes, idx);
	}
	else if(*type == '@') //external struct type: @[num]
	{
		++type;
		char* e;
		uint16_t idx = strtol(type, &e, 0);
		if(*e != 0)
			return 1;
		
		til_bytes_add(bytes, TYPEID_LIB_STRUCT);
		til_bytes_add_ushort(bytes, idx);
	}
	else if(!strcmp(type, "i8"))
		til_bytes_add(bytes, TYPEID_SBYTE);
	else if(!strcmp(type, "u8"))
		til_bytes_add(bytes, TYPEID_UBYTE);
	else if(!strcmp(type, "i16"))
		til_bytes_add(bytes, TYPEID_SHORT);
	else if(!strcmp(type, "u16"))
		til_bytes_add(bytes, TYPEID_USHORT);
	else if(!strcmp(type, "i32"))
		til_bytes_add(bytes, TYPEID_INT);
	else if(!strcmp(type, "u32"))
		til_bytes_add(bytes, TYPEID_UINT);
	else if(!strcmp(type, "i64"))
		til_bytes_add(bytes, TYPEID_LONG);
	else if(!strcmp(type, "u64"))
		til_bytes_add(bytes, TYPEID_ULONG);
	else if(!strcmp(type, "f32"))
		til_bytes_add(bytes, TYPEID_FLOAT);
	else if(!strcmp(type, "f64"))
		til_bytes_add(bytes, TYPEID_DOUBLE);
	else if(!strcmp(type, "void"))
		til_bytes_add(bytes, TYPEID_VOID);
	else if(!strcmp(type, "vp"))
		til_bytes_add(bytes, TYPEID_VOID_PTR);
	else if(!strcmp(type, "ssc"))
		til_bytes_add(bytes, TYPEID_NATIVE_CHAR);
	else if(!strcmp(type, "suc"))
		til_bytes_add(bytes, TYPEID_NATIVE_UCHAR);
	else if(!strcmp(type, "sss"))
		til_bytes_add(bytes, TYPEID_NATIVE_SHORT);
	else if(!strcmp(type, "sus"))
		til_bytes_add(bytes, TYPEID_NATIVE_USHORT);
	else if(!strcmp(type, "ssi"))
		til_bytes_add(bytes, TYPEID_NATIVE_INT);
	else if(!strcmp(type, "sui"))
		til_bytes_add(bytes, TYPEID_NATIVE_UINT);
	else if(!strcmp(type, "ssl"))
		til_bytes_add(bytes, TYPEID_NATIVE_LONG);
	else if(!strcmp(type, "sul"))
		til_bytes_add(bytes, TYPEID_NATIVE_ULONG);
	else if(!strcmp(type, "ssll"))
		til_bytes_add(bytes, TYPEID_NATIVE_LONGLONG);
	else if(!strcmp(type, "sull"))
		til_bytes_add(bytes, TYPEID_NATIVE_ULONGLONG);
	else if(!strcmp(type, "sf"))
		til_bytes_add(bytes, TYPEID_NATIVE_FLOAT);
	else if(!strcmp(type, "sd"))
		til_bytes_add(bytes, TYPEID_NATIVE_DOUBLE);
	else if(!strcmp(type, "sld"))
		til_bytes_add(bytes, TYPEID_NATIVE_LONGDOUBLE);
	else
		return 1;
	return 0;
}

