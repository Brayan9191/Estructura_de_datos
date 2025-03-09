#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//Declarar variables
	int Pro = 0;
	
	//Declarar array
	int N[3];
	
	//Entrada de valores en el vector
	for(int i=0; i<=2; i++)
	{
		cout<<"Ingrese el valor de la nota #"<<(i+1)<<": ";
		cin>>N[i];
	}	cout<<endl; //Solo para saltar linea
	
	//Salida datos
	for(int i=0; i<=2; i++)
	{
		cout<<"el valor de la nota #"<<(i+1)<<" es: "<<N[i]<<endl;
	}	
		Pro = (N[0] + N[1] + N[2]) / 3;
		cout<<"\nEl promedio de las notas es: "<<Pro<<endl;
} 
