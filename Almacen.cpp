#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//Declarar variables
	int opc, tam=4;
	
	//Declarar vectores
	string productos[tam];
	string codigo[tam];
	int precio[tam];
	
	/*
	cout<<"Ingrese la cantidad de productos a registrar:"<<endl;
	cin>>cant;
	*/
	/*
		Preguntar si quiere ingresar otro productos
	*/
	
	while(cout<<"Quiere ingresar un producto"<<)
	do
	{
		//Salida a pantalla
		cout<<("Almacen de cadena")<<endl;
		cout<<("1. Capturar productos")<<endl;
		cout<<("2. Reportes de productos")<<endl;
		cout<<("3. Menu 3")<<endl;
		cout<<("4. Salir")<<endl;
		cout<<("Selecciona  una opcion del menu: ");
		cin>>opc;
	
		switch(opc)
		{
			case 1: system("cls");
					cout<<"MODULO DE CAPTURA DE PRODUCTOS"<<endl;
					//Captura de productos
					for(int n=0; n<tam; n++)
					{
						cout<<"Producto #["<<(n+1)<<"]"<<endl;
						cout<<"Referencia producto: ";
						cin>>codigo[n];
						cout<<"Ingrese producto...: ";
						cin>>productos[n];
						cout<<"precio del producto: ";
						cin>>precio[n];
					} //Fin for
					
					system("pause");
					break;
					
			case 2: system("cls");
					cout<<"MODULO REPORTE DE PRODUCTOS"<<endl;
					for(int n=0; n<tam; n++)
					{
						cout<<"Producto #["<<(n+1)<<"]"<<endl;
						cout<<"Referencia: "<<(codigo[n])<<endl; 
						cout<<"Productos.: "<<(productos[n])<<endl;
						cout<<"Precio....: "<<(precio[n])<<endl;
						cout<<endl;
					} //Fin for
				
					system("pause");
					break;
					
			case 3: system("cls");
					cout<<"MODULO 3 EN PREOCESO"<<endl;
					/*
						Codigo
					*/
					system("pause");
					break;
					
			case 4: system("cls");
					cout<<"Salir"<<endl;
					system("pause");
					break;
					
			default: system("cls"); 
					cout<<"Opcion no valida"<<endl;
					system("pause");
					break;
		} //Fin switch
	
	}while(opc!=4);
	
	getch();
	return 0;
}
