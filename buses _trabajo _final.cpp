#include <iostream>
#include <cstring>
#include <conio.h>
#include <windows.h>

// Definir colores ANSI
#define ROJO "\033[31m"
#define VERDE "\033[32m"
#define AZUL "\033[34m"
#define AMARILLO "\033[33m"
#define RESET "\033[0m"

using namespace std;

// Estructura para buses
struct Bus {
    int id;
    char ruta[50];
    char horario[20];
    float precio;
};

// Estructura para pasajeros
struct Pasajero {
	int id;
    char nombre[50];
    int busID;
};

// Función para verificar si un busID existe en la lista de buses
bool validarBusID(Bus buses[], int totalBuses, int busID) {
    for (int i = 0; i < totalBuses; i++) {
        if (buses[i].id == busID) {
            return true; // El bus existe
        }
    }
    return false; // El bus no esta en la lista
}

void agregarPasajero(Pasajero pasajeros[], int &total, Bus buses[], int totalBuses) {
    int idbus;
    cin.ignore();
	cout << AMARILLO << "Ingrese ID del pasajero: " << RESET;
    cin >> pasajeros[total].id;

    fflush(stdin);
    cout << AMARILLO << " Ingrese nombre del pasajero: " << RESET;
    cin.getline(pasajeros[total].nombre, 50);

    cout << AMARILLO << " Ingrese ID del bus asignado: " << RESET;
    cin >> idbus;

    while (!validarBusID(buses, totalBuses, idbus)) {
        cout << ROJO << " ID de bus no valido. Intente nuevamente: " << RESET;
        cin >> idbus;
    }
    
    pasajeros[total].busID = idbus;
    cout << VERDE << " Pasajero agregado correctamente.\n" << RESET;
    
    total++;
}

//Codigo gotoxy
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 
// Funciones para decorar menu
void final(int ancho, int x, int y) {
    // Cambia color
    cout << AMARILLO;
    // Dibuja esquinas
    gotoxy(x, y);
    cout << "+";
    gotoxy(x + ancho, y);
    cout << "+";
    // Hace linea horizontal
    for (int i = 1; i < ancho; i++) {
        gotoxy(x + i, y);
        cout << "-";
    }
    RESET;
}

void renglon(int ancho, int x, int y) {
    cout << AMARILLO;
    // Dibuja lados
    gotoxy(x, y + 1);
    cout << "|";
    gotoxy(x + ancho, y + 1);
    cout << "|";
    // Dibuja borde superior
    final(ancho, x, y);
    // Alista para escribir adentro del cuadrito
    gotoxy(x + 2, y + 1);
}

// Funciones para buses
void listarBuses(Bus buses[], int total) {
cout << AZUL << "\n===== LISTADO DE BUSES =====\n" << RESET;
    for (int i = 0; i < total; i++) 
	{
        renglon(65,5,3+i*2);
		cout << AMARILLO << "Bus ID: " << RESET << buses[i].id << AMARILLO
             << " | Ruta: " << RESET << buses[i].ruta << "\t" << AMARILLO
             << " | Horario: " << RESET << buses[i].horario <<AMARILLO
             << " | Precio: " << VERDE << "$" << RESET << buses[i].precio << endl;
	}
	final(65,5,3+total*2);
	
	gotoxy(1, 15);
}

void listarPasajeros(Pasajero pasajeros[], int total) {
    if (total == 0) {
        cout << ROJO << "\nNo hay pasajeros registrados.\n" << RESET;
        return;
    }  
    
    for (int i = 0; i < total; i++) {
        renglon(50,5,3+i*2);
		cout << AMARILLO << "ID pasajero: " << RESET << pasajeros[i].id << "\t" << AMARILLO << " | Nombre: " << RESET << pasajeros[i].nombre << AMARILLO << "\t" << " | ID bus: " << pasajeros[i].busID << RESET << endl;
	}	
	final(50,5,3+total*2); cout << "\n\n";
}

void eliminarPasajero(Pasajero pasajeros[], int &total, int idEliminar) {
    for (int i = 0; i < total; i++) 
	{
        if (pasajeros[i].id == idEliminar) {
            for (int j = i; j < total - 1; j++) {
                pasajeros[j] = pasajeros[j + 1]; // Mueve elementos
			}
            total--;
            cout << "Pasajero eliminado correctamente.\n";
            return;
		}
	}
    cout << "Pasajero no encontrado.\n";
}

void editarPasajero(Pasajero pasajeros[], int total, int idEditar) 
{
    for (int i = 0; i < total; i++) {
        if (pasajeros[i].id == idEditar) {
            cout << AMARILLO << "Ingrese nuevo nombre: " << RESET;
            cin.ignore();
            cin.getline(pasajeros[i].nombre, 50);
            cout << AMARILLO<< "Ingrese nuevo ID de bus: " << RESET;
            cin>> pasajeros[i].busID;
            cout << VERDE<< "Datos actualizados correctamente.\n" << RESET;
            return;
		}
	}
    cout << ROJO << "Pasajero no encontrado.\n" << RESET;
}

