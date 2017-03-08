/*
 * natives.c
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

int compile_signature
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
	//get function name
	xmlChar* name = xmlGetProp(node, "name");
	if(name == NULL)
		NODE_ERROR(node, "missing 'name' attribute in 'signature' node");
	
	//get return type
	xmlChar* type = xmlGetProp(node, "type");
	if(type == NULL)
		NODE_ERROR(node, "missing 'type' attribute in 'signature' node");
	
	til_bytes_add_str(bytecode, (unsigned char*)name, strlen((char*)name) +1);
		
	xmlFree(name);
	
	int e = til_serialize_type(type, bytecode);
		
	xmlFree(type);
	
	if(e) NODE_ERROR(node, "invalid 'type' attribute in 'signature' node");
	
	
	xmlNodePtr child = xmlFirstElementChild(node);
	
	//add the number of node children to bytecode
	uint16_t count = (uint16_t)xmlChildElementCount(node);
	til_bytes_add_ushort(bytecode, count);
	
	//process each parameter
	while(child != NULL)
	{
		if(xmlStrcmp(child->name, XC"param") != 0)
			NODE_ERROR(child, "a child of a 'signature' node must be a 'param' node");
		
		//get parameter type
		xmlChar* type = xmlGetProp(child, "type");
		if(name == NULL)
			NODE_ERROR(child, "missing 'type' attribute in 'param' node");
		
		int e = til_serialize_type(type, bytecode);
		
		xmlFree(type);
	
		if(e) NODE_ERROR(node, "invalid 'type' attribute in 'param' node");
		
		child = xmlNextElementSibling(child);
	}
	
	return 0;
}

int compile_native
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
	xmlNodePtr child = xmlFirstElementChild(node);
	
	//add the number of node children to bytecode
	uint16_t count = (uint16_t)xmlChildElementCount(node);
	til_bytes_add_ushort(bytecode, count);
	
	int sum = 0;
	
	//process each native functions
	while(child != NULL)
	{
		if(xmlStrcmp(child->name, XC"signature") != 0)
			NODE_ERROR(child, "a child of a 'native' node must be a 'signature' node");
		
		sum += compile_signature(child, bytecode, err);
		
		child = xmlNextElementSibling(child);
	}
	
	if(sum)
		return 1;
	return 0;
}

int compile_natives
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
	xmlNodePtr child = xmlFirstElementChild(node);
	
	//add the number of node children to bytecode
	uint16_t count = (uint16_t)xmlChildElementCount(node);
	til_bytes_add_ushort(bytecode, count);
	
	int sum = 0;
	
	//process each native node
	while(child != NULL)
	{
		if(xmlStrcmp(child->name, XC"native") != 0)
			NODE_ERROR(child, "a child of the 'natives' node must be a 'native' node");
		
		//get native library name
		xmlChar* name = xmlGetProp(child, "name");
		if(name == NULL)
			NODE_ERROR(child, "missing 'name' attribute in 'native' node");
		
		til_bytes_add_str(bytecode, (unsigned char*)name, strlen((char*)name) +1);
		
		xmlFree(name);
		
		sum += compile_native(child, bytecode, err);
		
		child = xmlNextElementSibling(child);
	}
	
	if(sum)
		return 1;
	return 0;
}

