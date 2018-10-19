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
	    cout << "Ingrese su usuario: " << endl;
	    cin >> usuario;
            for (int i = 3; i > 0; i--)
            {
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
            break;
        case 2:
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
            }
            else
            {
                cout << "El registro ha fallado, intentalo nuevamente!" << endl;
            }
	    break;
        case 3:
            cout << "El programa se cerrará" << endl;
            return false;
        default:
            cout << "Ingrese una opcion correcta por favor" << endl;
            break;
        }

    } while (!loggedIn);
    if (loggedIn)
    {
        do
        {
		int opcionMenu;
		cout << "1. Consultar/Contratar Plan" << endl
			<< "2. Consulta de Saldo" << endl
			<< "3. Recarga" << endl
			<< "4. Añadir movimiento" << endl
			<< "5. Salir" << endl;
		cin >> opcionMenu;
		switch(opcionMenu) {
			case 1:
				cout << "Opcion 1" << endl;
				break;
			case 2:
				cout << "Opcion 2" << endl;
				break;
			case 3:
				cout << "Opcion 3" << endl;
				break;
			case 4:
				cout << "Opcion 4" << endl;
				break;
			case 5:
				cout << "Opcion 5" << endl;
				break;
			default:
				cout << "Comando invalido, intente nuevamente" << endl;
				break;
		}
        } while (loggedIn);
    }
    return 0;
}
