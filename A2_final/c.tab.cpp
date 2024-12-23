/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "c.y"

#include <cstdio>
#include <iostream>
using namespace std;
#include "asttree.hpp"
// stuff from flex that bison needs to know about:
extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;
void yyerror(const char *s);

ASTNode *ASTtree = NULL;

#line 84 "c.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_C_TAB_HPP_INCLUDED
# define YY_YY_C_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "c.y"

	#include <iostream>
	#include "asttree.hpp"

#line 132 "c.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CHAR_CONSTANT = 258,
    IDENTIFIER = 259,
    STRING_LITERAL = 260,
    I_CONSTANT = 261,
    F_CONSTANT = 262,
    FUNC_NAME = 263,
    SIZEOF = 264,
    PTR_OP = 265,
    INC_OP = 266,
    DEC_OP = 267,
    LEFT_OP = 268,
    RIGHT_OP = 269,
    LE_OP = 270,
    GE_OP = 271,
    EQ_OP = 272,
    NE_OP = 273,
    AND_OP = 274,
    OR_OP = 275,
    MUL_ASSIGN = 276,
    DIV_ASSIGN = 277,
    MOD_ASSIGN = 278,
    ADD_ASSIGN = 279,
    SUB_ASSIGN = 280,
    LEFT_ASSIGN = 281,
    RIGHT_ASSIGN = 282,
    AND_ASSIGN = 283,
    XOR_ASSIGN = 284,
    OR_ASSIGN = 285,
    TYPEDEF_NAME = 286,
    ENUMERATION_CONSTANT = 287,
    TYPEDEF = 288,
    EXTERN = 289,
    STATIC = 290,
    AUTO = 291,
    REGISTER = 292,
    INLINE = 293,
    CONST = 294,
    RESTRICT = 295,
    VOLATILE = 296,
    BOOL = 297,
    CHAR = 298,
    SHORT = 299,
    INT = 300,
    LONG = 301,
    SIGNED = 302,
    UNSIGNED = 303,
    FLOAT = 304,
    DOUBLE = 305,
    VOID = 306,
    COMPLEX = 307,
    IMAGINARY = 308,
    STRUCT = 309,
    UNION = 310,
    ENUM = 311,
    ELLIPSIS = 312,
    CASE = 313,
    DEFAULT = 314,
    IF = 315,
    ELSE = 316,
    SWITCH = 317,
    WHILE = 318,
    DO = 319,
    FOR = 320,
    GOTO = 321,
    CONTINUE = 322,
    BREAK = 323,
    RETURN = 324,
    ALIGNAS = 325,
    ALIGNOF = 326,
    ATOMIC = 327,
    GENERIC = 328,
    NORETURN = 329,
    STATIC_ASSERT = 330,
    THREAD_LOCAL = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "c.y"

	ASTNode* node;
	int ival;
	float fval;
	char* sval;
	char cval;

#line 228 "c.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1001

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  192
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  318

#define YYUNDEFTOK  2
#define YYMAXUTOK   331


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    93,     2,     2,     2,    95,    89,     2,
      80,    81,    84,    90,    78,    91,    88,    94,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,    77,
      96,    79,    97,   100,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,    98,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,    99,    86,    92,     2,     2,     2,
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
      75,    76
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    72,    73,    84,    85,    90,    91,   105,
     106,   110,   120,   137,   143,   145,   151,   152,   153,   154,
     155,   160,   161,   170,   176,   180,   189,   194,   195,   196,
     197,   201,   215,   216,   220,   221,   222,   223,   224,   228,
     229,   230,   234,   235,   236,   237,   241,   246,   252,   253,
     262,   266,   272,   273,   282,   283,   287,   288,   289,   290,
     291,   292,   296,   297,   310,   315,   316,   320,   321,   325,
     338,   348,   352,   363,   373,   391,   409,   423,   441,   445,
     446,   447,   448,   452,   453,   460,   464,   465,   466,   467,
     471,   472,   473,   477,   478,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   495,   496,   508,   509,   510,
     511,   515,   516,   517,   518,   519,   520,   524,   525,   530,
     535,   543,   544,   549,   557,   558,   563,   571,   572,   577,
     582,   587,   595,   596,   601,   609,   610,   618,   619,   627,
     628,   636,   637,   644,   645,   652,   653,   661,   662,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     689,   690,   700,   701,   718,   719,   723,   724,   725,   729,
     730,   731,   732,   733,   734,   735,   736,   737,   738,   739,
     744,   748,   749,   753,   754,   763,   764,   765,   766,   770,
     771,   775,   776
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR_CONSTANT", "IDENTIFIER",
  "STRING_LITERAL", "I_CONSTANT", "F_CONSTANT", "FUNC_NAME", "SIZEOF",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF_NAME",
  "ENUMERATION_CONSTANT", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE", "BOOL", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID",
  "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC",
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "';'", "','", "'='", "'('",
  "')'", "'['", "']'", "'*'", "'{'", "'}'", "':'", "'.'", "'&'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "$accept", "start", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "declarator", "direct_declarator", "pointer", "type_specifier",
  "initializer", "initializer_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "block_item_list",
  "block_item", "statement", "compound_statement", "labeled_statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "expression", "constant_expression",
  "primary_expression", "constant", "string", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "specifier_qualifier_list", "alignment_specifier", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "designation",
  "designator_list", "designator", "type_qualifier", "function_specifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,    59,    44,    61,
      40,    41,    91,    93,    42,   123,   125,    58,    46,    38,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63
};
# endif

