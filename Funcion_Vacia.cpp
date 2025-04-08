#include<iostream>
#include<conio.h>

using namespace std;
//Definir funciones vacias - no recibe datos ni entrega
void mensaje();
void mensaje_1();
void mensaje_anidado();

int main()
{
	//Funcion vacia - no recibe datos ni entrega
	//Llamado
	mensaje();
	mensaje_anidado();
	mensaje_1();
	mensaje();
	
	getch();
	return 0;
}

//Declara funcion vacia - no recibe datos ni entrega
void mensaje()
{
	cout<<"Mensaje uno"<<endl;
}//Fin funcion

void mensaje_1()
{
	cout<<"Mensaje otro"<<endl;
}//Fin funcion

void mensaje_anidado()
{
	cout<<"Mensaje anidado"<<endl;
	mensaje();
	mensaje_1();
}//Fin anidado
