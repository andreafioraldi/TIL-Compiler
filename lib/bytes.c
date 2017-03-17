/*
 * bytes.c
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

til_bytes_t til_bytes_create()
{
    til_bytes_t bytes = malloc(sizeof(struct _til_bytes));
    bytes->len = 0;
    
    //alloc buffer with a default size
    bytes->allocd = TIL_BYTES_INITIAL_BLOCK;
    bytes->buf = malloc(TIL_BYTES_INITIAL_BLOCK);
    
    return bytes;
}

void til_bytes_add
    (til_bytes_t bytes, unsigned char b)
{
    ++bytes->len;
    
    //if requested len > avaiable allocated size, incremental realloc
    if(bytes->len > bytes->allocd) {
        //allocd * 2.5 as int
        bytes->allocd += bytes->allocd + (bytes->allocd >> 1);
        bytes->buf = realloc(bytes->buf, bytes->allocd);
    }
    
    bytes->buf[bytes->len -1] = b;
}

void til_bytes_add_str
    (til_bytes_t bytes, unsigned char* a, size_t l)
{
    size_t len = bytes->len + l;
    
    //if requested len > avaiable allocated size, incremental realloc
    if(len > bytes->allocd) {
        while(len > bytes->allocd)
            bytes->allocd += bytes->allocd + (bytes->allocd >> 1);
        bytes->buf = realloc(bytes->buf, bytes->allocd);
    }
    
    //copy byffer
    memcpy(bytes->buf + bytes->len, a, l);
    bytes->len = len;
}

//note: numbers are stored using the little-endian format

void til_bytes_add_short
    (til_bytes_t bytes, int16_t n)
{
    if(bytes->len + 2 > bytes->allocd) {
        bytes->allocd += bytes->allocd + (bytes->allocd >> 1);
        bytes->buf = realloc(bytes->buf, bytes->allocd);
    }
    
    //number serialization into little-endian bytes array
    unsigned char a[2];
    a[1] = (n >> 8) & 0xFF;
    a[0] = n & 0xFF;
    
    memcpy(bytes->buf + bytes->len, a, 2);
    bytes->len += 2;
}

void til_bytes_add_ushort
    (til_bytes_t bytes, uint16_t n)
{
    if(bytes->len + 2 > bytes->allocd) {
        bytes->allocd += bytes->allocd + (bytes->allocd >> 1);
        bytes->buf = realloc(bytes->buf, bytes->allocd);
    }
    
    //number serialization into little-endian bytes array
    unsigned char a[2];
    a[1] = (n >> 8) & 0xFF;
    a[0] = n & 0xFF;
    
    memcpy(bytes->buf + bytes->len, a, 2);
    bytes->len += 2;
}


void til_bytes_add_int
    (til_bytes_t bytes, int32_t n)
{
    if(bytes->len + 4 > bytes->allocd) {
        bytes->allocd += bytes->allocd + (bytes->allocd >> 1);
        bytes->buf = realloc(bytes->buf, bytes->allocd);
    }
    
    //number serialization into little-endian bytes array
    unsigned char a[4];
    a[3] = (n >> 24) & 0xFF;
    a[2] = (n >> 16) & 0xFF;
    a[1] = (n >> 8) & 0xFF;
    a[0] = n & 0xFF;
    
    memcpy(bytes->buf + bytes->len, a, 4);
    bytes->len += 4;
}

void til_bytes_add_uint
    (til_bytes_t bytes, uint32_t n)
{
    if(bytes->len + 4 > bytes->allocd) {
        bytes->allocd += bytes->allocd + (bytes->allocd >> 1);
        bytes->buf = realloc(bytes->buf, bytes->allocd);
    }
    
    //number serialization into little-endian bytes array
    unsigned char a[4];
    a[3] = (n >> 24) & 0xFF;
    a[2] = (n >> 16) & 0xFF;
    a[1] = (n >> 8) & 0xFF;
    a[0] = n & 0xFF;
    
    memcpy(bytes->buf + bytes->len, a, 4);
    bytes->len += 4;
}


void til_bytes_add_long
    (til_bytes_t bytes, int64_t n)
{
    if(bytes->len + 8 > bytes->allocd) {
        bytes->allocd += bytes->allocd + (bytes->allocd >> 1);
        bytes->buf = realloc(bytes->buf, bytes->allocd);
    }
    
    //number serialization into little-endian bytes array
    unsigned char a[8];
    a[7] = (n >> 56) & 0xFF;
    a[6] = (n >> 48) & 0xFF;
    a[5] = (n >> 40) & 0xFF;
    a[4] = (n >> 32) & 0xFF;
    a[3] = (n >> 24) & 0xFF;
    a[2] = (n >> 16) & 0xFF;
    a[1] = (n >> 8) & 0xFF;
    a[0] = n & 0xFF;
    
    memcpy(bytes->buf + bytes->len, a, 8);
    bytes->len += 8;
}

void til_bytes_add_ulong
    (til_bytes_t bytes, uint64_t n)
{
    if(bytes->len + 8 > bytes->allocd) {
        bytes->allocd += bytes->allocd + (bytes->allocd >> 1);
        bytes->buf = realloc(bytes->buf, bytes->allocd);
    }
    
    //number serialization into little-endian bytes array
    unsigned char a[8];
    a[7] = (n >> 56) & 0xFF;
    a[6] = (n >> 48) & 0xFF;
    a[5] = (n >> 40) & 0xFF;
    a[4] = (n >> 32) & 0xFF;
    a[3] = (n >> 24) & 0xFF;
    a[2] = (n >> 16) & 0xFF;
    a[1] = (n >> 8) & 0xFF;
    a[0] = n & 0xFF;
    
    memcpy(bytes->buf + bytes->len, a, 8);
    bytes->len += 8;
}


void til_bytes_add_float32
    (til_bytes_t bytes, float n)
{
    //store float as unsigned int, naive way, must be improved in future
    til_bytes_add_uint(bytes, *(uint32_t*)&n);
}

void til_bytes_add_float64
    (til_bytes_t bytes, double n)
{
    //store double as unsigned long, naive way, must be improved in future
    til_bytes_add_ulong(bytes, *(uint64_t*)&n);
}


void til_bytes_cat
    (til_bytes_t bytes, til_bytes_t b)
{
    size_t len = bytes->len + b->len;
    if(len > bytes->allocd) {
        while(len > bytes->allocd)
            bytes->allocd += bytes->allocd + (bytes->allocd >> 1);
        bytes->buf = realloc(bytes->buf, bytes->allocd);
    }
    
    memcpy(bytes->buf + bytes->len, b->buf, b->len);
    bytes->len = len;
}


void til_bytes_print
    (til_bytes_t bytes, FILE* file)
{
    unsigned char* it = bytes->buf;
    unsigned char* end = bytes->buf + bytes->len;
    
    while(it != end)
    {
        fputc(*it, file);
        ++it;
    }
}

unsigned char* til_bytes_get_buffer
    (til_bytes_t bytes)
{
    unsigned char* copy = malloc(bytes->len);
    //copy buffer
    memcpy(copy, bytes->buf, bytes->len);
    return copy;
}

size_t til_bytes_get_buffer_size
    (til_bytes_t bytes)
{
    return bytes->len;
}

void til_bytes_free
    (til_bytes_t bytes)
{
    free(bytes->buf);
    free(bytes);
}
