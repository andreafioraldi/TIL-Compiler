/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 40 "parser.y" /* yacc.c:339  */


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


#line 88 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
#line 34 "parser.y" /* yacc.c:355  */


#include "til_internal.h"


#line 124 "parser.c" /* yacc.c:355  */

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
#line 62 "parser.y" /* yacc.c:355  */

   char* text;
   char byte;

#line 346 "parser.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 376 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  272
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   548

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  206
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  4
/* YYNRULES -- Number of rules.  */
#define YYNRULES  204
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  281

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   459

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   205,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   280,   280,   281,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     324,   328,   333,   339,   344,   350,   356,   362,   368,   374,
     381,   388,   395,   402,   406,   412,   416,   420,   424,   430,
     434,   438,   442,   446,   452,   456,   460,   464,   470,   474,
     478,   482,   486,   492,   496,   500,   504,   508,   514,   518,
     522,   526,   530,   536,   540,   544,   548,   552,   558,   562,
     566,   570,   574,   580,   584,   588,   592,   596,   602,   606,
     610,   614,   618,   624,   630,   634,   638,   642,   648,   654,
     660,   666,   672,   678,   684,   690,   696,   702,   708,   714,
     720,   726,   734,   740,   744,   748,   752,   756,   761,   765,
     769,   773,   777,   783,   789,   794,   798,   802,   806,   810,
     816,   822,   826,   830,   834,   838,   844,   848,   852,   856,
     860,   864,   871,   875,   882,   886,   893,   901,   909,   917,
     925,   929,   933,   939,   945,   951,   957,   963,   967,   971,
     977,   985,   989,   993,   997,  1001,  1005,  1009,  1013,  1017,
    1021,  1025,  1029,  1033,  1037,  1041,  1045,  1049,  1053,  1057,
    1061,  1065,  1069,  1073,  1077,  1082,  1088,  1094,  1100,  1106,
    1110,  1114,  1118,  1122,  1126,  1130,  1134,  1138,  1142,  1146,
    1150,  1156,  1162,  1168,  1174
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"'i8'\"", "\"'u8'\"", "\"'i16'\"",
  "\"'u16'\"", "\"'i32'\"", "\"'u32'\"", "\"'i64'\"", "\"'u64'\"",
  "\"'f32'\"", "\"'f64'\"", "\"'void'\"", "\"'vp'\"", "\"'ssc'\"",
  "\"'suc'\"", "\"'sss'\"", "\"'sus'\"", "\"'ssi'\"", "\"'sui'\"",
  "\"'ssl'\"", "\"'sul'\"", "\"'ssll'\"", "\"'sull'\"", "\"'sf'\"",
  "\"'sd'\"", "\"'sld'\"", "\"'nop'\"", "\"'ld_i8'\"", "\"'ld_u8'\"",
  "\"'ld_i16'\"", "\"'ld_u16'\"", "\"'ld_i32'\"", "\"'ld_u32'\"",
  "\"'ld_i64'\"", "\"'ld_u64'\"", "\"'ld_f32'\"", "\"'ld_f64'\"",
  "\"'ld_null'\"", "\"'ld_str'\"", "\"'addr'\"", "\"'val'\"", "\"'at'\"",
  "\"'at_c'\"", "\"'at_1'\"", "\"'at_2'\"", "\"'at_3'\"", "\"'ad_at'\"",
  "\"'ad_at_c'\"", "\"'ad_at_1'\"", "\"'ad_at_2'\"", "\"'ad_at_3'\"",
  "\"'field'\"", "\"'field_0'\"", "\"'field_1'\"", "\"'field_2'\"",
  "\"'field_3'\"", "\"'pt_field'\"", "\"'pt_field_0'\"",
  "\"'pt_field_1'\"", "\"'pt_field_2'\"", "\"'pt_field_3'\"",
  "\"'ad_field'\"", "\"'ad_field_0'\"", "\"'ad_field_1'\"",
  "\"'ad_field_2'\"", "\"'ad_field_3'\"", "\"'ad_pt_field'\"",
  "\"'ad_pt_field_0'\"", "\"'ad_pt_field_1'\"", "\"'ad_pt_field_2'\"",
  "\"'ad_pt_field_3'\"", "\"'push'\"", "\"'push_0'\"", "\"'push_1'\"",
  "\"'push_2'\"", "\"'push_3'\"", "\"'push_ad'\"", "\"'push_ad_0'\"",
  "\"'push_ad_1'\"", "\"'push_ad_2'\"", "\"'push_ad_3'\"",
  "\"'push_arg'\"", "\"'push_arg_0'\"", "\"'push_arg_1'\"",
  "\"'push_arg_2'\"", "\"'push_arg_3'\"", "\"'push_gbl'\"",
  "\"'push_e_gbl'\"", "\"'pop'\"", "\"'dup'\"", "\"'clear'\"",
  "\"'decl_i8'\"", "\"'decl_u8'\"", "\"'decl_i16'\"", "\"'decl_u16'\"",
  "\"'decl_i32'\"", "\"'decl_u32'\"", "\"'decl_i64'\"", "\"'decl_u64'\"",
  "\"'decl_f32'\"", "\"'decl_f64'\"", "\"'decl_vp'\"", "\"'decl_pt'\"",
  "\"'decl_st'\"", "\"'decl_e_st'\"", "\"'decl_t'\"", "\"'store'\"",
  "\"'store_0'\"", "\"'store_1'\"", "\"'store_2'\"", "\"'store_3'\"",
  "\"'store_val'\"", "\"'store_val_0'\"", "\"'store_val_1'\"",
  "\"'store_val_2'\"", "\"'store_val_3'\"", "\"'store_gbl'\"",
  "\"'store_e_gbl'\"", "\"'set_at'\"", "\"'set_at_0'\"", "\"'set_at_1'\"",
  "\"'set_at_2'\"", "\"'set_at_3'\"", "\"'set_at_c'\"", "\"'set_field'\"",
  "\"'set_field_0'\"", "\"'set_field_1'\"", "\"'set_field_2'\"",
  "\"'set_field_3'\"", "\"'set_pt_field'\"", "\"'set_pt_field_0'\"",
  "\"'set_pt_field_1'\"", "\"'set_pt_field_2'\"", "\"'set_pt_field_3'\"",
  "\"'s_alloc'\"", "\"'s_alloc_c'\"", "\"'gc_alloc'\"", "\"'gc_alloc_c'\"",
  "\"'gc_atom_alloc'\"", "\"'gc_atom_alloc_c'\"", "\"'call'\"",
  "\"'n_call'\"", "\"'e_call'\"", "\"'en_call'\"", "\"'ret'\"",
  "\"'ret_std'\"", "\"'func_ad'\"", "\"'e_func_ad'\"", "\"'n_func_ad'\"",
  "\"'en_func_ad'\"", "\"'call_pt'\"", "\"'val_assign'\"", "\"'sizeof'\"",
  "\"'sizeof_t'\"", "\"'sizeof_t_mul'\"", "\"'minum'\"", "\"'add'\"",
  "\"'sub'\"", "\"'mul'\"", "\"'div'\"", "\"'rem'\"", "\"'inc'\"",
  "\"'dec'\"", "\"'neg'\"", "\"'and'\"", "\"'or'\"", "\"'xor'\"",
  "\"'not'\"", "\"'shl'\"", "\"'shr'\"", "\"'eq'\"", "\"'neq'\"",
  "\"'lt'\"", "\"'le'\"", "\"'gt'\"", "\"'ge'\"", "\"'is_null'\"",
  "\"'to_bool'\"", "\"'to_bool_n'\"", "\"'jmp'\"", "\"'jmp_if'\"",
  "\"'jmp_if_n'\"", "\"'label'\"", "\"'cast_i8'\"", "\"'cast_u8'\"",
  "\"'cast_i16'\"", "\"'cast_u16'\"", "\"'cast_i32'\"", "\"'cast_u32'\"",
  "\"'cast_i64'\"", "\"'cast_u64'\"", "\"'cast_f32'\"", "\"'cast_f64'\"",
  "\"'cast_vp'\"", "\"'cast_pt'\"", "\"'cast_st'\"", "\"'cast_e_st'\"",
  "\"'cast_t'\"", "\"'abort'\"", "\"unrecognized token\"", "\"'integer'\"",
  "\"'real'\"", "\"'char'\"", "'^'", "$accept", "instructions_list",
  "type", "instruction", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,    94
};
# endif

