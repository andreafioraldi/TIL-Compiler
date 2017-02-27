/*
 * libs.c
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

int compile_links
	(char * node_name, xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
	xmlNodePtr child = xmlFirstElementChild(node);
	
	uint16_t count = (uint16_t)xmlChildElementCount(node);
	
	til_bytes_add_ushort(bytecode, count);
	
	int sum = 0;
	
	while(child != NULL)
	{
		if(xmlStrcmp(child->name, XC"link") != 0)
			NODE_ERROR(child, "a child of the '%s' node must be a 'link' node", node_name);
		
		xmlChar* name = xmlGetProp(child, "name");
		if(name == NULL)
			NODE_ERROR(child, "missing 'name' attribute in 'lib' node");
		
		til_bytes_add_str(bytecode, (unsigned char*)name, strlen((char*)name) +1);
		
		xmlFree(name);
		
		child = xmlNextElementSibling(child);
	}
	
	if(sum)
		return 1;
	return 0;
}

int compile_lib
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
	int sum = 0;
	
	xmlNodePtr child = xmlFirstElementChild(node);
	CHECK_MISSING_NODE(child, "records");
	if(xmlStrcmp(child->name, XC"records") != 0)
		NODE_ERROR(child, "the first child of a 'lib' node must be a 'records' node");
	
	sum += compile_links("records", child, bytecode, err);
	
	child = xmlNextElementSibling(child);
	CHECK_MISSING_NODE(child, "data");
	if(xmlStrcmp(child->name, XC"data") != 0)
		NODE_ERROR(child, "the second child of a 'lib' node must be a 'data' node");
	
	sum += compile_links("data", child, bytecode, err);
	
	child = xmlNextElementSibling(child);
	CHECK_MISSING_NODE(child, "imported");
	if(xmlStrcmp(child->name, XC"imported") != 0)
		NODE_ERROR(child, "the third child of a 'lib' node must be a 'imported' node");
	
	sum += compile_links("imported", child, bytecode, err);
	
	child = xmlNextElementSibling(child);
	CHECK_MISSING_NODE(child, "functions");
	if(xmlStrcmp(child->name, XC"functions") != 0)
		NODE_ERROR(child, "the fourth child of a 'lib' node must be a 'functions' node");
	
	sum += compile_links("functions", child, bytecode, err);
	
	if(sum)
		return 1;
	return 0;
}

int compile_libs
	(xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
	xmlNodePtr child = xmlFirstElementChild(node);
	
	uint16_t count = (uint16_t)xmlChildElementCount(node);
	
	til_bytes_add_ushort(bytecode, count);
	
	int sum = 0;
	
	while(child != NULL)
	{
		if(xmlStrcmp(child->name, XC"lib") != 0)
			NODE_ERROR(child, "a child of the 'libs' node must be a 'lib' node");
		
		xmlChar* name = xmlGetProp(child, "name");
		if(name == NULL)
			NODE_ERROR(child, "missing 'name' attribute in 'lib' node");
		
		til_bytes_add_str(bytecode, (unsigned char*)name, strlen((char*)name) +1);
		
		xmlFree(name);
		
		sum += compile_lib(child, bytecode, err);
		
		child = xmlNextElementSibling(child);
	}
	
	if(sum)
		return 1;
	return 0;
}