void listarPasajerosPorBus(Pasajero pasajeros[], int total, int busID) 
{  
	cout << "\nPasajeros en el bus ID " << busID << ":\n";
    for (int i = 0; i < total; i++) {
        //renglon(65,5,3+i*2);
		if (pasajeros[i].busID == busID) {
            cout << AMARILLO << "ID: " << RESET << pasajeros[i].id << AMARILLO << " | Nombre: " << RESET << pasajeros[i].nombre << endl;
		}
		//final(65,5,3+total*2);
	}	
}

void ordenarPorNombre(Pasajero pasajeros[], int total) 
{
    for (int i = 0; i < total - 1; i++) 
	{
        for (int j = 0; j < total - i - 1; j++) 
		{
            if (strcmp(pasajeros[j].nombre, pasajeros[j + 1].nombre)> 0) 
			{
                Pasajero temp = pasajeros[j];
                pasajeros[j] = pasajeros[j + 1];
                pasajeros[j + 1] = temp;
			}
		}
	}
    cout << VERDE << "\nPasajeros ordenados por nombre correctamente.\n";
}

void ordenarPorBusID(Pasajero pasajeros[], int total) 
{
    for (int i = 0; i < total - 1; i++) 
	{
        for (int j = 0; j < total - i - 1; j++) 
		{
            if (pasajeros[j].busID> pasajeros[j + 1].busID) 
			{
                Pasajero temp = pasajeros[j];
                pasajeros[j] = pasajeros[j + 1];
                pasajeros[j + 1] = temp;
			}
		}
	}
    cout << VERDE << "\nPasajeros ordenados por Bus ID correctamente.\n";
}

// Función principal con menú interactivo
int main() {
    Bus listaBuses[5] = 
	{
        {1, "Centro", "08:00 AM", 3200},
        {2, "Norte", "09:30 AM", 3200},
        {3, "Sur", "10:15 AM", 3200},
        {4, "Este", "07:00 AM", 3200},
        {5, "Oeste", "06:45 PM", 3200}
	};
	
    int totalBuses = 5;
	string np;
    Pasajero listaPasajeros[20];
    int totalPasajeros = 0;
    int opcion;

	system("cls");
    do {
		system("cls");
		cout << AMARILLO << "\n===== MENU DE GESTION =====\n";
        cout << VERDE << "1. Lista de Buses\n";
        cout << "2. Agregar Pasajero\n";
        cout << "3. Lista de pasajeros\n";
        cout << "4. Eliminar Pasajero\n";
        cout << "5. Editar Pasajero\n";
        cout << "6. Listar Pasajeros por Bus\n";
        cout << "7. Ordenar Pasajeros por Nombre\n";
        cout << "8. Ordenar Pasajeros por Bus ID\n" << RESET;
        cout << ROJO << "9. Salir\n" << RESET;
        cout << AMARILLO << "Seleccione una opcion: " << RESET;
        cin>> opcion;

        switch (opcion) {
            case 1:
            	system("cls");
                listarBuses(listaBuses, totalBuses);
                system("pause");
                break;
            case 2:
            	system("cls");
                do{
                	if(totalPasajeros < 20)
                	{
                		system("cls");
						listarBuses(listaBuses, totalBuses);
						agregarPasajero(listaPasajeros, totalPasajeros, listaBuses, totalBuses);
					}else
					{
						cout << ROJO <<"no hay mas cupo."<<endl << RESET;
						break;
					} // Fin else
					cout << AMARILLO<<"Quiere ingresar otro pasajero? [S] [N]" << RESET<<endl;
					cin>> np;
				}	while(np == "s" || np == "S");
				
                system("pause");
                break;
            case 3:
            	system("cls");
			    listarPasajeros(listaPasajeros, totalPasajeros);
			    system("pause");
			    break;
            case 4:
            	system("cls");
                int idEliminar;
                listarPasajeros(listaPasajeros, totalPasajeros);
                cin.ignore();
                cout << "Ingrese ID del pasajero a eliminar: " << RESET;
                cin>> idEliminar;
                eliminarPasajero(listaPasajeros, totalPasajeros, idEliminar);
                system("pause");
                break;
            case 5:
            	system("cls");
            	int idEditar;
                cout << VERDE << "Ingrese ID del pasajero a editar: " << RESET;
                cin>> idEditar;
                editarPasajero(listaPasajeros, totalPasajeros, idEditar);
                system("pause");
                break;
            case 6:
            	system("cls");
                int busID;
                cout << VERDE << "Ingrese ID del bus para listar pasajeros: " << RESET;
                cin>> busID;
                listarPasajerosPorBus(listaPasajeros, totalPasajeros, busID);
                system("pause");
                break;
            case 7:
            	system("cls");
                ordenarPorNombre(listaPasajeros, totalPasajeros);
                system("pause");
                break;
            case 8:
            	system("cls");
                ordenarPorBusID(listaPasajeros, totalPasajeros);
                system("pause");
                break;
            case 9:
            	system("cls");
                cout << AMARILLO << "Saliendo del programa...\n" << RESET;
                system("pause");
                break;
            default:
            	system("cls");
                cout << ROJO << "Opcion invalida, intente nuevamente.\n" << RESET;
                system("pause");
        }
    } while (opcion!= 9);

    return 0;
}