#define YYPACT_NINF -176

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-176)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     348,  -176,  -175,  -174,  -171,  -170,  -169,  -168,  -167,  -166,
    -165,  -164,  -176,  -162,  -176,  -176,  -176,  -161,  -176,  -176,
    -176,  -176,  -160,  -176,  -176,  -176,  -159,  -176,  -176,  -176,
    -176,  -158,  -176,  -176,  -176,  -176,  -157,  -176,  -176,  -176,
    -176,  -156,  -176,  -176,  -176,  -176,  -155,  -176,  -176,  -176,
    -176,  -154,  -176,  -176,  -176,  -176,  -153,  -176,  -176,  -176,
    -176,  -152,  -151,  -176,  -176,  -176,  -150,  -149,  -148,  -147,
    -146,  -145,  -144,  -143,  -142,  -141,  -140,  -139,  -138,  -137,
      -3,  -135,  -176,  -176,  -176,  -176,  -134,  -176,  -176,  -176,
    -176,  -132,  -131,  -130,  -176,  -176,  -176,  -176,  -129,  -128,
    -176,  -176,  -176,  -176,  -127,  -176,  -176,  -176,  -176,  -176,
    -126,  -176,  -125,  -176,  -124,  -123,  -122,  -121,  -120,  -176,
    -176,  -119,  -118,  -117,  -116,  -115,  -176,  -176,    -3,    -3,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -114,  -113,  -112,  -111,  -110,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,    -3,
    -109,  -108,    -3,  -176,   175,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,    -3,
    -107,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -106,  -105,  -104,  -102,  -176,  -176,  -176,  -176,
    -176,  -176,  -101,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,     0,    45,    46,    47,     0,    49,    50,
      51,    52,     0,    54,    55,    56,     0,    58,    59,    60,
      61,     0,    63,    64,    65,    66,     0,    68,    69,    70,
      71,     0,    73,    74,    75,    76,     0,    78,    79,    80,
      81,     0,    83,    84,    85,    86,     0,    88,    89,    90,
      91,     0,     0,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   114,   115,   116,     0,   118,   119,   120,
     121,     0,     0,     0,   125,   126,   127,   128,     0,     0,
     131,   132,   133,   134,     0,   136,   137,   138,   139,   140,
       0,   142,     0,   144,     0,     0,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,   157,   158,     0,     0,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,     0,     0,     0,     0,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,     0,
       0,     0,     0,   204,     0,     2,    32,    31,    34,    33,
      35,    36,    37,    38,    39,    40,    41,    42,    44,    48,
      53,    57,    62,    67,    72,    77,    82,    87,    92,    93,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,     0,
       0,   112,   117,   122,   123,   124,   129,   130,   135,   141,
     143,   145,     0,     0,     0,     0,   152,   153,   154,   155,
     156,   159,     0,   184,   185,   186,   187,   188,   200,   201,
     202,   203,     1,     3,    29,   111,   146,   147,   148,   149,
     160
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,  -103,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   174,   240,   175
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   261,   262,   176,   178,   177,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   268,   241,   242,   271,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   263,   264,
     265,   266,   267,   269,   270,   275,   276,   277,   278,   273,
     279,   280,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   128,   129,   202,   202,   204,
     204,   202,   202,   202,   202,   202,   202,    -1,   203,   203,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   169,   202,   202,   172,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   174,
     202,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   207,   209,   202,   204,   202,   204,
     202,   202,   202,   202,   202,   202,   203,   203,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   205,
     208,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   208,   208,   202,   202,   202,   202,   202,   208,   202,
     202,   208,     0,   209,   208,   202,   202,   202,   202,   202,
     202
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   206,   207,   207,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     2,     1,     1,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     2,     3,     3,     3,     3,
       1,     1,     2,     2,     2,     2,     2,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, assembler, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, assembler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct _assembler_data* assembler)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (assembler);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct _assembler_data* assembler)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, assembler);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, struct _assembler_data* assembler)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , assembler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, assembler); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, struct _assembler_data* assembler)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (assembler);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct _assembler_data* assembler)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, lexer);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 29:
