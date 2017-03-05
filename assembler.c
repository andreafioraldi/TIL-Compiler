/*
 * assembler.c
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
#include "parser.h"

til_bytes_t assembler
	(char* assembly, int initial_line, til_bytes_t err)
{
	til_bytes_t bytecode = til_bytes_create();
	
	assembler_data_t assembler;
	assembler_data_init(assembler, assembly, initial_line, bytecode, err);
	
	//call the bison generated parser
	yyparse(assembler);
	
	assembler_data_destroy(assembler);
	
	if(assembler->errors_num)
	{
		til_bytes_free(bytecode);
		return NULL;
	}
	return bytecode;
}



