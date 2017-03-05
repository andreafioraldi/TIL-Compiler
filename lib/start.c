/*
 * start.c
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

int compile_start
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
	xmlChar* stack = xmlGetProp(node, "stack");
	if(stack == NULL)
		NODE_ERROR(node, "missing 'stack' attribute in 'start' node");
	
	uint16_t num = atoi(stack);
	til_bytes_add_ushort(bytecode, num);
	
	xmlFree(stack);
	
	xmlChar* locals = xmlGetProp(node, "locals");
	if(locals == NULL)
		NODE_ERROR(node, "missing 'locals' attribute in 'start' node");
	
	num = atoi(locals);
	til_bytes_add_ushort(bytecode, num);
	
	xmlFree(locals);
	
	xmlChar* labels = xmlGetProp(node, "labels");
	if(labels == NULL)
		NODE_ERROR(node, "missing 'labels' attribute in 'start' node");
	
	num = atoi(labels);
	til_bytes_add_ushort(bytecode, num);
	
	xmlFree(labels);
	
	xmlNodePtr child = xmlFirstElementChild(node);
	CHECK_MISSING_NODE(child, "code");
	if(xmlStrcmp(child->name, XC"code") != 0)
		NODE_ERROR(child, "the child of the 'start' node must be a 'code' node");
		
	if(child->children)
	{
		char* text = (char*)child->children->content;
		
		til_bytes_t b = assembler(text, xmlGetLineNo(child) -1, err);
		
		if(b == NULL)
			return 1;
		
		til_bytes_add_uint(bytecode, til_bytes_get_buffer_size(b));
		til_bytes_cat(bytecode, b);
		
		til_bytes_free(b);
	}
	else til_bytes_add_uint(bytecode, 0);

	return 0;
}



