#ifndef LISTA_H
#define LISTA_H


//Tabla de constantes numericas
typedef struct num
{
    unsigned pos;
    float valor;
    struct num *next;
} t_numerica;

//Tabla de cadenas
typedef struct cad
{
    unsigned pos;
    char *valor;
    struct cad *next;
} t_cadena;

//Tabla de identificadores
typedef struct id
{
    unsigned pos;
    char *nombre;
    int tipo;
    struct id *next;
} t_ident;

//Tabla de tokens
typedef struct tok
{
    int clase;
    int valor;
    struct tok *next;
} t_token;


int addtoken(int clase, int valor);

int add_t_numerica(t_numerica *tabla, float valor);
int add_t_cadena(t_cadena *tabla, char *valor);
int add_t_ident(t_ident *tabla, char *nombre, int tipo);





#endif