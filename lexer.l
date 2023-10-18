%{
#include<stdio.h>

int pos_num, pos_cade, pos_ident = 0;
//#include"lista.h"
%}
entero  (+|-)?[1-9][0-9]{0,5}
real    [0-9]*\.[0-9]*
cadena  [^\"]{0-38}
ident [a-zA-Z]?([a-zA-Z]*[0-9]){,5}_
caracter .
%%
    "cadena"      {printf("(0,0)\n");}
    "caracter"    {printf("(0,1)\n");}
    "else"        {printf("(0,2)\n");}
    "entero"      {printf("(0,3)\n");}
    "for"         {printf("(0,4)\n");}
    "if"          {printf("(0,5)\n");}
    "real"        {printf("(0,6)\n");}
    "return"      {printf("(0,7)\n");}
    "void"        {printf("(0,8)\n");}
    "while"       {printf("(0,9)\n");}

    "+"|"-"|"*"|"/"|"$"   {printf("(1,%s)\n",yytext);}
    
    "~"         {printf("(2,0)\n");}
    "+~"        {printf("(2,1)\n");}
    "-~"        {printf("(2,2)\n");}
    "*~"        {printf("(2,3)\n");}
    "/~"        {printf("(2,4)\n");}
    "$~"        {printf("(2,5)\n");}

    (|)|{|}|[|]|&|,|: {printf("(3,%s)\n",yytext);}

    "^^"        {printf("(4,0)\n");}
    "^\""       {printf("(4,1)\n");}
    "=="        {printf("(4,2)\n");}
    "^^="       {printf("(4,3)\n");}
    "^\"="      {printf("(4,4)\n");}
    "<>"        {printf("(4,5)\n");}

    "\"{ident}\""
    
    {entero}   

    {real}

    {cadena}

    {caracter}

    .+          {printf("%s no reconocido", yytext);}
    
%%

int yywrap(){}

int main(int argc, char **argv)
{
    FILE *file = fopen(argv[1], "r");
    
    if(file == NULL)
    {
        printf("Sin archivo de entrada\n");
        return 1;
    }

    yyin = file;

}