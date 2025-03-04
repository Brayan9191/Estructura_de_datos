#include<iostream>
#include<conio.h>

using namespace std;

int main() 
{
//Programa Sin ciclo

	int i, N, N1, N2, N3, SM = 0, PR = 0; //Variables
	
	cout<<"Ingrese la nota #1: ";
		cin>>N1;
	cout<<"Ingrese la nota #2: ";
		cin>>N2;
	cout<<"Ingrese la nota #3: ";
		cin>>N3;
	
	cout<<"El valor de la  nota #1 es: "<<N1<<endl;
	cout<<"El valor de la  nota #2 es: "<<N2<<endl;
	cout<<"El valor de la  nota #3 es: "<<N3<<endl;
	
	PR = (N1 + N2 + N3) / 3;
	cout<<"El promedio de las tres notas es: "<<PR<<endl;

// Programa con ciclo

//	int i, N, SM = 0, PR = 0; //Variables
		
	for(i=1; i<=3; i++)
	{
		cout<<"Ingrese la nota #"<<i<<": ";
		cin>>N;
		SM = SM + N;
	}
	
	PR = SM / 3;
	cout<<"El promedio de las tres notas es: "<<PR;
	
	getch();
	return 0;
}
