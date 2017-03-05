/*
 * scanner.l
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

%option outfile="scanner.c"
%option reentrant
%option bison-bridge
%option bison-locations
%option noyywrap
%option yylineno
%option never-interactive
%option nounistd

%{

#include "parser.h"

#define YY_EXTRA_TYPE struct _assembler_data*
#define YY_USER_ACTION yylloc->first_line = yylineno;


#define YY_INPUT(buf, result, max_size) { \
	int c = *yyextra->source_it; \
	if(c == 0) \
		result = YY_NULL; \
	else \
	{ \
		buf[0] = c; \
		result = 1; \
		++yyextra->source_it; \
	} \
}

char* stringize
	(char c)
{
	char* buf = malloc(2);
	*buf = c;
	buf[1] = 0;
	return buf;
}

%}

%%

"i8"		{
			yylval->text = stringize(TYPEID_SBYTE);
			return T_I8;
		}
"u8"		{
			yylval->text = stringize(TYPEID_UBYTE);
			return T_U8;
		}
"i16"		{
			yylval->text = stringize(TYPEID_SHORT);
			return T_I16;
		}
"u16"		{
			yylval->text = stringize(TYPEID_USHORT);
			return T_U16;
		}
"i32"		{
			yylval->text = stringize(TYPEID_INT);
			return T_I32;
		}
"u32"		{
			yylval->text = stringize(TYPEID_UINT);
			return T_U32;
		}
"i64"		{
			yylval->text = stringize(TYPEID_LONG);
			return T_I64;
		}
"u64"		{
			yylval->text = stringize(TYPEID_ULONG);
			return T_U64;
		}
"f32"		{
			yylval->text = stringize(TYPEID_FLOAT);
			return T_F32;
		}
"f64"		{
			yylval->text = stringize(TYPEID_DOUBLE);
			return T_F64;
		}
"void"		{
			yylval->text = stringize(TYPEID_VOID);
			return T_VOID;
		}
"vp"		{
			yylval->text = stringize(TYPEID_VOID_PTR);
			return T_VP;
		}

"ssc"		{
			yylval->text = stringize(TYPEID_NATIVE_CHAR);
			return T_SSC;
		}
"suc"		{
			yylval->text = stringize(TYPEID_NATIVE_UCHAR);
			return T_SUC;
		}
"sss"		{
			yylval->text = stringize(TYPEID_NATIVE_SHORT);
			return T_SSS;
		}
"sus"		{
			yylval->text = stringize(TYPEID_NATIVE_USHORT);
			return T_SUC;
		}
"ssi"		{
			yylval->text = stringize(TYPEID_NATIVE_INT);
			return T_SSI;
		}
"sui"		{
			yylval->text = stringize(TYPEID_NATIVE_UINT);
			return T_SUI;
		}
"ssl"		{
			yylval->text = stringize(TYPEID_NATIVE_LONG);
			return T_SSL;
		}
"sul"		{
			yylval->text = stringize(TYPEID_NATIVE_ULONG);
			return T_SUL;
		}
"ssll"		{
			yylval->text = stringize(TYPEID_NATIVE_LONGLONG);
			return T_SSLL;
		}
"sull"		{
			yylval->text = stringize(TYPEID_NATIVE_ULONGLONG);
			return T_SULL;
		}
"sf"		{
			yylval->text = stringize(TYPEID_NATIVE_FLOAT);
			return T_SF;
		}
"sd"		{
			yylval->text = stringize(TYPEID_NATIVE_DOUBLE);
			return T_SD;
		}
"sld"		{
			yylval->text = stringize(TYPEID_NATIVE_LONGDOUBLE);
			return T_SLD;
		}

"nop"             { return T_NOP; }
"ld_i8"           { return T_LD_I8; }
"ld_u8"           { return T_LD_U8; }
"ld_i16"          { return T_LD_I16; }
"ld_u16"          { return T_LD_U16; }
"ld_i32"          { return T_LD_I32; }
"ld_u32"          { return T_LD_U32; }
"ld_i64"          { return T_LD_I64; }
"ld_u64"          { return T_LD_U64; }
"ld_f32"          { return T_LD_F32; }
"ld_f64"          { return T_LD_F64; }
"ld_null"         { return T_LD_NULL; }
"ld_str"          { return T_LD_STR; }
"addr"            { return T_ADDR; }
"val"             { return T_VAL; }
"at"              { return T_AT; }
"at_c"            { return T_AT_C; }
"at_1"            { return T_AT_1; }
"at_2"            { return T_AT_2; }
"at_3"            { return T_AT_3; }
"ad_at"           { return T_AD_AT; }
"ad_at_c"         { return T_AD_AT_C; }
"ad_at_1"         { return T_AD_AT_1; }
"ad_at_2"         { return T_AD_AT_2; }
"ad_at_3"         { return T_AD_AT_3; }
"field"           { return T_FIELD; }
"field_0"         { return T_FIELD_0; }
"field_1"         { return T_FIELD_1; }
"field_2"         { return T_FIELD_2; }
"field_3"         { return T_FIELD_3; }
"pt_field"        { return T_PT_FIELD; }
"pt_field_0"      { return T_PT_FIELD_0; }
"pt_field_1"      { return T_PT_FIELD_1; }
"pt_field_2"      { return T_PT_FIELD_2; }
"pt_field_3"      { return T_PT_FIELD_3; }
"ad_field"        { return T_AD_FIELD; }
"ad_field_0"      { return T_AD_FIELD_0; }
"ad_field_1"      { return T_AD_FIELD_1; }
"ad_field_2"      { return T_AD_FIELD_2; }
"ad_field_3"      { return T_AD_FIELD_3; }
"ad_pt_field"     { return T_AD_PT_FIELD; }
"ad_pt_field_0"   { return T_AD_PT_FIELD_0; }
"ad_pt_field_1"   { return T_AD_PT_FIELD_1; }
"ad_pt_field_2"   { return T_AD_PT_FIELD_2; }
"ad_pt_field_3"   { return T_AD_PT_FIELD_3; }
"push"            { return T_PUSH; }
"push_0"          { return T_PUSH_0; }
"push_1"          { return T_PUSH_1; }
"push_2"          { return T_PUSH_2; }
"push_3"          { return T_PUSH_3; }
"push_ad"         { return T_PUSH_AD; }
"push_ad_0"       { return T_PUSH_AD_0; }
"push_ad_1"       { return T_PUSH_AD_1; }
"push_ad_2"       { return T_PUSH_AD_2; }
"push_ad_3"       { return T_PUSH_AD_3; }
"push_arg"        { return T_PUSH_ARG; }
"push_arg_0"      { return T_PUSH_ARG_0; }
"push_arg_1"      { return T_PUSH_ARG_1; }
"push_arg_2"      { return T_PUSH_ARG_2; }
"push_arg_3"      { return T_PUSH_ARG_3; }
"push_gbl"        { return T_PUSH_GBL; }
"push_e_gbl"      { return T_PUSH_E_GBL; }
"pop"             { return T_POP; }
"dup"             { return T_DUP; }
"clear"           { return T_CLEAR; }
"decl_i8"         { return T_DECL_I8; }
"decl_u8"         { return T_DECL_U8; }
"decl_i16"        { return T_DECL_I16; }
"decl_u16"        { return T_DECL_U16; }
"decl_i32"        { return T_DECL_I32; }
"decl_u32"        { return T_DECL_U32; }
"decl_i64"        { return T_DECL_I64; }
"decl_u64"        { return T_DECL_U64; }
"decl_f32"        { return T_DECL_F32; }
"decl_f64"        { return T_DECL_F64; }
"decl_vp"         { return T_DECL_VP; }
"decl_pt"         { return T_DECL_PT; }
"decl_st"         { return T_DECL_ST; }
"decl_e_st"       { return T_DECL_E_ST; }
"decl_t"          { return T_DECL_T; }
"store"           { return T_STORE; }
"store_0"         { return T_STORE_0; }
"store_1"         { return T_STORE_1; }
"store_2"         { return T_STORE_2; }
"store_3"         { return T_STORE_3; }
"store_val"       { return T_STORE_VAL; }
"store_val_0"     { return T_STORE_VAL_0; }
"store_val_1"     { return T_STORE_VAL_1; }
"store_val_2"     { return T_STORE_VAL_2; }
"store_val_3"     { return T_STORE_VAL_3; }
"store_gbl"       { return T_STORE_GBL; }
"store_e_gbl"       { return T_STORE_GBL; }
"set_at"          { return T_SET_AT; }
"set_at_0"        { return T_SET_AT_0; }
"set_at_1"        { return T_SET_AT_1; }
"set_at_2"        { return T_SET_AT_2; }
"set_at_3"        { return T_SET_AT_3; }
"set_at_c"        { return T_SET_AT_C; }
"set_field"       { return T_SET_FIELD; }
"set_field_0"     { return T_SET_FIELD_0; }
"set_field_1"     { return T_SET_FIELD_1; }
"set_field_2"     { return T_SET_FIELD_2; }
"set_field_3"     { return T_SET_FIELD_3; }
"set_pt_field"    { return T_SET_PT_FIELD; }
"set_pt_field_0"  { return T_SET_PT_FIELD_0; }
"set_pt_field_1"  { return T_SET_PT_FIELD_1; }
"set_pt_field_2"  { return T_SET_PT_FIELD_2; }
"set_pt_field_3"  { return T_SET_PT_FIELD_3; }
"s_alloc"         { return T_S_ALLOC; }
"s_alloc_c"       { return T_S_ALLOC_C; }
"gc_alloc"        { return T_GC_ALLOC; }
"gc_alloc_c"      { return T_GC_ALLOC_C; }
"gc_atom_alloc"   { return T_GC_ATOM_ALLOC; }
"gc_atom_alloc_c" { return T_GC_ATOM_ALLOC_C; }
"call"            { return T_CALL; }
"n_call"          { return T_N_CALL; }
"e_call"          { return T_E_CALL; }
"en_call"         { return T_EN_CALL; }
"ret"             { return T_RET; }
"ret_std"         { return T_RET_STD; }
"func_ad"         { return T_FUNC_AD; }
"e_func_ad"       { return T_E_FUNC_AD; }
"n_func_ad"       { return T_N_FUNC_AD; }
"en_func_ad"      { return T_EN_FUNC_AD; }
"call_pt"         { return T_CALL_PT; }
"val_assign"      { return T_VAL_ASSIGN; }
"sizeof"          { return T_SIZEOF; }
"sizeof_t"        { return T_SIZEOF_T; }
"sizeof_t_mul"    { return T_SIZEOF_T_MUL; }
"minum"           { return T_MINUM; }
"add"             { return T_ADD; }
"sub"             { return T_SUB; }
"mul"             { return T_MUL; }
"div"             { return T_DIV; }
"rem"             { return T_REM; }
"inc"             { return T_INC; }
"dec"             { return T_DEC; }
"neg"             { return T_NEG; }
"and"             { return T_AND; }
"or"              { return T_OR; }
"xor"             { return T_XOR; }
"not"             { return T_NOT; }
"shl"             { return T_SHL; }
"shr"             { return T_SHR; }
"eq"              { return T_EQ; }
"neq"             { return T_NEQ; }
"lt"              { return T_LT; }
"le"              { return T_LE; }
"gt"              { return T_GT; }
"ge"              { return T_GE; }
"is_null"         { return T_IS_NULL; }
"to_bool"         { return T_TO_BOOL; }
"to_bool_n"       { return T_TO_BOOL_N; }
"jmp"             { return T_JMP; }
"jmp_if"          { return T_JMP_IF; }
"jmp_if_n"        { return T_JMP_IF_N; }
"label"           { return T_LABEL; }
"cast_i8"         { return T_CAST_I8; }
"cast_u8"         { return T_CAST_U8; }
"cast_i16"        { return T_CAST_I16; }
"cast_u16"        { return T_CAST_U16; }
"cast_i32"        { return T_CAST_I32; }
"cast_u32"        { return T_CAST_U32; }
"cast_i64"        { return T_CAST_I64; }
"cast_u64"        { return T_CAST_U64; }
"cast_f32"        { return T_CAST_F32; }
"cast_f64"        { return T_CAST_F64; }
"cast_vp"         { return T_CAST_VP; }
"cast_pt"         { return T_CAST_PT; }
"cast_st"         { return T_CAST_ST; }
"cast_e_st"       { return T_CAST_E_ST; }
"cast_t"          { return T_CAST_T; }
"abort"           { return T_ABORT; }

("0"|[1-9][0-9]*)|("0"[xX]([0-9]|[a-fA-F])+)|("0"[0-7]+) {
	yylval->text = strdup(yytext);
	return T_INT;
}

[0-9]*"."[0-9]+ {
	yylval->text = strdup(yytext);
	return T_FLOAT;
}

\'(\\.|[^\\'])+\' {
	#define CHAR_ERR \
	do { \
		char tmp[80]; \
		snprintf(tmp, 80, "Error: line %d: assembler error: invalid character constant %s", yylineno + yyextra->initial_line, yytext); \
		til_bytes_add_str(yyextra->err, tmp, strlen(tmp)); \
	} while(0)
	
	size_t size = strlen(yytext +1) -1;
	char* buf = yytext +1;
	
	if(*buf == '\\')
	{
		++buf;
		if(size < 2)
			CHAR_ERR;
		else if(size == 2)
		{
			if(*buf == '\\')
				yylval->byte = '\\';
			else if(*buf == '\'')
				yylval->byte = '\'';
			else if(*buf == '\"')
				yylval->byte = '\"';
			else if(*buf == 'n')
				yylval->byte = '\n';
			else if(*buf == 't')
				yylval->byte = '\t';
			else if(*buf == 'r')
				yylval->byte = '\r';
			else if(*buf == 'v')
				yylval->byte = '\v';
			else CHAR_ERR;
		}
		else if(size == 4)
		{
			if(*buf == 'x')
			{
				--buf;
				*buf = '0';
				char* end;
				long conv = strtol(buf, &end, 0);
				if(end != buf + 4)
					CHAR_ERR;
				yylval->byte = (char)conv;
			}
			else
			{
				char* end;
				long conv = strtol(buf, &end, 0);
				if(end != buf + 3)
					CHAR_ERR;
				yylval->byte = (char)conv;
			}
		}
		else CHAR_ERR;
	}
	else if(size == 1)
		yylval->byte = *buf;
	else CHAR_ERR;
	
	return T_CHAR;
}

"^"          { return '^'; }

[ \t\v\f\r\n]+	{ }
.		{ return T_NOT_RECOGNIZED; }

%%

void assembler_data_init	
	(struct _assembler_data* assembler, char* source, int initial_line, til_bytes_t bytecode, til_bytes_t err)
{
	assembler->source = source;
	assembler->source_it = source;
	assembler->initial_line = initial_line;
	assembler->bytecode = bytecode;
	assembler->err = err;
	assembler->errors_num = 0;
	
	yylex_init(&assembler->lexer);
	yyset_extra(assembler, assembler->lexer);
}

void assembler_data_destroy
	(struct _assembler_data* assembler)
{
	yylex_destroy(assembler->lexer);
}


