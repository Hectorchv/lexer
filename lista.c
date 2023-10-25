#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#include"lista.h"

t_error *errores = NULL;
t_token *tokens = NULL;
t_ident *ident = NULL;
t_cadena *cadenas = NULL;
t_numerica *numerica = NULL;

void add_t_numerica(unsigned pos, float valor)
{
    t_numerica *tmp = malloc(sizeof(t_numerica));
    assert(tmp != NULL);
    tmp->pos = pos;
    tmp->valor = valor;
    tmp->next = numerica;
    numerica = tmp;
}

void add_t_error(char error[128])
{
    if (error[0] != '\0')
    {
        t_error *tmp = malloc(sizeof(t_error));
        assert(tmp != NULL);
        strncpy(tmp->cadena,error,strlen(error));
        tmp->next = errores;
        errores = tmp;
        error[0] = '\0';
    }
}

void imp_errores()
{
    t_error *tmp = errores;

    printf("Errores: \n");
    while (tmp != NULL)
    {
        printf("\t%s no reconocido\n", tmp->cadena);
        tmp =  tmp->next;
    }
}
void add_t_cadena(unsigned pos, char *valor)
{

}
void add_t_ident(unsigned pos, char *nombre, int tipo)
{

}