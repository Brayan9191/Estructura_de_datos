#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>

#define color SetConsoleTextAttribute


using namespace std;

//Codigo de color 
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


//Codigo gotoxy
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 

//Declarar variables globales
const int TAM = 4;
int POS = 0, y = 1;

//Variables para ordenamiento
	int i, ubi, auxprecio, auxcodigo; //Control - posicion elemnto - alamacenamiento
	string auxprod;

//Declarar vectores
string productos[TAM];
int codigo[TAM];
int precio[TAM];

//Declarar funciones
void tabla(int pos);
void Mostrar_Productos(int z);
void Capturar_Productos();
void Buscar_pruducto();
void Ordenar_Array();
//Mostrar en pantalla
int main()
{	
	//Declarar variables
	int opc;
	string np ;
	
	//Salida a pantalla
	do
	{
		system("cls");
		color(hConsole, 3);								//Azul claro - 3
		cout<<("Almacen de cadena")<<endl;
		color(hConsole, 2);								//Verde - 2
		cout<<("1. Capturar productos")<<endl;
		color(hConsole, 5);								//Morado - 5
		cout<<("2. Reportes de productos")<<endl;
		color(hConsole, 10);							//Verde claro - 10
		cout<<("3. Buscar producto")<<endl;
		color(hConsole, 6);								//Naranja_Amarrollo - 6
		cout<<("4. Modificar producto")<<endl;
		color(hConsole, 9);								//Azul claro - 9
		cout<<("5. Ordenar Almacen")<<endl;
		color(hConsole, 4);								//rojo - 4
		cout<<("6. Salir")<<endl;
		color(hConsole, 12);							//Rosa - 12
		cout<<("Selecciona  una opcion del menu: ");
		cin>>opc;
		
		switch(opc)
		{
			case 1: system("cls");
					fflush(stdin);
					//Capturar productos
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
					
					system("pause");
					break;
					
			case 2: system("cls");
					fflush(stdin);
					//Reportes de productos
					tabla(POS);
					for(int i=0; i<POS; i++)
					{
						Mostrar_Productos(i);
					}
					y+=2;
					gotoxy(1, y);
					
					y = 1;
					
					system("pause");
					break;
			
			case 3: system("cls");
					fflush(stdin);
					//Buscar producto
					Buscar_pruducto();
					
					y = 1;
					
					system("pause");
					break;
			
			case 4: system("cls");
					fflush(stdin);
					//4. Modificar producto
					
					
					system("pause");
					break;
			
			case 5: system("cls");
					fflush(stdin);
					//Ordenar almacen
					
					Ordenar_Array();
					
					//Mostrar productos
					y+=2;
					gotoxy(1, y);
					
					y = 1;

					system("pause");
					break;
			
			case 6: system("cls");
					fflush(stdin);
					cout<<"Salir"<<endl;
					system("pause");
					break;
			
			default: system("cls"); 
					cout<<"Opcion no valida"<<endl;
					system("pause");
					break;
		}// Fin switch
	}while(opc!=6); //Fin do
		
	getch();
	return 0;
}


//Definir funciones
void tabla(int pos)
{
	//Declarar variables
	int lin = 0, clin = 3, o = 2;
	
	//Cuerpo de la tabla
	clin *= pos;
	//Filas
	for(int i=0; i<2; i++)
	{
		for(int i=1; i<=60; i++)
		{
			gotoxy(i, lin);
			cout<<"-";
		}//Fin for
		lin +=2;
	}
	for(int i=0; i<clin; i++)
	{
		for(int i=1; i<=60; i++)
		{
		gotoxy(i, lin);
		cout<<"-";
		}//Fin for
		lin += 2;
	}//Fin if
					
	//Columnas
	for(int i=0; i<(3+(6*pos)); i++)
	{
		gotoxy(1, i);
		cout<<"|";
		if(o<9)
		{
			gotoxy(30, o); o++;
			cout<<"|"; 
		}//Fin if 
		else
		{
			gotoxy(30, i);
			cout<<"|";
		}//Fin else
		gotoxy(60, i);
		cout<<"|";
	}//Fin for
	
	o=0;
	lin=0;
	clin=3;
}//Fin funcion tabla

void Mostrar_Productos(int z)
{	
	gotoxy(15, 1);
	cout<<"MODULO REPORTE DE PRODUCTOS"<<endl;
	
	//Mostrar en pantalla el producto
	y+=2;
	gotoxy(2, y);
	cout<<"Referancia"<<endl;
	gotoxy(32, y);
	cout<<(codigo[z]);
	y+=2;
	gotoxy(2, y);
	cout<<"Producto"<<endl;
	gotoxy(32, y);
	cout<<(productos[z]);
	y+=2;
	gotoxy(2, y);
	cout<<"precio del producto";
	gotoxy(32, y);
	cout<<"$"<<(precio[z]);		
}//Fin fincion mostrar productos

