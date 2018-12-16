/* Universidad de La Frontera
* Ingeniería Civil Electrónica
*
* ICC-202 PROGRAMACION DE COMPUTADORES
*
* Tarea 2
*
* Autor: 
* Tomás Jiménez. (t.jimenez03@ufromail.cl)
*
*
* Fecha: 16/12/2018
*
* Plataforma de atención de telefonía.
* Esta plataforma cuenta con un sistema de registro e ingreso, son sus respectivas validaciones para que no se haga abuso del sistema, como lo es un ataque a fuerza bruta
* Una vez en el menú, tenemos la capacidad de contratar o consultar planes, realizar consultas de saldo, realizar recargas tanto de minutos o megas de internet.
* También podemos realizar movimientos y dejar registrada la fecha del movimiento junto con la cantidad de megas o minutos gastados, todos estos movimientos quedarán registrados.
* Como los movimientos se quedan registrados, podremos consultarlos facilmente ya sea mostrando todos en pantalla o usando un filtro de rango de fechas (muestra todos los movimientos entre 2 fechas elegidas)
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

/*
Se declara el namespace por que estamos accediendo
a una clase llamada std incluida dentro de iostream y string
*/
using namespace std;

/*          PROTOTIPOS          */
void imprimirBienvenida();

// ESTA FUNCION CONTIENE 2 LINEAS DE CODIGO PARA LIMPIAR PANTALLA, HAY QUE ACTIVAR LA NECESARIA.
// UNA LINEA ES PARA LINUX
// OTRA LINEA ES PARA WINDOWS
// DE OTRO CASO APARECERÁ UN ERROR EN CONSOLA
void limpiarPantalla();

/* SECCION INICIO */
int menuInicio();
void programaInicio();
void inicio_Ingreso();
void inicio_Registro();

/* SECCION PRINCIPAL */
int menuPrincipal();
void programaPrincipal();
void principal_Contrato();
void principal_Consulta();
void principal_Saldo();
void principal_Recarga();
void principal_Movimiento();
void principal_ConsultaMovimientos();
void filtroMovimientos();

/*          DECLARACION DE VARIABLES            */

//Variable de sesión
bool loggedIn = false;

//Variables de registro
string usuarioRegistrado, contrasenaRegistrada;

//Variables de ingreso
string usuario, contrasena, confirmarContrasena;

//Variables de datos de cuenta
int minutos = 0;
int mb = 0;
int plancontratado = 0;

// Arrays de movimientos

/*  
{ 'dia', 'mes', 'año', 'hora', 'min', 'seg', 'cant', 'mb/minutos' }
min = 1
mb = 2
*/

char datosMovimientos[10][8][10];
int conteoMovimientos = 0; // Conteo de movimientos registrados

int main()
{
    /*BUCLE DE INICIO DEL PROGRAMA*/
    imprimirBienvenida();
    do
    {
        programaInicio();
    } while (!loggedIn);
    // Solo se ejecutara si es que ingreso correctamente
    /*
		En varios menus, se uso estado != 0 para verificar si es que es necesario terminar el ciclo
		de esta manera, cuando estado = 1, el ciclo finalizará
	*/
    if (loggedIn)
    { //Si el inicio de sesión fue éxitoso...
        // BUCLE MENU PRINCIPAL DEL PROGRAMA
        do
        {
            programaPrincipal();
        } while (loggedIn);
    }
    return 0;
}

void imprimirBienvenida()
{
    //Impresion de titulo del programa
    cout << endl
         << endl;
    cout << "*********************************************" << endl;
    cout << "*********************************************" << endl;
    cout << "***                                       ***" << endl;
    cout << "*** |-----------------------------------| ***" << endl;
    cout << "*** |              Telefonia            | ***" << endl;
    cout << "*** | Plataforma de Atencion al Usuario | ***" << endl;
    cout << "*** |                                   | ***" << endl;
    cout << "*** |     Desarrollado por: Tomas J.    | ***" << endl;
    cout << "*** |-----------------------------------| ***" << endl;
    cout << "***                                       ***" << endl;
    cout << "*********************************************" << endl;
    cout << "*********************************************" << endl;
    cout << endl
         << endl;
}