#line 311 "parser.y" /* yacc.c:1646  */
    {
		size_t len = strlen((yyvsp[0].text));
		(yyval.text) = malloc(len +2);
		
		((yyval.text))[0] = TYPEID_POINTER;
		memcpy((yyval.text) +1, (yyvsp[0].text), len);
		((yyval.text))[len +1] = 0;
		
		free((yyvsp[0].text));
	}
#line 1896 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 325 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_NOP);
	}
#line 1904 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 329 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_I8);
		til_bytes_add(assembler->bytecode, (yyvsp[0].byte));
	}
#line 1913 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 334 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_I8);
		til_bytes_add(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 1923 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 340 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_U8);
		til_bytes_add(assembler->bytecode, (yyvsp[0].byte));
	}
#line 1932 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 345 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_U8);
		til_bytes_add(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 1942 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 351 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_I16);
		til_bytes_add_short(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 1952 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 357 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_U16);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 1962 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 363 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_I32);
		til_bytes_add_int(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 1972 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 369 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_U32);
		til_bytes_add_uint(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 1982 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 375 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_I64);
		long long num = strtoll((yyvsp[0].text), NULL, 0);
		til_bytes_add_long(assembler->bytecode, num);
		free((yyvsp[0].text));
	}
#line 1993 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 382 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_U64);
		unsigned long long num = strtoull((yyvsp[0].text), NULL, 0);
		til_bytes_add_ulong(assembler->bytecode, num);
		free((yyvsp[0].text));
	}
