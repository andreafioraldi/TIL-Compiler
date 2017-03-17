/*
 * structs.c
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

int compile_vars
    (char * node_name, xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
    xmlNodePtr child = xmlFirstElementChild(node);
    
    //add the number of node children to bytecode
    uint16_t count = (uint16_t)xmlChildElementCount(node);
    til_bytes_add_ushort(bytecode, count);
    
    int sum = 0;
    
    //process each var node
    while(child != NULL)
    {
        if(xmlStrcmp(child->name, XC"var") != 0)
            NODE_ERROR(child, "a child of the '%s' node must be a 'var' node", node_name);
        
        //get var name
        xmlChar* name = xmlGetProp(child, "name");
        if(name == NULL)
            NODE_ERROR(child, "missing 'name' attribute in 'var' node");
        
        til_bytes_add_str(bytecode, (unsigned char*)name, strlen((char*)name) +1);
        
        xmlFree(name);
        
        //get var type
        xmlChar* type = xmlGetProp(child, "type");
        if(type == NULL)
            NODE_ERROR(child, "missing 'type' attribute in 'var' node");
        
        int e = til_serialize_type(type, bytecode);
        
        xmlFree(type);
        
        if(e) NODE_ERROR(child, "invalid 'type' attribute in 'var' node");
        
        child = xmlNextElementSibling(child);
    }
    
    if(sum)
        return 1;
    return 0;
}

int compile_structs
    (xmlNodePtr node, til_bytes_t bytecode, til_bytes_t err)
{
    xmlNodePtr child = xmlFirstElementChild(node);
    
    //add the number of node children to bytecode
    uint16_t count = (uint16_t)xmlChildElementCount(node);
    til_bytes_add_ushort(bytecode, count);
    
    int sum = 0;
    
    //process each struct node
    while(child != NULL)
    {
        if(xmlStrcmp(child->name, XC"struct") != 0)
            NODE_ERROR(child, "a child of the 'structs' node must be a 'struct' node");
        
        //get struct name
        xmlChar* name = xmlGetProp(child, "name");
        if(name == NULL)
            NODE_ERROR(child, "missing 'name' attribute in 'struct' node");
        
        til_bytes_add_str(bytecode, (unsigned char*)name, strlen((char*)name) +1);
        
        xmlFree(name);
        
        sum += compile_vars("struct", child, bytecode, err);
        
        child = xmlNextElementSibling(child);
    }

    if(sum)
        return 1;
    return 0;
}

