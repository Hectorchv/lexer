/*
    Programa realizado por Chavez Mejia Luis Hector
    
    Definicion de las estructuras necesarias 
    y las funciones necesarias
*/
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
    char *cadena;
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


//Funcion de busqueda de identificadores
int bus_t_ident(char *);

//Funcion de agregar token
void add_t_token(int, int);

//Funcion de agregar literales numericas
int add_t_numerica(float);

//Funcion de agregar literales de cadenas
int add_t_cadena(char *);

//Funcion de agregar identificaderes a la Tabla de Simbolos
int add_t_ident(char *);

//Funcion de agregar errores detectados
void add_t_error( char *);

//Imprime los errores y los guerda en el archivo de salida;
void imp_errores();

//Imprime los valores de la tabla de literales numericas y los guarda en el archivo de salida
void imp_t_numerica();

//Imprime los valores de la tabla de literales cadenas y los guarda en el archivo de salida
void imp_t_cadena();

//Imprime los valores de la tabla de Simbolos y los guarda en el archivo de salida
void imp_t_ident();

//Imprime la tabla de los Tokens detectados y los guarda en el archivo de salida
void imp_t_token();

//Abre el archivo de salida de texto
void open_file(char *);

//Cierra el archivo de salida de texto
void close_file();
#endif