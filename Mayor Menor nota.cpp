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
int E = e, N = n;
float notas[E][N] = {0}; // Inicializo notas en 0
float promedio[E] = {0}; // Inicializo promedio en 0
string Estu[E];	//Para ordenar
string Notas[N];//Para ordenar
int POS=0;
string estudiantes[];

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
		for(int u=1; u<=125; u++)
		{
			gotoxy(u, lin);
			cout<<"-";
		}//Fin for
		lin += 2;
	}//Fin if
	//Columnas
	for(int i=2; i<(5+(2*pos)); i++)
	{
		//Fecha
		gotoxy(0, i);
		cout<<"|";
		//Detalle
		gotoxy(15, i);
		cout<<"|";
		//V. unitario
		gotoxy(25, i);
		cout<<"|";
		//Cantidad 	Entrada
		gotoxy(35, i);
		cout<<"|";
		//Total
		gotoxy(45, i);
		cout<<"|";
		//Cantidad  Salida
		gotoxy(71, i);
		cout<<"|";
		//Total
		gotoxy(83, i);
		cout<<"|";
		//Cantidad  Saldo
		gotoxy(98, i);
		cout<<"|";
		//Total
		gotoxy(110, i);
		cout<<"|";
		//Columna final 
		gotoxy(125, i);
		cout<<"|";		
	}
	
	lin = 0;
	clin = 3;
	
	gotoxy(2, 3);
    cout << "ESTUDIANTE";
    gotoxy(15, 3);

	cout << "Nota 1";
    gotoxy(34, 3);
    cout << "Nota 2";
    //Entrada
    gotoxy(46, 1);
    cout << "Nota 3";
	gotoxy(46, 3);
    cout << "CANTIDAD";
    gotoxy(58, 3);
    cout << "TOTAL";
    //Salidas
    gotoxy(73, 1);
    cout << "SALIDAS";
    gotoxy(73, 3);
    cout << "CANTIDAD";
    gotoxy(85, 3);
    cout << "TOTAL";
}//Fin funcion tabla

cout CantEyN()
{
	cout<<"Ingrese la cantidad de notas: ";
	cin>>n;
	cout<<"Cuantos estudiantes quiere ingresar: "
	cin>>e;
	for(int i=0; i<E; i++)
	{
		cout<<"Ingrese el nombre del estudiante"
		cin>>estudiantes[i];
	}
	
}

void capturaNotas() 
{
/*  for (int i = 0; i < v; i++) 
	{
        cout << "\nCapturando notas para: " << estudiantes[i] << endl;
        for (int j = 0; j < d; j++) 
		{
            cout << "  Ingrese nota " << j + 1 << ": ";
            cin >> notas[i][j];
        }
    }
*/
    int cod, reg=0;
    string conf;
    float nota;
	
	cout<<"Listado de estudiantes\n";
	for(int i=0; i<4; i++)
	{
		cout<<(i+1)<<" - "<<estudiantes[i]<<endl;
	}//Fin estudiantes
	
	//Capturar estudiantes
	cout<<"Ingrese el codigo del estudiantes....: ";
	cin>>cod;
	cout<<"Selecciono a "<<estudiantes[cod-1];
	
	cout<<" Si este es el estudiante inserte [S] si no otra tecla...: ";
	cin>>conf;
	
	while((conf=="S" || conf=="s") && (reg<3))
	{
		cout<<" Ingrese la nota ["<<(reg+1)<<"]....:";
		cin>>nota;
		//	Asignar nota a la matriz notas
		notas[cod-1][reg]=nota;
		reg++;
	}//Fin ciclo
    
    cout << "\nNotas capturadas exitosamente!\n";	
}// Captura de notas

void reporteNotas() {
    int pos = 0;
    
	cout << "REPORTE DE NOTAS\n";
    cout << "Estudiante\tNota1\tNota2\tNota3\tPromedio\n";
    for (int i = 0; i < E; i++) {
        int suma = 0;
        cout << estudiantes[i] << "\t";
        for (int j = 0; j < N; j++) {
            cout << notas[i][j] << "\t";
            suma += notas[i][j];
        }
        promedio[pos] = suma / (float)N;
        cout << promedio[pos] << endl;
        
        pos++;
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

    // Selecci�n del estudiante
    cout << "Ingrese el c�digo del estudiante a editar: ";
    cin >> cod;

    if (cod < 1 || cod > E) {
        cout << "C�digo de estudiante inv�lido.\n";
        return;
    }

    cout << "Seleccion� a " << estudiantes[cod - 1] << endl;

    // Mostrar las notas actuales del estudiante
    cout << "Notas actuales:\n";
    for (int i = 0; i < N; i++) {
        cout << "Nota " << (i + 1) << ": " << notas[cod - 1][i] << endl;
    }

    // Selecci�n de la nota a editar
    cout << "Ingrese el n�mero de la nota que desea editar (1-" << N << "): ";
    cin >> reg;

    if (reg < 1 || reg > N) {
        cout << "N�mero de nota inv�lido.\n";
        return;
    }

    // Confirmaci�n y edici�n
    cout << "Ingrese la nueva nota para Nota " << reg << ": ";
    cin >> nuevaNota;

    if (nuevaNota < 0 || nuevaNota > 100) {
        cout << "Nota inv�lida. Debe estar entre 0 y 100.\n";
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

    // Selecci�n del estudiante
    cout << "Ingrese el c�digo del estudiante para eliminar notas: ";
    cin >> cod;

    if (cod < 1 || cod > E) {
        cout << "C�digo de estudiante inv�lido.\n";
        return;
    }

    cout << "Seleccion� a " << estudiantes[cod - 1] << endl;

    // Confirmaci�n de eliminaci�n
    cout << "�Desea eliminar TODAS las notas de este estudiante? Inserte [S] para confirmar, o cualquier otra tecla para eliminar una nota espec�fica: ";
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

        // Selecci�n de la nota a eliminar
        cout << "Ingrese el n�mero de la nota que desea eliminar (1-" << N << "): ";
        cin >> reg;

        if (reg < 1 || reg > N) {
            cout << "N�mero de nota inv�lido.\n";
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
//              	tabla(E);
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


