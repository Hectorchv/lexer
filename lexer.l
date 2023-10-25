%{
#include<stdio.h>
#include<string.h>
#include"lista.h"

int valor = 0;
char buff[128];

%}

OPERA   [+\-*/$]
SIMBO   [\(\)\{\}\[\]&\,:]
ENTERO	[ ]*[-+]?[1-9][0-9]{0,5}
REAL	[0-9]*\.[0-9]+
CADENA	\"[^\"\n]{0,38}\"
IDENT	[a-zA-Z]([a-zA-Z]|[0-9]){0,4}_
CARACT	'[^']'
ALFANUM [A-Za-z0-1]+[^ _]

%%
"cadena"	{add_t_token(0,0); add_t_error(buff);}
"caracter"	{add_t_token(0,1); add_t_error(buff);}
"else"		{add_t_token(0,2); add_t_error(buff);}
"entero"	{add_t_token(0,3); add_t_error(buff);}
"for"		{add_t_token(0,4); add_t_error(buff);}
"if"		{add_t_token(0,5); add_t_error(buff);}
"real"		{add_t_token(0,6); add_t_error(buff);}
"return"	{add_t_token(0,7); add_t_error(buff);}
"void"		{add_t_token(0,8); add_t_error(buff);}
"while"		{add_t_token(0,9); add_t_error(buff);}
{OPERA}	    {add_t_token(1,(int)yytext[0]); add_t_error(buff);}
"~"		    {add_t_token(2,0); add_t_error(buff);}
"+~"		{add_t_token(2,1); add_t_error(buff);}
"-~"		{add_t_token(2,2); add_t_error(buff);}
"*~"		{add_t_token(2,3); add_t_error(buff);}
"/~"		{add_t_token(2,4); add_t_error(buff);}
"$~"		{add_t_token(2,5); add_t_error(buff);}
{SIMBO}	    {add_t_token(3,(int)yytext[0]); add_t_error(buff);}
"\^\^"		{add_t_token(4,0); add_t_error(buff);}
\^\"		{add_t_token(4,1); add_t_error(buff);}
"=="		{add_t_token(4,2); add_t_error(buff);}
"\^\^\="	{add_t_token(4,3); add_t_error(buff);}
\^\"=		{add_t_token(4,4); add_t_error(buff);}
"<>"		{add_t_token(4,5); add_t_error(buff);}
{IDENT}		{valor = add_t_ident(yytext); add_t_token(5,valor); add_t_error(buff);}
{ENTERO}	{valor = add_t_numerica(atof(yytext)); add_t_token(6,valor); add_t_error(buff);}
{REAL}		{valor = add_t_numerica(atof(yytext)); add_t_token(7,valor); add_t_error(buff);}
{CADENA}	{valor = add_t_cadena(yytext); add_t_token(8,valor); add_t_error(buff);}
{CARACT}	{valor = add_t_cadena(yytext); add_t_token(9,valor); add_t_error(buff);}
[ \t\n]     {add_t_error(buff);}
{ALFANUM}   {strncat(buff,yytext,yyleng); add_t_error(buff);}
.           {strncat(buff,yytext,yyleng); add_t_error(buff);}


%%

int yywrap(){}

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	if(fopen == NULL)
		return 1;
	yyin = file;
	yylex();
    imp_t_numerica();
    imp_t_cadena();
    imp_t_ident();
    imp_t_token();
    imp_errores();
	return 0;
}