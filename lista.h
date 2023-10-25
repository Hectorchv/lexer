#ifndef LISTA_H
#define LISTA_H


//Tabla de constantes numericas
typedef struct num
{
    unsigned pos;
    float valor;
    struct num *next;
} t_numerica;

typedef struct error
{
    char cadena[128];
    struct error *next;
} t_error;


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

typedef struct l_tok
{
    t_token *inicio, *fin;
} l_token;


int bus_t_ident(char *);
void add_t_token(int, int);
int add_t_numerica(float);
int add_t_cadena(char *);
int add_t_ident(char *);
void add_t_error( char [128]);

void imp_errores();
void imp_t_numerica();
void imp_t_cadena();
void imp_t_ident();
void imp_t_token();

#endif