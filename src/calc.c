#ifndef lint
static char const 
yyrcsid[] = "$FreeBSD: src/usr.bin/yacc/skeleton.c,v 1.28 2000/01/17 02:04:06 bde Exp $";
#endif
#include <stdlib.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
static int yygrowstack();
#define YYPREFIX "yy"
#line 2 "calc.y"
/*  Copyright 1981 Gary Perlman */

#ifdef sun /* need corrective version of atof */
double	myatof ();
#else
#define	myatof(s)   atof(s)
#endif

#ifdef __STDC__
#include "stdlib.h"
#else
extern	double	atof ();
extern	void	*malloc ();
#endif

#ifndef lint
static	char	sccsid[] = "@(#) calc.y 5.3 (|stat) 10/1/88";
#endif

#define	CALC_VERSION                   "5.3 10/1/88"
/* PGM(calc, Algebraic Modeling Calculator) */

#ifdef __MSDOS__
#define	MARK_EOF "Ctrl-Z"
#elif macintosh
#define	MARK_EOF "Apple-."
#else
#define	MARK_EOF "^D"
#endif

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <signal.h>
#ifdef	macintosh
#include <IOCtl.h>
#define isatty(x) (!ioctl(x, FIOINTERACTIVE, NULL))
#endif

#define	FZERO         (10e-10)
#define	fzero(x)      (fabs (x) < FZERO)
#define	isvarchar(c)  (isalnum (c) || (c) == '_')

#ifndef iscntrl
#define iscntrl(a) ((a)>0&&(a)<26)
#endif
#define OPERATOR     1
#define PARSERROR    1
#define	MAXVAR    1000 
#define	UNDEFINED   -99999999999.987654321
int 	Nvar;
char	*Varname[MAXVAR];
char	*Eptr;
int 	Printequation = 1;
char	*Prompt = "CALC: ";
int 	Interactive = 0;
char	Format[100] = "%.10g";    /* default print format for numbers */

typedef	union
	{
	int 	opr;        /* if OPERATOR */
	double	*num;       /* if NUMBER */
	int 	var;        /* if VARIABLE */
	} STUFF;
STUFF	Tmp1, Tmp2;  /* used in the parser to cast operators */
typedef struct enode        /* expression node in tree */
	{
	int 	etype;          /* type of node */
	STUFF	contents;
	struct	enode *left;
	struct	enode *right;
	} ENODE;
#define	ENULL ((ENODE *) NULL)
ENODE	*Expression, *Variable[MAXVAR];

double	eval (), Answer;
double	*Constant;
char	*cgetline ();
FILE	*Outfile;
#line 83 "calc.y"
typedef union
	{
	int 	opr;   /* an operator */
	int 	var;   /* an index into the variable table */
	double	*num;  /* a pointer to a numerical constant */
	ENODE	*ex;   /* an expression in the parse tree */
	} YYSTYPE;
