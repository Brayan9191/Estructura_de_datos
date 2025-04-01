#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>

#define color SetConsoleTextAttribute

using namespace std;

//Codigo de color 
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Codigo gotoxy
 void gotoxy(int x,int y)
 {  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
 int main()
 {
 	//Declarar variables
	int opc, tam = 4, pos = 0, bus, pr;
	string np; // Para anadir nuevo producto
	bool bandera; 
	
	//Declarar vectores
	string productos[tam];
	int codigo[tam];
	int precio[tam];
 	
	 //Cuerpo de la tabla
	for(int i=1; i<=50; i++)
	{
		gotoxy(i, 1);
		cout<<"-";
		gotoxy(i, 3);
		cout<<"-";
		gotoxy(i, 5);
		cout<<"-";
		gotoxy(i, 7);
		cout<<"-";
	}//Fin if
	for(int i=1; i<=20; i++)
	{
		gotoxy(1, i);
		cout<<"|";
		gotoxy(30, i);
		cout<<"|";
		gotoxy(50, i);
		cout<<"|";
	}//Fin if
	
	//Salida en pantalla
	
		codigo [pos]=(pos+1);
		gotoxy(2, 2);
		cout<<"Referancia"<<endl;
		gotoxy(32, 2);
		cout<<codigo[pos];
		gotoxy(2, 4);
		cout<<"Producto"<<endl;
		gotoxy(32, 4);
		cin>>productos[pos];
		gotoxy(2, 6);
		cout<<"precio del producto";
		gotoxy(32, 6);
		cout<<"$";
		gotoxy(33, 6);
		cin>>precio[pos];

	system("cls");
	cout<<"MODULO REPORTE DE PRODUCTOS"<<endl;
	for(int i=0; i<pos; i++)
	{
		cout<<"Producto #["<<(i+1)<<"]"<<endl;
		cout<<"Referencia: "<<(codigo[i])<<endl; 
		cout<<"Productos.: "<<(productos[i])<<endl;
		cout<<"Precio....: "<<(precio[i])<<endl;
		cout<<endl;
	} //Fin for
				
	system("pause");
	
	
 	getch();
 	return 0;
 }//Fin main
