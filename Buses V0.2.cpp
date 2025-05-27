// Estructura para almacenar buses
struct Bus {
    int id;
    char ruta[50];
    char horario[20];
    float precio;
};

// Estructura para almacenar pasajeros
struct Pasajero {
    int id;
    char nombre[50];
    int busID;
};

// Función para agregar un pasajero
void agregarPasajero(Pasajero pasajeros[], int &total) 
{
    cout << "\nIngrese ID del pasajero: ";
    cin>> pasajeros[total].id;

    cin.ignore();
    cout << "Ingrese nombre del pasajero: ";
    cin.getline(pasajeros[total].nombre, 50);

    cout << "Ingrese ID del bus asignado: ";
    cin>> pasajeros[total].busID;

    total++;
    cout << "Pasajero agregado correctamente.\n";
}

// Función para eliminar un pasajero por ID
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

// Función para editar un pasajero por ID
void editarPasajero(Pasajero pasajeros[], int total, int idEditar) 
{
    for (int i = 0; i < total; i++) {
        if (pasajeros[i].id == idEditar) {
            cout << "Ingrese nuevo nombre: ";
            cin.ignore();
            cin.getline(pasajeros[i].nombre, 50);
            cout << "Ingrese nuevo ID de bus: ";
            cin>> pasajeros[i].busID;
            cout << "Datos actualizados correctamente.\n";
            return;
		}
	}
    cout << "Pasajero no encontrado.\n";
}

// Función para listar pasajeros de un bus específico
void listarPasajerosPorBus(Pasajero pasajeros[], int total, int busID) 
{
    cout << "\nPasajeros en el bus ID " << busID << ":\n";
    for (int i = 0; i < total; i++) {
        if (pasajeros[i].busID == busID) {
            cout << "ID: " << pasajeros[i].id << " | Nombre: " << pasajeros[i].nombre << endl;
		}
	}
}


// Función principal
int main() {
    Pasajero listaPasajeros[20];  // Arreglo de pasajeros
    int totalPasajeros = 0;

    // Pruebas de funciones
    agregarPasajero(listaPasajeros, totalPasajeros);
    agregarPasajero(listaPasajeros, totalPasajeros);

    listarPasajerosPorBus(listaPasajeros, totalPasajeros, 1);  // Listar pasajeros del bus 1

    editarPasajero(listaPasajeros, totalPasajeros, listaPasajeros[0].id);  // Editar primer pasajero

    eliminarPasajero(listaPasajeros, totalPasajeros, listaPasajeros[0].id);  // Eliminar primer pasajero

    getch(); // Pausa antes de cerrar
    return 0;
}
