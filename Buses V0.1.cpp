#include<iostream>
#include<conio.h>
#include<Windows.h>
#include <cstring> // Para manejar cadenas de texto

using namespace std;

//Codigo gotoxy
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} //	Fin Gotoxy

struct Bus
{
	int id;
    char ruta[50];
    char horario[20];
};	//	Fin Bus

struct Pasajero
{
	int id;
    char nombre[50];
    int busID;
};	//	Fin Pasajeros

// Función para buscar buses según la ruta ingresada
void buscarRuta(Bus buses[], int total, char rutaBus[]) {
    cout << "Buses disponibles en la ruta " << rutaBus << ":\n";
    for (int i = 0; i < total; i++) {
        if (strcmp(buses[i].ruta, rutaBus) == 0) {
            cout << "Bus ID: " << buses[i].id << " | Horario: " << buses[i].horario << endl;
}}}

// Función para registrar pasajeros en un bus específico
void registrarPasajero(Pasajero pasajeros[], int &total, int busID) {
    cout << "Ingrese ID del pasajero: ";
    cin>> pasajeros[total].id;
    cout << "Ingrese nombre del pasajero: ";
    cin>> pasajeros[total].nombre;
    pasajeros[total].busID = busID;
    total++;
    cout << "Pasajero registrado en el bus " << busID << " correctamente.\n";
}

// Función principal con ejemplos de uso
int main() {
    // Definir lista de buses
    Bus listaBuses[9] = {
        {1, "Centro", "08:00 PM"},
        {2, "Norte", "09:30 AM"},
        {3, "Centro", "10:15 PM"},
        {4, "Centro", "07:00 AM"},
        {5, "Norte", "11:30 AM"},
        {6, "Centro", "10:00 PM"},
        {7, "Este", "08:00 AM"},
        {8, "Sur", "09:45 PM"},
        {9, "Oeste", "10:15 AM"}
	};

    // Buscar una ruta específica
    char rutaBus[50];
    cout << "Ingrese la ruta que desea consultar: ";
    cin>> rutaBus;
    buscarRuta(listaBuses, 9, rutaBus);

    // Registrar pasajeros
    Pasajero listaPasajeros[10];
    int totalPasajeros = 0;

    int busID;
    cout << "Ingrese el ID del bus en el que desea registrar un pasajero: ";
    cin>> busID;
    registrarPasajero(listaPasajeros, totalPasajeros, busID);

    getch();
	return 0;
}



