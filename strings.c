/*
 * strings.c
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

int compile_strings
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
	xmlNodePtr child = xmlFirstElementChild(node);
	
	uint16_t count = (uint16_t)xmlChildElementCount(node);
	
	til_bytes_add_ushort(bytecode, count);
	
	while(child != NULL)
	{
		if(xmlStrcmp(child->name, XC"string") != 0)
			NODE_ERROR(child, "a child of the 'strings' node must be a 'string' node");
		
		if(child->children == NULL)
			til_bytes_add(bytecode, 0);
		else {
			char* text = (char*)child->children->content;
			
			til_bytes_add_str(bytecode, text, strlen(text) +1);
		}
		
		child = xmlNextElementSibling(child);
	}

	return 0;
}

