

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
//variables de la sesion
bool loggedIn = false;
//variables registro
string usuarioRegistrado, contrasenaRegistrada;
//variables del login
string usuario, contrasena, confirmarContrasena;
//variables de datos cuenta
int minutos = 0;
int mb = 0;
int plancontratado = 0;

/*
	En los switches, en su mayoria, se utilizo el caso "default" para corresponder
	a la opcion mal ingresada
*/

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
		//Caso de ingreso
		case 1:
			//3 Intentos para Ingresar
			for (int i = 3; i > 0; i--)
			{
				cout << "Ingrese su usuario: " << endl;
				cin >> usuario;
				cout << "Ingrese su contrasena: " << endl;
				cin >> contrasena;
				// Comprobar con datos registrados
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
		//Caso registro de usuario
		case 2:
			cout << "Ingrese el usuario que desea registrar" << endl;
			cin >> usuario;
			do
			{
				cout << "Ingrese la contrasena deseada de 4 digitos" << endl;
				cin >> contrasena;
				// Comprobar que la contraseña sea de maximo 4 digitos o caracteres
				if (contrasena.length() == 4)
				{
					break;
				}
			} while (true);
			cout << "Confirme la contrasena anterior" << endl;
			cin >> confirmarContrasena;
			// Validar contraseñas
			if (contrasena == confirmarContrasena)
			{
				usuarioRegistrado = usuario;
				contrasenaRegistrada = contrasena;
				cout << "Te has registrado correctamente!" << endl;
			}
			else
			{
				cout << "El registro ha fallado, seras devuelto al menu" << endl;
			}
			break;
		case 3:
			cout << "El programa se cerrara" << endl;
			return false;
		// Caso de que no seleccione una opcion valida
		default:
			cout << "Ingrese una opcion correcta por favor" << endl;
			break;
		}

	} while (!loggedIn);
	// Solo se ejecutara si es que ingreso correctamente
	/*
		En varios menus, se uso estado != 0 para verificar si es que es necesario terminar el ciclo
		de esta manera, cuando estado = 1, el ciclo finalizara
	*/
	if (loggedIn)
	{
		// BUCLE MENU PRINCIPAL DEL PROGRAMA
		do
		{
			// IMPRESION DE MENU PRINCIPAL
			int opcionMenu;
			cout << "1. Consultar/Contratar Plan" << endl
				 << "2. Consulta de Saldo" << endl
				 << "3. Recarga" << endl
				 << "4. Añadir movimiento" << endl
				 << "5. Salir" << endl;
			cin >> opcionMenu;
			switch (opcionMenu)
			{
			// Consultar o contratar plan
			case 1:
				if (plancontratado == 0)
				{
					int estado = 0;
					while (estado != 1)
					{
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
							//Caso plan 1
						case 1:
							estado = 1;
							mb = mb + 3000;
							minutos = minutos + 200;
							plancontratado = 1;
							break;
							//Caso plan 2
						case 2:
							estado = 1;
							mb = mb + 5000;
							minutos = minutos + 400;
							plancontratado = 2;
							break;
							//Caso plan 3
						case 3:
							estado = 1;
							mb = mb + 7000;
							minutos = minutos + 600;
							plancontratado = 3;
							break;
							//Caso plan 4
						case 4:
							estado = 1;
							mb = mb + 10000;
							minutos = minutos + 800;
							plancontratado = 4;
							break;
						case 5: //Caso plan 5
							estado = 1;
							mb = mb + 25;
							minutos = minutos + 1000;
							plancontratado = 5;
							break;

						default:
							cout << "\n Comando invalido. Por favor ingrese una opcion valida:\n  " << endl;
						}
					}
				}
				else
				{
					//Si es que ya hay un plan contradado
					switch (plancontratado)
					{
					//Imprimir datos plan 1
					case 1:
						cout << " Plan 1 --> $7.990 (200 minutos + 3 GB)" << endl;
						break;
					//Imprimir datos plan 2
					case 2:
						cout << " Plan 2 --> $14.990 (400 minutos + 5 GB)" << endl;
						break;
					//Imprimir datos plan 3
					case 3:
						cout << " Plan 3 --> $19.990 (600 minutos + 7 GB)" << endl;
						break;
					//Imprimir datos plan 4
					case 4:
						cout << " Plan 4 --> $24.990 (800 minutos + 10 GB)" << endl;
						break;
					//Imprimir datos plan 5
					case 5:
						cout << " Plan 5 --> $29.990 (1.000 minutos + 25 GB)" << endl;
					// No deberia ejecutarse
					default:
						cout << " No hay plan vigente." << endl;
					}
				}
				break;
			// Caso consulta
			case 2:
				cout << "Le quedan " << minutos << "y " << mb << " MB" << endl;
				//printf("\n Tiene %d minutos y %d MB.\n", minutos, mb);
				break;
			// Caso de recarga
			case 3:
			{
				int recarga;
				int estado = 0;
				while (estado != 1)
				{
					cout << "¿Que tipo de recarga desea realizar?:" << endl;
					cout << "1. minutos." << endl;
					cout << "2. MB." << endl;
					cin >> recarga;
					switch (recarga)
					{
					//caso regarga de minutos
					case 1:
					{
						int recargaminutos = 0;
						cout << " ¿Cuantos minutos desea recargar?" << endl;
						cin >> recargaminutos;
						minutos = minutos + recargaminutos;
						estado = 1;
					}
					break;
					// Caso recarga de mb
					case 2:
					{
						int recargamb = 0;
						cout << "¿Cuantos MB desea recargar?" << endl;
						cin >> recargamb;
						mb = mb + recargamb;
						estado = 1;
					}
					break;
					default:
						cout << "\n Comando invalido. Por favor ingrese una opcion valida\n  " << endl;
					}
				}
			}
			break;
			// Caso movimiento
			case 4:
			{
				int movimiento;
				int estado = 0;
				while (estado != 1)
				{
					cout << "¿Que tipo de movimiento se desea añadir?:" << endl;
					cout << "1. minutos." << endl;
					cout << "2. MB." << endl;
					cin >> movimiento;
					switch (movimiento)
					{
					// Caso movimiento minutos
					case 1:
					{
						int movminutos = 0;
						cout << " ¿Cuantos minutos se utilizaron en el movimiento?" << endl;
						cin >> movminutos;
						if (minutos - movminutos < 0)
						{
							cout << " Saldo insuficiente. No es posible realizar el movimiento." << endl;
							estado = 1;
						}
						else
						{
							minutos = minutos - movminutos;
							estado = 1;
						}
					}
					break;
					//Caso movimiento mb
					case 2:
					{
						int movmb = 0;
						cout << "¿Cuantos MB se utilizaron en el movimiento?" << endl;
						cin >> movmb;
						if (mb - movmb < 0)
						{
							cout << " Saldo insuficiente. No es posible realizar el movimiento." << endl;
							estado = 1;
						}
						else
						{
							mb = mb - movmb;
							estado = 1;
						}
					}
					break;
					default:
						cout << "\n Comando invalido. Por favor ingrese una opcion valida:\n  " << endl;
					}
				}
			}
			break;
			// Caso salir
			case 5:
				cout << "El programa se cerrara." << endl;
				return false;
				break;
			default:
				cout << "Comando invalido, intente nuevamente" << endl;
			}
		} while (loggedIn);
	}
	return 0;
}
