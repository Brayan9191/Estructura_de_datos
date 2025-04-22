#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	// Formato ->	Tip_dato nom_matriz [Filas] [Colimnas]
	
	//Crear matriz 3, 3
	int v1 [3] [3];
	
	//	Decclarar variables
	int z=1;
	
	//	Captura de datos
	for(int f=0; f<3; f++)
	{
		for(int c=0; c<3; c++)
		{
			v1[f][c]=z;
		}//	Fin for columnas
		z++;
	}//	Fin for filas
	
	//	Mostrar datos
	for(int f=0; f<3; f++)
	{
		for(int c=0; c<3; c++)
		{
			cout<<v1[f][c] <<" ";
		}//	Fin for columnas
		cout<<endl;
	}//	Fin for filas
	
	getch();
	return 0;
}// fin main 