void limpiarPantalla()
{
    // EN CASO DE QUE NO FUNCIONE CON NINGUNA, COMENTAR LAS 2 LINEAS POR FAVOR
    // system("cls"); // WINDOWS
    system("clear"); // BASADO EN LINUX
}

int menuInicio()
{
    int opcion;
    //menu de inicio del programa
    cout << "Selecciona alguna opcion antes de seguir" << endl;
    cout << "1. Ingresar" << endl;
    cout << "2. Registrarse" << endl;
    cout << "3. Salir" << endl;
    cin >> opcion;
    return opcion;
}
void programaInicio()
{
    int opcion = menuInicio();
    limpiarPantalla();
    switch (opcion)
    {
    case 1: //Caso de ingreso
        inicio_Ingreso();
        break;
    case 2: //Caso registro de usuario
        inicio_Registro();
        break;
    case 3: // Caso para salir
        cout << "El programa se cerrará" << endl;
        exit(0);
    default: // Caso de que no seleccione una opcion valida, esto se repetirá en los otros casos "default"
        cout << "Ingrese una opcion correcta por favor: " << endl;
        break;
    }
}

void inicio_Ingreso()
{
    //For que representa 3 Intentos para Ingresar
    for (int i = 3; i > 0; i--)
    {
        cout << "Ingrese su usuario: " << endl;
        cin >> usuario;
        limpiarPantalla();
        cout << "Ingrese su contrasena: " << endl;
        cin >> contrasena;
        limpiarPantalla();
        // Hacer comparacion con los datos registrados
        if (usuario == usuarioRegistrado && contrasena == contrasenaRegistrada)
        {
            //Hacer que la variable loggedIn sea verdadera para dar cuenta de que el inicio de sesión fue exitoso
            loggedIn = true;
            limpiarPantalla();
            cout << "Has ingresado al sistema correctamente!" << endl;
            break;
        }
        else
        {
            limpiarPantalla();
            cout << "Datos incorrectos, te quedan " << (i - 1) << " intentos!" << endl;
        }
    }
    if (!loggedIn)
    {
        limpiarPantalla();
        cout << "No has podido ingresar sesion" << endl;
    }
}
void inicio_Registro()
{
    cout << "Ingrese su rut sin puntos ni guion para registarse: " << endl;
    cin >> usuario;
    limpiarPantalla();
    do
    {
        cout << "Ingrese la contrasena deseada de 4 digitos: " << endl;
        cin >> contrasena;
        // Comprobar que la contrasa sea de maximo 4 digitos o caracteres
        if (contrasena.length() == 4)
        {
            break;
        }
        limpiarPantalla();
    } while (true);
    cout << "Confirme la contrasena anterior:" << endl;
    cin >> confirmarContrasena;
    // Validar contraseñas
    if (contrasena == confirmarContrasena)
    {
        usuarioRegistrado = usuario;
        contrasenaRegistrada = contrasena;
        limpiarPantalla();
        cout << "Te has registrado correctamente! Ahora inicia sesion" << endl;
    }
    else
    {
        limpiarPantalla();
        cout << "El registro ha fallado! Intentalo nuevamente" << endl;
    }
}