#line 2004 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 389 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_F32);
		double num = strtod((yyvsp[0].text), NULL);
		til_bytes_add_float32(assembler->bytecode, num);
		free((yyvsp[0].text));
	}
#line 2015 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 396 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_F64);
		double num = strtod((yyvsp[0].text), NULL);
		til_bytes_add_float64(assembler->bytecode, num);
		free((yyvsp[0].text));
	}
#line 2026 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 403 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_NULL);
	}
#line 2034 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 407 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LD_STR);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2044 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 413 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_ADDR);
	}
#line 2052 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 417 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_VAL);
	}
#line 2060 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 421 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AT);
	}
#line 2068 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 425 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AT_C);
		til_bytes_add_uint(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2078 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 431 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AT_1);
	}
#line 2086 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 435 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AT_2);
	}
#line 2094 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 439 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AT_3);
	}
#line 2102 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 443 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_AT);
	}
#line 2110 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 447 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_AT_C);
		til_bytes_add_uint(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2120 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 453 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_AT_1);
	}
#line 2128 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 457 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_AT_2);
	}
#line 2136 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 461 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_AT_3);
	}
#line 2144 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 465 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2154 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 471 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_FIELD_0);
	}
#line 2162 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 475 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_FIELD_1);
	}
#line 2170 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 479 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_FIELD_2);
	}
#line 2178 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 483 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_FIELD_3);
	}
#line 2186 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 487 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PT_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2196 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 493 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PT_FIELD_0);
	}
#line 2204 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 497 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PT_FIELD_1);
	}
#line 2212 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 501 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PT_FIELD_2);
	}
#line 2220 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 505 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PT_FIELD_3);
	}
#line 2228 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 509 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2238 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 515 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_FIELD_0);
	}
#line 2246 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 519 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_FIELD_1);
	}
#line 2254 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 523 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_FIELD_2);
	}
#line 2262 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 527 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_FIELD_3);
	}
#line 2270 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 531 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_PT_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2280 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 537 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_PT_FIELD_0);
	}
#line 2288 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 541 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_PT_FIELD_1);
	}
#line 2296 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 545 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_PT_FIELD_2);
	}
#line 2304 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 549 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AD_PT_FIELD_3);
	}
#line 2312 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 553 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2322 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 559 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_0);
	}
#line 2330 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 563 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_1);
	}
#line 2338 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 567 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_2);
	}
#line 2346 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 571 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_3);
	}
#line 2354 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 575 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_AD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2364 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 581 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_AD_0);
	}
#line 2372 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 585 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_AD_1);
	}
#line 2380 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 589 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_AD_2);
	}
