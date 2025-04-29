#include <iostream>
#include <conio.h>

using namespace std;

//Declarar Matriz - Variables
string raya [3] [3];
int c, ubi;
string pos, O=O, X=X;
int NumJugadas=0;

//Declarar Funciones
void Mostrar_Matriz();
void Jugada(string Marca);
void Validar();


int main()
{	
	raya[0][0]="1";		raya[0][1]="2";		raya[0][2]="3";
	
	raya[1][0]="4";		raya[1][1]="5";		raya[1][2]="6";
	
	raya[2][0]="7";		raya[2][1]="8";		raya[2][2]="9";
	
	//	Mostrar datos
//	Mostrar_Matriz();
	
	do
	{
	//j_1
		cout<<"Jugador 1\n"; //	O		
//		Mostrar_Matriz();
		
//		Jugada(O);
		NumJugadas++;
//		Validar();
	
	//j_2
		cout<<"Jugador 2\n"; //	X
//		Mostrar_Matriz();
		
//		Jugada(X);
		NumJugadas++;
//		Validar();
	}while(NumJugadas!=9);
	
	
	getch();
	return 0;
}// fin main 

void Mostrar_Matriz()
{
	//	Mostrar datos
	for(int f=0; f<3; f++)
	{
		for(int c=0; c<3; c++)
		{
			cout<<raya[f][c] <<" ";
		}//	Fin for columnas
		cout<<endl;
	}//	Fin for filas
}// Fin Mostrar_Matriz

void Jugada(string Marca)
{
	cout<<"Indique la posicion donde quiere hacer la jugada [#]: ";
	cin>>pos;
	
	for(int f=0; f<3; f++)
	{
		for(int c=0; c<3; c++)
		{
			if((raya[f][c]) == pos)
			{
				raya[f][c]=Marca;
			}
			else
			{
				cout<<"Pierde turno por intentar escribir en una celda ya ocupada";
			}	
		}//	Fin for columnas
	}//	Fin for filas
}

void Validar()
{
	//Valida F y C
	for(int f=0; f<3; f++)
	{
		if(raya[f][0] == raya[f][1] && raya[f][1] == raya[f][2])
		{
			NumJugadas=9;
			cout<<"\n\nGana "<<raya[f][2]<<endl;
			system("pause");
		}//Fin if
		if(raya[0][f] == raya[1][f] && raya[1][f] == raya[2][f])
		{
			NumJugadas=9;
			cout<<"\n\nGana "<<raya[2][f]<<endl;
			system("pause");
		}//Fin if
	}
	
	if(raya[0][0] == raya[1][1] && raya[1][1] == raya[2][2])
	{
		NumJugadas=9;
		cout<<"\n\nGana "<<raya[2][2]<<endl;
		system("pause");
	}//Fin if
	
	if(raya[0][2] == raya[1][1] && raya[1][1] == raya[2][0])
	{
		NumJugadas=9;
		cout<<"\n\nGana "<<raya[2][0]<<endl;
		system("pause");
	}//Fin if
}

