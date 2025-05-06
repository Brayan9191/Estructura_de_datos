#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <limits>

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
int POS=0, E, N;
vector<vector<float> > notas;   // Matriz para almacenar las notas
vector<string> estudiantes;    // Lista de estudiantes
vector<vector<float> > Notas;   
vector<string> Estu;    // Lista de estudiantes
vector<vector<float> > promedio;



// Declarar funciones
void tabla(int pos)
{
	//Declarar variables
	int lin = 0, clin = 1;
	
	//Cabeza de tabla default	
	//Filas
	for(int i=0; i<1; i++)
	{
		for(int u=1; u<=125; u++)
		{
			gotoxy(u, lin);
			cout<<"-";
		}//Fin for
		lin += 2;
	}
	
	clin *= pos;
	//Tabla segun Registro
	//Filas
	for(int i=0; i<=(clin); i++)
	{
		for(int u=1; u<=55; u++)
		{
			gotoxy(u, lin);
			cout<<"-";
		}//Fin for
		lin += 2;
	}//Fin if
	//Columnas
	for(int i=2; i<(5+(2*pos)); i++)
	{
		gotoxy(0, i);
		cout<<"|";
		gotoxy(15, i);
		cout<<"|";
		gotoxy(25, i);
		cout<<"|";
		gotoxy(35, i);
		cout<<"|";
		gotoxy(45, i);
		cout<<"|";
		gotoxy(55, i);
		cout<<"|";		
	}
	
	lin = 0;
	clin = 3;
	
	gotoxy(2, 3);
    cout << "ESTUDIANTE";
    gotoxy(17, 3);
	cout << "Nota 1";
    gotoxy(27, 3);
    cout << "Nota 2";
    gotoxy(37, 1);
    cout << "Nota 3";
	gotoxy(47, 3);
    cout << "Promedio";
}//Fin funcion tabla

int CantEyN()
{
	cout << "Ingrese la cantidad de estudiantes: ";
    cin >> E;

    // Validar entrada
    while (cin.fail() || E <= 0) {
        cin.clear(); // Limpia el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora entradas inválidas
        cout << "Por favor, ingrese un número válido de estudiantes: ";
        cin >> E;
    }

    cout << "Ingrese la cantidad de notas por estudiante: ";
    cin >> N;

    // Validar entrada
    while (cin.fail() || N <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Por favor, ingrese un número válido de notas: ";
        cin >> N;
    }

    // Redimensionar estructuras de datos
    notas.resize(E, vector<float>(N, 0)); // Inicializar la matriz de notas en 0
    estudiantes.resize(E, "");           // Inicializar los nombres de los estudiantes
    
    // Capturar nombres de los estudiantes
    for (int i = 0; i < E; ++i) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i];
    }

    cout << "\nDatos inicializados correctamente.\n";
}

void capturaNotas() 
{
	int cod;
    float nota;

    cout << "Listado de estudiantes\n";
    for (int i = 0; i < E; i++) {
        cout << (i + 1) << " - " << estudiantes[i] << endl;
    }

    // Seleccionar estudiante
    cout << "Ingrese el código del estudiante (1-" << E << "): ";
    cin >> cod;

    if (cod < 1 || cod > E) {
        cout << "Código de estudiante inválido.\n";
        return;
    }

    cout << "Capturando notas para " << estudiantes[cod - 1] << ":\n";
	
	tabla(1);
    
    int F=27;
    
	// Capturar las notas del estudiante
    for (int i = 0; i < N; i++) {
        gotoxy(F,5);
        cin >> nota;
        F+=10;

        // Validar nota
        while (cin.fail() || nota < 0 || nota > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Por favor, ingrese una nota válida (0-5): ";
            cin >> nota;
        }

        notas[cod - 1][i] = nota;
    }

    cout << "Notas capturadas exitosamente.\n";	
}// Captura de notas

void reporteNotas() {
    cout << "REPORTE DE NOTAS\n";
    cout << "Estudiante\t";

    for (int i = 1; i <= N; i++) {
        cout << "Nota" << i << "\t";
    }

    cout << "Promedio\n";

    for (int i = 0; i < E; i++) {
        float suma = 0;
        cout << estudiantes[i] << "\t";

        for (int j = 0; j < N; j++) {
            cout << notas[i][j] << "\t";
            suma += notas[i][j];
        }

        cout << suma / N << endl;
    }
}//Reporte de notas