int menuPrincipal()
{
    int opcion;
    cout << endl
         << endl
         << "Menu Principal" << endl
         << endl;
    cout << "1. Consultar/Contratar Plan" << endl
         << "2. Consulta de Saldo" << endl
         << "3. Recarga" << endl
         << "4. Anadir movimiento" << endl
         << "5. Listado de movimientos" << endl
         << "6. Salir" << endl;
    cin >> opcion;
    return opcion;
}
void programaPrincipal()
{
    int opcion = menuPrincipal();
    limpiarPantalla();
    switch (opcion)
    {
    case 1:
        // Caso consultar o contratar plan
        // Si es que no se ha contratado un plan...
        if (plancontratado == 0)
        {
            principal_Contrato();
        }
        else
        {
            principal_Consulta();
        }
        break;
    case 2: // Caso consulta
        principal_Saldo();
        break;
    case 3: // Caso de recarga
    {
        principal_Recarga();
        break;
    }
    case 4: // Caso movimiento
        principal_Movimiento();
        break;
    case 5: // Caso consulta movimientos
        principal_ConsultaMovimientos();
        break;
    case 6: // Caso salir
        cout << "El programa se cerrara." << endl;
        exit(0);
        break;
    default:
        cout << "Comando invalido, intente nuevamente: " << endl;
    }
}
void principal_Contrato()
{
    // Esta es la variable estado anteriormente mencionada para determinar cuando se rompe el ciclo
    int estado = 0;
    while (estado != 1)
    {
        // Variable para guardar la opcion ingresada
        int plan;
        cout << " Cual plan desea contratar?" << endl;
        cout << " 1. 7.990 (200 minutos + 3 GB)" << endl;
        cout << " 2. 14.990 (400 minutos + 5 GB)" << endl;
        cout << " 3. 19.990 (600 minutos + 7 GB)" << endl;
        cout << " 4. 24.990 (800 minutos + 10 GB)" << endl;
        cout << " 5. 29.990 (1.000 minutos + 25 GB)" << endl;
        cin >> plan;
        switch (plan)
        {
        case 1: //Caso plan 1
            estado = 1;
            mb = mb + 3000;          //Agregará los mb correspondientes por el plan contratado, incluyendo los que se hayan recargado aparte
            minutos = minutos + 200; //Agregará los minutos correspondientes por el plan contratado, incluyendo los que se hayan recargado aparte
            plancontratado = 1;      //Asignará el tipo de plan contratado
            break;
        case 2: //Caso plan 2
            estado = 1;
            mb = mb + 5000;
            minutos = minutos + 400;
            plancontratado = 2;
            break;
        case 3: //Caso plan 3
            estado = 1;
            mb = mb + 7000;
            minutos = minutos + 600;
            plancontratado = 3;
            break;
        case 4: //Caso plan 4
            estado = 1;
            mb = mb + 10000;
            minutos = minutos + 800;
            plancontratado = 4;
            break;
        case 5: //Caso plan 5
            estado = 1;
            mb = mb + 25000;
            minutos = minutos + 1000;
            plancontratado = 5;
            break;

        default:
            cout << "Comando invalido. Por favor ingrese una opcion valida: " << endl;
        }
    }
    limpiarPantalla();
}
void principal_Consulta()
{
    //Si es que ya hay un plan contradado
    switch (plancontratado)
    {
    case 1: //Imprimir datos plan 1
        cout << " Plan 1 --> $7.990 (200 minutos + 3 GB)" << endl;
        break;
    case 2: //Imprimir datos plan 2
        cout << " Plan 2 --> $14.990 (400 minutos + 5 GB)" << endl;
        break;
    case 3: //Imprimir datos plan 3
        cout << " Plan 3 --> $19.990 (600 minutos + 7 GB)" << endl;
        break;
    case 4: //Imprimir datos plan 4
        cout << " Plan 4 --> $24.990 (800 minutos + 10 GB)" << endl;
        break;
    case 5: //Imprimir datos plan 5
        cout << " Plan 5 --> $29.990 (1.000 minutos + 25 GB)" << endl;
        break;
    default:
        cout << " No hay plan vigente." << endl;
    }
}

void principal_Saldo()
{
    limpiarPantalla();
    cout << "Tiene " << minutos << " minutos y " << mb << " MB" << endl;
}

void principal_Recarga()
{
    int recarga;        //guardar la opcion ingresada
    int estado = 0;     //variable de estado como lo anteriormente mecionado
    while (estado != 1) //mientras estado sea 0, este bucle se ejecutará
    {
        cout << "Que tipo de recarga desea realizar?" << endl;
        cout << "1. minutos." << endl;
        cout << "2. MB." << endl;
        cin >> recarga;
        limpiarPantalla();
        switch (recarga)
        {
        case 1: //caso regarga de minutos
        {
            int recargaminutos = 0;
            cout << "Cuantos minutos desea recargar?" << endl;
            cin >> recargaminutos;
            minutos += recargaminutos; //sumamos los minutos recargados a los minutos guardados
            estado = 1;
            break;
        }
        case 2: //caso regarga de MB
        {
            int recargamb = 0;
            cout << "Cuantos MB desea recargar?" << endl;
            cin >> recargamb;
            mb += recargamb; //sumamos los mb recargados a los mb guardados
            estado = 1;
            break;
        }
        default:
            limpiarPantalla();
            cout << "Comando invalido. Por favor ingrese una opcion valida: " << endl;
        }
    }
    limpiarPantalla();
}

