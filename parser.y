/*
 * parser.y
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
 
%output  "parser.c"
%pure-parser
%locations
%defines "parser.h"
%error-verbose
%parse-param { struct _assembler_data* assembler }
%lex-param { void * lexer }

%code requires {

#include "til_internal.h"

}

%{

#include "parser.h"

int yylex(YYSTYPE* lvalp, YYLTYPE* llocp, void* lexer);

void yyerror(YYLTYPE* locp, struct _assembler_data* assembler, const char* error)
{
	assembler->errors_num++;
	
	char tmp[40];
	snprintf(tmp, 40, "Error: line %d: assembler error: ", locp->first_line + assembler->initial_line);
	til_bytes_add_str(assembler->err, tmp, strlen(tmp));
	
	til_bytes_add_str(assembler->err, (unsigned char*)error, strlen(error));
	til_bytes_add(assembler->err, '\n');
}

#define lexer assembler->lexer

%}

%union {
   char* text;
   char byte;
}

%token <text> T_I8  "'i8'"
%token <text> T_U8  "'u8'"
%token <text> T_I16  "'i16'"
%token <text> T_U16  "'u16'"
%token <text> T_I32  "'i32'"
%token <text> T_U32  "'u32'"
%token <text> T_I64  "'i64'"
%token <text> T_U64  "'u64'"
%token <text> T_F32  "'f32'"
%token <text> T_F64  "'f64'"
%token <text> T_VOID  "'void'"
%token <text> T_VP  "'vp'"
%token <text> T_SSC  "'ssc'"
%token <text> T_SUC  "'suc'"
%token <text> T_SSS  "'sss'"
%token <text> T_SUS  "'sus'"
%token <text> T_SSI  "'ssi'"
%token <text> T_SUI  "'sui'"
%token <text> T_SSL  "'ssl'"
%token <text> T_SUL  "'sul'"
%token <text> T_SSLL  "'ssll'"
%token <text> T_SULL  "'sull'"
%token <text> T_SF  "'sf'"
%token <text> T_SD  "'sd'"
%token <text> T_SLD  "'sld'"

%token T_NOP  "'nop'"
%token T_LD_I8  "'ld_i8'"
%token T_LD_U8  "'ld_u8'"
%token T_LD_I16  "'ld_i16'"
%token T_LD_U16  "'ld_u16'"
%token T_LD_I32  "'ld_i32'"
%token T_LD_U32  "'ld_u32'"
%token T_LD_I64  "'ld_i64'"
%token T_LD_U64  "'ld_u64'"
%token T_LD_F32  "'ld_f32'"
%token T_LD_F64  "'ld_f64'"
%token T_LD_NULL  "'ld_null'"
%token T_LD_STR  "'ld_str'"
%token T_ADDR  "'addr'"
%token T_VAL  "'val'"
%token T_AT  "'at'"
%token T_AT_C  "'at_c'"
%token T_AT_1  "'at_1'"
%token T_AT_2  "'at_2'"
%token T_AT_3  "'at_3'"
%token T_AD_AT  "'ad_at'"
%token T_AD_AT_C  "'ad_at_c'"
%token T_AD_AT_1  "'ad_at_1'"
%token T_AD_AT_2  "'ad_at_2'"
%token T_AD_AT_3  "'ad_at_3'"
%token T_FIELD  "'field'"
%token T_FIELD_0  "'field_0'"
%token T_FIELD_1  "'field_1'"
%token T_FIELD_2  "'field_2'"
%token T_FIELD_3  "'field_3'"
%token T_PT_FIELD  "'pt_field'"
%token T_PT_FIELD_0  "'pt_field_0'"
%token T_PT_FIELD_1  "'pt_field_1'"
%token T_PT_FIELD_2  "'pt_field_2'"
%token T_PT_FIELD_3  "'pt_field_3'"
%token T_AD_FIELD  "'ad_field'"
%token T_AD_FIELD_0  "'ad_field_0'"
%token T_AD_FIELD_1  "'ad_field_1'"
%token T_AD_FIELD_2  "'ad_field_2'"
%token T_AD_FIELD_3  "'ad_field_3'"
%token T_AD_PT_FIELD  "'ad_pt_field'"
%token T_AD_PT_FIELD_0  "'ad_pt_field_0'"
%token T_AD_PT_FIELD_1  "'ad_pt_field_1'"
%token T_AD_PT_FIELD_2  "'ad_pt_field_2'"
%token T_AD_PT_FIELD_3  "'ad_pt_field_3'"
%token T_PUSH  "'push'"
%token T_PUSH_0  "'push_0'"
%token T_PUSH_1  "'push_1'"
%token T_PUSH_2  "'push_2'"
%token T_PUSH_3  "'push_3'"
%token T_PUSH_AD  "'push_ad'"
%token T_PUSH_AD_0  "'push_ad_0'"
%token T_PUSH_AD_1  "'push_ad_1'"
%token T_PUSH_AD_2  "'push_ad_2'"
%token T_PUSH_AD_3  "'push_ad_3'"
%token T_PUSH_ARG  "'push_arg'"
%token T_PUSH_ARG_0  "'push_arg_0'"
%token T_PUSH_ARG_1  "'push_arg_1'"
%token T_PUSH_ARG_2  "'push_arg_2'"
%token T_PUSH_ARG_3  "'push_arg_3'"
%token T_PUSH_GBL  "'push_gbl'"
%token T_PUSH_E_GBL  "'push_e_gbl'"
%token T_POP  "'pop'"
%token T_DUP  "'dup'"
%token T_CLEAR  "'clear'"
%token T_DECL_I8  "'decl_i8'"
%token T_DECL_U8  "'decl_u8'"
%token T_DECL_I16  "'decl_i16'"
%token T_DECL_U16  "'decl_u16'"
%token T_DECL_I32  "'decl_i32'"
%token T_DECL_U32  "'decl_u32'"
%token T_DECL_I64  "'decl_i64'"
%token T_DECL_U64  "'decl_u64'"
%token T_DECL_F32  "'decl_f32'"
%token T_DECL_F64  "'decl_f64'"
%token T_DECL_VP  "'decl_vp'"
%token T_DECL_PT  "'decl_pt'"
%token T_DECL_ST  "'decl_st'"
%token T_DECL_E_ST  "'decl_e_st'"
%token T_DECL_T  "'decl_t'"
%token T_STORE  "'store'"
%token T_STORE_0  "'store_0'"
%token T_STORE_1  "'store_1'"
%token T_STORE_2  "'store_2'"
%token T_STORE_3  "'store_3'"
%token T_STORE_VAL  "'store_val'"
%token T_STORE_VAL_0  "'store_val_0'"
%token T_STORE_VAL_1  "'store_val_1'"
%token T_STORE_VAL_2  "'store_val_2'"
%token T_STORE_VAL_3  "'store_val_3'"
%token T_STORE_GBL  "'store_gbl'"
%token T_STORE_E_GBL  "'store_e_gbl'"
%token T_SET_AT  "'set_at'"
%token T_SET_AT_0  "'set_at_0'"
%token T_SET_AT_1  "'set_at_1'"
%token T_SET_AT_2  "'set_at_2'"
%token T_SET_AT_3  "'set_at_3'"
%token T_SET_AT_C  "'set_at_c'"
%token T_SET_FIELD  "'set_field'"
%token T_SET_FIELD_0  "'set_field_0'"
%token T_SET_FIELD_1  "'set_field_1'"
%token T_SET_FIELD_2  "'set_field_2'"
%token T_SET_FIELD_3  "'set_field_3'"
%token T_SET_PT_FIELD  "'set_pt_field'"
%token T_SET_PT_FIELD_0  "'set_pt_field_0'"
%token T_SET_PT_FIELD_1  "'set_pt_field_1'"
%token T_SET_PT_FIELD_2  "'set_pt_field_2'"
%token T_SET_PT_FIELD_3  "'set_pt_field_3'"
%token T_S_ALLOC  "'s_alloc'"
%token T_S_ALLOC_C  "'s_alloc_c'"
%token T_GC_ALLOC  "'gc_alloc'"
%token T_GC_ALLOC_C  "'gc_alloc_c'"
%token T_GC_ATOM_ALLOC  "'gc_atom_alloc'"
%token T_GC_ATOM_ALLOC_C  "'gc_atom_alloc_c'"
%token T_CALL  "'call'"
%token T_N_CALL  "'n_call'"
%token T_E_CALL  "'e_call'"
%token T_EN_CALL  "'en_call'"
%token T_RET  "'ret'"
%token T_RET_STD  "'ret_std'"
%token T_FUNC_AD  "'func_ad'"
%token T_E_FUNC_AD  "'e_func_ad'"
%token T_N_FUNC_AD  "'n_func_ad'"
%token T_EN_FUNC_AD  "'en_func_ad'"
%token T_CALL_PT  "'call_pt'"
%token T_VAL_ASSIGN  "'val_assign'"
%token T_SIZEOF  "'sizeof'"
%token T_SIZEOF_T  "'sizeof_t'"
%token T_SIZEOF_T_MUL  "'sizeof_t_mul'"
%token T_MINUM  "'minum'"
%token T_ADD  "'add'"
%token T_SUB  "'sub'"
%token T_MUL  "'mul'"
%token T_DIV  "'div'"
%token T_REM  "'rem'"
%token T_INC  "'inc'"
%token T_DEC  "'dec'"
%token T_NEG  "'neg'"
%token T_AND  "'and'"
%token T_OR  "'or'"
%token T_XOR  "'xor'"
%token T_NOT  "'not'"
%token T_SHL  "'shl'"
%token T_SHR  "'shr'"
%token T_EQ  "'eq'"
%token T_NEQ  "'neq'"
%token T_LT  "'lt'"
%token T_LE  "'le'"
%token T_GT  "'gt'"
%token T_GE  "'ge'"
%token T_IS_NULL  "'is_null'"
%token T_TO_BOOL  "'to_bool'"
%token T_TO_BOOL_N  "'to_bool_n'"
%token T_JMP  "'jmp'"
%token T_JMP_IF  "'jmp_if'"
%token T_JMP_IF_N  "'jmp_if_n'"
%token T_LABEL  "'label'"
%token T_CAST_I8  "'cast_i8'"
%token T_CAST_U8  "'cast_u8'"
%token T_CAST_I16  "'cast_i16'"
%token T_CAST_U16  "'cast_u16'"
%token T_CAST_I32  "'cast_i32'"
%token T_CAST_U32  "'cast_u32'"
%token T_CAST_I64  "'cast_i64'"
%token T_CAST_U64  "'cast_u64'"
%token T_CAST_F32  "'cast_f32'"
%token T_CAST_F64  "'cast_f64'"
%token T_CAST_VP  "'cast_vp'"
%token T_CAST_PT  "'cast_pt'"
%token T_CAST_ST  "'cast_st'"
%token T_CAST_E_ST  "'cast_e_st'"
%token T_CAST_T  "'cast_t'"
%token T_ABORT  "'abort'"

%token T_NOT_RECOGNIZED "unrecognized token"

%token <text> T_INT "'integer'"
%token <text> T_FLOAT "'real'"
%token <byte> T_CHAR "'char'"

%start instructions_list

%type <text> type

%%

instructions_list
	: instruction
	| instructions_list instruction
	;

type
	: T_I8
	| T_U8
	| T_I16
	| T_U16
	| T_I32
	| T_U32
	| T_I64
	| T_U64
	| T_F32
	| T_F64
	| T_VOID
	| T_VP
	| T_SSC
	| T_SUC
	| T_SSS
	| T_SUS
	| T_SSI
	| T_SUI
	| T_SSL
	| T_SUL
	| T_SSLL
	| T_SULL
	| T_SF
	| T_SD
	| T_SLD
	| '^' type
	{
		size_t len = strlen($2);
		$$ = malloc(len +2);
		
		($$)[0] = TYPEID_POINTER;
		memcpy($$ +1, $2, len);
		($$)[len +1] = 0;
	}
	;

instruction
	: T_NOP
	{
		til_bytes_add(assembler->bytecode, OP_NOP);
	}
	| T_LD_I8 T_CHAR
	{
		til_bytes_add(assembler->bytecode, OP_LD_I8);
		til_bytes_add(assembler->bytecode, $2);
	}
	| T_LD_I8 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_LD_I8);
		til_bytes_add(assembler->bytecode, atoi($2));
	}
	| T_LD_U8 T_CHAR
	{
		til_bytes_add(assembler->bytecode, OP_LD_U8);
		til_bytes_add(assembler->bytecode, $2);
	}
	| T_LD_U8 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_LD_U8);
		til_bytes_add(assembler->bytecode, atoi($2));
	}
	| T_LD_I16 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_LD_I16);
		til_bytes_add_short(assembler->bytecode, atoi($2));
	}
	| T_LD_U16 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_LD_U16);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_LD_I32 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_LD_I32);
		til_bytes_add_int(assembler->bytecode, atoi($2));
	}
	| T_LD_U32 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_LD_U32);
		til_bytes_add_uint(assembler->bytecode, atoi($2));
	}
	| T_LD_I64 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_LD_I64);
		long long num = strtoll($2, NULL, 0);
		til_bytes_add_long(assembler->bytecode, num);
	}
	| T_LD_U64 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_LD_U64);
		unsigned long long num = strtoull($2, NULL, 0);
		til_bytes_add_ulong(assembler->bytecode, num);
	}
	| T_LD_F32 T_FLOAT
	{
		til_bytes_add(assembler->bytecode, OP_LD_F32);
		double num = strtod($2, NULL);
		til_bytes_add_float32(assembler->bytecode, num);
	}
	| T_LD_F64 T_FLOAT
	{
		til_bytes_add(assembler->bytecode, OP_LD_F64);
		double num = strtod($2, NULL);
		til_bytes_add_float64(assembler->bytecode, num);
	}
	| T_LD_NULL
	{
		til_bytes_add(assembler->bytecode, OP_LD_NULL);
	}
	| T_LD_STR T_INT
	{
		til_bytes_add(assembler->bytecode, OP_LD_STR);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_ADDR
	{
		til_bytes_add(assembler->bytecode, OP_ADDR);
	}
	| T_VAL
	{
		til_bytes_add(assembler->bytecode, OP_VAL);
	}
	| T_AT
	{
		til_bytes_add(assembler->bytecode, OP_AT);
	}
	| T_AT_C T_INT
	{
		til_bytes_add(assembler->bytecode, OP_AT_C);
		til_bytes_add_uint(assembler->bytecode, atoi($2));
	}
	| T_AT_1
	{
		til_bytes_add(assembler->bytecode, OP_AT_1);
	}
	| T_AT_2
	{
		til_bytes_add(assembler->bytecode, OP_AT_2);
	}
	| T_AT_3
	{
		til_bytes_add(assembler->bytecode, OP_AT_3);
	}
	| T_AD_AT
	{
		til_bytes_add(assembler->bytecode, OP_AD_AT);
	}
	| T_AD_AT_C T_INT
	{
		til_bytes_add(assembler->bytecode, OP_AD_AT_C);
		til_bytes_add_uint(assembler->bytecode, atoi($2));
	}
	| T_AD_AT_1
	{
		til_bytes_add(assembler->bytecode, OP_AD_AT_1);
	}
	| T_AD_AT_2
	{
		til_bytes_add(assembler->bytecode, OP_AD_AT_2);
	}
	| T_AD_AT_3
	{
		til_bytes_add(assembler->bytecode, OP_AD_AT_3);
	}
	| T_FIELD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_FIELD_0
	{
		til_bytes_add(assembler->bytecode, OP_FIELD_0);
	}
	| T_FIELD_1
	{
		til_bytes_add(assembler->bytecode, OP_FIELD_1);
	}
	| T_FIELD_2
	{
		til_bytes_add(assembler->bytecode, OP_FIELD_2);
	}
	| T_FIELD_3
	{
		til_bytes_add(assembler->bytecode, OP_FIELD_3);
	}
	| T_PT_FIELD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_PT_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_PT_FIELD_0
	{
		til_bytes_add(assembler->bytecode, OP_PT_FIELD_0);
	}
	| T_PT_FIELD_1
	{
		til_bytes_add(assembler->bytecode, OP_PT_FIELD_1);
	}
	| T_PT_FIELD_2
	{
		til_bytes_add(assembler->bytecode, OP_PT_FIELD_2);
	}
	| T_PT_FIELD_3
	{
		til_bytes_add(assembler->bytecode, OP_PT_FIELD_3);
	}
	| T_AD_FIELD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_AD_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_AD_FIELD_0
	{
		til_bytes_add(assembler->bytecode, OP_AD_FIELD_0);
	}
	| T_AD_FIELD_1
	{
		til_bytes_add(assembler->bytecode, OP_AD_FIELD_1);
	}
	| T_AD_FIELD_2
	{
		til_bytes_add(assembler->bytecode, OP_AD_FIELD_2);
	}
	| T_AD_FIELD_3
	{
		til_bytes_add(assembler->bytecode, OP_AD_FIELD_3);
	}
	| T_AD_PT_FIELD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_AD_PT_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_AD_PT_FIELD_0
	{
		til_bytes_add(assembler->bytecode, OP_AD_PT_FIELD_0);
	}
	| T_AD_PT_FIELD_1
	{
		til_bytes_add(assembler->bytecode, OP_AD_PT_FIELD_1);
	}
	| T_AD_PT_FIELD_2
	{
		til_bytes_add(assembler->bytecode, OP_AD_PT_FIELD_2);
	}
	| T_AD_PT_FIELD_3
	{
		til_bytes_add(assembler->bytecode, OP_AD_PT_FIELD_3);
	}
	| T_PUSH T_INT
	{
		til_bytes_add(assembler->bytecode, OP_PUSH);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_PUSH_0
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_0);
	}
	| T_PUSH_1
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_1);
	}
	| T_PUSH_2
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_2);
	}
	| T_PUSH_3
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_3);
	}
	| T_PUSH_AD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_AD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_PUSH_AD_0
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_AD_0);
	}
	| T_PUSH_AD_1
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_AD_1);
	}
	| T_PUSH_AD_2
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_AD_2);
	}
	| T_PUSH_AD_3
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_AD_3);
	}
	| T_PUSH_ARG T_INT
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_ARG);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_PUSH_ARG_0
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_ARG_0);
	}
	| T_PUSH_ARG_1
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_ARG_1);
	}
	| T_PUSH_ARG_2
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_ARG_2);
	}
	| T_PUSH_ARG_3
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_ARG_3);
	}
	| T_PUSH_GBL T_INT
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_GBL);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_PUSH_E_GBL T_INT
	{
		til_bytes_add(assembler->bytecode, OP_PUSH_E_GBL);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_POP
	{
		til_bytes_add(assembler->bytecode, OP_POP);
	}
	| T_DUP
	{
		til_bytes_add(assembler->bytecode, OP_DUP);
	}
	| T_CLEAR
	{
		til_bytes_add(assembler->bytecode, OP_CLEAR);
	}
	| T_DECL_I8 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_I8);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_U8 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_U8);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_I16 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_I16);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_U16 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_U16);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_I32 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_I32);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_U32 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_U32);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_I64 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_I64);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_U64 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_U64);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_F32 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_F32);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_F64 T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_F64);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_VP T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_VP);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_PT T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_PT);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_ST T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_ST);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_E_ST T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_E_ST);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_DECL_T type T_INT
	{
		til_bytes_add(assembler->bytecode, OP_DECL_E_ST);
		til_bytes_add_str(assembler->bytecode, $2, strlen($2));
		til_bytes_add_ushort(assembler->bytecode, atoi($3));
	}
	| T_STORE T_INT
	{
		til_bytes_add(assembler->bytecode, OP_STORE);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_STORE_0
	{
		til_bytes_add(assembler->bytecode, OP_STORE_0);
	}
	| T_STORE_1
	{
		til_bytes_add(assembler->bytecode, OP_STORE_1);
	}
	| T_STORE_2
	{
		til_bytes_add(assembler->bytecode, OP_STORE_2);
	}
	| T_STORE_3
	{
		til_bytes_add(assembler->bytecode, OP_STORE_3);
	}
	| T_STORE_VAL T_INT
	{
		til_bytes_add(assembler->bytecode, OP_STORE_VAL);
	}
	| T_STORE_VAL_0
	{
		til_bytes_add(assembler->bytecode, OP_STORE_VAL_0);
	}
	| T_STORE_VAL_1
	{
		til_bytes_add(assembler->bytecode, OP_STORE_VAL_1);
	}
	| T_STORE_VAL_2
	{
		til_bytes_add(assembler->bytecode, OP_STORE_VAL_2);
	}
	| T_STORE_VAL_3
	{
		til_bytes_add(assembler->bytecode, OP_STORE_VAL_3);
	}
	| T_STORE_GBL T_INT
	{
		til_bytes_add(assembler->bytecode, OP_STORE_GBL);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_STORE_E_GBL T_INT
	{
		til_bytes_add(assembler->bytecode, OP_STORE_E_GBL);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_SET_AT T_INT
	{
		til_bytes_add(assembler->bytecode, OP_SET_AT);
	}
	| T_SET_AT_0
	{
		til_bytes_add(assembler->bytecode, OP_SET_AT_0);
	}
	| T_SET_AT_1
	{
		til_bytes_add(assembler->bytecode, OP_SET_AT_1);
	}
	| T_SET_AT_2
	{
		til_bytes_add(assembler->bytecode, OP_SET_AT_2);
	}
	| T_SET_AT_3
	{
		til_bytes_add(assembler->bytecode, OP_SET_AT_3);
	}
	| T_SET_AT_C T_INT
	{
		til_bytes_add(assembler->bytecode, OP_SET_AT_C);
		til_bytes_add_uint(assembler->bytecode, atoi($2));
	}
	| T_SET_FIELD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_SET_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_SET_FIELD_0
	{
		til_bytes_add(assembler->bytecode, OP_SET_FIELD_0);
	}
	| T_SET_FIELD_1
	{
		til_bytes_add(assembler->bytecode, OP_SET_FIELD_1);
	}
	| T_SET_FIELD_2
	{
		til_bytes_add(assembler->bytecode, OP_SET_FIELD_2);
	}
	| T_SET_FIELD_3
	{
		til_bytes_add(assembler->bytecode, OP_SET_FIELD_3);
	}
	| T_SET_PT_FIELD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_SET_PT_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_SET_PT_FIELD_0
	{
		til_bytes_add(assembler->bytecode, OP_SET_PT_FIELD_0);
	}
	| T_SET_PT_FIELD_1
	{
		til_bytes_add(assembler->bytecode, OP_SET_PT_FIELD_1);
	}
	| T_SET_PT_FIELD_2
	{
		til_bytes_add(assembler->bytecode, OP_SET_PT_FIELD_2);
	}
	| T_SET_PT_FIELD_3
	{
		til_bytes_add(assembler->bytecode, OP_SET_PT_FIELD_3);
	}
	| T_S_ALLOC
	{
		til_bytes_add(assembler->bytecode, OP_S_ALLOC);
	}
	| T_S_ALLOC_C T_INT
	{
		til_bytes_add(assembler->bytecode, OP_S_ALLOC_C);
		long long num = strtoll($2, NULL, 0);
		til_bytes_add_ulong(assembler->bytecode, num);
	}
	| T_GC_ALLOC
	{
		til_bytes_add(assembler->bytecode, OP_GC_ALLOC);
	}
	| T_GC_ALLOC_C T_INT
	{
		til_bytes_add(assembler->bytecode, OP_GC_ALLOC_C);
		long long num = strtoll($2, NULL, 0);
		til_bytes_add_ulong(assembler->bytecode, num);
	}
	| T_GC_ATOM_ALLOC
	{
		til_bytes_add(assembler->bytecode, OP_GC_ATOM_ALLOC);
	}
	| T_GC_ATOM_ALLOC_C T_INT
	{
		til_bytes_add(assembler->bytecode, OP_GC_ATOM_ALLOC_C);
		long long num = strtoll($2, NULL, 0);
		til_bytes_add_ulong(assembler->bytecode, num);
	}
	| T_CALL T_INT T_INT
	{
		til_bytes_add(assembler->bytecode, OP_CALL);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
		til_bytes_add_ushort(assembler->bytecode, atoi($3));
	}
	| T_N_CALL T_INT T_INT
	{
		til_bytes_add(assembler->bytecode, OP_N_CALL);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
		til_bytes_add_ushort(assembler->bytecode, atoi($3));
	}
	| T_E_CALL T_INT T_INT
	{
		til_bytes_add(assembler->bytecode, OP_E_CALL);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
		til_bytes_add_ushort(assembler->bytecode, atoi($3));
	}
	| T_EN_CALL T_INT T_INT
	{
		til_bytes_add(assembler->bytecode, OP_EN_CALL);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
		til_bytes_add_ushort(assembler->bytecode, atoi($3));
	}
	| T_RET
	{
		til_bytes_add(assembler->bytecode, OP_RET);
	}
	| T_RET_STD
	{
		til_bytes_add(assembler->bytecode, OP_RET_STD);
	}
	| T_FUNC_AD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_FUNC_AD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_E_FUNC_AD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_E_FUNC_AD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_N_FUNC_AD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_N_FUNC_AD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_EN_FUNC_AD T_INT
	{
		til_bytes_add(assembler->bytecode, OP_EN_FUNC_AD);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_CALL_PT T_INT
	{
		til_bytes_add(assembler->bytecode, OP_CALL_PT);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_VAL_ASSIGN
	{
		til_bytes_add(assembler->bytecode, OP_VAL_ASSIGN);
	}
	| T_SIZEOF
	{
		til_bytes_add(assembler->bytecode, OP_SIZEOF);
	}
	| T_SIZEOF_T type
	{
		til_bytes_add(assembler->bytecode, OP_SIZEOF_T);
		til_bytes_add_str(assembler->bytecode, $2, strlen($2));
	}
	| T_SIZEOF_T_MUL type T_INT
	{
		til_bytes_add(assembler->bytecode, OP_SIZEOF_T_MUL);
		til_bytes_add_str(assembler->bytecode, $2, strlen($2));
		til_bytes_add_ushort(assembler->bytecode, atoi($3));
	}
	| T_MINUM
	{
		til_bytes_add(assembler->bytecode, OP_MINUM);
	}
	| T_ADD
	{
		til_bytes_add(assembler->bytecode, OP_ADD);
	}
	| T_SUB
	{
		til_bytes_add(assembler->bytecode, OP_SUB);
	}
	| T_MUL
	{
		til_bytes_add(assembler->bytecode, OP_MUL);
	}
	| T_DIV
	{
		til_bytes_add(assembler->bytecode, OP_DIV);
	}
	| T_REM
	{
		til_bytes_add(assembler->bytecode, OP_REM);
	}
	| T_INC
	{
		til_bytes_add(assembler->bytecode, OP_INC);
	}
	| T_DEC
	{
		til_bytes_add(assembler->bytecode, OP_DEC);
	}
	| T_NEG
	{
		til_bytes_add(assembler->bytecode, OP_NEG);
	}
	| T_AND
	{
		til_bytes_add(assembler->bytecode, OP_AND);
	}
	| T_OR
	{
		til_bytes_add(assembler->bytecode, OP_OR);
	}
	| T_XOR
	{
		til_bytes_add(assembler->bytecode, OP_XOR);
	}
	| T_NOT
	{
		til_bytes_add(assembler->bytecode, OP_NOT);
	}
	| T_SHL
	{
		til_bytes_add(assembler->bytecode, OP_SHL);
	}
	| T_SHR
	{
		til_bytes_add(assembler->bytecode, OP_SHR);
	}
	| T_EQ
	{
		til_bytes_add(assembler->bytecode, OP_EQ);
	}
	| T_NEQ
	{
		til_bytes_add(assembler->bytecode, OP_NEQ);
	}
	| T_LT
	{
		til_bytes_add(assembler->bytecode, OP_LT);
	}
	| T_LE
	{
		til_bytes_add(assembler->bytecode, OP_LE);
	}
	| T_GT
	{
		til_bytes_add(assembler->bytecode, OP_GT);
	}
	| T_GE
	{
		til_bytes_add(assembler->bytecode, OP_GE);
	}
	| T_IS_NULL
	{
		til_bytes_add(assembler->bytecode, OP_IS_NULL);
	}
	| T_TO_BOOL
	{
		til_bytes_add(assembler->bytecode, OP_TO_BOOL);
	}
	| T_TO_BOOL_N T_INT
	{
		til_bytes_add(assembler->bytecode, OP_TO_BOOL_N);
	}
	| T_JMP T_INT
	{
		til_bytes_add(assembler->bytecode, OP_JMP);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_JMP_IF T_INT
	{
		til_bytes_add(assembler->bytecode, OP_JMP_IF);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_JMP_IF_N T_INT
	{
		til_bytes_add(assembler->bytecode, OP_JMP_IF_N);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_LABEL T_INT
	{
		til_bytes_add(assembler->bytecode, OP_LABEL);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_CAST_I8
	{
		til_bytes_add(assembler->bytecode, OP_CAST_I8);
	}
	| T_CAST_U8
	{
		til_bytes_add(assembler->bytecode, OP_CAST_U8);
	}
	| T_CAST_I16
	{
		til_bytes_add(assembler->bytecode, OP_CAST_I16);
	}
	| T_CAST_U16
	{
		til_bytes_add(assembler->bytecode, OP_CAST_U16);
	}
	| T_CAST_I32
	{
		til_bytes_add(assembler->bytecode, OP_CAST_I32);
	}
	| T_CAST_U32
	{
		til_bytes_add(assembler->bytecode, OP_CAST_U32);
	}
	| T_CAST_I64
	{
		til_bytes_add(assembler->bytecode, OP_CAST_I64);
	}
	| T_CAST_U64
	{
		til_bytes_add(assembler->bytecode, OP_CAST_U64);
	}
	| T_CAST_F32
	{
		til_bytes_add(assembler->bytecode, OP_CAST_F32);
	}
	| T_CAST_F64
	{
		til_bytes_add(assembler->bytecode, OP_CAST_F64);
	}
	| T_CAST_VP
	{
		til_bytes_add(assembler->bytecode, OP_CAST_VP);
	}
	| T_CAST_PT type
	{
		til_bytes_add(assembler->bytecode, OP_CAST_PT);
		til_bytes_add_str(assembler->bytecode, $2, strlen($2));
	}
	| T_CAST_ST T_INT
	{
		til_bytes_add(assembler->bytecode, OP_CAST_ST);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_CAST_E_ST T_INT
	{
		til_bytes_add(assembler->bytecode, OP_CAST_E_ST);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_CAST_T type
	{
		til_bytes_add(assembler->bytecode, OP_CAST_PT);
		til_bytes_add_str(assembler->bytecode, $2, strlen($2));
	}
	| T_ABORT
	{
		til_bytes_add(assembler->bytecode, OP_ABORT);
	}
	;

%%

