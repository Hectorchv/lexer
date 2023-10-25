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




void addtoken(int, int );
void add_t_error( char [128]);
void add_t_numerica(unsigned , float);
void add_t_cadena(unsigned, char *);
void add_t_ident(unsigned, char *, int);

void imp_errores();

#endif