void principal_Movimiento()
{
    int movimiento; // variable que guardara el tipo de movimiento
    int estado = 0; // variable para ejecutar el while y salir del mismo
    while (estado != 1)
    {
        cout << "Que tipo de movimiento se desea anadir?" << endl;
        cout << "1. minutos." << endl;
        cout << "2. MB." << endl;
        cin >> movimiento;
        limpiarPantalla();
        switch (movimiento)
        {
        case 1: // Caso movimiento minutos
        {
            // Arreglo que guardara todos los datos que se van a pedir
            /* { 'dia', 'mes', 'año', 'hora', 'min', 'seg', 'cant', 'mb/minutos' } */
            char ingMov[8][100];
            strcpy(ingMov[7], "minutos");
            // El scanf me daba error cuando quería leer el formato "dd/mm/yyyy hh:mm:ss cant" usando un %s en cada valor que necesitaba
            // por lo tanto, cree 3 arreglos que me almacenaran "dd/mm/yyyy" - "hh:mm:ss" - "cant" por separado, y luego, hacer la separación
            char fecha[25];
            char hora[25];
            char cant[25];
            int error = 0;
            do
            {
                limpiarPantalla();
                if (error == 1)
                {
                    printf("Formato invalido. Por favor ingrese los datos nuevamente.\n\n");
                }

                cout << "Ingrese el movimiento con el formato: " << endl
                     << "dd/mm/yyyy hh:mm:ss cantMinutos" << endl;
                scanf("%s %s %s", fecha, hora, cant);
                // Si se vuelve a ejecutar el while, es por que hubo un error con el formato
                error = 1;
                // strlen cuenta los caracteres que se encuentran en la cadena
            } while (strlen(fecha) != 10 || strlen(hora) != 8);

            /* El uso de la función la expliqué en el archivo "strings.cpp" ya que fue una explicación bastante extensa y usé ese modulo para realizar esta sección del código */
            /* De forma super resumida, strtok separa cadenas de strings en base a un delimitador, con esto pude separar las fechas (dias, meses, años) y los horarios (horas, minutos, segundos) */
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

            // La función atoi convierte el valor explicito del string en un entero, no nos mostrará el código ascii, si no el valor como tal. EJ: tengo un string que es "100", si la paso por atoi: atoi("100") -> arrojará 100 como entero
            // Comprobamos que el saldo sea suficiente para ejecutar el movimiento
            if ((minutos - atoi(cant)) < 0)
            {
                limpiarPantalla();
                cout << "Saldo insuficiente. No es posible realizar el movimiento." << endl;
                estado = 1;
            }
            else
            {
                // De lo contrario, guardaremos el movimiento en el arreglo global que almacenará en cada fila un movimiento con todos sus datos.
                for (int i = 0; i < 8; i++)
                {
                    strcpy(datosMovimientos[conteoMovimientos][i], ingMov[i]);
                }
                conteoMovimientos++;            //Contador que nos indica cuantos movimientos se han realizado CORRECTAMENTE
                minutos = minutos - atoi(cant); // Restamos la cantidad utilizada
                limpiarPantalla();
                estado = 1; // Salimos del bucle
            }
            break;
        }
        case 2: //Caso movimiento mb. En este caso, se repite el mismo procedimiento que en el caso anterior
        {
            char ingMov[8][100];
            strcpy(ingMov[7], "mb");
            char fecha[25];
            char hora[25];
            char cant[25];
            int error = 0;
            do
            {
                limpiarPantalla();
                if (error == 1)
                {
                    printf("Formato invalido. Por favor ingrese los datos nuevamente.\n\n");
                }
                cout << "Ingrese el movimiento con el formato: " << endl
                     << "dd/mm/yyyy hh:mm:ss cantMb" << endl;
                scanf("%s %s %s", fecha, hora, cant);
                error = 1;
            } while (strlen(fecha) != 10 || strlen(hora) != 8);

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

            if ((mb - stoi(cant)) < 0)
            {
                limpiarPantalla();
                cout << "Saldo insuficiente. No es posible realizar el movimiento." << endl;
                estado = 1;
            }
            else
            {
                for (int i = 0; i < 8; i++)
                {
                    strcpy(datosMovimientos[conteoMovimientos][i], ingMov[i]);
                }
                conteoMovimientos++;
                mb = mb - atoi(cant);
                limpiarPantalla();
                estado = 1;
            }
        }
        break;
        default:
            cout << "Comando invalido. Por favor ingrese una opcion valida: " << endl;
        }
    }
}

