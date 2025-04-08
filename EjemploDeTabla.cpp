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
	int opc, tam = 1, pos = 0, bus, pr, lin, clin = 3, col=9, o=2, c=1, pilar;
	string np; // Para anadir nuevo producto
	bool bandera; 
	
	//Declarar vectores
	string productos[tam];
	int codigo[tam];
	int precio[tam];
 	
	//Cuerpo de la tabla
	clin *= tam;
	//Flias
	for(int i=0; i<2; i++)
	{
		for(int i=1; i<=50; i++)
		{
			gotoxy(i, lin);
			cout<<"-";
		}//Fin for
		lin +=2;
	}
		
	for(int i=0; i<clin; i++)
	{
		for(int i=1; i<=50; i++)
		{
			gotoxy(i, lin);
			cout<<"-";
		}//Fin for
		lin +=2;
	}//Fin if
	
	//Columnas
	for(int i=0; i<col; i++)
	{
		gotoxy(1, i);
		cout<<"|";
		if((o<9))
		{
			gotoxy(30, o); o++;
			cout<<"|";
		}//Fin if
		else
		{
			gotoxy(30, i);
			cout<<"|";
		}//Fin else
		gotoxy(50, i);
		cout<<"|";
	}//Fin if
	
	//Salida en pantalla
	
		codigo [pos]=(pos+1);
		gotoxy(2, 3);
		cout<<"Referancia"<<endl;
		gotoxy(32, 3);
		cout<<codigo[pos];
		gotoxy(2, 5);
		cout<<"Producto"<<endl;
		gotoxy(32, 5);
		cin>>productos[pos];
		gotoxy(2, 7);
		cout<<"precio del producto";
		gotoxy(32, 7);
		cout<<"$";
		gotoxy(33, 7);
		cin>>precio[pos];
		
		system("pause");

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
