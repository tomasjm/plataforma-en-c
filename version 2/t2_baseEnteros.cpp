#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*          PROTOTIPOS          */
void imprimirBienvenida();
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
{ 'dia', 'mes', 'año', 'hora', 'min', 'seg', 'mb/min', 'cant' }
min = 1
mb = 2
*/

string datosMovimientos[10][8];
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
    cout << "*****************************************" << endl;
    cout << "*                                       *" << endl;
    cout << "*   Plataforma de Atencion al Usuario   *" << endl;
    cout << "*                                       *" << endl;
    cout << "*****************************************" << endl;
    cout << endl
         << endl;
}

void limpiarPantalla()
{
    system("cls");
    // system("clear");
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
    int movimiento;
    int estado = 0;
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
            int ingMov[8];
            ingMov[6] = 1;
            do
            {
                limpiarPantalla();
                cout << "Ingrese el movimiento con el formato: " << endl
                     << "dd/mm/yyyy hh:mm:ss cantMinutos" << endl;
                scanf("%s/%s/%s %s:%s:%s %s", &ingMov[0], &ingMov[1], &ingMov[2], &ingMov[3], &ingMov[4], &ingMov[5], &ingMov[7]);

                /* VALIDACIONES DE FECHAS, HORAS, ETC. SE PERMITE CUALQUIER AÑO */
                /* { 'dia', 'mes', 'año', 'hora', 'min', 'seg', 'mb/min', 'cant' } */
                /* 01/01/xxxx - 30/12/xxxx || 00:00:00 - 23:59:59 */
            } while (ingMov[0] > 30 || ingMov[0] < 1 || ingMov[1] > 12 || ingMov[1] < 1 || ingMov[3] > 23 || ingMov[3] < 0 || ingMov[4] > 59 || ingMov[4] < 0 || ingMov[5] > 59 || ingMov[5] < 0);
            if ((minutos - ingMov[7]) < 0)
            {
                limpiarPantalla();
                cout << "Saldo insuficiente. No es posible realizar el movimiento." << endl;
                estado = 1;
            }
            else
            {
                for (int i = 0; i < 8; i++)
                {
                    datosMovimientos[conteoMovimientos][i] = ingMov[i];
                }
                conteoMovimientos++;
                minutos = minutos - ingMov[7];
                limpiarPantalla();
                estado = 1;
            }
            break;
        }
        case 2: //Caso movimiento mb
        {
            int ingMov[8];
            ingMov[6] = 2;
            do
            {
                limpiarPantalla();
                cout << "Ingrese el movimiento con el formato: " << endl
                     << "dd/mm/yyyy hh:mm:ss cantMb" << endl;
                scanf("%s/%s/%s %s:%s:%s %s", &ingMov[0], &ingMov[1], &ingMov[2], &ingMov[3], &ingMov[4], &ingMov[5], &ingMov[7]);

                /* VALIDACIONES DE FECHAS, HORAS, ETC. SE PERMITE CUALQUIER AÑO */
                /* { 'dia', 'mes', 'año', 'hora', 'min', 'seg', 'mb/min', 'cant' } */
                /* 01/01/xxxx - 30/12/xxxx || 00:00:00 - 23:59:59 */
            } while (ingMov[0] > 30 || ingMov[0] < 1 || ingMov[1] > 12 || ingMov[1] < 1 || ingMov[3] > 23 || ingMov[3] < 0 || ingMov[4] > 59 || ingMov[4] < 0 || ingMov[5] > 59 || ingMov[5] < 0);
            if ((mb - ingMov[7]) < 0)
            {
                limpiarPantalla();
                cout << "Saldo insuficiente. No es posible realizar el movimiento." << endl;
                estado = 1;
            }
            else
            {
                for (int i = 0; i < 8; i++)
                {
                    datosMovimientos[conteoMovimientos][i] = ingMov[i];
                }
                conteoMovimientos++;
                mb = mb - ingMov[7];
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
        case 1:
            if (conteoMovimientos == 0)
            {
                cout << "No se han realizado movimientos" << endl;
            }
            else
            {
                for (int i = 0; i < conteoMovimientos; i++)
                {
                    if (datosMovimientos[i][6] == "1")
                    {
                        printf("%s/%s/%s %s:%s:%s %s minutos\n", datosMovimientos[i][0], datosMovimientos[i][1], datosMovimientos[i][2], datosMovimientos[i][3], datosMovimientos[i][4], datosMovimientos[i][5], datosMovimientos[i][7]);
                    }
                    else
                    {
                        printf("%s/%s/%s %s:%s:%s %s mb\n", datosMovimientos[i][0], datosMovimientos[i][1], datosMovimientos[i][2], datosMovimientos[i][3], datosMovimientos[i][4], datosMovimientos[i][5], datosMovimientos[i][7]);
                    }
                }
            }
            estado = 1;
            break;
        case 2:
            if (conteoMovimientos == 0)
            {
                cout << "No se han realizado movimientos" << endl;
            }
            else
            {
                cout << "caso 2" << endl;
            }

            estado = 1;
            break;
        case 3:
            estado = 1;
            break;
        default:
            cout << "Comando invalido. Por favor ingrese una opcion valida: " << endl;
        }
    } while (estado == 0);
}