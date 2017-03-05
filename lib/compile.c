/*
 * compile.c
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

int compile_tree
	(xmlDocPtr doc, til_bytes_t bytecode, til_bytes_t err)
{
	//check if root is a til node
	xmlNodePtr root = xmlDocGetRootElement(doc);
	CHECK_MISSING_NODE(root, "root");
	if(xmlStrcmp(root->name, XC"til") != 0)
		NODE_ERROR(root, "root node is not a 'til' node");
	
	//check til version
	xmlChar* ver = xmlGetProp(root, "version");
	if(ver == NULL)
		NODE_ERROR(root, "missing 'version' attribute in 'til' node");
	if(xmlStrcmp(ver, XC TIL_VERSION))
		NODE_ERROR(root, "invalid version, " TIL_VERSION " is the supported version");
	xmlFree(ver);
	
	//all return values ​​will be added to this variable
	int sum = 0;
	
	//process libs node
	xmlNodePtr child = xmlFirstElementChild(root);
	CHECK_MISSING_NODE(child, "libs");
	if(xmlStrcmp(child->name, XC"libs") != 0)
		NODE_ERROR(child, "the first child of the 'til' node must be the 'libs' node");
	
	sum += compile_libs(child, bytecode, err);
	
	//process strings node
	child = xmlNextElementSibling(child);
	CHECK_MISSING_NODE(child, "strings");
	if(xmlStrcmp(child->name, XC"strings") != 0)
		NODE_ERROR(child, "the second child of the 'til' node must be the 'strings' node");
	
	sum += compile_strings(child, bytecode, err);
	
	//process structs node
	child = xmlNextElementSibling(child);
	CHECK_MISSING_NODE(child, "structs");
	if(xmlStrcmp(child->name, XC"structs") != 0)
		NODE_ERROR(child, "the third child of the 'til' node must be the 'structs' node");
	
	sum += compile_structs(child, bytecode, err);
	
	//process globals node
	child = xmlNextElementSibling(child);
	CHECK_MISSING_NODE(child, "globals");
	if(xmlStrcmp(child->name, XC"globals") != 0)
		NODE_ERROR(child, "the fourth child of the 'til' node must be the 'globals' node");
	
	sum += compile_vars("globals", child, bytecode, err);
	
	//process natives node
	child = xmlNextElementSibling(child);
	CHECK_MISSING_NODE(child, "natives");
	if(xmlStrcmp(child->name, XC"natives") != 0)
		NODE_ERROR(child, "the fifth child of the 'til' node must be the 'natives' node");
	
	sum += compile_natives(child, bytecode, err);
	
	//process start node
	child = xmlNextElementSibling(child);
	CHECK_MISSING_NODE(child, "start");
	if(xmlStrcmp(child->name, XC"start") != 0)
		NODE_ERROR(child, "the sixth child of the 'til' node must be the 'start' node");
	
	sum += compile_start(child, bytecode, err);
	
	//process funcs node
	child = xmlNextElementSibling(child);
	CHECK_MISSING_NODE(child, "funcs");
	if(xmlStrcmp(child->name, XC"funcs") != 0)
		NODE_ERROR(child, "the seventh child of the 'til' node must be the 'funcs' node");
	
	sum += compile_functions(child, bytecode, err);
	
	if(sum)
		return 1;
	return 0;
}

void parser_error_handler
	(void *ctx, const char *msg, ...)
{
	til_bytes_t err = ctx;
	
	//alloc temporary buffer
	char tmp[TMP_ERR_SIZE];
	
	va_list args;
	va_start(args, msg);
	vsnprintf(tmp, TMP_ERR_SIZE, msg, args);
	va_end(args);
	
	//merge tmp to error buffer
	til_bytes_add_str(err, tmp, strlen(tmp));
}

til_bytes_t til_compile
	(char *source, char** err_ptr)
{
	//create the error buffer
	til_bytes_t err = til_bytes_create();
	
	xmlInitParser();
	
	//set the error handler function for the parser
	xmlSetGenericErrorFunc(err, parser_error_handler);
	
	//parse source code
	xmlDocPtr doc = xmlReadMemory(source, strlen(source), NULL, NULL, 0);
	if(doc == NULL)
	{
		til_bytes_add(err, 0);
		*err_ptr = (char*)err->buf;
		free(err);
		return NULL;
	}
	
	//compile parsed tree
	til_bytes_t bytecode = til_bytes_create();
	int e = compile_tree(doc, bytecode, err);
	if(e)
	{
		til_bytes_free(bytecode);
		til_bytes_add(err, 0);
		*err_ptr = (char*)err->buf;
		free(err);
		bytecode = NULL;
	}
	else til_bytes_free(err);
	
	xmlFreeDoc(doc);
	xmlCleanupParser();
	return bytecode;
}




