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

//	Variables globales
const int v=4, d=8;
int ventas [v] [d];

//Declarar funciones
void MatrizCero();
void Matriz_Captura();
void Mostrar_Matriz();



int main()
{			
	MatrizCero();
	
	//Declarar variables
	int opc;
	string np;
	
	do
	{	
		//Opciones del menu
		cout<<"1. Captura ventas"<<endl;
		cout<<"2. Reporte ventas"<<endl;
		cout<<"3. Reporte vendedor con mas ventas"<<endl;
		cout<<"4. Reporte vendedor con menos ventas"<<endl;
		cout<<"5. Modificar ventas"<<endl;
		cout<<"6. Eliminar ventas"<<endl;
		cout<<"7. Salir"<<endl;
		
		switch(opc)
		{
			case 1: 
				system("cls");
				fflush(stdin);
/*				//Capturar productos
				do
				{	
					tabla(1);	
					Capturar_Productos();
					
					POS++; // Incremento de pos
					gotoxy(1, 10);
					cout<<"Quiere ingresar otro producto? [S] [N]"<<endl;
					cin>> np;
					system("cls");
				}while(np == "s" || np == "S"); // || -> es para agregar otra condicion or, o,	
*/					
				system("pause");
				break;
			
			case 2: 
				system("cls");
				fflush(stdin);
				//4. Modificar producto
						
				system("pause");
				break;	
				
			case 3: 
				system("cls");
				fflush(stdin);
				//4. Modificar producto
						
				system("pause");
				break;
				
			case 4: 
				system("cls");
				fflush(stdin);
				//4. Modificar producto
						
				system("pause");
				break;
				
			case 5: 
				system("cls");
				fflush(stdin);
				//4. Modificar producto
						
				system("pause");
				break;
				
			case 6: 
				system("cls");
				fflush(stdin);
				//4. Modificar producto
						
				system("pause");
				break;
			
			case 7: 
				system("cls");
				fflush(stdin);
				//4. Modificar producto
						
				system("pause");
				break;	
				
			default: 
				system("cls"); 
				cout<<"Opcion invalida"<<endl;
				system("pause");
				break;
		}// Fin switch
	}while(opc!=6); //Fin do
	
		
	getch();
	return 0;
}// fin main 

void MatrizCero()
{
	//	Llenar la matriz de ceros
	for(int i=0; i<v; i++)
	{
		for(int o=0; o<d; o++)
		{
			ventas [i][o]=0;
		}
	}
}// Fin MatrizCero

void Matriz_Captura()
{
	//Declarar variables
	int Vendedor=1;
	
	//	Captura de datos
	for(int f=0; f<v; f++)
	{
		for(int c=0; c<d; c++)
		{
			
		}//	Fin for columnas
	}//	Fin for filas
}// Fin Matriz_Captura

void Mostrar_Matriz()
{
	//	Mostrar datos
	for(int f=0; f<v; f++)
	{
		for(int c=0; c<d; c++)
		{
			cout<<ventas[f][c] <<" ";
		}//	Fin for columnas
		cout<<endl;
	}//	Fin for filas
}// Fin Mostrar_Matriz


