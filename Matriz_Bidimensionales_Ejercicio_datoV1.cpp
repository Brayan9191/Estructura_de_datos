#include <iostream>
#include <conio.h>

using namespace std;

//Declarar Matriz - Variables
string raya [3] [3];
int f, c, ubi;
int NumJugadas=0;

//Declarar Funciones
void Mostrar_Matriz();
void Jugada();
void Validar();


int main()
{	
	raya[0][0]="1";		raya[0][1]="2";		raya[0][2]="3";
	
	raya[1][0]="4";		raya[1][1]="5";		raya[1][2]="6";
	
	raya[2][0]="7";		raya[2][1]="8";		raya[2][2]="9";
	
	//	Mostrar datos
	Mostrar_Matriz();
	
	do
	{
	//j_1
		cout<<"Jugador 1\n";
		Jugada();
		raya[f][c]="O";
		
		//Ver matriz
		Mostrar_Matriz();
		
		NumJugadas++;
		Validar();
	
	//j_2
		cout<<"Jugador 2\n";
		Jugada();
		raya[f][c]="X";
		
		//Ver matriz
		Mostrar_Matriz();
		
		NumJugadas++;
		Validar();
	}while(NumJugadas<9);
	
	
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

void Jugada()
{
	cout<<"Indique fila.....: ";
	cin>>f;
	cout<<"Indique columna..: ";
	cin>>c;
}

void Validar()
{
	for(int f=0; f<3; f++)
	{
		if(raya[f][0]==raya[f][1])
		{
			if(raya[f][0]==raya[f][2])
			{
				NumJugadas=9;
			}
		}//Fin if
	}//Fin for
	
	for(int f=0; f<3; f++)
	{
		if(raya[f][0]==raya[f][1])
		{
			if(raya[f][0]==raya[f][2])
			{
				NumJugadas=9;
			}
		}//Fin if
	}//Fin for
}

//		if(raya[f][0]=="O" && raya[f][0]=="O" && raya[f][0]=="O")
