#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	// Formato ->	Tip_dato nom_matriz [Filas] [Colimnas]
	
	//Crear matriz
	int d1 [3] [3];
	
	//	Asignar valores directamente
	d1[0][0]=5;
	d1[2][2]=-15;
	d1[2][4]=-55; //Da error por tamano
	
	//	Mostrar datos
	cout<<d1[0][0]<<endl;
	cout<<d1[2][2]<<endl;
	cout<<d1[2][4]<<endl; //Error por tamano
	
	getch();
	return 0;
}// fin main 


