#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	// Declarar vector
	int datos[5]; // Tipo_dato nombre [Cantidad];
	
	//Asignar valores al vector
	datos[0] = 15; 
	datos[1] = 25;
	datos[2] = -8;
	datos[3] = -15;
	datos[4] = 20;
	
	//Salida de valores en pantalla
	for(int i=0; i<=4; i++)
	{
	cout<<"En la posicion "<<(i+1)<<" esta: "<<datos[i]<<endl;
	}
	
	//Entrada de valores de tecaldo en el vector
	for(int i=0; i<=4; i++)
	{
		cout<<"Ingrese el valor para la posicion #"<<(i+1)<<": ";
		cin>>datos[i];
	}
	
	for(int i=0; i<=4; i++)
	{
	cout<<"En la posicion "<<(i+1)<<" esta: "<<datos[i]<<endl;
	}
	
	getch();
	return 0;
}