#line 105 "y.tab.c"
#define YYERRCODE 256
#define NUMBER 257
#define VARIABLE 258
#define IF 259
#define THEN 260
#define ELSE 261
#define EQ 262
#define NE 263
#define GE 264
#define LE 265
#define UMINUS 266
#define ABS 267
#define EXP 268
#define LOG 269
#define SQRT 270
#define COS 271
#define TAN 272
#define SIN 273
#define ACOS 274
#define ASIN 275
#define ATAN 276
const short yylhs[] = {                                        -1,
    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,
};
const short yylen[] = {                                         2,
    1,    3,    3,    2,    3,    3,    3,    3,    3,    3,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    5,    4,    3,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    1,    1,
};
const short yydefred[] = {                                      0,
   35,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   11,   32,   31,   30,   33,   27,   29,
   28,   24,   25,   26,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
const short yydgoto[] = {                                      18,
   19,
};
const short yysindex[] = {                                    199,
    0,  -61,  199,  199,  199,  199,  199,  199,  199,  199,
  199,  199,  199,  199,  199,  199,  199,    0,  467,  199,
  467,  339,  574,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  368,  199,  199,  199,  199,  199,
  199,  199,  199,  199,  199,  199,  199,  199,  199,  199,
  199,  467,  199,    0,  439,  502,  547,  574,  -27,  -27,
  -27,  -27,  -27,  -27,  -20,  -20,  -92,  -92,  -92,  -92,
  481,  199,  502,
};
const short yyrindex[] = {                                      0,
    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    3,    0,
    8,    0,   91,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   12,    0,    0,    0,   21,  182,  143,  147,  156,
  162,  166,  175,  189,  107,  133,   13,   40,   68,   97,
  253,    0,   31,
};
const short yygindex[] = {                                      0,
  639,
};
#define YYTABLESIZE 839
const short yytable[] = {                                      20,
   34,   51,    1,    0,    0,    0,    0,    4,    0,   50,
    0,    3,    7,    0,   48,   46,   50,   47,    0,   49,
   23,   48,    0,    0,    0,    0,   49,    0,    0,    0,
   21,    0,    0,    0,    0,    0,    0,   34,   34,    9,
    0,   34,   34,   34,    0,   34,    0,   34,    4,    7,
    7,    0,    3,    7,    7,    7,    0,    7,   34,    7,
   34,   23,   34,   34,    0,    4,   51,    8,    0,    3,
    7,   21,    7,   51,    7,    7,    9,    9,   23,    0,
    9,    9,    9,   23,    9,    0,    9,    0,   21,    0,
   20,    0,    0,   21,   34,    0,   10,    9,    0,    9,
    0,    9,    9,    0,    8,    8,    5,    0,    8,    8,
    8,    0,    8,    0,    8,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   34,    8,    0,    8,   20,    8,
    8,   20,    6,   10,   10,    0,    7,   10,   10,   10,
    0,   10,   18,   10,    5,    0,   12,    5,   20,    5,
    0,    5,    0,   20,   10,   13,   10,    0,   10,   10,
    0,   16,    0,    9,    5,   14,    5,    0,    5,    5,
    6,    0,    0,    6,   15,    6,    0,    6,    0,    0,
   18,   19,    0,   18,   12,    0,    0,   12,   17,    0,
    6,    8,    6,   13,    6,    6,   13,    0,    0,   16,
   18,    0,   16,   14,   12,   18,   14,    0,    0,   12,
    0,    0,   15,   13,   20,   15,    0,    0,   13,   16,
   10,    0,   19,   14,   16,    0,   17,    0,   14,   17,
    5,    5,   15,    3,    0,    0,    0,   15,   17,   19,
    0,    0,    0,    6,   19,    0,   17,    0,    0,    0,
    0,   17,   22,    0,    0,    0,    6,    0,    0,    0,
   34,   34,   34,   34,   34,   34,   18,    4,    0,    0,
   12,    3,    7,    7,    7,    7,    7,    7,    0,   13,
   23,   23,    0,    0,    0,   16,    0,    0,    0,   14,
   21,   21,    0,   22,    0,    0,    0,    0,   15,    9,
    9,    9,    9,    9,    9,   19,    0,    0,    0,    0,
   22,    0,   17,    0,    0,   22,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    8,    8,    8,
    8,    8,    8,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   20,   20,    0,    0,    0,    0,   10,   10,   10,   10,
   10,   10,    0,    0,    0,    0,    5,    5,    5,    5,
    5,    5,    0,    0,    0,   50,   39,    0,    0,    0,
   48,   46,    0,   47,    0,   49,    0,    0,    0,    0,
    0,    0,    6,    6,    6,    6,    6,    6,   44,    0,
   45,   36,   18,   18,   50,   39,   12,   12,   54,   48,
   46,    0,   47,    0,   49,   13,   13,    0,    0,    0,
    0,   16,   16,    0,    0,   14,   14,   44,    0,   45,
   36,    0,   51,    0,   15,   15,    0,    0,    0,    0,
    0,   19,   19,    0,    0,    0,    0,    0,   17,   17,
    0,    0,    0,    0,    0,    1,    2,    4,    0,    0,
    0,   51,   38,    0,    0,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   16,   50,   39,    0,    0,    0,
   48,   46,    0,   47,    0,   49,    0,    0,    0,    0,
    0,   38,    0,    0,    0,    0,   72,    0,   44,    0,
   45,   36,    0,   50,   39,    0,    0,    0,   48,   46,
    0,   47,   22,   49,    0,    0,    0,   50,   39,    0,
    0,    0,   48,   46,    0,   47,   44,   49,   45,   36,
    0,    0,   51,    0,    0,    0,    0,    0,   50,   39,
   44,    0,   45,   48,   46,    0,   47,    0,   49,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   51,   44,   38,   45,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   51,    0,    0,    0,    0,    0,
    0,    0,    0,   50,   39,    0,    0,    0,   48,   46,
   38,   47,    0,   49,    0,   51,    0,    0,   53,   37,
   40,   41,   42,   43,   38,    0,   44,    0,   45,    0,
   50,    0,    0,    0,    0,   48,   46,    0,   47,    0,
   49,    0,    0,    0,    0,   38,    0,    0,   37,   40,
   41,   42,   43,   44,    0,   45,    0,    0,    0,    0,
   51,   21,   22,   23,   24,   25,   26,   27,   28,   29,
   30,   31,   32,   33,   34,   35,    0,    0,   52,    0,
    0,    0,    0,    0,    0,    0,    0,   51,    0,    0,
    0,    0,    0,    0,   55,   56,   57,   58,   59,   60,
   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,
    0,   71,    0,    0,    0,    0,    0,    0,    0,   37,
   40,   41,   42,   43,    0,    0,    0,    0,    0,    0,
   73,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   37,   40,   41,
   42,   43,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   37,   40,   41,   42,   43,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   40,   41,   42,   43,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   40,   41,
   42,   43,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,   41,   42,   43,
};
const short yycheck[] = {                                      61,
    0,   94,    0,   -1,   -1,   -1,   -1,    0,   -1,   37,
   -1,    0,    0,   -1,   42,   43,   37,   45,   -1,   47,
    0,   42,   -1,   -1,   -1,   -1,   47,   -1,   -1,   -1,
    0,   -1,   -1,   -1,   -1,   -1,   -1,   37,   38,    0,
   -1,   41,   42,   43,   -1,   45,   -1,   47,   41,   37,
   38,   -1,   41,   41,   42,   43,   -1,   45,   58,   47,
   60,   41,   62,   63,   -1,   58,   94,    0,   -1,   58,
   58,   41,   60,   94,   62,   63,   37,   38,   58,   -1,
   41,   42,   43,   63,   45,   -1,   47,   -1,   58,   -1,
    0,   -1,   -1,   63,   94,   -1,    0,   58,   -1,   60,
   -1,   62,   63,   -1,   37,   38,    0,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   58,   -1,   60,   38,   62,
   63,   41,    0,   37,   38,   -1,  124,   41,   42,   43,
   -1,   45,    0,   47,   38,   -1,    0,   41,   58,   43,
   -1,   45,   -1,   63,   58,    0,   60,   -1,   62,   63,
   -1,    0,   -1,  124,   58,    0,   60,   -1,   62,   63,
   38,   -1,   -1,   41,    0,   43,   -1,   45,   -1,   -1,
   38,    0,   -1,   41,   38,   -1,   -1,   41,    0,   -1,
   58,  124,   60,   38,   62,   63,   41,   -1,   -1,   38,
   58,   -1,   41,   38,   58,   63,   41,   -1,   -1,   63,
   -1,   -1,   38,   58,  124,   41,   -1,   -1,   63,   58,
  124,   -1,   41,   58,   63,   -1,   38,   -1,   63,   41,
  124,   33,   58,   35,   -1,   -1,   -1,   63,   40,   58,
   -1,   -1,   -1,   45,   63,   -1,   58,   -1,   -1,   -1,
   -1,   63,    0,   -1,   -1,   -1,  124,   -1,   -1,   -1,
  260,  261,  262,  263,  264,  265,  124,  260,   -1,   -1,
  124,  260,  260,  261,  262,  263,  264,  265,   -1,  124,
  260,  261,   -1,   -1,   -1,  124,   -1,   -1,   -1,  124,
  260,  261,   -1,   41,   -1,   -1,   -1,   -1,  124,  260,
  261,  262,  263,  264,  265,  124,   -1,   -1,   -1,   -1,
   58,   -1,  124,   -1,   -1,   63,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,  261,  262,
  263,  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  260,  261,   -1,   -1,   -1,   -1,  260,  261,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,  260,  261,  262,  263,
  264,  265,   -1,   -1,   -1,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   -1,  260,  261,  262,  263,  264,  265,   60,   -1,
   62,   63,  260,  261,   37,   38,  260,  261,   41,   42,
   43,   -1,   45,   -1,   47,  260,  261,   -1,   -1,   -1,
   -1,  260,  261,   -1,   -1,  260,  261,   60,   -1,   62,
   63,   -1,   94,   -1,  260,  261,   -1,   -1,   -1,   -1,
   -1,  260,  261,   -1,   -1,   -1,   -1,   -1,  260,  261,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,   -1,
   -1,   94,  124,   -1,   -1,  267,  268,  269,  270,  271,
  272,  273,  274,  275,  276,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   58,   -1,   60,   -1,
   62,   63,   -1,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,  260,   47,   -1,   -1,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,   60,   47,   62,   63,
   -1,   -1,   94,   -1,   -1,   -1,   -1,   -1,   37,   38,
   60,   -1,   62,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   94,   60,  124,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   37,   38,   -1,   -1,   -1,   42,   43,
  124,   45,   -1,   47,   -1,   94,   -1,   -1,  260,  261,
  262,  263,  264,  265,  124,   -1,   60,   -1,   62,   -1,
   37,   -1,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,  124,   -1,   -1,  261,  262,
  263,  264,  265,   60,   -1,   62,   -1,   -1,   -1,   -1,
   94,    3,    4,    5,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   16,   17,   -1,   -1,   20,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,
   -1,   -1,   -1,   -1,   36,   37,   38,   39,   40,   41,
   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,
   -1,   53,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,
  262,  263,  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,
   72,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  261,  262,  263,  264,  265,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  262,  263,  264,  265,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
};
#define YYFINAL 18
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#if YYDEBUG
const char * const yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,"':'",0,"'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'|'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUMBER","VARIABLE","IF","THEN","ELSE","EQ",
"NE","GE","LE","UMINUS","ABS","EXP","LOG","SQRT","COS","TAN","SIN","ACOS",
"ASIN","ATAN",
};
const char * const yyrule[] = {
"$accept : start",
"start : expr",
"expr : '(' expr ')'",
"expr : VARIABLE '=' expr",
"expr : '#' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '%' expr",
"expr : expr '/' expr",
"expr : expr '^' expr",
"expr : '-' expr",
"expr : expr EQ expr",
"expr : expr NE expr",
"expr : expr LE expr",
"expr : expr '<' expr",
"expr : expr GE expr",
"expr : expr '>' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '!' expr",
"expr : expr '?' expr ':' expr",
"expr : IF expr THEN expr",
"expr : expr ELSE expr",
"expr : ACOS expr",
"expr : ASIN expr",
"expr : ATAN expr",
"expr : COS expr",
"expr : SIN expr",
"expr : TAN expr",
"expr : LOG expr",
"expr : EXP expr",
"expr : ABS expr",
"expr : SQRT expr",
"expr : VARIABLE",
"expr : NUMBER",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
int yystacksize;
#line 288 "calc.y"

yylex ()
	{
	extern	YYSTYPE yylval;
	char	tmpvarname[BUFSIZ];
	int 	i;
	while (isspace (*Eptr)) Eptr++;
	if (begins ("acos", Eptr)) {Eptr += 4; return (ACOS);}
	if (begins ("asin", Eptr)) {Eptr += 4; return (ASIN);}
	if (begins ("atan", Eptr)) {Eptr += 4; return (ATAN);}
	if (begins ("cos", Eptr)) {Eptr += 3; return (COS);}
	if (begins ("sin", Eptr)) {Eptr += 3; return (SIN);}
	if (begins ("tan", Eptr)) {Eptr += 3; return (TAN);}
	if (begins ("log", Eptr)) {Eptr += 3; return (LOG);}
	if (begins ("sqrt", Eptr)) {Eptr += 4; return (SQRT);}
	if (begins ("exp", Eptr)) {Eptr += 3; return (EXP);}
	if (begins ("abs", Eptr)) {Eptr += 3; return (ABS);}
	if (begins ("if", Eptr)) {Eptr += 2; return (IF);}
	if (begins ("then", Eptr)) {Eptr += 4; return (THEN);}
	if (begins ("else", Eptr)) {Eptr += 4; return (ELSE);}
	if (*Eptr == '$')
		{
		Eptr++;
		yylval.num = &Answer;
		return (NUMBER);
		}
	if (isdigit (*Eptr) || *Eptr == '.')
		{
		Constant = (double *) malloc (sizeof (double));
		if (Constant == NULL)
			errorexit ("Out of storage space");
		*Constant = myatof (Eptr);
		yylval.num = Constant;
		Eptr += skipnumber (Eptr, 1);
		return (NUMBER);
		}
	if (isvarchar (*Eptr))
		{
		for (i = 0; isvarchar (Eptr[i]); i++)
			tmpvarname[i] = Eptr[i];
		tmpvarname[i] = '\0';
		Eptr += i;
		i = 0;
		while (i < Nvar && strcmp (tmpvarname, Varname[i])) i++;
		if (i == Nvar)
			{
			Varname[i] = (char *) malloc ((unsigned) (strlen(tmpvarname)+1));
			if (Varname[i] == NULL)
				errorexit ("Out of storage space");
			(void) strcpy (Varname[i], tmpvarname);
			if (++Nvar == MAXVAR)
				errorexit ("Too many variables");
			}
		yylval.var = i;
		return (VARIABLE);
		}
	if (begins ("!=", Eptr)) { Eptr += 2; return (NE); }
	if (begins (">=", Eptr)) { Eptr += 2; return (GE); }
	if (begins ("<=", Eptr)) { Eptr += 2; return (LE); }
	if (begins ("==", Eptr)) { Eptr += 2; return (EQ); }
	if (begins ("**", Eptr)) { Eptr += 2; return ('^'); }
	if (begins ("&&", Eptr)) { Eptr += 2; return ('&'); }
	if (begins ("||", Eptr)) { Eptr += 2; return ('|'); }
	return ((int) *Eptr++);
	}

yyerror (msg)
char	*msg;
	{
	fprintf (Outfile, "%s:\n", msg);
	fprintf (Outfile, "Parsing error.  ");
	fprintf (Outfile, "This is left in input: [%s]\n", Eptr-1);
	}

ENODE *
node (datum, datatype, lson, rson)
STUFF	*datum;       /* pointer to a number or an operator */
int 	datatype;     /* NUMBER or VARIABLE or OPERATOR */
ENODE	*lson;        /* left part of tree */
ENODE	*rson;        /* right part of tree */
	{
	ENODE *newnode;
	newnode = (ENODE *) malloc (sizeof (ENODE));
	if (newnode == ENULL)
		errorexit ("Out of storage space");
	newnode->etype = datatype;
	if (datatype == OPERATOR)
		newnode->contents.opr = datum->opr;
	else if (datatype == VARIABLE)
		newnode->contents.var = datum->var;
	else /* (datatype == NUMBER) */
		newnode->contents.num = datum->num;
	newnode->left = lson;
	newnode->right = rson;
	return (newnode);
	}

main (argc, argv) int argc; char *argv[];
	{
	int 	i;
	Outfile = stdout;
	signal (SIGINT, SIG_IGN);
	if (isatty (fileno (stdin)))
		{
		Interactive = 1;
		printf ("calc: version %s (Copyright 1981 Gary Perlman)\n", CALC_VERSION);
		printf ("Enter expressions after the prompt '%s'\n", Prompt);
		printf ("Quit with %s, get help with ?\n", MARK_EOF);
		}
	for (i = 1; i < argc; i++)
		process (argv[i]);
	process ("-");
	if (Interactive) /* wipe out prompt */
		printf ("\015           \015");
	exit (0);
	}

process (filename) char *filename;
	{
#ifdef macintosh
	int 	i;
#endif
	char	exprline[BUFSIZ];
	FILE	*ioptr;
	if (filename == NULL || !strcmp (filename, "-"))
		{
		ioptr = stdin;
		filename = NULL;
		}
	else if ((ioptr = fopen (filename, "r")) == NULL)
		{
		fprintf (stderr, "Can't open %s\n", filename);
		return;
		}
	if (filename)
		fprintf (Outfile, "Reading from %s\n", filename);
	for (;;)
		{
		if (ioptr == stdin && Interactive)
			fprintf (Outfile, Prompt);
		if (!cgetline (exprline, ioptr)) break;
#ifdef macintosh
		for (i=0; exprline[i] == Prompt[i] && exprline[i]; i++) ;
		for (; exprline[i] == ' ' || exprline[i] == '\t'; i++) ;
		strcpy(exprline, exprline+i);
#endif
		Eptr = exprline;
		while (isspace (*Eptr))
			Eptr++;
		if (*Eptr == '\0' || *Eptr == '?')
			{
			if (filename == NULL && Interactive)
				printmenu ();
			continue;
			}
		if (iscntrl (*Eptr))
			{
			control (Eptr);
			continue;
			}
		if (yyparse() == PARSERROR)
			continue;
		if (Printequation || ioptr != stdin)
			ptree (Outfile, Expression);
		if (fzero (Answer = eval (Expression)))
			Answer = 0.0;
		if (Printequation)
			printf (" =");
		if (Answer == UNDEFINED)
			fprintf (Outfile, "\tUNDEFINED\n");
		else
			{
			putc ('\t', Outfile);
			fprintf (Outfile, Format, Answer);
			putc ('\n', Outfile);
			}
		}
	if (ioptr != stdin)
		(void) fclose (ioptr);
	}

printmenu ()
	{
	puts ("Expressions are in standard C syntax (like algebra).");
	puts ("The following CTRL characters have special functions:");
	puts ("(You may have to precede the character with a ^V)");
	printf ("%s	end of input to CALC\n", MARK_EOF);
	puts ("^P	toggles the printing of equations");
	puts ("^Rfile	reads the expressions from the named file");
	puts ("^Wfile	writes all expressions to the named file");
	puts ("	If no file is supplied, then print to the screen");
	}

#define	CTRL_PRINT     16
#define	CTRL_READ      18
#define	CTRL_WRITE     23
#define	CTRL_VAR       22
#define	CTRL_FMT        6

control (key) char *key;
	{
	int 	var;
	FILE	*saveoutfile;
	switch (*key)
		{
		case CTRL_FMT:
			if (key[1] == '\0' || isspace (key[1]))
				fprintf (Outfile, "Current_Format = '%s'\n", Format);
			else
				strcpy (Format+1, key+1);
			return;
		case CTRL_PRINT:
			Printequation = !Printequation;
			return;
		case CTRL_READ:
			while (iscntrl (*key) || isspace (*key))
				key++;
			process (key);
			return;
		case CTRL_WRITE:
		case CTRL_VAR:
			while (*key && (iscntrl (*key) || isspace (*key)))
				key++;
			if (*key)
				{
				fprintf (Outfile, "Writing to %s\n", key);
				saveoutfile = Outfile;
				if ((Outfile = fopen (key, "a")) == NULL)
					{
					fprintf (stderr, "Can't open %s\n", key);
					Outfile = saveoutfile;
					}
				}
			for (var = 0; var < Nvar; var++)
				{
				fprintf (Outfile, "%-10s = ", Varname[var]);
				if (Outfile == stdout)
					{
					if (fzero (Answer = eval (Variable[var])))
						Answer = 0.0;
					if (Answer == UNDEFINED)
						fprintf (Outfile, " UNDEFINED = ");
					else
						{
						fprintf (Outfile, Format, Answer);
						fprintf (Outfile, " = ");
						}
					}
				ptree (Outfile, Variable[var]);
				fprintf (Outfile, "\n");
				}
			if (*key)
				{
				(void) fclose (Outfile);
				Outfile = saveoutfile;
				}
			return;
		default:
			fprintf (stderr, "Unknown control character.\n");
		}
	}

double
eval (expression)
ENODE *expression;
	{
	double	tmp1, tmp2;

	if (expression == ENULL)
		return (UNDEFINED);
	if (expression->etype == NUMBER)
		return (*expression->contents.num);
	if (expression->etype == VARIABLE)
		{
		if (Variable[expression->contents.var])
			return (eval (Variable[expression->contents.var]));
		else
			return (UNDEFINED);
		}

	if ((tmp2 = eval (expression->right)) == UNDEFINED)
		return (UNDEFINED);

	switch (expression->contents.opr)
	{
	case '_': return (-tmp2);
	case '!': return (fzero (tmp2) ? 1.0 : 0.0);
	case LOG: if (tmp2 <= FZERO) return (UNDEFINED);
		else return (log (tmp2));
	case COS: return (cos (tmp2));
	case SIN: return (sin (tmp2));
	case TAN: return (tan (tmp2));
	case ACOS: return (acos (tmp2));
	case ASIN: return (asin (tmp2));
	case ATAN: return (atan (tmp2));
	case EXP: return (exp (tmp2));
	case ABS: return (fabs (tmp2));
	case SQRT: if (tmp2 < 0.0) return (UNDEFINED);
		else return (sqrt (tmp2));
	}

	if ((tmp1 = eval (expression->left)) == UNDEFINED)
		return (UNDEFINED);
	switch (expression->contents.opr)
	{
	case '+': return (tmp1 + tmp2);
	case '-': return (tmp1 - tmp2);
	case '*': return (tmp1 * tmp2);
	case '%': if ((int) tmp2 == 0) return (tmp1);
		else return ((double) (((int) tmp1) % ((int) tmp2)));
	case '/': if (fzero (tmp2)) return (UNDEFINED);
		else return (tmp1/tmp2);
	case '^': return (pow (tmp1, tmp2));
	case '&': return ((!fzero (tmp1) && !fzero (tmp2)) ? 1.0 : 0.0);
	case '|': return ((!fzero (tmp1) || !fzero (tmp2)) ? 1.0 : 0.0);
	case '>': return (tmp1 > tmp2 ? 1.0 : 0.0);
	case '<': return (tmp1 < tmp2 ? 1.0 : 0.0);
	case EQ : return (fzero (tmp1 - tmp2) ? 1.0 : 0.0);
	case NE : return (!fzero (tmp1 - tmp2) ? 1.0 : 0.0);
	case LE : return (tmp1 <= tmp2 ? 1.0 : 0.0);
	case GE : return (tmp1 >= tmp2 ? 1.0 : 0.0);
	case ':': return (0.0); /* dummy return for ? */
	case '?':
		if (expression->right->contents.opr == ':')
			return (!fzero (tmp1)
				? eval (expression->right->left)
				: eval (expression->right->right));
		else if (!fzero (tmp1)) return (eval (expression->right));
		else return (UNDEFINED);
	default: fprintf (stderr, "calc: Unknown operator '%c' = %d\n",
		expression->contents.opr, expression->contents.opr);
		return (UNDEFINED);
	}
	}

ptree (ioptr, expression) ENODE *expression; FILE *ioptr;
	{
	if (expression == ENULL)
		return;
	if (expression->etype == VARIABLE)
		{
		fprintf (ioptr, "%s", Varname[expression->contents.var]);
		return;
		}
	else if (expression->etype == NUMBER)
		{
		if (*expression->contents.num == UNDEFINED)
			fprintf (ioptr, "UNDEFINED");
		else
			fprintf (ioptr, Format, *expression->contents.num);
		return;
		}
	switch	(expression->contents.opr)
		{
		case LOG: fprintf (ioptr, "log("); break;
		case ABS: fprintf (ioptr, "abs("); break;
		case EXP: fprintf (ioptr, "exp("); break;
		case SQRT: fprintf (ioptr, "sqrt("); break;
		case ATAN: fprintf (ioptr, "atan("); break;
		case ASIN: fprintf (ioptr, "asin("); break;
		case ACOS: fprintf (ioptr, "acos("); break;
		case TAN: fprintf (ioptr, "tan("); break;
		case SIN: fprintf (ioptr, "sin("); break;
		case COS: fprintf (ioptr, "cos("); break;
		case '_' : putc ('-', ioptr);
			ptree (ioptr, expression->right); return;
		case '?':
			fprintf (ioptr, "(if ");
			ptree (ioptr, expression->left);
			fprintf (ioptr, " then ");
			if (expression->right->contents.opr == ':')
				{
				ptree (ioptr, expression->right->left);
				fprintf (ioptr, " else ");
				ptree (ioptr, expression->right->right);
				}
			else ptree (ioptr, expression->right);
			putc (')', ioptr);
			return;
		default: putc ('(', ioptr);
			ptree (ioptr, expression->left);
			switch (expression->contents.opr)
				{
				case EQ: fprintf (ioptr, " == "); break;
				case NE: fprintf (ioptr, " != "); break;
				case GE: fprintf (ioptr, " >= "); break;
				case LE: fprintf (ioptr, " <= "); break;
				default: fprintf (ioptr, " %c ",expression->contents.opr);
				}
		}
	ptree (ioptr, expression->right);
	putc (')', ioptr);
	}

/* Suzanne Shouman fixed a bug here. Thanks */
begins (s1, s2) char *s1, *s2;
	{
	int 	alphlag = isvarchar (*s1);
	while (*s1)
		if (*s1++ != *s2++) return (0);
	return (alphlag ? !isvarchar(*s2) : 1);
	}

checkrecursion (varno, expr)
int 	varno;      /* look for recursion involving this variable */
ENODE	*expr;      /* look for recursion of varno in this expr */
	{
	if (expr == ENULL || expr->etype == NUMBER)
		return (0);

	if (expr->etype == VARIABLE)
		{
		if (expr->contents.var == varno)
			return (1);
		if (checkrecursion (varno, Variable[expr->contents.var]))
			return (1);
		}

	return
		(
		checkrecursion (varno, expr->left)
		||
		checkrecursion (varno, expr->right)
		);
	}

char *
cgetline (line, ioptr) char *line; FILE *ioptr;
	{
	register int C;
	register char *lptr = line;
	while ((C = getc (ioptr)) != '\n' && C != ';' && C != EOF)
		*lptr++ = C;
	if (C == EOF) return (NULL);
	while (C != '\n' && C != EOF) C = getc (ioptr);
	*lptr = '\0';
	return (line);
	}

errorexit (string) char *string;
	{
	fprintf (stderr, "calc: %s\n", string);
	control ("\027calc.save");
	fprintf (stderr, "Current state saved in calc.save\n");
	exit (1);
	}
#line 879 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack()
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    i = yyssp - yyss;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss);
    if (newss == NULL)
        return -1;
    yyss = newss;
    yyssp = newss + i;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs);
    if (newvs == NULL)
        return -1;
    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