void reporteMayorNota() {
    float mayorNota = -1; // Inicia con un valor muy bajo
    string estudianteMayor;

    for (int i = 0; i < E; i++) {
        for (int j = 0; j < N; j++) {
            if (notas[i][j] > mayorNota) {
                mayorNota = notas[i][j];
                estudianteMayor = estudiantes[i];
            }
        }
    }

    cout << "Estudiante con la mayor nota:\n";
    cout << "------------------------------\n";
    cout << "Estudiante: " << estudianteMayor << endl;
    cout << "Nota: " << mayorNota << endl;
}

void reporteMenorNota() {
    float menorNota = 101; // Inicia con un valor muy alto
    string estudianteMenor;

    for (int i = 0; i < E; i++) {
        for (int j = 0; j < N; j++) {
            if (notas[i][j] < menorNota) {
                menorNota = notas[i][j];
                estudianteMenor = estudiantes[i];
            }
        }
    }

    cout << "Estudiante con la menor nota:\n";
    cout << "------------------------------\n";
    cout << "Estudiante: " << estudianteMenor << endl;
    cout << "Nota: " << menorNota << endl;
}

void editarNotas() {
    int cod, reg;
    float nuevaNota;
    string conf;

    cout << "Listado de estudiantes\n";
    for (int i = 0; i < E; i++) {
        cout << (i + 1) << " - " << estudiantes[i] << endl;
    }

    // Selección del estudiante
    cout << "Ingrese el código del estudiante a editar: ";
    cin >> cod;

    if (cod < 1 || cod > E) {
        cout << "Código de estudiante inválido.\n";
        return;
    }

    cout << "Seleccionó a " << estudiantes[cod - 1] << endl;

    // Mostrar las notas actuales del estudiante
    cout << "Notas actuales:\n";
    for (int i = 0; i < N; i++) {
        cout << "Nota " << (i + 1) << ": " << notas[cod - 1][i] << endl;
    }

    // Selección de la nota a editar
    cout << "Ingrese el número de la nota que desea editar (1-" << N << "): ";
    cin >> reg;

    if (reg < 1 || reg > N) {
        cout << "Número de nota inválido.\n";
        return;
    }

    // Confirmación y edición
    cout << "Ingrese la nueva nota para Nota " << reg << ": ";
    cin >> nuevaNota;

    if (nuevaNota < 0 || nuevaNota > 100) {
        cout << "Nota inválida. Debe estar entre 0 y 100.\n";
        return;
    }

    notas[cod - 1][reg - 1] = nuevaNota;
    cout << "Nota actualizada exitosamente.\n";
}

void eliminarNotas() {
    int cod, reg;
    string conf;

    cout << "Listado de estudiantes\n";
    for (int i = 0; i < E; i++) {
        cout << (i + 1) << " - " << estudiantes[i] << endl;
    }

    // Selección del estudiante
    cout << "Ingrese el código del estudiante para eliminar notas: ";
    cin >> cod;

    if (cod < 1 || cod > E) {
        cout << "Código de estudiante inválido.\n";
        return;
    }

    cout << "Seleccionó a " << estudiantes[cod - 1] << endl;

    // Confirmación de eliminación
    cout << "¿Desea eliminar TODAS las notas de este estudiante? Inserte [S] para confirmar, o cualquier otra tecla para eliminar una nota específica: ";
    cin >> conf;

    if (conf == "S" || conf == "s") {
        // Eliminar todas las notas del estudiante
        for (int i = 0; i < N; i++) {
            notas[cod - 1][i] = 0;
        }
        cout << "Todas las notas del estudiante han sido eliminadas.\n";
    } else {
        // Mostrar las notas actuales del estudiante
        cout << "Notas actuales:\n";
        for (int i = 0; i < N; i++) {
            cout << "Nota " << (i + 1) << ": " << notas[cod - 1][i] << endl;
        }

        // Selección de la nota a eliminar
        cout << "Ingrese el número de la nota que desea eliminar (1-" << N << "): ";
        cin >> reg;

        if (reg < 1 || reg > N) {
            cout << "Número de nota inválido.\n";
            return;
        }

        // Eliminar la nota seleccionada
        notas[cod - 1][reg - 1] = 0;
        cout << "La nota " << reg << " ha sido eliminada.\n";
    }
}

int main()
{			
    int opc;
    
    CantEyN();
	
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
              	tabla(E);
                system("pause");
				reporteNotas();
                
                system("pause");
                break;	
				
            case 3: 
                system("cls");
        	    reporteMayorNota();
        	    
                system("pause");
                break;
				
            case 4: 
                system("cls");
                reporteMenorNota();
                
                system("pause");
                break;
				
            case 5: 
                system("cls");
 			    editarNotas();
 			   
                system("pause");
                break;
				
            case 6: 
                system("cls");
  				eliminarNotas();
  				
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


