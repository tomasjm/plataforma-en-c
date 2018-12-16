#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

/* 
ESCRITO POR: TOMAS JIMENEZ
FECHA: 15/12/2018 23:55
*/

// BUENA CABROS NO QUIERO QUE VIVAN LA MISMA DEPRESION QUE TUVE YO INTENTANDO SEPARAR strings
// AL FINAL DE ESTE ARCHIVO OBTENDRAN EL FORMATO YA SEPARADO EN UN ARRAY
// LUEGO SI QUIEREN TRABAJAR CON ENTEROS (TENIENDO EL STRING), USEN LA FUNCION atoi(cadena) Y LA CONVERTIRÁ A ENTERO. !!! NO SIRVE EL (INT)STRING YA QUE LO CONVERTIRÁ AL EQUIVALENTE ASCII
// Y atoi TE DEVUELVE EL VALOR ENTERO COMO TAL. EJ: atoi("100") => nos devuelve 100 como entero.

int main()
{
    // Declaro un array de cadenas de texto, son 8 palabras las que se necesitan
    // { 'dia', 'mes', 'año', 'hora', 'minuto', 'segundo', 'cantidad', 'minutos/mb'}
    // char ingMov hace referencia a "MovimientoIngresado"
    char ingMov[8][100];
    // Como no podemos escribir ingMov[7] = "algo", tenemos que usar la función strcpy(char* dest, char[] str); que es practicamente strcpy(direccion memoria destino, cadena de texto a colocar)
    strcpy(ingMov[7], "minutos");
    // Declaramos 3 nuevas cadenas de lectura para el formato "dd/mm/yyyy hh:mm:ss cantidad" como "fecha hora cant"
    char fecha[25];
    char hora[25];
    char cant[25];
    // Pueden cambiarlo por un printf
    cout << "Ingrese el movimiento con el formato: " << endl
         << "dd/mm/yyyy hh:mm:ss cantMinutos" << endl;
    // Leemos "(fecha: dd/mm/yyyy) (hora: hh/mm/ss) (cant)"
    scanf("%s %s %s", fecha, hora, cant);

    // ¿Por qué no leemos directamte %s/%s/%s %s:%s:%s %s? Porque les dará error/bug en el buffer guardando cualquier cosa ya que el scanf toma como parte del string el espacio en blanco

    /*
        Como más adelante en la tarea, tenemos que imprimir los movimientos con este formato: 01/01/2018, necesitamos si o si usar strings
        ya que con enteros o flotantes, lo que imprimiría sería 1/1/2018 y eso está malo.
        Ahora, en fecha tenemos: dd/mm/yyyy y necesitaremos separar los dd mm yyyy los cuales están separados por "/"
        en hora tenemos hh:mm:ss y se separan con ":"
        la cantidad ya la tenemos separada

        asi que usaremos la función strtok para separar
        ¿Como funciona?

        la función strok(cadena, separador) toma la cadena de string y ASIGNA el caracter NULO en la posicion donde encuentra el separador. Luego, nos retorna un PUNTERO hacia el inicio de la cadena
        ¿Que significa esto?
        la función toma dd/mm/yyyy y la deja como dd\0mm/yyyy y asigna un puntero al inicio, por lo tanto cuando llamamos al puntero y consultamos el valor, nos mostrará solo: dd ya que despues siguen el caracter NULO
        sin embargo el puntero sigue siendo dd\0mm/yyyy, por lo tanto podemos seguir cortandolo.
        Ahora, para seguir cortando tenemos que llamar denuevo a strtok, pero cambia a esta forma: strtok(NULL, "/"), por que el NULL? cuando no le asignamos una cadena, esta función usara el ultimo puntero que devolvió
        es decir, usará el mismo puntero con el cual estabamos trabajando, Y ADEMÁS, comenzará desde el caracter NULO. 
        Ejemplificando:
        char* token = strtok("dd/mm/yyyy", "/"); -> devuelve un puntero hacia "dd\0mm/yyyy" y si lo leemos, tenemos "dd", asi que lo guardamos
        dia = token; -> ahora, llamamos denuevo a la funcion
        token = strtok(NULL, "/"); -> comenzará leyendo desde el caracter NULO, es decir desde \0. En token antes de llamar la funcion tenemos: "dd\0mm/yyyy", luego de llamarla tenemos: "dd\0mm\0yyyy" y nos devuelve un puntero que apunta a la posicion del anterior caracter NULO
        eso significa que al leer token, leeremos "mm" ya que tenemos "dd\0mm\0yyyy" pero comienza a leer desde el final de "dd\0"
        Si llamamos por tercera vez strtok de la misma manera, este no encontrará el "/" por lo que asignará al final de la cadena el caracter nulo y obtendremos el valor de yyyy ya que practicamente terminariamos con lo siguiente: dd\0mm\0yyyy\0 y nos devolvería un puntero apuntando al yyyy
        
    */
    char *tokenFecha;
    tokenFecha = strtok(fecha, "/");
    strcpy(ingMov[0], tokenFecha);
    tokenFecha = strtok(NULL, "/");
    strcpy(ingMov[1], tokenFecha);
    tokenFecha = strtok(NULL, "/");
    strcpy(ingMov[2], tokenFecha);

    char *tokenHora;
    tokenHora = strtok(hora, ":");
    strcpy(ingMov[3], tokenHora);
    tokenHora = strtok(NULL, ":");
    strcpy(ingMov[4], tokenHora);
    tokenHora = strtok(NULL, ":");
    strcpy(ingMov[5], tokenHora);

    strcpy(ingMov[6], cant);

    // PRUEBA DE QUE LA SEPARACIÓN A FUNCIONADO :D
    printf("\n\n%s/%s/%s %s:%s:%s %s\n\n", ingMov[0], ingMov[1], ingMov[2], ingMov[3], ingMov[4], ingMov[5], ingMov[6]);

    return 0;
}