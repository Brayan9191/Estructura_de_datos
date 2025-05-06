#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//Codigo gotoxy
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 

// Variables globales
const int v = 4, d = 3;
int notas[v][d] = {0}; // Inicializo notas en 0
string estudiantes[] = {"Jose  ", "Maria ", "Ana   ", "Pepe  "};

// Declarar funciones
void capturaNotas() {
    for (int i = 0; i < v; i++) {
        cout << "\nCapturando notas para: " << estudiantes[i] << endl;
        for (int j = 0; j < d; j++) {
            cout << "  Ingrese nota " << j + 1 << ": ";
            cin >> notas[i][j];
        }
    }
    cout << "\nNotas capturadas exitosamente!\n";
}

void reporteNotas() {
    cout << "REPORTE DE NOTAS\n";
    cout << "------------------------------\n";
    cout << "Estudiante\tNota1\tNota2\tNota3\tPromedio\n";
    cout << "------------------------------\n";
    for (int i = 0; i < v; i++) {
        int suma = 0;
        cout << estudiantes[i] << "\t";
        for (int j = 0; j < d; j++) {
            cout << notas[i][j] << "\t";
            suma += notas[i][j];
        }
        float promedio = suma / (float)d;
        cout << promedio << endl;
    }
}

int main()
{			
    int opc;
    do
    {	
        system("cls");
        //Opciones del menu
        cout << "1. Captura notas" << endl;
        cout << "2. Reporte notas" << endl;
        cout << "3. Reporte Estudiante con mayor nota" << endl;
        cout << "4. Reporte Estudiante con menor nota" << endl;
        cout << "5. Modificar notas" << endl;
        cout << "6. Eliminar notas" << endl;
        cout << "7. Salir" << endl;
        cout << "\nSelecciona  una opcion del menu: ";
        cin >> opc;
		
        switch(opc)
        {
            case 1: 
                system("cls");
                capturaNotas();
                system("pause");
                break;
			
            case 2: 
                system("cls");
                reporteNotas();
                system("pause");
                break;	
				
            case 3: 
                system("cls");
                // Pendiente implementar
                system("pause");
                break;
				
            case 4: 
                system("cls");
                // Pendiente implementar
                system("pause");
                break;
				
            case 5: 
                system("cls");
                // Pendiente implementar
                system("pause");
                break;
				
            case 6: 
                system("cls");
                // Pendiente implementar
                system("pause");
                break;
			
            case 7: 
                system("cls");
                cout << "Saliendo del programa...\n";
                system("pause");
                break;	
				
            default: 
                system("cls"); 
                cout << "Opcion invalida" << endl;
                system("pause");
                break;
        }
    } while (opc != 7);
		
    getch();
    return 0;
}

