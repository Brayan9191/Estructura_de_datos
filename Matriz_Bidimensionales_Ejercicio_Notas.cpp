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
int POS=0;

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
		cout<<("\nSelecciona  una opcion del menu: ");
		cin>>opc;
		
		switch(opc)
		{
			case 1: 
				system("cls");
				fflush(stdin);
				//1. Captura ventas
				do
				{	
//					tabla(1);	
					Matriz_Captura();
					
					POS++; // Incremento de pos
					gotoxy(1, 10);
					cout<<"Quiere ingresar otro numero de ventas? [S] [N]"<<endl;
					cin>> np;
					system("cls");
				}while(np == "s" || np == "S"); // || -> es para agregar otra condicion or, o,	
					
				system("pause");
				break;
			
			case 2: 
				system("cls");
				fflush(stdin);
				//2. Reporte ventas
				for(int f=0; f<3; f++)
				{
					for(int c=0; c<3; c++)
					{
						cout<<ventas[f][c] <<" ";
					}//	Fin for columnas
					cout<<endl;
				}//	Fin for filas
						
				system("pause");
				break;	
				
			case 3: 
				system("cls");
				fflush(stdin);
				//3. Reporte vendedor con mas ventas
				
					
				system("pause");
				break;
				
			case 4: 
				system("cls");
				fflush(stdin);
				//4. Reporte vendedor con menos ventas
						
				system("pause");
				break;
				
			case 5: 
				system("cls");
				fflush(stdin);
				//5. Modificar ventas
						
				system("pause");
				break;
				
			case 6: 
				system("cls");
				fflush(stdin);
				//6. Eliminar ventas
						
				system("pause");
				break;
			
			case 7: 
				system("cls");
				fflush(stdin);
				//7. Salir
						
				system("pause");
				break;	
				
			default: 
				system("cls"); 
				cout<<"Opcion invalida"<<endl;
				system("pause");
				break;
		}// Fin switch
	}while(opc!=7); //Fin do
	
		
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
	
	for(int f=0; f<(v-1); f++)
	{
		for(int c=0; (d-1)<3; c++)
		{
			cout<<"Ingrese el numero de ventas: ";
			cin>>ventas[f][c];
		}//	Fin for columnas
	}//	Fin for filas
}// Fin Matriz_Captura

void Mostrar_Matriz()
{
	for(int f=0; f<4; f++)
	{
		for(int c=0; c<4; c++)
		{
			cout<<ventas[f][c] <<" ";
		}//	Fin for columnas
		cout<<endl;
	}//	Fin for filas
}// Fin Mostrar_Matriz