#ifndef YYPARSE_PARAM
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG void
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif	/* ANSI-C/C++ */
#else	/* YYPARSE_PARAM */
#ifndef YYPARSE_PARAM_TYPE
#define YYPARSE_PARAM_TYPE void *
#endif
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG YYPARSE_PARAM_TYPE YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL YYPARSE_PARAM_TYPE YYPARSE_PARAM;
#endif	/* ANSI-C/C++ */
#endif	/* ! YYPARSE_PARAM */

int
yyparse (YYPARSE_PARAM_ARG)
    YYPARSE_PARAM_DECL
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate])) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#if defined(lint) || defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(lint) || defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 109 "calc.y"
 { Expression = yyvsp[0].ex;}
break;
case 2:
#line 111 "calc.y"
 { yyval.ex = yyvsp[-1].ex; }
break;
case 3:
#line 112 "calc.y"

			{
			if (checkrecursion (yyvsp[-2].var, yyvsp[0].ex))
				{
				fprintf (stderr, "calc: Can't have recursive definitions\n");
				Variable[yyvsp[-2].var] = NULL;
				}
			else Variable[yyvsp[-2].var] = yyvsp[0].ex;
			yyval.ex = yyvsp[0].ex;
		}
break;
case 4:
#line 122 "calc.y"

		{
		Constant = (double *) malloc (sizeof (double));
		if (Constant == NULL)
			errorexit ("Out of storage space");
		*Constant = eval (yyvsp[0].ex);
		Tmp1.num = Constant;
		yyval.ex = node (&Tmp1, NUMBER, ENULL, ENULL);
		}