#line 2388 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 593 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_AD_3);
	}
#line 2396 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 597 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_ARG);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2406 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 603 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_ARG_0);
	}
#line 2414 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 607 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_ARG_1);
	}
#line 2422 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 611 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_ARG_2);
	}
#line 2430 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 615 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_ARG_3);
	}
#line 2438 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 619 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_GBL);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2448 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 625 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_PUSH_E_GBL);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2458 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 631 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_POP);
	}
#line 2466 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 635 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DUP);
	}
#line 2474 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 639 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CLEAR);
	}
#line 2482 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 643 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_I8);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2492 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 649 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_U8);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2502 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 655 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_I16);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2512 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 661 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_U16);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2522 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 667 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_I32);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2532 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 673 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_U32);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2542 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 679 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_I64);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2552 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 685 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_U64);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2562 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 691 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_F32);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2572 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 697 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_F64);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2582 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 703 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_VP);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2592 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 709 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_PT);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2602 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 715 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_ST);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2612 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 721 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_E_ST);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2622 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 727 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DECL_E_ST);
		til_bytes_add_str(assembler->bytecode, (yyvsp[-1].text), strlen((yyvsp[-1].text)));
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[-1].text));
		free((yyvsp[0].text));
	}
#line 2634 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 735 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2644 "parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 741 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_0);
	}
#line 2652 "parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 745 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_1);
	}
#line 2660 "parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 749 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_2);
	}
#line 2668 "parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 753 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_3);
	}
#line 2676 "parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 757 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_VAL);
		free((yyvsp[0].text));
	}
#line 2685 "parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 762 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_VAL_0);
	}
#line 2693 "parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 766 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_VAL_1);
	}
#line 2701 "parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 770 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_VAL_2);
	}
#line 2709 "parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 774 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_VAL_3);
	}
#line 2717 "parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 778 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_GBL);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2727 "parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 784 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_STORE_E_GBL);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2737 "parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 790 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_AT);
		free((yyvsp[0].text));
	}
#line 2746 "parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 795 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_AT_0);
	}
#line 2754 "parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 799 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_AT_1);
	}
#line 2762 "parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 803 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_AT_2);
	}
#line 2770 "parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 807 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_AT_3);
	}
#line 2778 "parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 811 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_AT_C);
		til_bytes_add_uint(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2788 "parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 817 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2798 "parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 823 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_FIELD_0);
	}
#line 2806 "parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 827 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_FIELD_1);
	}
#line 2814 "parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 831 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_FIELD_2);
	}
#line 2822 "parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 835 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_FIELD_3);
	}
#line 2830 "parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 839 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_PT_FIELD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 2840 "parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 845 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_PT_FIELD_0);
	}
#line 2848 "parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 849 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_PT_FIELD_1);
	}
#line 2856 "parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 853 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_PT_FIELD_2);
	}
#line 2864 "parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 857 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SET_PT_FIELD_3);
	}
#line 2872 "parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 861 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_S_ALLOC);
	}
#line 2880 "parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 865 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_S_ALLOC_C);
		long long num = strtoll((yyvsp[0].text), NULL, 0);
		til_bytes_add_ulong(assembler->bytecode, num);
		free((yyvsp[0].text));
	}
#line 2891 "parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 872 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_GC_ALLOC);
	}
#line 2899 "parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 876 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_GC_ALLOC_C);
		long long num = strtoll((yyvsp[0].text), NULL, 0);
		til_bytes_add_ulong(assembler->bytecode, num);
		free((yyvsp[0].text));
	}
#line 2910 "parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 883 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_GC_ATOM_ALLOC);
	}
#line 2918 "parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 887 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_GC_ATOM_ALLOC_C);
		long long num = strtoll((yyvsp[0].text), NULL, 0);
		til_bytes_add_ulong(assembler->bytecode, num);
		free((yyvsp[0].text));
	}
#line 2929 "parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 894 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CALL);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[-1].text)));
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[-1].text));
		free((yyvsp[0].text));
	}
#line 2941 "parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 902 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_N_CALL);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[-1].text)));
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[-1].text));
		free((yyvsp[0].text));
	}