#define YYPACT_NINF (-248)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     927,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
     -68,  -248,  -248,    29,   927,  -248,  -248,  -248,     4,   927,
     927,   927,   927,   536,  -248,  -248,  -248,  -248,    43,   -41,
     -22,  -248,   774,    -9,     2,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,   799,   799,   536,  -248,  -248,
    -248,  -248,  -248,  -248,    -5,    13,  -248,  -248,  -248,    85,
    -248,   799,   -60,    95,   175,    -6,   173,    37,   -20,   -16,
     116,    -7,  -248,    49,    81,    96,  -248,  -248,    43,   480,
     263,   211,  -248,     4,  -248,   790,    87,    -9,  -248,  -248,
     -50,   199,  -248,  -248,    98,  -248,  -248,   179,  -248,  -248,
     603,   799,   194,  -248,   799,   799,   799,   799,   799,   799,
     799,   799,   799,   799,   799,   799,   799,   799,   799,   799,
     799,   799,   799,   855,   627,    54,  -248,    58,  -248,  -248,
    -248,   122,    57,  -248,  -248,   120,   799,   121,   129,   130,
     132,   445,   134,   213,   138,   141,   644,  -248,  -248,  -248,
     354,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,   115,
    -248,  -248,  -248,    43,   149,   154,  -248,  -248,   799,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,   799,   148,  -248,  -248,   -28,  -248,   -51,  -248,  -248,
    -248,  -248,   -60,   -60,    95,    95,   175,   175,   175,   175,
      -6,    -6,   173,    37,   -20,   -16,   116,    -2,  -248,   153,
     155,  -248,   156,   158,    58,   870,   658,   799,   233,  -248,
     -53,   480,   -43,  -248,   445,   151,   445,   799,   799,   799,
     181,   512,   165,  -248,  -248,  -248,   117,  -248,  -248,  -248,
    -248,  -248,   907,  -248,  -248,    57,   799,  -248,  -248,   799,
    -248,  -248,  -248,  -248,  -248,   174,  -248,   176,   178,   180,
    -248,   287,  -248,  -248,  -248,  -248,  -248,   445,  -248,    -1,
      47,    82,   177,   694,   694,  -248,  -248,  -248,  -248,   -12,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,   480,  -248,
     445,   445,   445,   799,   674,   785,   378,  -248,  -248,   197,
    -248,  -248,    83,   445,    91,   445,    97,  -248,   445,   195,
    -248,   445,  -248,   445,  -248,  -248,  -248,  -248
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   189,   185,   186,   187,    38,    35,    36,    37,    34,
       0,   188,   190,     0,     2,     3,     5,     6,     0,    14,
      20,    16,    18,     0,     1,     4,    27,    11,     0,    33,
       0,    21,    24,    26,     0,    13,    19,    15,    17,    92,
      86,    93,    90,    91,    94,     0,     0,     0,   112,   111,
     113,   114,   115,   116,   161,     0,    95,    87,    88,   107,
     117,     0,   121,   124,   127,   132,   135,   137,   139,   141,
     143,   145,    85,   165,     0,     0,    32,    12,     0,     0,
       0,     0,     9,     0,     8,     0,     0,    25,   108,   109,
       0,   117,   147,    83,     0,   160,   163,     0,   101,   102,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   164,   168,   162,    28,
      22,    24,     0,    23,    41,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,    62,    54,
       0,    52,    55,    57,    56,    58,    59,    60,    61,     0,
      10,     7,    31,    51,     0,    47,    48,    29,     0,    89,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     149,     0,     0,   100,    97,     0,   105,     0,    99,   118,
     119,   120,   122,   123,   125,   126,   130,   131,   128,   129,
     133,   134,   136,   138,   140,   142,   144,     0,   176,     0,
       0,   170,   112,     0,   166,     0,     0,     0,     0,    43,
       0,     0,     0,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,     0,    63,    53,    68,
      50,    30,     0,    84,   148,     0,     0,    98,    96,     0,
     177,   169,   171,   172,   178,     0,   173,   112,     0,     0,
     184,     0,    39,    42,   180,   182,    64,     0,    66,     0,
       0,     0,     0,     0,     0,    78,    82,    46,    49,     0,
     106,   146,   179,   174,   175,   183,    40,    45,     0,    65,
       0,     0,     0,     0,     0,     0,     0,   103,    44,    70,
      71,    72,     0,     0,     0,     0,     0,   104,     0,     0,
      76,     0,    74,     0,    69,    73,    77,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -248,  -248,  -248,   259,  -248,  -248,   -29,     1,  -248,   198,
     -11,   243,    -3,    25,   -77,    34,   -93,  -248,    40,  -248,
     136,  -137,   -14,  -248,  -215,  -248,  -248,  -248,   -47,  -125,
    -248,  -248,  -248,  -248,  -248,    -4,  -248,    89,    94,    45,
      90,   167,   169,   170,   168,   188,  -248,   -18,    19,  -248,
     246,  -248,   250,   187,   186,  -247,  -248,   102,  -248,  -248
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    81,    17,    83,    30,    31,
     131,    33,    34,    19,   219,   220,   164,   165,   166,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    55,
      56,    57,    58,    59,   185,    91,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    92,    93,   181,
      73,    20,    74,   126,   127,   221,   222,   223,    21,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    18,   133,    82,   230,    72,    26,    32,    26,   111,
     112,   225,    23,   121,   288,    18,   274,    75,    84,    60,
      35,    36,    37,    38,   104,   261,    76,   168,   168,    24,
     209,   169,   248,   262,   105,   106,   264,     5,     6,   217,
       7,    88,    89,    29,     8,   218,     9,    26,    54,   288,
     246,   149,   160,   247,   187,    77,    78,   103,   294,   295,
      39,    40,    41,    42,    43,    44,   296,   161,    45,    46,
     125,    85,    54,    86,   297,   207,   168,   168,   118,    54,
     290,    27,    28,   119,    28,   249,   163,   266,    29,   268,
     113,   114,   259,   122,    96,    97,    98,    99,   134,   236,
     189,   190,   191,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    72,   186,
     125,   149,   255,    28,   163,   168,   117,    29,   291,   123,
     289,   124,    60,    29,   123,   120,   124,    47,   215,   217,
     216,    48,   132,   213,   263,   218,    49,    50,    51,    52,
      53,   134,   240,   299,   300,   301,   196,   197,   198,   199,
     168,   168,   128,   292,   309,   100,   310,   101,   312,   168,
     167,   314,   311,   102,   316,   168,   317,   129,   313,   182,
     269,   270,   271,   183,   287,   107,   108,   243,   109,   110,
     115,   116,   239,   168,   276,   168,   192,   193,   188,    72,
     244,    79,   273,   194,   195,   200,   201,   224,   226,   227,
     228,   298,   229,    60,   231,   233,   163,   232,   234,   287,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     241,   281,   242,   245,   250,   258,   251,   260,   267,   252,
     134,   253,   275,   163,   272,    60,   302,   304,   306,     1,
       2,     3,     4,     5,     6,   282,     7,   293,   308,   283,
       8,   284,     9,   285,   134,   280,    39,   135,    41,    42,
      43,    44,   315,    25,    45,    46,   130,    87,   180,   279,
     134,    10,   278,    11,   202,    12,   238,   203,   205,   204,
      39,    40,    41,    42,    43,    44,    80,    94,    45,    46,
      95,     1,     2,     3,     4,     5,     6,   134,     7,   206,
     210,   214,     8,     0,     9,   134,     0,     0,     0,     0,
       0,   136,   137,   138,   265,   139,   140,   141,   142,   143,
     144,   145,   146,    10,     0,    11,     0,    12,     0,     0,
     147,     0,     0,    47,     0,     0,     0,    48,    80,   148,
       0,     0,    49,    50,    51,    52,    53,    39,   135,    41,
      42,    43,    44,     0,     0,    45,    46,    47,     0,   217,
       0,    48,   132,   286,     0,   218,    49,    50,    51,    52,
      53,    39,    40,    41,    42,    43,    44,     0,     0,    45,
      46,     0,     1,     2,     3,     4,     5,     6,     0,     7,
       0,     0,     0,     8,     0,     9,     0,     0,     0,     0,
       0,     0,   136,   137,   138,     0,   139,   140,   141,   142,
     143,   144,   145,   146,    10,     0,    11,     0,    12,     0,
       0,   147,     0,     0,    47,     0,     0,     0,    48,    80,
     237,     0,     0,    49,    50,    51,    52,    53,    39,   135,
      41,    42,    43,    44,     0,     0,    45,    46,    47,     0,
     217,     0,    48,   132,   307,     0,   218,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,    44,     0,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,   137,   138,     0,   139,   140,   141,
     142,   143,   144,   145,   146,    39,    40,    41,    42,    43,
      44,     0,   147,    45,    46,    47,     0,     0,     0,    48,
      80,     0,     0,     0,    49,    50,    51,    52,    53,    39,
      40,    41,    42,    43,    44,     0,     0,    45,    46,     0,
       1,     2,     3,     4,     5,     6,     0,     7,     0,     0,
      47,     8,     0,     9,    48,   132,     0,     0,     0,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     5,     6,
       0,     7,    10,     0,    11,     8,    12,     9,     0,   147,
       0,     0,    47,     0,     0,     0,    48,     0,     0,     0,
       0,    49,    50,    51,    52,    53,    39,    40,    41,    42,
      43,    44,     0,     0,    45,    46,    47,     0,     0,     0,
      48,     0,     0,     0,     0,    49,    50,    51,    52,    53,
      39,    40,    41,    42,    43,    44,     0,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,    44,     0,     0,    45,    46,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,    45,
      46,     0,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,    44,    47,   184,    45,    46,    48,     0,     0,
       0,     0,    49,    50,    51,    52,    53,    39,    40,    41,
      42,    43,    44,     0,     0,    45,    46,    47,     0,     0,
     211,   212,     0,     0,     0,     0,    49,    50,    51,    52,
      53,   235,     0,     0,    47,     0,     0,     0,    48,     0,
       0,     0,     0,    49,    50,    51,    52,    53,    47,     0,
       0,   256,   257,     0,     0,     0,     0,    49,    50,    51,
      52,    53,     0,     0,    47,   303,     0,     0,    48,     0,
       0,     0,     0,    49,    50,    51,    52,    53,     0,     0,
       0,   147,     0,     0,    47,     0,     0,     0,    48,     0,
       0,     0,     0,    49,    50,    51,    52,    53,    39,    40,
      41,    42,    43,    44,     0,     0,    45,    46,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
      45,    46,     1,     2,     3,     4,     5,     6,     0,     7,
       0,     0,     0,     8,     0,     9,     0,     0,     1,     2,
       3,     4,     5,     6,     0,     7,     0,     0,     0,     8,
       0,     9,     0,     0,    10,     0,    11,     0,    12,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,    80,
      10,     0,    11,     0,    12,    47,   305,     0,     0,    48,
       0,   162,     0,     0,    49,    50,    51,    52,    53,    47,
       0,     0,     0,    48,     0,     0,     0,     0,    49,    50,
      51,    52,    53,     1,     2,     3,     4,     5,     6,     0,
       7,     0,     0,     0,     8,     0,     9,     0,     1,     2,
       3,     4,     5,     6,     0,     7,     0,     0,     0,     8,
       0,     9,     0,     0,     0,    10,     0,    11,     0,    12,
       0,     0,     0,     0,     0,   123,   208,   124,     0,    29,
      10,     0,    11,     0,    12,     1,     2,     3,     4,     5,
       6,   254,     7,     0,     0,     0,     8,     0,     9,     0,
       0,     0,     0,     0,   277,     1,     2,     3,     4,     5,
       6,     0,     7,     0,     0,     0,     8,    10,     9,    11,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     0,    11,
       0,    12
};

