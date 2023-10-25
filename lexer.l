%{
	/*
		Programa realizado por Luis Hector Chavez Mejia
		Fecha: 25/oct/2023
		
		Implementación del analizador lexico
	*/
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
"cadena"	{add_t_token(0,0);}
"caracter"	{add_t_token(0,1);}
"else"		{add_t_token(0,2);}
"entero"	{add_t_token(0,3);}
"for"		{add_t_token(0,4);}
"if"		{add_t_token(0,5);}
"real"		{add_t_token(0,6);}
"return"	{add_t_token(0,7);}
"void"		{add_t_token(0,8);}
"while"		{add_t_token(0,9);}
{OPERA}	    {add_t_token(1,(int)yytext[0]);}
"~"		    {add_t_token(2,0);}
"+~"		{add_t_token(2,1);}
"-~"		{add_t_token(2,2);}
"*~"		{add_t_token(2,3);}
"/~"		{add_t_token(2,4);}
"$~"		{add_t_token(2,5);}
{SIMBO}	    {add_t_token(3,(int)yytext[0]);}
"\^\^"		{add_t_token(4,0);}
\^\"		{add_t_token(4,1);}
"=="		{add_t_token(4,2);}
"\^\^\="	{add_t_token(4,3);}
\^\"=		{add_t_token(4,4);}
"<>"		{add_t_token(4,5);}
{IDENT}		{valor = add_t_ident(yytext); add_t_token(5,valor);}
{ENTERO}	{valor = add_t_numerica(atof(yytext)); add_t_token(6,valor);}
{REAL}		{valor = add_t_numerica(atof(yytext)); add_t_token(7,valor);}
{CADENA}	{valor = add_t_cadena(yytext); add_t_token(8,valor);}
{CARACT}	{valor = add_t_cadena(yytext); add_t_token(9,valor);}
[ \t\n]     {}
{ALFANUM}   {add_t_error(yytext);}
.           {add_t_error(yytext);}


%%

int yywrap(){}

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	if(fopen == NULL)
		return 1;
	yyin = file;
	yylex();
	
	open_file(argv[2]);
    imp_t_numerica();
    imp_t_cadena();
    imp_t_ident();
    imp_t_token();
    imp_errores();
	close_file();
	return 0;
}