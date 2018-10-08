/*DECLARACION DE LIBRERIAS*/
//libreria "renovada" respecto a stdio.h
#include <iostream>
//la siguiente libreria es para trabajar con tipos de datos string
#include <string>
/*
Se declara el namespace por que estamos accediendo
a una clase llamada std incluida dentro de iostream
*/
using namespace std;

/*DECLARACION DE VARIABLES*/
//variables de la sesión
bool loggedIn = false;
//variables registro
string usuarioRegistrado, contrasenaRegistrada;
//variables del login
string usuario, contrasena, confirmarContrasena;

int main()
{
    cout << endl
         << endl;
    cout << "***********************************" << endl;
    cout << "* Bienvenido al sistema de ventas *" << endl;
    cout << "***********************************" << endl;
    cout << endl
         << endl;
    /*BUCLE DE INICIO DEL PROGRAMA*/
    do
    {
        //Variable para guardar la opcion ingresada
        int opcionPrimerMenu;
        //menu de inicio del programa
        cout << "Selecciona alguna opcion antes de seguir" << endl;
        cout << "1. Ingresar" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Salir" << endl;
        cin >> opcionPrimerMenu;
        //switch entre las opciones ingresadas
        switch (opcionPrimerMenu)
        {
        case 1:
            for (int i = 3; i > 0; i--)
            {
                cout << "Ingrese su usuario: " << endl;
                cin >> usuario;
                cout << "Ingrese su contrasena: " << endl;
                cin >> contrasena;
                if (usuario == usuarioRegistrado && contrasena == contrasenaRegistrada)
                {
                    loggedIn = true;
                    cout << "Has ingresado al sistema correctamente!" << endl;
                    break;
                }
                else
                {
                    cout << "Datos incorrectos, te quedan " << (i - 1) << " intentos!" << endl;
                }
            }
            if (!loggedIn)
            {
                cout << "No has podido ingresar sesion" << endl;
                return false;
            }
            else
            {
                break;
            }
        case 2:
            cout << "caso 2" << endl;
            cout << "Ingrese su usuario" << endl;
            cin >> usuario;
            cout << "Ingrese la contrasena" << endl;
            cin >> contrasena;
            cout << "Confirme la contrasena" << endl;
            cin >> confirmarContrasena;
            if (contrasena == confirmarContrasena)
            {
                usuarioRegistrado = usuario;
                contrasenaRegistrada = contrasena;
                cout << "Te has registrado correctamente!" << endl;
                break;
            }
            else
            {
                cout << "El registro ha fallado, intentalo nuevamente!" << endl;
                break;
            }
        case 3:
            cout << "El programa se cerrará" << endl;
            return false;
        default:
            cout << "Ingrese una opcion correcta por favor" << endl;
            break;
        }

    } while (!loggedIn);
    cout << "pase por aqui " << loggedIn << endl;
    if (loggedIn)
    {
        cout << "HOLA MUNDO " << endl;
        do
        {

        } while (loggedIn);
    }
    return 0;
}