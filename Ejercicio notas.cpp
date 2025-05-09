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
vector<float> Promedio;   
vector<string> Estu;    // Lista de estudiantes

// Declarar funciones
void tabla(int e, int n)
{
	//Declarar variables
	int lin = 0, col=15;
		
	//Filas
	for(int i=0; i<3+e; i++)
	{
		for(int u=1; u<=(9*n)+26; u++)
		{
			gotoxy(u, lin);
			cout<<"-";
		}//Fin for
		lin += 2;
	}
	//Columnas
	for(int j=0; j<n; j++)
	{
		gotoxy(col+2, 3);
		cout << "Nota " << j+1;
		for(int i=2; i<(5+(2*e)); i++)
		{
			gotoxy(col, i);
			cout<<"|";		
		}
		col+=9;
	}
	
	gotoxy(2, 3);
    cout << "ESTUDIANTE";
    gotoxy(col+2, 3);
    cout << "Promedio";
	for(int i=0; i<(5+(2*e)); i++)
	{
		gotoxy(0, i);
		cout<<"|"; 
		if(i>=2)
		{
			gotoxy(col, i);
			cout<<"|";
		}
		gotoxy(col+11, i);
		cout<<"|";
	}
	
	col= 15;
	lin = 0;
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
    Promedio.resize(N);
    
    // Capturar nombres de los estudiantes
    for (int i = 0; i < E; ++i) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i];
    }

    cout << "\nDatos inicializados correctamente.\n";
}

void capturaNotas() 
{
	int cod, suma=0;
    float nota;

    cout << "Listado de estudiantes\n";
    for (int i = 0; i < E; i++) {
        cout << (i + 1) << " - " << estudiantes[i] << endl;
    }

    // Seleccionar estudiante
    cout << "Ingrese el codigo del estudiante (1-" << E << "): ";
    cin >> cod;

    if (cod < 1 || cod > E) {
        cout << "Codigo de estudiante invalido.\n";
    	return;
    }
	
	system("cls");
	
	gotoxy(12+(3*N),1);
    cout << "Capturando notas";
	
	tabla(1, N);
    
    int F=17;
    
    gotoxy(2,5);
    cout<<estudiantes[cod - 1];
    
	// Capturar las notas del estudiante
	for (int i = 0; i < N; i++) 
	{
        gotoxy(F,5);
        cin >> nota;

        // Validar nota
        while (cin.fail() || nota < 0 || nota > 10) 
		{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            gotoxy(1 ,8);
			cout << "Por favor, ingrese una nota válida (0.0-10.0): ";
            gotoxy(F,5);
			cin >> nota;
        }
        notas[cod - 1][i] = nota;
        suma += nota;
        
        F+=9;
    }
	Promedio[cod - 1] = suma / N;
	gotoxy(F, 5);
	cout << Promedio[cod - 1];
	
	gotoxy(1 ,8);
    cout << "Notas capturadas exitosamente.";	
}// Captura de notas

void reporteNotas() 
{
	int col=15, columna=5;
	gotoxy(12+(3*N),1);
    cout << "REPORTE DE NOTAS";
    for (int i = 0; i < E; i++) 
	{
        float suma = 0;
        gotoxy(2, columna);
		cout << estudiantes[i];

        for (int j = 0; j < N; j++) {
            gotoxy(col+2, columna);
			cout << notas[i][j];
            col+=9;	
        }
		gotoxy(col+2, columna);
        cout << Promedio[i];
        columna+=2;
        col=15;
    }
    gotoxy(1 ,columna+1);
}//Reporte de notas

void ReportarUno(int estu)
{
	int col=15, columna=5;
	float suma = 0;
    gotoxy(2, columna);
	cout << estudiantes[estu];

    for (int j = 0; j < N; j++) 
	{
        gotoxy(col+2, columna);
		cout << notas[estu][j];
        col+=9;
        suma += notas[estu][j];
    }
	Promedio[estu] = suma / N;
	gotoxy(col+2, columna);
    cout << Promedio[estu];
}

