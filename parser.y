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

%token T_I8  "'i8'"
%token T_U8  "'u8'"
%token T_I16  "'i16'"
%token T_U16  "'u16'"
%token T_I32  "'i32'"
%token T_U32  "'u32'"
%token T_I64  "'i64'"
%token T_U64  "'u64'"
%token T_F32  "'f32'"
%token T_F64  "'f64'"
%token T_VOID  "'void'"
%token T_VP  "'vp'"
%token T_SSC  "'ssc'"
%token T_SUC  "'suc'"
%token T_SSS  "'sss'"
%token T_SUS  "'sus'"
%token T_SSI  "'ssi'"
%token T_SUI  "'sui'"
%token T_SSL  "'ssl'"
%token T_SUL  "'sul'"
%token T_SSLL  "'ssll'"
%token T_SULL  "'sull'"
%token T_SF  "'sf'"
%token T_SD  "'sd'"
%token T_SLD  "'sld'"
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
%token T_ABORT  "'abort'"

%token T_NOT_RECOGNIZED

%token <text> T_INT "'integer'"
%token <byte> T_CHAR "'char'"

%start instructions_list

%%

instructions_list
	: instruction
	| instructions_list instruction
	;

type
	: T_I8
	| T_U8
	
	| '^' type
	;

instruction
	: T_NOP
	{
		til_bytes_add(assembler->bytecode, 0);
	}
	| T_LD_I8 T_CHAR
	{
		til_bytes_add(assembler->bytecode, 1);
		til_bytes_add(assembler->bytecode, $2);
	}
	| T_LD_I8 T_INT
	{
		til_bytes_add(assembler->bytecode, 1);
		til_bytes_add(assembler->bytecode, atoi($2));
	}
	| T_LD_U8 T_CHAR
	{
		til_bytes_add(assembler->bytecode, 2);
		til_bytes_add(assembler->bytecode, $2);
	}
	| T_LD_U8 T_INT
	{
		til_bytes_add(assembler->bytecode, 2);
		til_bytes_add(assembler->bytecode, atoi($2));
	}
	| T_LD_I16 T_INT
	{
		til_bytes_add(assembler->bytecode, 3);
		til_bytes_add_short(assembler->bytecode, atoi($2));
	}
	| T_LD_U16 T_INT
	{
		til_bytes_add(assembler->bytecode, 4);
		til_bytes_add_ushort(assembler->bytecode, atoi($2));
	}
	| T_LD_I32 T_INT
	{
		til_bytes_add(assembler->bytecode, 5);
		til_bytes_add_short(assembler->bytecode, atoi($2));
	}
	;

%%

