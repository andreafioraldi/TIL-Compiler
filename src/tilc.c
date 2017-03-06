/*
 * tilc.c
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

#include "til.h"
#include <stdlib.h>
#include <string.h>

#ifdef __APPLE__
#include "TargetConditionals.h"
#endif

static void help(FILE* file)
{
	fprintf(file, "Usage: tilc [options] <source-file>\n"
	              "Options:\n"
	              "    --help          Show this help\n"
	              "    --info          Print compiler build info\n"
	              "    --stdout        Print compiled bytecode to standard output\n"
	              "    --stdin         Get source code from standard inut\n"
	              "    -o <file>       Set output file name\n\n"
	              "For info or bug report visit\n"
	              "<http://andreafioraldi.altervista.org>\n");
}

static void info()
{
	puts("Tripel Intermediate Language Compiler\n"
	     "Copyright 2017 Andrea Fioraldi <andreafioraldi@gmail.com>\n"
	     "    + version: " TIL_VERSION
	#if UINTPTR_MAX == 0xffffffff
	     " 32 bit"
	#elif UINTPTR_MAX == 0xffffffffffffffff
	     " 64 bit"
	#endif
	);
	
	#if defined _WIN32
	puts("    + built on: Windows");
	#elif defined __ANDROID__
	puts("    + built on: Android");
	#elif defined __linux__
		#ifdef __GNUC__
		puts("    + built on: GNU/Linux");
		#else
		puts("    + built on: Linux");
		#endif
	#elif defined __APPLE__
		#if TARGET_OS_IPHONE
		puts("    + built on: iOS");
		#elif TARGET_OS_MAC
		puts("    + built on: macOS");
		#else
		puts("    + built on: Darwin");
		#endif
	#elif defined __sun__
		puts("    + built on: Solaris");
	#elif defined BSD
		#ifdef __FreeBSD__
		puts("    + built on: FreeBSD");
		#else
		puts("    + built on: BSD");
		#endif
	#elif defined __unix__
		#ifdef __GNUC__
		puts("    + built on: GNU");
		#else
		puts("    + built on: Unix");
		#endif
	#endif
	puts("    + license: GNU Lesser General Public License v3\n");
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		help(stderr);
		return EXIT_FAILURE;
	}
	
	if(strcmp(argv[1], "--help") == 0)
	{
		help(stdout);
		return 0;
	}
	else if(strcmp(argv[1], "--info") == 0)
	{
		info();
		return 0;
	}
	
	char* input_file = NULL;
	char* output_file = NULL;
	
	int i;
	for(i = 1; i < argc; ++i)
	{
		if(strcmp(argv[i], "--stdout") == 0)
			output_file = NULL;
		else if(strcmp(argv[i], "--stdin") == 0)
			input_file = NULL;
		else if(strcmp(argv[i], "-o") == 0)
		{
			if(i == argc-1)
			{
				fprintf(stderr, "Invalid arguments: '-o' must be followed by a file name\n");
				return EXIT_FAILURE;
			}
			if(output_file != NULL)
			{
				fprintf(stderr, "Invalid arguments: output file must be specified only one time\n");
				return EXIT_FAILURE;
			}
			output_file = argv[++i];
		}
		else
		{
			if(input_file != NULL)
			{
				fprintf(stderr, "Invalid arguments: input file must be specified only one time\n");
				return EXIT_FAILURE;
			}
			input_file = argv[i];
		}
	}
	
	FILE* input;
	if(input_file)
		input = fopen(input_file, "r");
	else input = stdin;

	fseek(input, 0, SEEK_END);
	long input_size = ftell(input);
	rewind(input);
	
	char* input_content = malloc(input_size +1);
	
	long k;
	for(k = 0; k < input_size; ++k)
		input_content[k] = fgetc(input);
	input_content[input_size] = 0;
	
	if(input_file)
		fclose(input);
		
	char* err = NULL;
	til_bytes_t bytecode = til_compile(input_content, &err);
	if(bytecode == NULL)
	{
		fprintf(stderr, "%s\n", err);
		
		free(err);
		free(input_content);
		return EXIT_FAILURE;
	}
	
	FILE* output;
	if(output_file)
		output = fopen(output_file, "wb");
	else output = stdout;
	
	til_bytes_print(bytecode, output);
	
	til_bytes_free(bytecode);

	if(output_file)
		fclose(output);

	free(input_content);
	return 0;
}