void reporteMayorNota() {
    float mayorNota = -1; // Inicia con un valor muy bajo
    string estudianteMayor;
    int F=17;

    for (int i = 0; i < E; i++) {
        if (Promedio[i] > mayorNota) {
            mayorNota = Promedio[i];
            estudianteMayor = estudiantes[i];
        }
    }
	tabla(1, 0);
	gotoxy(2,1);
    cout << "Mayor Promedio:";
    gotoxy(2,5);
    cout << estudianteMayor;
    gotoxy(F,5);
    cout << mayorNota;
 
	gotoxy(1 ,8);

}

void reporteMenorNota() {
    float menorNota = 101; // Inicia con un valor muy alto
    string estudianteMenor;
    int F=17;

    for (int i = 0; i < E; i++) {
        if (Promedio[i] < menorNota) {
            menorNota = Promedio[i];
            estudianteMenor = estudiantes[i];
        }
    }
	tabla(1, 0);
	gotoxy(2,1);
    cout << "Menor Promedio:";
    gotoxy(2,5);
    cout << estudianteMenor;
    gotoxy(F,5);
    cout << menorNota;
    
    gotoxy(1 ,8);
}

void editarNotas() {
    int cod, reg;
    float nuevaNota;
    string conf;
    int F=17;

    cout << "Listado de estudiantes\n";
    for (int i = 0; i < E; i++) {
        cout << (i + 1) << " - " << estudiantes[i] << endl;
    }

    // Selección del estudiante
    cout << "Ingrese el codigo del estudiante a editar: ";
    cin >> cod;

    if (cod < 1 || cod > E) {
        cout << "Codigo de estudiante invalido.\n";
        return;
    }
    
    system("cls");
    
	tabla(1, N);
	gotoxy(12+(3*N),1);
    cout << "Editar notas";
	gotoxy(2,5);
    cout << estudiantes[cod - 1];

    // Mostrar las notas actuales del estudiante
    ReportarUno(cod - 1);

    // Selección de la nota a editar
    gotoxy(2,8);
    cout << "Ingrese el numero de la nota que desea editar (1-" << N << "): ";
    cin >> reg;

    if (reg < 1 || reg > N) {
        cout << "Numero de nota inválido.\n";
        return;
    }

    // Confirmación y edición
    gotoxy(2,10);
    cout << "Ingrese la nueva nota para Nota " << reg << ": ";
    cin >> nuevaNota;

    if (nuevaNota < 0 || nuevaNota > 100) {
        cout << "Nota invalida. Debe estar entre 0 y 10\n";
        return;
    }
    notas[cod - 1][reg - 1] = nuevaNota;
    
    system("cls");
    
    tabla(1, N);
    ReportarUno(cod - 1);
    
    gotoxy(1 ,8);
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
    cout << "Ingrese el codigo del estudiante para eliminar notas: ";
    cin >> cod;

    if (cod < 1 || cod > E) {
        cout << "Codigo de estudiante invalido.\n";
        return;
    }
	
	system("cls");
	
	tabla(1, N);
	gotoxy(12+(3*N),1);
	cout << "Eliminar  notas";
	gotoxy(2,5);
	ReportarUno(cod - 1);
	
    // Confirmación de eliminación
    gotoxy(2,8);
    cout << "Desea eliminar TODAS las notas de este estudiante? Inserte [S] para confirmar, o cualquier otra tecla para eliminar una nota especifica: \n";
    cin >> conf;

    if (conf == "S" || conf == "s") {
        // Eliminar todas las notas del estudiante
        for (int i = 0; i < N; i++) {
            notas[cod - 1][i] = 0;
        }
        cout << "Todas las notas del estudiante han sido eliminadas.\n";
    } else {
        // Mostrar las notas actuales del estudiante
        ReportarUno(cod - 1);

        // Selección de la nota a eliminar
        gotoxy(2,8);
        cout << "Ingrese el numero de la nota que desea eliminar (1-" << N << "): ";
        cin >> reg;

        if (reg < 1 || reg > N) {
            cout << "Numero de nota invalido.\n";
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
        cout << "3. Reporte Estudiante con mayor Promedio" << endl;
        cout << "4. Reporte Estudiante con menor Promedio" << endl;
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
              	tabla(E, N);
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


