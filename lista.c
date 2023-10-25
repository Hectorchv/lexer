/*
    Programa realizado por Chavez Mejia Luis Hector
    
    Implementación de las estructuras
    y las funciones necesarias
*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#include"lista.h"

int pos_num = 0;
int pos_cade = 0;
int pos_ident = 0;

FILE *salida;

t_error *errores_i = NULL, *errores_f = NULL;
t_token *tokens_i = NULL, *tokens_f = NULL;
t_ident *ident_i = NULL, *ident_f = NULL;
t_cadena *cadenas_i = NULL, *cadenas_f = NULL;
t_numerica *numerica_i = NULL, *numerica_f = NULL;

int bus_t_ident(char *nombre)
{
    int pos = -1;
    t_ident *tmp = ident_i;
    while(tmp != NULL)
    {        
        if(!strncmp(tmp->nombre,nombre,strlen(nombre)))
        {
            pos = tmp->pos;
            break;
        }
        tmp = tmp->next;
    }
    return pos;
}

void add_t_token(int clase, int valor)
{
    t_token *tmp = malloc(sizeof(t_token));
    assert(tmp != NULL);
    tmp->clase = clase;
    tmp->valor = valor;
    tmp->next = NULL;
    if(tokens_i == NULL)
        tokens_f = tokens_i = tmp;
    else
    {
        tokens_f->next = tmp;
        tokens_f = tmp;
    }
}

int add_t_numerica(float valor)
{
    t_numerica *tmp = malloc(sizeof(t_numerica));
    assert(tmp != NULL);
    tmp->pos = pos_num;
    pos_num ++;
    tmp->valor = valor;
    tmp->next = NULL;
    if (numerica_i == NULL)
        numerica_f = numerica_i = tmp;
    else
    {
        numerica_f->next = tmp;
        numerica_f = tmp;
    }
    return tmp->pos;
}

int add_t_cadena(char *valor)
{
    t_cadena *tmp = malloc(sizeof(t_cadena));
    assert(tmp != NULL);
    tmp->pos = pos_cade;
    pos_cade ++;
    tmp->valor = malloc(strlen(valor)*sizeof(char));
    strncpy(tmp->valor,valor,strlen(valor));
    tmp->next = NULL;
    if(cadenas_i == NULL)
        cadenas_f = cadenas_i = tmp;
    else
    {
        cadenas_f->next = tmp;
        cadenas_f = tmp;
    }
    
    return tmp->pos;
}

int add_t_ident(char *nombre)
{
    int ind = bus_t_ident(nombre);

    if(ind == -1)
    {
        t_ident *tmp = malloc(sizeof(t_ident));
        assert(tmp != NULL);
        tmp->pos = pos_ident;
        ind = pos_ident;
        pos_ident ++;
        tmp->nombre = malloc(sizeof(char)*strlen(nombre));
        strncpy(tmp->nombre, nombre, strlen(nombre));
        tmp->tipo = -1;
        tmp->next = NULL;
        if (ident_i == NULL)
            ident_f = ident_i = tmp;
        else
        {
            ident_f->next = tmp;
            ident_f = tmp;
        }
    }
    return ind;
}

void add_t_error(char *error)
{
    if (error != NULL)
    {
        t_error *tmp = malloc(sizeof(t_error));
        assert(tmp != NULL);
        tmp->cadena = malloc(sizeof(char)*strlen(error));
        assert(tmp->cadena != NULL);
        strncpy(tmp->cadena,error,strlen(error));
        tmp->next = NULL;
        if (errores_i == NULL)
            errores_i = errores_f = tmp;
        else
        {
            errores_f->next = tmp;
            errores_f = tmp;
        }
        error = NULL;
    }
}

void imp_errores()
{
    t_error *tmp = errores_i;

    printf("Errores: \n");
    fprintf(salida, "Errores: \n");
    while (tmp != NULL)
    {
        printf("\t%s no reconocido\n", tmp->cadena);
        fprintf(salida, "\t%s no reconocido\n", tmp->cadena);
        tmp =  tmp->next;
    }
}

void imp_t_numerica()
{
    t_numerica *tmp = numerica_i;
    printf("Tabla de literales(numericas)\n");
    fprintf(salida, "Tabla de literales(numericas)\n");
    while (tmp != NULL)
    {
        printf("\t%d %f\n",tmp->pos, tmp->valor);
        fprintf(salida, "\t%d %f\n",tmp->pos, tmp->valor);
        tmp = tmp->next;
    }
}

void imp_t_cadena()
{
    t_cadena *tmp = cadenas_i;
    printf("Tabla de literales(cadenas)\n");
    fprintf(salida, "Tabla de literales(cadenas)\n");
    while (tmp != NULL)
    {
        printf("\t%d %s\n",tmp->pos,tmp->valor);
        fprintf(salida, "\t%d %s\n",tmp->pos,tmp->valor);
        tmp = tmp->next;
    }
}

void imp_t_ident()
{
    t_ident *tmp = ident_i;
    printf("Tabla de simbolos\n");
    fprintf(salida, "Tabla de simbolos\n");
    while (tmp != NULL)
    {
        printf("\t%d %s\n", tmp->pos, tmp->nombre);
        tmp = tmp->next;
    }
}

void imp_t_token()
{
    t_token *tmp = tokens_i;
    printf("Tokens\n");
    fprintf(salida, "Tokens\n");
    while (tmp != NULL)
    {
        if(tmp->clase == 1 || tmp->clase == 3)
        {
            printf("(%d,%c)\n", tmp->clase, tmp->valor);
            fprintf(salida, "(%d,%c)\n", tmp->clase, tmp->valor);
        }
        else
        {
            printf("(%d,%d)\n", tmp->clase, tmp->valor);
            fprintf(salida, "(%d,%d)\n", tmp->clase, tmp->valor);
        }
        tmp = tmp->next;
    }
}

void open_file(char *archivo)
{
    if(archivo == NULL)
        printf("--Sin archivo de salida--\n");
    else
    {
        salida = fopen(archivo, "w+");
        assert(archivo != NULL);
    }
}

void close_file()
{
    fclose(salida);
}