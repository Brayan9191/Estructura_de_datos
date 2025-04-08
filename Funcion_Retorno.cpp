#include<iostream>
#include<conio.h>

using namespace std;

//Declarar funciones de retorno
float promedio (float v1, float v2);

int main()
{
	float rp=0;
	
	//Llamado de la fincion de retorno
	rp = promedio(8,20);
	
	cout<<"El promedio es "<<rp<<endl;
	cout<<"El promedio es "<<promedio(7,8)<<endl;
	
	getch();
	return 0;
}//Fin main

//Definir finciones
float promedio (float v1, float v2)
{
	//Declarar variables
	float pro = 0;
	
	//Operacion
	pro = (v1+v2)/2;
	
	//Salida en pantalla
	return pro;
}//Fin fincion promedio
