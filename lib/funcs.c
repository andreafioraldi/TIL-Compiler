/*
 * funcs.c
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

int compile_function
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
	//get signature node
	xmlNodePtr child = xmlFirstElementChild(node);
	CHECK_MISSING_NODE(child, "signature");
	if(xmlStrcmp(child->name, XC"signature") != 0)
		NODE_ERROR(child, "the first child of a 'func' node must be a 'signature' node");
	
	int r = compile_signature(child, bytecode, err);
	
	//get stack length
	xmlChar* stack = xmlGetProp(node, "stack");
	if(stack == NULL)
		NODE_ERROR(node, "missing 'stack' attribute in 'func' node");
	
	uint16_t num = atoi(stack);
	til_bytes_add_ushort(bytecode, num);
	
	xmlFree(stack);
	
	//get the number of local variables
	xmlChar* locals = xmlGetProp(node, "locals");
	if(locals == NULL)
		NODE_ERROR(node, "missing 'locals' attribute in 'func' node");
	
	num = atoi(locals);
	til_bytes_add_ushort(bytecode, num);
	
	xmlFree(locals);
	
	//get the number of labels
	xmlChar* labels = xmlGetProp(node, "labels");
	if(labels == NULL)
		NODE_ERROR(node, "missing 'labels' attribute in 'func' node");
	
	num = atoi(labels);
	til_bytes_add_ushort(bytecode, num);
	
	xmlFree(labels);
	
	//process code node
	child = xmlNextElementSibling(child);
	CHECK_MISSING_NODE(child, "code");
	if(xmlStrcmp(child->name, XC"code") != 0)
		NODE_ERROR(child, "the second child of a 'func' node must be a 'code' node");
	
	if(child->children)
	{
		char* text = (char*)child->children->content;
		
		//compile the assembly contained in the code node
		til_bytes_t b = til_assembler(text, xmlGetLineNo(child) -1, err);
		
		if(b == NULL)
			return 1;
		
		//add the length of the compiled code to the bytecode
		til_bytes_add_uint(bytecode, til_bytes_get_buffer_size(b));
		
		//merge compiled code to the main bytecode stack
		til_bytes_cat(bytecode, b);
		
		til_bytes_free(b);
	}
	else til_bytes_add_uint(bytecode, 0); //if code node text doesn't exist add 0 to bytecode
	
	return r;
}

int compile_functions
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
	xmlNodePtr child = xmlFirstElementChild(node);
	
	//add the number of node children to bytecode
	uint16_t count = (uint16_t)xmlChildElementCount(node);
	til_bytes_add_ushort(bytecode, count);
	
	int sum = 0;
	
	//process each func node
	while(child != NULL)
	{
		if(xmlStrcmp(child->name, XC"func") != 0)
			NODE_ERROR(child, "a child of the 'funcs' node must be a 'func' node");
		
		sum += compile_function(child, bytecode, err);
		
		child = xmlNextElementSibling(child);
	}

	if(sum)
		return 1;
	return 0;
}
