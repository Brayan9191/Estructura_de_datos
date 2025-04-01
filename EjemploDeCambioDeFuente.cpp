#include<iostream>
#include<windows.h>

#define color SetConsoleTextAttribute

using namespace std;

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	color(hConsole, 1);
	
	for(int i=1; i<=15; i++)
	{
		color(hConsole, i);
		cout<<"Hola mundo"<<endl;
	}
	/*
		1 _ Azul Oscuro
		2 _ Verde Oscuro
		3 _ Azul clarito
		4 _ Rojo
		5 _ Violeta
		6 _ Amarrillo
		7 _ Blanco
		8 _ Gris
		9 _ Azul Clarito
		10_ Verde clarito
		11_ Cian
		12_ Rosa
		13_ Morado
		14_ Piel
		15_ Blanco brillante
	*/
}