static const yytype_int16 yycheck[] =
{
      47,     0,    79,    32,   141,    23,     4,    18,     4,    15,
      16,   136,    80,    20,   261,    14,   231,    28,    32,    23,
      19,    20,    21,    22,    84,    78,    29,    78,    78,     0,
     123,    81,    83,    86,    94,    95,    79,    42,    43,    82,
      45,    45,    46,    84,    49,    88,    51,     4,    23,   296,
      78,    80,    81,    81,   101,    77,    78,    61,   273,   274,
       3,     4,     5,     6,     7,     8,    78,    81,    11,    12,
      73,    80,    47,    82,    86,   122,    78,    78,    98,    54,
      81,    77,    80,    99,    80,    87,    85,   224,    84,   226,
      96,    97,   217,   100,    81,    10,    11,    12,    79,   146,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   136,   100,
     123,   150,   215,    80,   123,    78,    89,    84,    81,    80,
     267,    82,   136,    84,    80,    19,    82,    80,    80,    82,
      82,    84,    85,   124,   221,    88,    89,    90,    91,    92,
      93,   132,   163,   290,   291,   292,   111,   112,   113,   114,
      78,    78,    81,    81,    81,    80,   303,    82,   305,    78,
      83,   308,    81,    88,   311,    78,   313,    81,    81,    81,
     227,   228,   229,     4,   261,    90,    91,   168,    13,    14,
      17,    18,    77,    78,    77,    78,   107,   108,     4,   217,
     181,    79,   231,   109,   110,   115,   116,    87,    87,    80,
      80,   288,    80,   217,    80,    77,   215,     4,    77,   296,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      81,   249,    78,    85,    81,   216,    81,     4,    87,    83,
     221,    83,    77,   242,    63,   249,   293,   294,   295,    38,
      39,    40,    41,    42,    43,    81,    45,    80,    61,    83,
      49,    83,    51,    83,   245,   246,     3,     4,     5,     6,
       7,     8,    77,    14,    11,    12,    78,    34,    79,   245,
     261,    70,   242,    72,   117,    74,   150,   118,   120,   119,
       3,     4,     5,     6,     7,     8,    85,    47,    11,    12,
      54,    38,    39,    40,    41,    42,    43,   288,    45,   121,
     123,   125,    49,    -1,    51,   296,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,   222,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    -1,    72,    -1,    74,    -1,    -1,
      77,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,    86,
      -1,    -1,    89,    90,    91,    92,    93,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    80,    -1,    82,
      -1,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      93,     3,     4,     5,     6,     7,     8,    -1,    -1,    11,
      12,    -1,    38,    39,    40,    41,    42,    43,    -1,    45,
      -1,    -1,    -1,    49,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    72,    -1,    74,    -1,
      -1,    77,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,
      86,    -1,    -1,    89,    90,    91,    92,    93,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    80,    -1,
      82,    -1,    84,    85,    86,    -1,    88,    89,    90,    91,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,     3,     4,     5,     6,     7,
       8,    -1,    77,    11,    12,    80,    -1,    -1,    -1,    84,
      85,    -1,    -1,    -1,    89,    90,    91,    92,    93,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,    12,    -1,
      38,    39,    40,    41,    42,    43,    -1,    45,    -1,    -1,
      80,    49,    -1,    51,    84,    85,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    -1,    42,    43,
      -1,    45,    70,    -1,    72,    49,    74,    51,    -1,    77,
      -1,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    80,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    80,    81,    11,    12,    84,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    80,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    77,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    80,    -1,
      -1,    83,    84,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    -1,    -1,    80,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    77,    -1,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    38,    39,    40,    41,    42,    43,    -1,    45,
      -1,    -1,    -1,    49,    -1,    51,    -1,    -1,    38,    39,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    -1,    49,
      -1,    51,    -1,    -1,    70,    -1,    72,    -1,    74,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    85,
      70,    -1,    72,    -1,    74,    80,    81,    -1,    -1,    84,
      -1,    81,    -1,    -1,    89,    90,    91,    92,    93,    80,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    38,    39,    40,    41,    42,    43,    -1,
      45,    -1,    -1,    -1,    49,    -1,    51,    -1,    38,    39,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    -1,    49,
      -1,    51,    -1,    -1,    -1,    70,    -1,    72,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    -1,    84,
      70,    -1,    72,    -1,    74,    38,    39,    40,    41,    42,
      43,    81,    45,    -1,    -1,    -1,    49,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    57,    38,    39,    40,    41,    42,
      43,    -1,    45,    -1,    -1,    -1,    49,    70,    51,    72,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,    40,    41,    42,    43,    45,    49,    51,
      70,    72,    74,   102,   103,   104,   105,   107,   108,   114,
     152,   159,   160,    80,     0,   104,     4,    77,    80,    84,
     109,   110,   111,   112,   113,   108,   108,   108,   108,     3,
       4,     5,     6,     7,     8,    11,    12,    80,    84,    89,
      90,    91,    92,    93,   114,   130,   131,   132,   133,   134,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   151,   153,   111,   113,    77,    78,    79,
      85,   106,   107,   108,   123,    80,    82,   112,   136,   136,
     129,   136,   148,   149,   153,   151,    81,    10,    11,    12,
      80,    82,    88,   136,    84,    94,    95,    90,    91,    13,
      14,    15,    16,    96,    97,    17,    18,    89,    98,    99,
      19,    20,   100,    80,    82,   113,   154,   155,    81,    81,
     110,   111,    85,   115,   149,     4,    58,    59,    60,    62,
      63,    64,    65,    66,    67,    68,    69,    77,    86,   107,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     107,   123,    81,   108,   117,   118,   119,    83,    78,    81,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      79,   150,    81,     4,    81,   135,   149,   129,     4,   136,
     136,   136,   138,   138,   139,   139,   140,   140,   140,   140,
     141,   141,   142,   143,   144,   145,   146,   129,    81,   117,
     154,    83,    84,   149,   155,    80,    82,    82,    88,   115,
     116,   156,   157,   158,    87,   130,    87,    80,    80,    80,
     122,    80,     4,    77,    77,    77,   129,    86,   121,    77,
     111,    81,    78,   149,   149,    85,    78,    81,    83,    87,
      81,    81,    83,    83,    81,   117,    83,    84,   149,   130,
       4,    78,    86,   115,    79,   158,   122,    87,   122,   129,
     129,   129,    63,   107,   125,    77,    77,    57,   119,   116,
     149,   148,    81,    83,    83,    83,    86,   115,   156,   122,
      81,    81,    81,    80,   125,   125,    78,    86,   115,   122,
     122,   122,   129,    81,   129,    81,   129,    86,    61,    81,
     122,    81,   122,    81,   122,    77,   122,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   113,   113,   114,   114,   114,   114,   114,   115,
     115,   115,   116,   116,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     122,   122,   123,   123,   124,   124,   124,   125,   125,   126,
     126,   126,   127,   127,   127,   127,   127,   127,   128,   128,
     128,   128,   128,   129,   129,   130,   131,   131,   131,   131,
     132,   132,   132,   133,   133,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   135,   135,   136,   136,   136,
     136,   137,   137,   137,   137,   137,   137,   138,   138,   138,
     138,   139,   139,   139,   140,   140,   140,   141,   141,   141,
     141,   141,   142,   142,   142,   143,   143,   144,   144,   145,
     145,   146,   146,   147,   147,   148,   148,   149,   149,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     151,   151,   152,   152,   153,   153,   154,   154,   154,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     156,   157,   157,   158,   158,   159,   159,   159,   159,   160,
     160,   152,   152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     4,     3,     1,
       2,     2,     3,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     3,     3,     1,     2,     1,     1,     3,     3,
       4,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     1,     2,     1,     4,     3,     3,     1,     1,     3,
       2,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     4,     3,     1,     2,     7,
       5,     5,     5,     7,     6,     7,     6,     7,     3,     2,
       2,     2,     3,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     3,     4,     3,
       3,     2,     2,     6,     7,     1,     3,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     4,     4,     2,     1,     2,     1,     1,     3,
       2,     3,     3,     3,     4,     4,     2,     3,     3,     4,
       2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 68 "c.y"
                          {ASTNode *temp = new ASTNode("START");  temp->children = (yyvsp[0].node)->children; (yyval.node)=temp; ASTtree = (yyval.node);}
#line 1800 "c.tab.cpp"
    break;

  case 3:
#line 72 "c.y"
                                                      {ASTNode *temp = new ASTNode(""); temp->children.push_back((yyvsp[0].node)); (yyval.node)=temp;}
#line 1806 "c.tab.cpp"
    break;

  case 4:
#line 73 "c.y"
                                                      {ASTNode *temp = new ASTNode("");
														for(int i=0; i<(yyvsp[-1].node)->children.size(); i++)
														{
															temp->children.push_back((yyvsp[-1].node)->children[i]);
														}
														temp->children.push_back((yyvsp[0].node));
														(yyval.node) = temp;
												   }
#line 1819 "c.tab.cpp"
    break;

  case 5:
#line 84 "c.y"
                                                                        {(yyval.node)=(yyvsp[0].node);}
#line 1825 "c.tab.cpp"
    break;

  case 6:
#line 85 "c.y"
                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 1831 "c.tab.cpp"
    break;

  case 7:
#line 90 "c.y"
                                                                                   {(yyval.node) = (yyvsp[-2].node);}
#line 1837 "c.tab.cpp"
    break;

  case 8:
#line 91 "c.y"
                                                                                        {auto *fun = new FunctionNode(""); 
																			  	fun->children = (yyvsp[-2].node)->children;
																				if ((yyvsp[-1].node)->type == "dummy" || "func"){
																				for (int i=0; i< (yyvsp[-1].node)->children.size(); i++){
																					fun->children.push_back((yyvsp[-1].node)->children[i]);
																				}}
																				else{
																				fun->children.push_back((yyvsp[-1].node));}
																				fun->children.push_back((yyvsp[0].node));
																			  	(yyval.node) = fun;}
#line 1852 "c.tab.cpp"
    break;

  case 11:
#line 110 "c.y"
                                                                                                                         {	string dtype;
																				for (auto child: (yyvsp[-1].node)->children){
																				if (child->type == "datatype"){
																					dtype = ((DataTypeNode*)child)->name;
																					break;
																				}
																				}
																				DeclNode *temp = new DeclNode(dtype);
																				temp->children = (yyvsp[-1].node)->children; (yyval.node)=temp;
																			 }
#line 1867 "c.tab.cpp"
    break;

  case 12:
#line 120 "c.y"
                                                                                                         {	string dtype;
																				for (auto child: (yyvsp[-2].node)->children){
																				if (child->type == "datatype"){
																					dtype = ((DataTypeNode*)child)->name;
																					break;
																				}
																				}
																				DeclNode *temp = new DeclNode(dtype);
																				temp->children = (yyvsp[-2].node)->children;
																				for (int i=0; i<(yyvsp[-1].node)->children.size(); i++){
																					temp->children.push_back((yyvsp[-1].node)->children[i]);
																				}
																				(yyval.node)=temp; 
																				}
#line 1886 "c.tab.cpp"
    break;

  case 13:
#line 137 "c.y"
                                                                                                                {auto *temp =  new ASTNode("dummy"); temp->children.push_back((yyvsp[-1].node)); 
																			for (int i = 0; i<(yyvsp[0].node)->children.size();i++){
																				temp->children.push_back((yyvsp[0].node)->children[i]);
																			}
																			(yyval.node) = temp;}
#line 1896 "c.tab.cpp"
    break;

  case 14:
#line 143 "c.y"
                                                                                                                                        {auto *temp = new ASTNode("dummy"); temp->children.push_back((yyvsp[0].node)); (yyval.node) = temp;}
#line 1902 "c.tab.cpp"
    break;

  case 15:
#line 145 "c.y"
                                                                                                                {auto *temp =  new ASTNode("dummy"); temp->children.push_back((yyvsp[-1].node)); 
																			for (int i = 0; i<(yyvsp[0].node)->children.size();i++){
																				temp->children.push_back((yyvsp[0].node)->children[i]);
																			}
																			(yyval.node) = temp;}
#line 1912 "c.tab.cpp"
    break;

  case 16:
#line 151 "c.y"
                                                                                                                                        {auto *temp = new ASTNode("dummy"); temp->children.push_back((yyvsp[0].node)); (yyval.node) = temp;}
#line 1918 "c.tab.cpp"
    break;

  case 21:
#line 160 "c.y"
                                                                                 {auto *temp = new ASTNode("dummy"); temp->children.push_back((yyvsp[0].node)); (yyval.node) = temp; }
#line 1924 "c.tab.cpp"
    break;

  case 22:
#line 161 "c.y"
                                                                                          {ASTNode *temp = new ASTNode("dummy");
																	for (int i=0; i<(yyvsp[-2].node)->children.size(); i++){
																		temp->children.push_back((yyvsp[-2].node)->children[i]);
																	}
																	temp->children.push_back((yyvsp[0].node));
																	(yyval.node)=temp;}
#line 1935 "c.tab.cpp"
    break;

  case 23:
#line 170 "c.y"
                                                                                                {auto *temp = new ASTNode("decl_info"); temp->children.push_back((yyvsp[-2].node));
																 OperatorNode* init = new OperatorNode("binary_op","ASSIGN"); 
																 init->children.push_back((yyvsp[-2].node));
																 init->children.push_back((yyvsp[0].node));
																 temp->children.push_back(init);
																 (yyval.node) = temp;}
#line 1946 "c.tab.cpp"
    break;

  case 24:
#line 176 "c.y"
                                                                                        {auto *temp = new ASTNode("decl_info"); temp->children.push_back((yyvsp[0].node)); (yyval.node) = temp;}
#line 1952 "c.tab.cpp"
    break;

  case 25:
#line 180 "c.y"
                                                                                                                { (yyvsp[-1].node)->children.push_back((yyvsp[0].node));
																	// int depth = ((PointerNode*)$1)->num_indirection;
																	// ASTNode* temp = $1;
																	// for (int i=1;i<depth;i++){
																	// 	temp = temp->children[0];
																	// }
																	// temp->children.push_back($2);
																	(yyval.node) = (yyvsp[-1].node);}
#line 1965 "c.tab.cpp"
    break;

  case 26:
#line 189 "c.y"
                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 1971 "c.tab.cpp"
    break;

  case 27:
#line 194 "c.y"
                                                    {ASTNode *temp = new IdNode((yyvsp[0].sval)); (yyval.node) = temp;}
#line 1977 "c.tab.cpp"
    break;

  case 30:
#line 197 "c.y"
                                                                     {ASTNode *temp = new ASTNode("func");
																   temp->children.push_back((yyvsp[-3].node));
																   temp->children.push_back((yyvsp[-1].node));
																   (yyval.node) = temp;}
#line 1986 "c.tab.cpp"
    break;

  case 31:
#line 201 "c.y"
                                                                                                          {auto *temp = new ASTNode("func"); temp->children.push_back((yyvsp[-2].node)); (yyval.node)=temp; }
#line 1992 "c.tab.cpp"
    break;

  case 32:
#line 215 "c.y"
                                {auto *temp = new PointerNode(((PointerNode*)(yyvsp[0].node))->num_indirection + 1);  (yyval.node) = temp;}
#line 1998 "c.tab.cpp"
    break;

  case 33:
#line 216 "c.y"
                                        {auto *temp = new PointerNode(1); (yyval.node)=temp; }
#line 2004 "c.tab.cpp"
    break;

  case 34:
#line 220 "c.y"
                            {DataTypeNode *kwrd = new DataTypeNode("type_spec","VOID"); (yyval.node) = kwrd; }
#line 2010 "c.tab.cpp"
    break;

  case 35:
#line 221 "c.y"
                                        {DataTypeNode *kwrd = new DataTypeNode("type_spec","CHAR"); (yyval.node) = kwrd; }
#line 2016 "c.tab.cpp"
    break;

  case 36:
#line 222 "c.y"
                                        {DataTypeNode *kwrd = new DataTypeNode("type_spec","INT"); (yyval.node) = kwrd; }
#line 2022 "c.tab.cpp"
    break;

  case 37:
#line 223 "c.y"
                                        {DataTypeNode *kwrd = new DataTypeNode("type_spec","FLOAT"); (yyval.node) = kwrd; }
#line 2028 "c.tab.cpp"
    break;

  case 38:
#line 224 "c.y"
                                        {DataTypeNode *kwrd = new DataTypeNode("type_spec","BOOL"); (yyval.node) = kwrd; }
#line 2034 "c.tab.cpp"
    break;

  case 41:
#line 230 "c.y"
                                               {(yyval.node) = (yyvsp[0].node);}
#line 2040 "c.tab.cpp"
    break;

  case 46:
#line 241 "c.y"
                                           {ASTNode *temp = new ASTNode("parameters");
										temp->children = (yyvsp[-2].node)->children;
										temp->children.push_back(new KeywordNode("ELLIPSIS"));
										(yyval.node) = temp;
										}
#line 2050 "c.tab.cpp"
    break;

  case 47:
#line 246 "c.y"
                                                                {ASTNode *temp = new ASTNode("parameters");
										 temp->children = (yyvsp[0].node)->children;
										 (yyval.node) = temp;}
#line 2058 "c.tab.cpp"
    break;

  case 48:
#line 252 "c.y"
                                                                        {ASTNode *temp = new ASTNode("dummy"); temp->children.push_back((yyvsp[0].node)); (yyval.node) = temp;}
#line 2064 "c.tab.cpp"
    break;

  case 49:
#line 253 "c.y"
                                                    {ASTNode *temp = new ASTNode("dummy");
												 for (int i=0; i<(yyvsp[-2].node)->children.size(); i++){
													temp->children.push_back((yyvsp[-2].node)->children[i]);
												 }
												 temp->children.push_back((yyvsp[0].node));
												 (yyval.node)=temp;}
#line 2075 "c.tab.cpp"
    break;

  case 50:
#line 262 "c.y"
                                                   {auto *temp = new ParamNode("param_with_id");
												temp->children = (yyvsp[-1].node)->children;
												temp->children.push_back((yyvsp[0].node));
												(yyval.node) =temp;}
#line 2084 "c.tab.cpp"
    break;

  case 51:
#line 266 "c.y"
                                                                {auto *temp = new ParamNode("param_type_only"); temp->children = (yyvsp[0].node)->children; (yyval.node) = temp;}
#line 2090 "c.tab.cpp"
    break;

  case 52:
#line 272 "c.y"
                                                                {auto *temp = new ASTNode("dummy"); temp->children.push_back((yyvsp[0].node)); (yyval.node) = temp;}
#line 2096 "c.tab.cpp"
    break;

  case 53:
#line 273 "c.y"
                                                {ASTNode *temp = new ASTNode("dummy");
										for(int i=0; i<(yyvsp[-1].node)->children.size();i++){
											temp->children.push_back((yyvsp[-1].node)->children[i]);
										}
										temp->children.push_back((yyvsp[0].node));
										(yyval.node) = temp;}
#line 2107 "c.tab.cpp"
    break;

  case 54:
#line 282 "c.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 2113 "c.tab.cpp"
    break;

  case 55:
#line 283 "c.y"
                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2119 "c.tab.cpp"
    break;

  case 56:
#line 287 "c.y"
                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2125 "c.tab.cpp"
    break;

  case 57:
#line 288 "c.y"
                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2131 "c.tab.cpp"
    break;

  case 58:
#line 289 "c.y"
                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2137 "c.tab.cpp"
    break;

  case 59:
#line 290 "c.y"
                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2143 "c.tab.cpp"
    break;

  case 60:
#line 291 "c.y"
                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2149 "c.tab.cpp"
    break;

  case 61:
#line 292 "c.y"
                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2155 "c.tab.cpp"
    break;

  case 62:
#line 296 "c.y"
                                                                                                                                                        {ASTNode *temp = new ASTNode("SCOPE"); (yyval.node) = temp;}
#line 2161 "c.tab.cpp"
    break;

  case 63:
#line 297 "c.y"
                                                                                                                                        {ASTNode *temp = new ASTNode("SCOPE"); 
																				if ((yyvsp[-1].node)->type == "dummy"){
																					for (int i=0;i<(yyvsp[-1].node)->children.size();i++){
																						temp->children.push_back((yyvsp[-1].node)->children[i]);}
																				}
																				else
																					temp->children.push_back((yyvsp[-1].node));
																				(yyval.node) = temp;
																				 }
#line 2175 "c.tab.cpp"
    break;

  case 64:
#line 310 "c.y"
                                                                                                        {auto *temp = new BranchNode("LABEL"); 
																auto *id = new IdNode((yyvsp[-2].sval));
																temp->children.push_back((ASTNode*)id);	
																temp->children.push_back((yyvsp[0].node));
																(yyval.node) = temp; }
#line 2185 "c.tab.cpp"
    break;

  case 67:
#line 320 "c.y"
                                                                                                                                {ASTNode *temp = new ASTNode(";"); (yyval.node)=temp;}
#line 2191 "c.tab.cpp"
    break;

  case 68:
#line 321 "c.y"
                                                                                                                        {(yyval.node)=(yyvsp[-1].node);}
#line 2197 "c.tab.cpp"
    break;

  case 69:
#line 325 "c.y"
                                                                      {auto *temp = new BranchNode("IF_ELSE"); 
																	auto *cond = new BasicBlockNode("condition");
																	cond->children.push_back((yyvsp[-4].node));
																	auto *ifpart = new BasicBlockNode("true_block");
																	ifpart->children.push_back((yyvsp[-2].node));
																	auto *elsepart = new BasicBlockNode("false_block");
																	elsepart->children.push_back((yyvsp[0].node));
																	temp->children.push_back(cond);
																	temp->children.push_back(ifpart);
																	temp->children.push_back(elsepart);
																	(yyval.node) = temp;
																	}
#line 2214 "c.tab.cpp"
    break;

  case 70:
#line 338 "c.y"
                                                                                                        {auto *temp = new BranchNode("IF"); 
																	auto *cond = new BasicBlockNode("condition");
																	cond->children.push_back((yyvsp[-2].node));
																	auto *ifpart = new BasicBlockNode("true_block");
																	ifpart->children.push_back((yyvsp[0].node));
																	temp->children.push_back(cond);
																	temp->children.push_back(ifpart);
																	(yyval.node) = temp;
																	}
#line 2228 "c.tab.cpp"
    break;

  case 72:
#line 352 "c.y"
                                                                                                {auto *temp = new BranchNode("WHILE"); 
																	auto *cond = new BasicBlockNode("condition");
																	cond->children.push_back((yyvsp[-2].node));
																	auto *ifpart = new BasicBlockNode("true_block");
																	ifpart->children.push_back((yyvsp[0].node));
																	temp->children.push_back(cond);
																	temp->children.push_back(ifpart);
																	(yyval.node) = temp;

																	}
#line 2243 "c.tab.cpp"
    break;

  case 73:
#line 363 "c.y"
                                                                                                {auto *temp = new BranchNode("DO_WHILE"); 
																	auto *cond = new BasicBlockNode("condition");
																	cond->children.push_back((yyvsp[-2].node));
																	auto *ifpart = new BasicBlockNode("true_block");
																	ifpart->children.push_back((yyvsp[-5].node));
																	temp->children.push_back(ifpart);
																	temp->children.push_back(cond);
																	(yyval.node) = temp;
																	}
#line 2257 "c.tab.cpp"
    break;

  case 74:
#line 373 "c.y"
                                                                                                                                                        {auto *temp = new BranchNode("FOR"); 
																											auto *cond = new BasicBlockNode("condition");
																											auto *decl = new BasicBlockNode("initial");
																											cond->children.push_back((yyvsp[-2].node));
																											if ((yyvsp[-3].node)->type != ";"){
																												decl->children.push_back((yyvsp[-3].node));
																												temp->children.push_back(decl);
																												temp->children.push_back(cond);
																											}
																											else{
																												temp->children.push_back(cond);
																											}
																											auto *ifpart = new BasicBlockNode("true_block");
																											ifpart->children.push_back((yyvsp[0].node));
																											temp->children.push_back(ifpart);
																											(yyval.node) = temp;
																											}
#line 2279 "c.tab.cpp"
    break;

  case 75:
#line 391 "c.y"
                                                                                                        {auto *temp = new BranchNode("FOR"); 
																							auto *cond = new BasicBlockNode("condition");
																							auto *decl = new BasicBlockNode("initial");
																							auto *incr = new BasicBlockNode("increment");
																							cond->children.push_back((yyvsp[-3].node));
																							incr->children.push_back((yyvsp[-2].node));
																							if ((yyvsp[-4].node)->type != ";"){
																								decl->children.push_back((yyvsp[-4].node));
																								temp->children.push_back(decl);
																							}
																							temp->children.push_back(cond);
																							temp->children.push_back(incr);
																							auto *ifpart = new BasicBlockNode("true_block");
																							ifpart->children.push_back((yyvsp[0].node));
																							temp->children.push_back(ifpart);
																							(yyval.node) = temp;
																							}
#line 2301 "c.tab.cpp"
    break;

  case 76:
#line 409 "c.y"
                                                                                                                            {auto *temp = new BranchNode("FOR"); 
																							auto *cond = new BasicBlockNode("condition");
																							auto *decl = new BasicBlockNode("initial");
																							cond->children.push_back((yyvsp[-2].node));
																							decl->children.push_back((yyvsp[-3].node));
																							temp->children.push_back(decl);
																							temp->children.push_back(cond);
																							auto *ifpart = new BasicBlockNode("true_block");
																							ifpart->children.push_back((yyvsp[0].node));
																							temp->children.push_back(ifpart);
																							(yyval.node) = temp;
																							}
#line 2318 "c.tab.cpp"
    break;

  case 77:
#line 423 "c.y"
                                                                                                                        {auto *temp = new BranchNode("FOR"); 
																							auto *cond = new BasicBlockNode("condition");
																							auto *decl = new BasicBlockNode("initial");
																							auto *incr = new BasicBlockNode("increment");
																							cond->children.push_back((yyvsp[-3].node));
																							incr->children.push_back((yyvsp[-2].node));
																							decl->children.push_back((yyvsp[-4].node));
																							temp->children.push_back(decl);
																							temp->children.push_back(cond);
																							temp->children.push_back(incr);
																							auto *ifpart = new BasicBlockNode("true_block");
																							ifpart->children.push_back((yyvsp[0].node));
																							temp->children.push_back(ifpart);
																							(yyval.node) = temp;
																							}
#line 2338 "c.tab.cpp"
    break;

  case 78:
#line 441 "c.y"
                                                                                                {auto *temp = new BranchNode("GOTO"); 
															auto *id = new IdNode((yyvsp[-1].sval));
															temp->children.push_back((ASTNode*)id);
															(yyval.node) = temp;}
#line 2347 "c.tab.cpp"
    break;

  case 79:
#line 445 "c.y"
                                                                                                        {auto *temp = new BranchNode("CONTINUE"); (yyval.node)=temp;}
#line 2353 "c.tab.cpp"
    break;

  case 80:
#line 446 "c.y"
                                                                                                                {auto *temp = new BranchNode("BREAK"); (yyval.node)=temp;}
#line 2359 "c.tab.cpp"
    break;

  case 81:
#line 447 "c.y"
                                                                                                        {auto *temp = new KeywordNode("return_void", "RETURN"); (yyval.node)=temp;}
#line 2365 "c.tab.cpp"
    break;

  case 82:
#line 448 "c.y"
                                                                                                {KeywordNode *temp = new KeywordNode("return_value", "RETURN"); temp->children.push_back((yyvsp[-1].node)); (yyval.node)=temp;}
#line 2371 "c.tab.cpp"
    break;

  case 83:
#line 452 "c.y"
                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2377 "c.tab.cpp"
    break;

  case 84:
#line 453 "c.y"
                                                                            {auto *temp = new ASTNode("expr"); 
															temp->children = (yyvsp[-2].node)->children;
															temp->children.push_back((yyvsp[0].node));
															(yyval.node) = temp;}
#line 2386 "c.tab.cpp"
    break;

  case 85:
#line 460 "c.y"
                                                                     {(yyval.node)=(yyvsp[0].node);}
#line 2392 "c.tab.cpp"
    break;

  case 86:
#line 464 "c.y"
                                                                                                        {ASTNode *temp = new IdNode((yyvsp[0].sval)); (yyval.node) = temp;}
#line 2398 "c.tab.cpp"
    break;

  case 87:
#line 465 "c.y"
                                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2404 "c.tab.cpp"
    break;

  case 88:
#line 466 "c.y"
                                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2410 "c.tab.cpp"
    break;

  case 89:
#line 467 "c.y"
                                                                                                {(yyval.node)=(yyvsp[-1].node);}
#line 2416 "c.tab.cpp"
    break;

  case 90:
#line 471 "c.y"
                                                                  {ConstNode *con = new ConstNode((yyvsp[0].ival));  (yyval.node)=con;}
#line 2422 "c.tab.cpp"
    break;

  case 91:
#line 472 "c.y"
                                                                                                  {ConstNode *con = new ConstNode((yyvsp[0].fval)); (yyval.node)=con;}
#line 2428 "c.tab.cpp"
    break;

  case 92:
#line 473 "c.y"
                                                                                                  {ConstNode *con = new ConstNode((yyvsp[0].cval)); (yyval.node) = con;}
#line 2434 "c.tab.cpp"
    break;

  case 93:
#line 477 "c.y"
                                                                                                        {ConstNode *con = new ConstNode((yyvsp[0].sval)); (yyval.node)=con;}
#line 2440 "c.tab.cpp"
    break;

  case 95:
#line 482 "c.y"
                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2446 "c.tab.cpp"
    break;

  case 97:
#line 484 "c.y"
                                                                                        {auto *temp = new ASTNode("function_call"); temp->children.push_back((yyvsp[-2].node)); (yyval.node)=temp;}
#line 2452 "c.tab.cpp"
    break;

  case 98:
#line 485 "c.y"
                                                                {auto *temp = new ASTNode("function_call"); temp->children.push_back((yyvsp[-3].node)), temp->children.push_back((yyvsp[-1].node)); (yyval.node)= temp;}
#line 2458 "c.tab.cpp"
    break;

  case 101:
#line 488 "c.y"
                                                                                                {OperatorNode *uop = new OperatorNode("unary_op", "POST_INCREMENT"); uop->children.push_back((yyvsp[-1].node)); (yyval.node)=uop;}
#line 2464 "c.tab.cpp"
    break;

  case 102:
#line 489 "c.y"
                                                                                                {OperatorNode *uop = new OperatorNode("unary_op", "POST_DECREMENT"); uop->children.push_back((yyvsp[-1].node)); (yyval.node)=uop;}
#line 2470 "c.tab.cpp"
    break;

  case 105:
#line 495 "c.y"
                                                                                                {ASTNode *temp = new ASTNode("args"); temp->children.push_back((yyvsp[0].node)); (yyval.node) = temp;}
#line 2476 "c.tab.cpp"
    break;

  case 106:
#line 496 "c.y"
                                                                {
																ASTNode *temp = new ASTNode("args"); 
																for (int i = 0; i<(yyvsp[-2].node)->children.size(); i++)
																{
																	temp->children.push_back((yyvsp[-2].node)->children[i]);
																}
																temp->children.push_back((yyvsp[0].node)); 
																(yyval.node) = temp;
															}
#line 2490 "c.tab.cpp"
    break;

  case 107:
#line 508 "c.y"
                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2496 "c.tab.cpp"
    break;

  case 108:
#line 509 "c.y"
                                                                                                {OperatorNode *uop = new OperatorNode("unary_op", "PRE_INCREMENT"); uop->children.push_back((yyvsp[0].node)); (yyval.node)=uop;}
#line 2502 "c.tab.cpp"
    break;

  case 109:
#line 510 "c.y"
                                                                                                {OperatorNode *uop = new OperatorNode("unary_op", "PRE_DECREMENT"); uop->children.push_back((yyvsp[0].node)); (yyval.node)=uop;}
#line 2508 "c.tab.cpp"
    break;

  case 110:
#line 511 "c.y"
                                                                                        {(yyvsp[-1].node)->children.push_back((yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node);}
#line 2514 "c.tab.cpp"
    break;

  case 111:
#line 515 "c.y"
                                                                                                                        {OperatorNode *op = new OperatorNode("unary_op", "REFERENCE"); (yyval.node)=op;}
#line 2520 "c.tab.cpp"
    break;

  case 112:
#line 516 "c.y"
                                                                                                                        {OperatorNode *op = new OperatorNode("unary_op", "DEREF"); (yyval.node)=op;}
#line 2526 "c.tab.cpp"
    break;

  case 113:
#line 517 "c.y"
                                                                                                                        {OperatorNode *op = new OperatorNode("unary_op", "UNARY_PLUS"); (yyval.node)=op;}
#line 2532 "c.tab.cpp"
    break;

  case 114:
#line 518 "c.y"
                                                                                                                        {OperatorNode *op = new OperatorNode("unary_op", "UNARY_NEG"); (yyval.node)=op;}
#line 2538 "c.tab.cpp"
    break;

  case 115:
#line 519 "c.y"
                                                                                                                        {OperatorNode *op = new OperatorNode("unary_op", "BITWISE_NOT"); (yyval.node)=op;}
#line 2544 "c.tab.cpp"
    break;

  case 116:
#line 520 "c.y"
                                                                                                                        {OperatorNode *op = new OperatorNode("unary_op", "NOT"); (yyval.node)=op;}
#line 2550 "c.tab.cpp"
    break;

  case 117:
#line 524 "c.y"
                                                                                                                        {(yyval.node)=(yyvsp[0].node);}
#line 2556 "c.tab.cpp"
    break;

  case 118:
#line 525 "c.y"
                                                                                                {OperatorNode *op = new OperatorNode("binary_op", "MUL");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2566 "c.tab.cpp"
    break;

  case 119:
#line 530 "c.y"
                                                                                                {OperatorNode *op = new OperatorNode("binary_op", "DIV");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2576 "c.tab.cpp"
    break;

  case 120:
#line 535 "c.y"
                                                                                                {OperatorNode *op = new OperatorNode("binary_op", "INT_MOD");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2586 "c.tab.cpp"
    break;

  case 121:
#line 543 "c.y"
                                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2592 "c.tab.cpp"
    break;

  case 122:
#line 544 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "ADD");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2602 "c.tab.cpp"
    break;

  case 123:
#line 549 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "SUB");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2612 "c.tab.cpp"
    break;

  case 124:
#line 557 "c.y"
                                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2618 "c.tab.cpp"
    break;

  case 125:
#line 558 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "LEFT_SHIFT");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2628 "c.tab.cpp"
    break;

  case 126:
#line 563 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "RIGHT_SHIFT");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2638 "c.tab.cpp"
    break;

  case 127:
#line 571 "c.y"
                                                                                                                        {(yyval.node)=(yyvsp[0].node);}
#line 2644 "c.tab.cpp"
    break;

  case 128:
#line 572 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "LESS_THAN");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2654 "c.tab.cpp"
    break;

  case 129:
#line 577 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "GREATER_THAN");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2664 "c.tab.cpp"
    break;

  case 130:
#line 582 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "LESS_EQ");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2674 "c.tab.cpp"
    break;

  case 131:
#line 587 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "GREATER_EQ");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2684 "c.tab.cpp"
    break;

  case 132:
#line 595 "c.y"
                                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2690 "c.tab.cpp"
    break;

  case 133:
#line 596 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "EQ");
																	op->children.push_back((yyvsp[-2].node));			
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2700 "c.tab.cpp"
    break;

  case 134:
#line 601 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "NEQ");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2710 "c.tab.cpp"
    break;

  case 135:
#line 609 "c.y"
                                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2716 "c.tab.cpp"
    break;

  case 136:
#line 610 "c.y"
                                                                                                {OperatorNode *op = new OperatorNode("binary_op", "&");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2726 "c.tab.cpp"
    break;

  case 137:
#line 618 "c.y"
                                                                                                                        {(yyval.node)=(yyvsp[0].node);}
#line 2732 "c.tab.cpp"
    break;

  case 138:
#line 619 "c.y"
                                                                                        {OperatorNode *op = new OperatorNode("binary_op", "^");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2742 "c.tab.cpp"
    break;

  case 139:
#line 627 "c.y"
                                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2748 "c.tab.cpp"
    break;

  case 140:
#line 628 "c.y"
                                                                                {OperatorNode *op = new OperatorNode("binary_op", "|");
																	op->children.push_back((yyvsp[-2].node));
																	op->children.push_back((yyvsp[0].node));
																	(yyval.node)=op;
																	}
#line 2758 "c.tab.cpp"
    break;

  case 141:
#line 636 "c.y"
                                                                                                       {(yyval.node)=(yyvsp[0].node);}
#line 2764 "c.tab.cpp"
    break;

  case 142:
#line 637 "c.y"
                                                                                {OperatorNode *temp = new OperatorNode("binary_op","LOGICAL_AND");
																	temp->children.push_back((yyvsp[-2].node));
																	temp->children.push_back((yyvsp[0].node));
																	(yyval.node)=temp;}
#line 2773 "c.tab.cpp"
    break;

  case 143:
#line 644 "c.y"
                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2779 "c.tab.cpp"
    break;

  case 144:
#line 645 "c.y"
                                                                {OperatorNode *temp = new OperatorNode("binary_op","LOGICAL_OR");
															temp->children.push_back((yyvsp[-2].node));
															temp->children.push_back((yyvsp[0].node));
															(yyval.node)=temp;}
#line 2788 "c.tab.cpp"
    break;

  case 145:
#line 652 "c.y"
                                                                                                                                {(yyval.node)=(yyvsp[0].node);}
#line 2794 "c.tab.cpp"
    break;

  case 146:
#line 653 "c.y"
                                                                                        {OperatorNode *temp = new OperatorNode("ternary_op", "CONDITIONAL"); 
																			temp->children.push_back((yyvsp[-4].node));
																			temp->children.push_back((yyvsp[-2].node));
																			temp->children.push_back((yyvsp[0].node));
																			(yyval.node) = temp;}
#line 2804 "c.tab.cpp"
    break;

  case 147:
#line 661 "c.y"
                                                                           {(yyval.node)=(yyvsp[0].node);}
#line 2810 "c.tab.cpp"
    break;

  case 148:
#line 662 "c.y"
                                                                                {(yyvsp[-1].node)->children.push_back((yyvsp[-2].node)); (yyvsp[-1].node)->children.push_back((yyvsp[0].node)); (yyval.node)=(yyvsp[-1].node);}
#line 2816 "c.tab.cpp"
    break;

  case 149:
#line 666 "c.y"
                                                                {OperatorNode *temp = new OperatorNode("binary_op","ASSIGN"); (yyval.node) = temp; }
#line 2822 "c.tab.cpp"
    break;

  case 150:
#line 667 "c.y"
                                                        {OperatorNode *temp = new OperatorNode("binary_op","MUL_ASSIGN"); (yyval.node) = temp; }
#line 2828 "c.tab.cpp"
    break;

  case 151:
#line 668 "c.y"
                                                        {OperatorNode *temp = new OperatorNode("binary_op","DIV_ASSIGN"); (yyval.node) = temp; }
#line 2834 "c.tab.cpp"
    break;

  case 152:
#line 669 "c.y"
                                                        {OperatorNode *temp = new OperatorNode("binary_op","MOD_ASSIGN"); (yyval.node) = temp; }
#line 2840 "c.tab.cpp"
    break;

  case 153:
#line 670 "c.y"
                                                        {OperatorNode *temp = new OperatorNode("binary_op","ADD_ASSIGN"); (yyval.node) = temp; }
#line 2846 "c.tab.cpp"
    break;

  case 154:
#line 671 "c.y"
                                                        {OperatorNode *temp = new OperatorNode("binary_op","SUB_ASSIGN"); (yyval.node) = temp; }
#line 2852 "c.tab.cpp"
    break;

  case 155:
#line 672 "c.y"
                                                        {OperatorNode *temp = new OperatorNode("binary_op","LEFT_ASSIGN"); (yyval.node) = temp; }
#line 2858 "c.tab.cpp"
    break;

  case 156:
#line 673 "c.y"
                                                        {OperatorNode *temp = new OperatorNode("binary_op","RIGHT_ASSIGN"); (yyval.node) = temp; }
#line 2864 "c.tab.cpp"
    break;

  case 157:
#line 674 "c.y"
                                                        {OperatorNode *temp = new OperatorNode("binary_op","AND_ASSIGN"); (yyval.node) = temp; }
#line 2870 "c.tab.cpp"
    break;

  case 158:
#line 675 "c.y"
                                                        {OperatorNode *temp = new OperatorNode("binary_op","XOR_ASSIGN"); (yyval.node) = temp; }
#line 2876 "c.tab.cpp"
    break;

  case 159:
#line 676 "c.y"
                                                                {OperatorNode *temp = new OperatorNode("binary_op","OR_ASSIGN"); (yyval.node) = temp; }
#line 2882 "c.tab.cpp"
    break;

  case 185:
#line 763 "c.y"
                           {auto *temp = new KeywordNode("type_qualifier", "CONST"); (yyval.node) = temp;}
#line 2888 "c.tab.cpp"
    break;

  case 186:
#line 764 "c.y"
                                        {auto *temp = new KeywordNode("type_qualifier", "RESTRICT"); (yyval.node) = temp;}
#line 2894 "c.tab.cpp"
    break;

  case 187:
#line 765 "c.y"
                                        {auto *temp = new KeywordNode("type_qualifier", "VOLATILE"); (yyval.node) = temp;}
#line 2900 "c.tab.cpp"
    break;

  case 188:
#line 766 "c.y"
                                        {auto *temp = new KeywordNode("type_qualifier", "ATOMIC"); (yyval.node) = temp;}
#line 2906 "c.tab.cpp"
    break;

  case 189:
#line 770 "c.y"
                                        {auto *temp = new KeywordNode("func_spec", "INLINE"); (yyval.node) = temp;}
#line 2912 "c.tab.cpp"
    break;

  case 190:
#line 771 "c.y"
                                        {auto *temp = new KeywordNode("func_spec", "NORETURN"); (yyval.node) = temp;}
#line 2918 "c.tab.cpp"
    break;


#line 2922 "c.tab.cpp"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
      yyerror (YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 781 "c.y"

#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
