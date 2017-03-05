/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 34 "parser.y" /* yacc.c:1909  */


#include "til_internal.h"


#line 50 "parser.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_I8 = 258,
    T_U8 = 259,
    T_I16 = 260,
    T_U16 = 261,
    T_I32 = 262,
    T_U32 = 263,
    T_I64 = 264,
    T_U64 = 265,
    T_F32 = 266,
    T_F64 = 267,
    T_VOID = 268,
    T_VP = 269,
    T_SSC = 270,
    T_SUC = 271,
    T_SSS = 272,
    T_SUS = 273,
    T_SSI = 274,
    T_SUI = 275,
    T_SSL = 276,
    T_SUL = 277,
    T_SSLL = 278,
    T_SULL = 279,
    T_SF = 280,
    T_SD = 281,
    T_SLD = 282,
    T_NOP = 283,
    T_LD_I8 = 284,
    T_LD_U8 = 285,
    T_LD_I16 = 286,
    T_LD_U16 = 287,
    T_LD_I32 = 288,
    T_LD_U32 = 289,
    T_LD_I64 = 290,
    T_LD_U64 = 291,
    T_LD_F32 = 292,
    T_LD_F64 = 293,
    T_LD_NULL = 294,
    T_LD_STR = 295,
    T_ADDR = 296,
    T_VAL = 297,
    T_AT = 298,
    T_AT_C = 299,
    T_AT_1 = 300,
    T_AT_2 = 301,
    T_AT_3 = 302,
    T_AD_AT = 303,
    T_AD_AT_C = 304,
    T_AD_AT_1 = 305,
    T_AD_AT_2 = 306,
    T_AD_AT_3 = 307,
    T_FIELD = 308,
    T_FIELD_0 = 309,
    T_FIELD_1 = 310,
    T_FIELD_2 = 311,
    T_FIELD_3 = 312,
    T_PT_FIELD = 313,
    T_PT_FIELD_0 = 314,
    T_PT_FIELD_1 = 315,
    T_PT_FIELD_2 = 316,
    T_PT_FIELD_3 = 317,
    T_AD_FIELD = 318,
    T_AD_FIELD_0 = 319,
    T_AD_FIELD_1 = 320,
    T_AD_FIELD_2 = 321,
    T_AD_FIELD_3 = 322,
    T_AD_PT_FIELD = 323,
    T_AD_PT_FIELD_0 = 324,
    T_AD_PT_FIELD_1 = 325,
    T_AD_PT_FIELD_2 = 326,
    T_AD_PT_FIELD_3 = 327,
    T_PUSH = 328,
    T_PUSH_0 = 329,
    T_PUSH_1 = 330,
    T_PUSH_2 = 331,
    T_PUSH_3 = 332,
    T_PUSH_AD = 333,
    T_PUSH_AD_0 = 334,
    T_PUSH_AD_1 = 335,
    T_PUSH_AD_2 = 336,
    T_PUSH_AD_3 = 337,
    T_PUSH_ARG = 338,
    T_PUSH_ARG_0 = 339,
    T_PUSH_ARG_1 = 340,
    T_PUSH_ARG_2 = 341,
    T_PUSH_ARG_3 = 342,
    T_PUSH_GBL = 343,
    T_PUSH_E_GBL = 344,
    T_POP = 345,
    T_DUP = 346,
    T_CLEAR = 347,
    T_DECL_I8 = 348,
    T_DECL_U8 = 349,
    T_DECL_I16 = 350,
    T_DECL_U16 = 351,
    T_DECL_I32 = 352,
    T_DECL_U32 = 353,
    T_DECL_I64 = 354,
    T_DECL_U64 = 355,
    T_DECL_F32 = 356,
    T_DECL_F64 = 357,
    T_DECL_VP = 358,
    T_DECL_PT = 359,
    T_DECL_ST = 360,
    T_DECL_E_ST = 361,
    T_DECL_T = 362,
    T_STORE = 363,
    T_STORE_0 = 364,
    T_STORE_1 = 365,
    T_STORE_2 = 366,
    T_STORE_3 = 367,
    T_STORE_VAL = 368,
    T_STORE_VAL_0 = 369,
    T_STORE_VAL_1 = 370,
    T_STORE_VAL_2 = 371,
    T_STORE_VAL_3 = 372,
    T_STORE_GBL = 373,
    T_STORE_E_GBL = 374,
    T_SET_AT = 375,
    T_SET_AT_0 = 376,
    T_SET_AT_1 = 377,
    T_SET_AT_2 = 378,
    T_SET_AT_3 = 379,
    T_SET_AT_C = 380,
    T_SET_FIELD = 381,
    T_SET_FIELD_0 = 382,
    T_SET_FIELD_1 = 383,
    T_SET_FIELD_2 = 384,
    T_SET_FIELD_3 = 385,
    T_SET_PT_FIELD = 386,
    T_SET_PT_FIELD_0 = 387,
    T_SET_PT_FIELD_1 = 388,
    T_SET_PT_FIELD_2 = 389,
    T_SET_PT_FIELD_3 = 390,
    T_S_ALLOC = 391,
    T_S_ALLOC_C = 392,
    T_GC_ALLOC = 393,
    T_GC_ALLOC_C = 394,
    T_GC_ATOM_ALLOC = 395,
    T_GC_ATOM_ALLOC_C = 396,
    T_CALL = 397,
    T_N_CALL = 398,
    T_E_CALL = 399,
    T_EN_CALL = 400,
    T_RET = 401,
    T_RET_STD = 402,
    T_FUNC_AD = 403,
    T_E_FUNC_AD = 404,
    T_N_FUNC_AD = 405,
    T_EN_FUNC_AD = 406,
    T_CALL_PT = 407,
    T_VAL_ASSIGN = 408,
    T_SIZEOF = 409,
    T_SIZEOF_T = 410,
    T_SIZEOF_T_MUL = 411,
    T_MINUM = 412,
    T_ADD = 413,
    T_SUB = 414,
    T_MUL = 415,
    T_DIV = 416,
    T_REM = 417,
    T_INC = 418,
    T_DEC = 419,
    T_NEG = 420,
    T_AND = 421,
    T_OR = 422,
    T_XOR = 423,
    T_NOT = 424,
    T_SHL = 425,
    T_SHR = 426,
    T_EQ = 427,
    T_NEQ = 428,
    T_LT = 429,
    T_LE = 430,
    T_GT = 431,
    T_GE = 432,
    T_IS_NULL = 433,
    T_TO_BOOL = 434,
    T_TO_BOOL_N = 435,
    T_JMP = 436,
    T_JMP_IF = 437,
    T_JMP_IF_N = 438,
    T_LABEL = 439,
    T_CAST_I8 = 440,
    T_CAST_U8 = 441,
    T_CAST_I16 = 442,
    T_CAST_U16 = 443,
    T_CAST_I32 = 444,
    T_CAST_U32 = 445,
    T_CAST_I64 = 446,
    T_CAST_U64 = 447,
    T_CAST_F32 = 448,
    T_CAST_F64 = 449,
    T_CAST_VP = 450,
    T_CAST_PT = 451,
    T_CAST_ST = 452,
    T_CAST_E_ST = 453,
    T_CAST_T = 454,
    T_ABORT = 455,
    T_NOT_RECOGNIZED = 456,
    T_INT = 457,
    T_FLOAT = 458,
    T_CHAR = 459
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 62 "parser.y" /* yacc.c:1909  */

   char* text;
   char byte;

#line 272 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (struct _assembler_data* assembler);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