#line 2953 "parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 910 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_E_CALL);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[-1].text)));
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[-1].text));
		free((yyvsp[0].text));
	}
#line 2965 "parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 918 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_EN_CALL);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[-1].text)));
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[-1].text));
		free((yyvsp[0].text));
	}
#line 2977 "parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 926 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_RET);
	}
#line 2985 "parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 930 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_RET_STD);
	}
#line 2993 "parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 934 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_FUNC_AD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3003 "parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 940 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_E_FUNC_AD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3013 "parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 946 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_N_FUNC_AD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3023 "parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 952 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_EN_FUNC_AD);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3033 "parser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 958 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CALL_PT);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3043 "parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 964 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_VAL_ASSIGN);
	}
#line 3051 "parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 968 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SIZEOF);
	}
#line 3059 "parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 972 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SIZEOF_T);
		til_bytes_add_str(assembler->bytecode, (yyvsp[0].text), strlen((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3069 "parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 978 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SIZEOF_T_MUL);
		til_bytes_add_str(assembler->bytecode, (yyvsp[-1].text), strlen((yyvsp[-1].text)));
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[-1].text));
		free((yyvsp[0].text));
	}
#line 3081 "parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 986 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_MINUM);
	}
#line 3089 "parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 990 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_ADD);
	}
#line 3097 "parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 994 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SUB);
	}
#line 3105 "parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 998 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_MUL);
	}
#line 3113 "parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1002 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DIV);
	}
#line 3121 "parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1006 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_REM);
	}
#line 3129 "parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1010 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_INC);
	}
#line 3137 "parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1014 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_DEC);
	}
#line 3145 "parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1018 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_NEG);
	}
#line 3153 "parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1022 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_AND);
	}
#line 3161 "parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1026 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_OR);
	}
#line 3169 "parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1030 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_XOR);
	}
#line 3177 "parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1034 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_NOT);
	}
#line 3185 "parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1038 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SHL);
	}
#line 3193 "parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1042 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_SHR);
	}
#line 3201 "parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1046 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_EQ);
	}
#line 3209 "parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1050 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_NEQ);
	}
#line 3217 "parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1054 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LT);
	}
#line 3225 "parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1058 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LE);
	}
#line 3233 "parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1062 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_GT);
	}
#line 3241 "parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1066 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_GE);
	}
#line 3249 "parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1070 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_IS_NULL);
	}
#line 3257 "parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1074 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_TO_BOOL);
	}
#line 3265 "parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1078 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_TO_BOOL_N);
		free((yyvsp[0].text));
	}
#line 3274 "parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1083 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_JMP);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3284 "parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1089 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_JMP_IF);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3294 "parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1095 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_JMP_IF_N);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3304 "parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1101 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_LABEL);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3314 "parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1107 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_I8);
	}
#line 3322 "parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1111 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_U8);
	}
#line 3330 "parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1115 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_I16);
	}
#line 3338 "parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1119 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_U16);
	}
#line 3346 "parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1123 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_I32);
	}
#line 3354 "parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1127 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_U32);
	}
#line 3362 "parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1131 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_I64);
	}
#line 3370 "parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1135 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_U64);
	}
#line 3378 "parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1139 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_F32);
	}
#line 3386 "parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1143 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_F64);
	}
#line 3394 "parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1147 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_VP);
	}
#line 3402 "parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1151 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_PT);
		til_bytes_add_str(assembler->bytecode, (yyvsp[0].text), strlen((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3412 "parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1157 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_ST);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3422 "parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1163 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_E_ST);
		til_bytes_add_ushort(assembler->bytecode, atoi((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3432 "parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1169 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_CAST_PT);
		til_bytes_add_str(assembler->bytecode, (yyvsp[0].text), strlen((yyvsp[0].text)));
		free((yyvsp[0].text));
	}
#line 3442 "parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1175 "parser.y" /* yacc.c:1646  */
    {
		til_bytes_add(assembler->bytecode, OP_ABORT);
	}
#line 3450 "parser.c" /* yacc.c:1646  */
    break;


#line 3454 "parser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, assembler, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, assembler, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, assembler);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, assembler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, assembler, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, assembler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, assembler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1180 "parser.y" /* yacc.c:1906  */


