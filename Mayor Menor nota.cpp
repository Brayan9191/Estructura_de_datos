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
const int E = 4, N = 3;
float notas[E][N] = {0}; // Inicializo notas en 0
string Estu[E];	//Para ordenar
string Notas[N];//Para ordenar
int POS=0;
string estudiantes[] = {"Jose  ", "Maria ", "Ana   ", "Pepe  "};

// Declarar funciones
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
    cout << "REPORTE DE NOTAS\n";
    cout << "------------------------------\n";
    cout << "Estudiante\tNota1\tNota2\tNota3\tPromedio\n";
    cout << "------------------------------\n";
    for (int i = 0; i < E; i++) {
        int suma = 0;
        cout << estudiantes[i] << "\t";
        for (int j = 0; j < N; j++) {
            cout << notas[i][j] << "\t";
            suma += notas[i][j];
        }
        float promedio = suma / (float)N;
        cout << promedio << endl;
    }
}//Reporte de notas

void OrdNot()
{
	int ubi;
	float auxnot;
	int e=0;
	
	for(int i=0; i<N; i++)
	{
		ubi = i;
		auxnot = notas[e][i];
		
		//Comparar Posiciones 
		while((ubi>0)&&(notas[e][i]>auxnot))
		{
			Notas[i]=notas[e][i-1];
			ubi--;
		}//Fin while
		Notas[i]=auxnot;
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