void Capturar_Productos()
{	
		if(POS<TAM)
		{
			gotoxy(15, 1);
			cout<<"MODULO DE CAPTURA DE PRODUCTOS"<<endl;
			codigo [POS]=(POS+1);
			gotoxy(2, 3);
			cout<<"Referancia"<<endl;
			gotoxy(2, 5);
			cout<<"Producto"<<endl;
			gotoxy(2, 7);
			cout<<"precio del producto";
						
			gotoxy(32, 3);
			cout<<codigo[POS];
			gotoxy(32, 5);
			cin>>productos[POS];
			gotoxy(32, 7);
			cout<<"$";
			gotoxy(33, 7);
			cin>>precio[POS];
		} //Fin if
		else
		{
			cout<<"El almacen esta lleno"<<endl;
		} // Fin else				
}//Fin fincion Capturar productos

void Buscar_pruducto()
{
	//Declara variables
	int bus, pr;
	bool bandera; 
	
	cout<<"Modulo Buscar productos"<<endl;
	cout<<"Referencia del producto buscado: ";
	cin>>bus;
					
	for(int i=0; i<POS; i++)
	{
		// Comparacion
		if(bus==codigo[i])
		{
			pr= i;
			bandera=true;
			break;
		}
		else
		{
			bandera=false;
		} //Fin else
	} //Fin for
	// Validar bendera
	if(bandera==true)
	{
		color(hConsole, 2);
		cout<<"El producto si existe"<<endl;
		system("pause");
		system("cls");
		
		//Cuerpo de la tabla
		tabla(1);
		
		color(hConsole, 6);
		gotoxy(15, 1);
		cout<<"Modulo Buscar producto"<<endl;
						
		Mostrar_Productos(pr);
	}
	else
	{
		color(hConsole, 4);
		cout<<"El producto buscado no existe"<<endl;
	}
					
	gotoxy(1, 10);
}

void Ordenar_Array()
{	
	int OPC;

	do
	{
		system("cls");
		cout<<("Almacen de cadena")<<endl;
		cout<<("1. Ordenar por precio menor a mayor")<<endl;
		cout<<("2. Ordenar por orden alfabetico")<<endl;
		cout<<("3. Ordenar por referencia")<<endl;
		cout<<("4. Salir")<<endl;
		cout<<("Selecciona  una opcion del menu: ");
		cin>>OPC;
		
		switch(OPC)
		{
			case 1: system("cls");
					fflush(stdin);
					//Ordenar array por precio menor a mayor
					//Recorre ordenar array
					for(int i=0; i<POS; i++)
					{
						ubi = i; //Definir posicion
						auxprecio = precio[i];
						auxcodigo = codigo[i];
						auxprod = productos[i];
						
						//Comparar posiciones
						while((ubi>0)&&(precio[ubi-1]>auxprecio))
						{
							precio[ubi]=precio[ubi-1];
							codigo[ubi]=codigo[ubi-1];
							productos[ubi]=productos[ubi-1];
							ubi--;
						}//Fin while
						precio[ubi]=auxprecio;
						codigo[ubi]=auxcodigo;
						productos[ubi]=auxprod;
					}//Fin for
					
					//Mostrar productos
					tabla(POS);
					for(int i=0; i<POS; i++)
					{
						Mostrar_Productos(i);
					}
					y+=2;
					gotoxy(1, y);
					
					y = 1;
					
					system("pause");
					break;
					
			case 2: system("cls");
					fflush(stdin);
					//Ordenar array por orden alfabetico
					for(int i=0; i<5; i++)
					{
						ubi = i; //Definir posicion
						auxprecio = precio[i];
						auxcodigo = codigo[i];
						auxprod = productos[i];
							
						//Comparar posiciones
						if((ubi>0)&&(productos[ubi-1]>auxprod))
						{
							precio[ubi]=precio[ubi-1];
							codigo[ubi]=codigo[ubi-1];
							productos[ubi]=productos[ubi-1];
							ubi--;
						}//Fin while
						precio[ubi]=auxprecio;
						codigo[ubi]=auxcodigo;
						productos[ubi]=auxprod;
					}//Fin for
					
					//Mostrar productos
					tabla(POS);
					for(int i=0; i<POS; i++)
					{
						Mostrar_Productos(i);
					}
					y+=2;
					gotoxy(1, y);
					
					y = 1;
					
					system("pause");
					break;
			
			case 3: system("cls");
					fflush(stdin);
					//Ordenar array por referencia
					for(int i=0; i<POS; i++)
					{
						ubi = i; //Definir posicion
						auxprecio = precio[i];
						auxcodigo = codigo[i];
						auxprod = productos[i];
							
						//Comparar posiciones
						if((ubi>0)&&(codigo[ubi-1]>auxcodigo))
						{
							precio[ubi]=precio[ubi-1];
							codigo[ubi]=codigo[ubi-1];
							productos[ubi]=productos[ubi-1];
							ubi--;
						}//Fin while
						precio[ubi]=auxprecio;
						codigo[ubi]=auxcodigo;
						productos[ubi]=auxprod;
					}//Fin for
					
					//Mostrar productos
					tabla(POS);
					for(int i=0; i<POS; i++)
					{
						Mostrar_Productos(i);
					}
					y+=2;
					gotoxy(1, y);
					
					y = 1;
					
					system("pause");
					break;
					
			case 4: system("cls");
					fflush(stdin);
					cout<<"Salir"<<endl;
					system("pause");
					break;
			
			default: system("cls"); 
					cout<<"Opcion no valida"<<endl;
					system("pause");
					break;
		}
	}while(OPC!=4); //Fin do
}