void principal_ConsultaMovimientos()
{
    int estado = 0;
    do
    {
        int opcion;
        cout << "1. Todos los movimientos" << endl
             << "2. Filtrar por fecha y hora" << endl
             << "3. Regresar al menu principal" << endl;
        cin >> opcion;
        limpiarPantalla();
        switch (opcion)
        {
        case 1: // Caso mostrar todos los movimientos
            // Si el contador de movimientos es 0, logicamente no se han realizado movimientos
            if (conteoMovimientos == 0)
            {
                cout << "No se han realizado movimientos" << endl;
            }
            else
            {
                // En caso contrario, si el contador es distntito de 0, se mostrarán TODOS los movimientos
                for (int i = 0; i < conteoMovimientos; i++)
                {
                    printf("%s/%s/%s %s:%s:%s %s %s\n", datosMovimientos[i][0], datosMovimientos[i][1], datosMovimientos[i][2], datosMovimientos[i][3], datosMovimientos[i][4], datosMovimientos[i][5], datosMovimientos[i][6], datosMovimientos[i][7]);
                }
            }
            estado = 1;
            break;
        case 2: // Caso movimientos por filtro de hora y fecha
            if (conteoMovimientos == 0)
            {
                cout << "No se han realizado movimientos" << endl;
            }
            else
            {
                filtroMovimientos();
            }

            estado = 1;
            break;
        case 3: // Caso volver al menu principal
            estado = 1;
            break;
        default:
            cout << "Comando invalido. Por favor ingrese una opcion valida: " << endl;
        }
    } while (estado == 0);
}

