#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//Declarar variables
	int opc;
	
	do
	{
		//Salida a pantalla
		cout<<("Menu")<<endl;
		cout<<("1. Menu 1")<<endl;
		cout<<("2. Menu 2")<<endl;
		cout<<("3. Menu 3")<<endl;
		cout<<("4. Salir")<<endl;
		cout<<("Selecciona  una opcion del menu: ");
		cin>>opc;
	
		switch(opc)
		{
			case 1: system("cls");
					cout<<"Modulo 1"<<endl;
					system("pause");
					break;
					
			case 2: system("cls");
					cout<<"Modulo 2"<<endl;
					system("pause");
					break;
					
			case 3: system("cls");
					cout<<"Modulo 3"<<endl;
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
