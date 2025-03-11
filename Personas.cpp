/* Capturar el nombre de tres personas */
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//Declarar vectores
	string per[3];
	
	//Capturar datos
	for(int n=0; n<=2; n++)
	{
		cout<<(n+1)<<"Ingrese un nombre: ";
		cin>>per[n];
	} //Fin for
	
	//Salida de datos
	for(int n=0; n<=2; n++)
	{
		cout<<"Registro #: "<<(n+1)<<endl;
		cout<<"Usuario: "<<(per[n])<<endl;
	} //Fin for
	
	getch();
	return 0;
} //Fin main
