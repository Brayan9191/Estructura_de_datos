#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

// Definir colores ANSI
#define ROJO "\033[31m"
#define VERDE "\033[32m"
#define AZUL "\033[34m"
#define AMARILLO "\033[33m"
#define RESET "\033[0m"

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

// Mapa de asientos (2 filas, 5 columnas)
char mapaBus[2][5] = {
    {'O', 'O', 'O', 'O', 'O'},
    {'O', 'O', 'O', 'O', 'O'}
};

// Funciones para buses
void listarBuses(Bus buses[], int total);
void mostrarMapaBus(char bus[2][5]);

// Funciones para pasajeros
void agregarPasajero(Pasajero pasajeros[], int &total);
void eliminarPasajero(Pasajero pasajeros[], int &total, int idEliminar);
void editarPasajero(Pasajero pasajeros[], int total, int idEditar);
void listarPasajerosPorBus(Pasajero pasajeros[], int total, int busID);
void ordenarPorNombre(Pasajero pasajeros[], int total);
void ordenarPorBusID(Pasajero pasajeros[], int total);

// Función principal con menú interactivo
int main() {
    Bus listaBuses[5] = {
        {1, "Centro", "08:00 AM", 2.50},
        {2, "Norte", "09:30 AM", 3.00},
        {3, "Sur", "10:15 AM", 2.75},
        {4, "Este", "07:00 AM", 3.20},
        {5, "Oeste", "06:45 PM", 2.80}
};
    int totalBuses = 5;

    Pasajero listaPasajeros[20];
    int totalPasajeros = 0;
    int opcion;

    do {
        cout << AZUL << "\n===== MENU DE GESTION =====\n" << RESET;
        cout << AMARILLO << "1. Listar Buses\n";
        cout << "2. Agregar Pasajero\n";
        cout << "3. Mostrar Mapa del Bus\n";
        cout << "4. Eliminar Pasajero\n";
        cout << "5. Editar Pasajero\n";
        cout << "6. Listar Pasajeros por Bus\n";
        cout << "7. Ordenar Pasajeros por Nombre\n";
        cout << "8. Ordenar Pasajeros por Bus ID\n";
        cout << "9. Salir\n" << RESET;
        cout << AZUL << "Seleccione una opción: " << RESET;
        cin>> opcion;

        switch (opcion) {
            case 1:
                listarBuses(listaBuses, totalBuses);
                break;
            case 2:
                agregarPasajero(listaPasajeros, totalPasajeros);
                break;
            case 3:
                mostrarMapaBus(mapaBus);
                break;
            case 4:
                int idEliminar;
                cout << ROJO << "Ingrese ID del pasajero a eliminar: " << RESET;
                cin>> idEliminar;
                eliminarPasajero(listaPasajeros, totalPasajeros, idEliminar);
                break;
            case 5:
                int idEditar;
                cout << AMARILLO << "Ingrese ID del pasajero a editar: " << RESET;
                cin>> idEditar;
                editarPasajero(listaPasajeros, totalPasajeros, idEditar);
                break;
            case 6:
                int busID;
                cout << VERDE << "Ingrese ID del bus para listar pasajeros: " << RESET;
                cin>> busID;
                listarPasajerosPorBus(listaPasajeros, totalPasajeros, busID);
                break;
            case 7:
                ordenarPorNombre(listaPasajeros, totalPasajeros);
                break;
            case 8:
                ordenarPorBusID(listaPasajeros, totalPasajeros);
                break;
            case 9:
                cout << ROJO << "Saliendo del programa...\n" << RESET;
                break;
            default:
			cout << ROJO << "Opción inválida, intente nuevamente.\n" << RESET;
}
} while (opcion!= 9);

    getch();
    return 0;
}

// Implementación de funciones

void listarBuses(Bus buses[], int total) {
    cout << AZUL << "\n===== LISTADO DE BUSES =====\n" << RESET;
    for (int i = 0; i < total; i++) {
        cout << AMARILLO << "Bus ID: " << buses[i].id << RESET
             << " | Ruta: " << VERDE << buses[i].ruta << RESET
             << " | Horario: " << buses[i].horario
             << " | Precio: " << ROJO << "$" << buses[i].precio << RESET << endl;
}
}

void mostrarMapaBus(char bus[2][5]) {
    cout << AZUL << "\n===== MAPA DEL BUS =====\n" << RESET;
    cout << "+---+---+---+---+---+\n";

    for (int i = 0; i < 2; i++) {
        cout << "|";
        for (int j = 0; j < 5; j++) {
            if (bus[i][j] == 'X') {
                cout << ROJO << " X " << RESET << "|";  // ?? Asiento ocupado
} else {
                cout << VERDE << " O " << RESET << "|";  // ?? Asiento libre
}
}
        cout << "\n+---+---+---+---+---+\n";
}
}
