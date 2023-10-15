#ifndef LISTA_H
#define LISTA_H

typedef struct numerica
{
    unsigned pos;
    float valor;
    numerica *next;
};

typedef struct cadena
{
    unsigned pos;

};

typedef struct ident
{
    unsigned pos;
    char *nombre;
    int tipo;
    ident *next;
};

typedef struct token
{
    int clase;
    int valor;
    token *next;
};

int addtoken(int clase, int valor);





#endif