void filtroMovimientos()
{
    // Se repite el procedimiento de separación de strings
    char desde[2][20];      // Guardará el rango inicial: [0]: "dd/mm/yyyy" [1]: "hh:mm:ss"
    char hasta[2][20];      // Guardará el rango final: [0]: "dd/mm/yyyy" [1]: "hh:mm:ss"
    char aux[10];           // Variable auxiliar para no tener errores con el buffer del scanf al leer strings
    char desdeRango[6][20]; //En este arreglo guardaremos las variables SEPARADAS contenidas en el arreglo anterior llamado "desde" | dd, mm, yyyy, hh, mm, ss
    char hastaRango[6][20]; //En este arreglo guardaremos las variables SEPARADAS contenidas en el arreglo anterior llamado "hasta" | dd, mm, yyyy, hh, mm, ss
    /* En las siguientes variables usaré una forma de evaluar los rangos de fechas con la siguiente formula: 
        año*10000 + mes*100 + dia para las fechas
        hora*10000 + minutos*100 + segundos para las horas
        De esta forma, obtendremos un entero de la siguiente forma:
        yyyymmdd y hhmmss respectivamente
        EJEMPLO: 05/08/2018 -> 20180805  || 12:30:52 ->  123052
        De esta forma, podremos hacer comparaciones de fechas de una forma super sencilla, esta forma de calcular se utiliza en PHP para calculos simples
    */
    int sumDesdeFechas; // Este guardara la formula de fechas para el rango INICIAL
    int sumDesdeHoras;  // Este guardara la formula de horas para el rango INICIAL
    int sumHastaFechas; // Este guardara la formula de fechas para el rango FINAL
    int sumHastaHoras;  // Este guardara la formula de horas para el rango FINAL
    int error = 0;

    do
    {
        limpiarPantalla();
        if (error == 1)
        {
            printf("Formato invalido. Por favor ingrese los datos nuevamente.\n\n");
        }
        cout << "Ingrese el rango a filtrar con el siguiente formato: " << endl
             << "dd/mm/yyyy hh:mm:ss - dd/mm/yyyy hh:mm:ss" << endl;
        scanf("%s %s %s %s %s", desde[0], desde[1], aux, hasta[0], hasta[1]); // -> nos retorna: "dd/mm/yyyy" "hh:mm:ss" "-" "dd/mm/yyyy" "hh:mm:ss"
        error = 1;
    } while (strlen(desde[0]) != 10 || strlen(desde[1]) != 8 || strlen(hasta[0]) != 10 || strlen(hasta[1]) != 8); //Pequeñas validaciones para prevenir errores en el formato

    // Misma explicación que está en "strings.cpp", pues, tenemos que separar los strings ingresados

    //NOS DEVUELVE dd, mm, yyyy
    char *tokenDesdeFecha;
    tokenDesdeFecha = strtok(desde[0], "/");
    strcpy(desdeRango[0], tokenDesdeFecha);
    tokenDesdeFecha = strtok(NULL, "/");
    strcpy(desdeRango[1], tokenDesdeFecha);
    tokenDesdeFecha = strtok(NULL, "/");
    strcpy(desdeRango[2], tokenDesdeFecha);

    // NOS DEVUELVE hh, mm, ss
    char *tokenDesdeHora;
    tokenDesdeHora = strtok(desde[1], ":");
    strcpy(desdeRango[3], tokenDesdeHora);
    tokenDesdeHora = strtok(NULL, ":");
    strcpy(desdeRango[4], tokenDesdeHora);
    tokenDesdeHora = strtok(NULL, ":");
    strcpy(desdeRango[5], tokenDesdeHora);

    //NOS DEVUELVE dd, mm, yyyy
    char *tokenHastaFecha;
    tokenHastaFecha = strtok(hasta[0], "/");
    strcpy(hastaRango[0], tokenHastaFecha);
    tokenHastaFecha = strtok(NULL, "/");
    strcpy(hastaRango[1], tokenHastaFecha);
    tokenHastaFecha = strtok(NULL, "/");
    strcpy(hastaRango[2], tokenHastaFecha);

    // NOS DEVUELVE hh, mm, ss
    char *tokenHastaHora;
    tokenHastaHora = strtok(hasta[1], ":");
    strcpy(hastaRango[3], tokenHastaHora);
    tokenHastaHora = strtok(NULL, ":");
    strcpy(hastaRango[4], tokenHastaHora);
    tokenHastaHora = strtok(NULL, ":");
    strcpy(hastaRango[5], tokenHastaHora);

    // Aqui aplicamos las formulas ya explicadas
    sumHastaFechas = atoi(hastaRango[0]) + atoi(hastaRango[1]) * 100 + atoi(hastaRango[2]) * 10000; // -> queda como un entero de la forma yyyymmdd
    sumHastaHoras = atoi(hastaRango[3]) * 10000 + atoi(hastaRango[4]) * 100 + atoi(hastaRango[5]);  // -> queda como un entero de la forma hhmmss
    sumDesdeFechas = atoi(desdeRango[0]) + atoi(desdeRango[1]) * 100 + atoi(desdeRango[2]) * 10000; // -> queda como un entero de la forma yyyymmdd
    sumDesdeHoras = atoi(desdeRango[3]) * 10000 + atoi(desdeRango[4]) * 100 + atoi(desdeRango[5]);  // -> queda como un entero de la forma hhmmss

    limpiarPantalla();
    int contador = 0;
    // Aca comenzaremos a evaluar todos los movimientos que han sido INGRESADOS
    for (int i = 0; i < conteoMovimientos; i++)
    {
        // Realizaremos las sumas con las mismas formulas explicadas anteriormente
        int sumFechas;
        int sumHoras;
        sumFechas = atoi(datosMovimientos[i][0]) + atoi(datosMovimientos[i][1]) * 100 + atoi(datosMovimientos[i][2]) * 10000; // -> queda como un entero de la forma yyyymmdd
        sumHoras = atoi(datosMovimientos[i][3]) * 10000 + atoi(datosMovimientos[i][4]) * 100 + atoi(datosMovimientos[i][5]);  // -> queda como un entero de la forma hhmmss

        // Si las fechas coinciden para el rango inicial y final, significa que podría haber un desfase solo por horas
        if (sumDesdeFechas == sumFechas && sumHastaFechas == sumFechas)
        {
            // Comprobamos que el desfase de horas cumple que haya un movimiento dentro del rango inicial y final
            if (sumDesdeHoras < sumHoras && sumHastaHoras > sumHoras)
            {
                // Si se cumple, imprimira el movimiento por pantalla y aumentara el contador
                contador++;
                printf("%s/%s/%s %s:%s:%s %s %s\n", datosMovimientos[i][0], datosMovimientos[i][1], datosMovimientos[i][2], datosMovimientos[i][3], datosMovimientos[i][4], datosMovimientos[i][5], datosMovimientos[i][6], datosMovimientos[i][7]);
            }
        }
        /*
            Aca comprobaremos si la fecha de rango INICIAL es IGUAL a la fecha del MOVIMIENTO
            Si estas son iguales, tenemos que comprobar que el horario inicial sea menor o igual al horario del movimiento ingresado, de lo contrario, quedaría fuera.
            Si estas 2 se cumplen, tendremos que comprobar A LA VEZ si es que la fecha del rango FINAL es MAYOR, si esto se cumple, imprimiremos el movimiento facilmente o si las fechas son iguales y la hora del rango final es mayor a la del movimiento.
        */
        else if (sumDesdeFechas == sumFechas && sumHoras >= sumDesdeHoras && (sumHastaFechas > sumFechas || (sumHastaFechas == sumFechas && sumHoras < sumHastaHoras)))
        {
            contador++;
            printf("%s/%s/%s %s:%s:%s %s %s\n", datosMovimientos[i][0], datosMovimientos[i][1], datosMovimientos[i][2], datosMovimientos[i][3], datosMovimientos[i][4], datosMovimientos[i][5], datosMovimientos[i][6], datosMovimientos[i][7]);
        }
        // Aca hacemos lo mismo del caso anterior, solo que asumimos que la fecha del rango FINAL es igual a la INICIAL, entonces tendremos que comprobar que la hora del rango final es mayor a la del movimiento y además que esté dentro del rango inicial
        else if (sumHastaFechas == sumFechas && sumHoras <= sumHastaHoras && (sumDesdeFechas < sumFechas || (sumDesdeFechas == sumFechas && sumHoras > sumDesdeHoras)))
        {
            contador++;
            printf("%s/%s/%s %s:%s:%s %s %s\n", datosMovimientos[i][0], datosMovimientos[i][1], datosMovimientos[i][2], datosMovimientos[i][3], datosMovimientos[i][4], datosMovimientos[i][5], datosMovimientos[i][6], datosMovimientos[i][7]);
        }
        // El caso más sencillo, si el rango de fechas inicial es menor a la fecha del movimiento y si el rango de fechas final es mayor a la del movimiento, significa que SI o SI el movimiento esta dentro del rango
        else if (sumDesdeFechas < sumFechas && sumHastaFechas > sumFechas)
        {
            contador++;
            printf("%s/%s/%s %s:%s:%s %s %s\n", datosMovimientos[i][0], datosMovimientos[i][1], datosMovimientos[i][2], datosMovimientos[i][3], datosMovimientos[i][4], datosMovimientos[i][5], datosMovimientos[i][6], datosMovimientos[i][7]);
        }
    }
    // Si no se encontró ningún movimiento, lo imprimirá por pantalla
    if (contador == 0)
    {
        printf("No se han encontrado movimientos en el rango de fechas dado\n");
    }
}