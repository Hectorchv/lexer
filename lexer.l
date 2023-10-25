%{
#include<stdio.h>
#include<string.h>
#include"lista.h"

int pos_num 	= 0;
int pos_cade 	= 0;
int pos_ident 	= 0;

char buff[128];

%}

OPERA   [+\-*/$]
SIMBO   [\(\)\{\}\[\]&\,:]
ENTERO	[ \t]*[-+]?[1-9][0-9]{0,5}
REAL	[ \t]*[0-9]*\.[0-9]+
CADENA	\"[^\"\n]{0,38}\"
IDENT	[a-zA-Z]([a-zA-Z]|[0-9]){0,4}_
CARACT	'[^']' 

%%
"cadena"	{printf("(0,0)\n"); add_t_error(buff);}
"caracter"	{printf("(0,1)\n"); add_t_error(buff);}
"else"		{printf("(0,2)\n"); add_t_error(buff);}
"entero"	{printf("(0,3)\n"); add_t_error(buff);}
"for"		{printf("(0,4)\n"); add_t_error(buff);}
"if"		{printf("(0,5)\n"); add_t_error(buff);}
"real"		{printf("(0,6)\n"); add_t_error(buff);}
"return"	{printf("(0,7)\n"); add_t_error(buff);}
"void"		{printf("(0,8)\n"); add_t_error(buff);}
"while"		{printf("(0,9)\n"); add_t_error(buff);}
{OPERA}	    {printf("(1,%s)\n",yytext); add_t_error(buff);}
"~"		    {printf("(2,0)\n"); add_t_error(buff);}
"+~"		{printf("(2,1)\n"); add_t_error(buff);}
"-~"		{printf("(2,2)\n"); add_t_error(buff);}
"*~"		{printf("(2,3)\n"); add_t_error(buff);}
"/~"		{printf("(2,4)\n"); add_t_error(buff);}
"$~"		{printf("(2,5)\n"); add_t_error(buff);}
{SIMBO}	    {printf("(3,%s)\n", yytext); add_t_error(buff);}
"\^\^"		{printf("(4,0)\n"); add_t_error(buff);}
\^\"		{printf("(4,1)\n"); add_t_error(buff);}
"=="		{printf("(4,2)\n"); add_t_error(buff);}
"\^\^\="	{printf("(4,3)\n"); add_t_error(buff);}
\^\"=		{printf("(4,4)\n"); add_t_error(buff);}
"<>"		{printf("(4,5)\n"); add_t_error(buff);}
{IDENT}		{printf("(5,%d)\n", pos_ident); pos_ident ++; add_t_error(buff);}
{ENTERO}	{printf("(6,%d)\n", pos_num); pos_num ++; add_t_error(buff);}
{REAL}		{printf("(7,%d)\n", pos_num); pos_num ++; add_t_error(buff);}
{CADENA}	{printf("(8,%d)\n", pos_cade); pos_cade ++; add_t_error(buff);}
{CARACT}	{printf("(9,%d)\n", pos_cade); pos_cade ++; add_t_error(buff);}
"salir"     return 0;
[ \t\n]     {add_t_error(buff);}
.           {strncat(buff,yytext,yyleng);}


%%

int yywrap(){}

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	if(fopen == NULL)
		return 1;
	yyin = file;
	yylex();
    imp_errores();
	return 0;
}