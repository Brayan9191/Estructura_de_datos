#include<iostream>
#include<conio.h>

using namespace std;

////Definir funciones parametrizadas - solo recibe y muestra datos
void suma(int d1, int d2);
void resta(int r1, int r2);
void miltiplicacion(int m1, int m2);


int main()
{
	//Llamado de la fincion
	suma(5,6);
	miltiplicacion(5,2);
	resta(48,20);
	
	getch();
	return 0;
}//Fin main

//Definir finciones
void suma(int d1, int d2)
{
	int rs=0;
	//Operacion
	rs = d1 + d2;
	cout<<"La suma de "<<d1<<" + "<<d2<<" = "<<rs<<endl;
}//Fin funcion suma

void resta(int r1, int r2)
{
	int rs=0;
	//Operacion
	rs = r1 - r2;
	cout<<"La resta de "<<r1<<" - "<<r2<<" = "<<rs<<endl;
}//Fin funcion suma

void miltiplicacion(int m1, int m2)
{
	int rs=0;
	//Operacion
	rs = m1 * m2;
	cout<<"La multiplicacion de "<<m1<<" * "<<m2<<" = "<<rs<<endl;
}//Fin funcion miltiplicacion