break;
case 5:
#line 131 "calc.y"

		{
		Tmp1.opr = '+';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 6:
#line 136 "calc.y"

		{
		Tmp1.opr = '-';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 7:
#line 141 "calc.y"

		{
		Tmp1.opr = '*';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 8:
#line 146 "calc.y"

		{
		Tmp1.opr = '%';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 9:
#line 151 "calc.y"

		{
		Tmp1.opr = '/';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 10:
#line 156 "calc.y"

		{
		Tmp1.opr = '^';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 11:
#line 161 "calc.y"

		{
		Tmp1.opr = '_';
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 12:
#line 166 "calc.y"

		{
		Tmp1.opr = EQ;
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 13:
#line 171 "calc.y"

		{
		Tmp1.opr = NE;
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 14:
#line 176 "calc.y"

		{
		Tmp1.opr = LE;
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 15:
#line 181 "calc.y"

		{
		Tmp1.opr = '<';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 16:
#line 186 "calc.y"

		{
		Tmp1.opr = GE;
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 17:
#line 191 "calc.y"

		{
		Tmp1.opr = '>';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 18:
#line 196 "calc.y"

		{
		Tmp1.opr = '&';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 19:
#line 201 "calc.y"

		{
		Tmp1.opr = '|';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 20:
#line 206 "calc.y"

		{
		Tmp1.opr = '!';
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 21:
#line 211 "calc.y"

		{
		Tmp1.opr = '?';
		Tmp2.opr = ':';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-4].ex, node (&Tmp2, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex));
		}
break;
case 22:
#line 217 "calc.y"

		{
		Tmp1.opr = '?';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 23:
#line 222 "calc.y"

		{
		Tmp1.opr = ':';
		yyval.ex = node (&Tmp1, OPERATOR, yyvsp[-2].ex, yyvsp[0].ex);
		}
break;
case 24:
#line 227 "calc.y"

		{
		Tmp1.opr = ACOS;
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 25:
#line 232 "calc.y"

		{
		Tmp1.opr = ASIN;
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 26:
#line 237 "calc.y"

		{
		Tmp1.opr = ATAN;
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 27:
#line 242 "calc.y"

		{
		Tmp1.opr = COS;
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 28:
#line 247 "calc.y"

		{
		Tmp1.opr = SIN;
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 29:
#line 252 "calc.y"

		{
		Tmp1.opr = TAN;
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 30:
#line 257 "calc.y"

		{
		Tmp1.opr = LOG;
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 31:
#line 262 "calc.y"

		{
		Tmp1.opr = EXP;
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 32:
#line 267 "calc.y"

		{
		Tmp1.opr = ABS;
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 33:
#line 272 "calc.y"

		{
		Tmp1.opr = SQRT;
		yyval.ex = node (&Tmp1, OPERATOR, ENULL, yyvsp[0].ex);
		}
break;
case 34:
#line 277 "calc.y"

		{
		Tmp1.var = yyvsp[0].var;
		yyval.ex = node (&Tmp1, VARIABLE, ENULL, ENULL);
		}
break;
case 35:
#line 282 "calc.y"

		{
		Tmp1.num = yyvsp[0].num;
		yyval.ex = node (&Tmp1, NUMBER, ENULL, ENULL);
		}
break;
#line 1356 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
