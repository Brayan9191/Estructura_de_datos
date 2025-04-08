/*
	Pedir al usuario ingresar 5 numeros en una funcion vacia
	Muestre los datos en una funcion parametrizada
	Calcule el promedio y devuelva el promedio, funcion retorno
	Se debe usar un array
*/

#include<iostream>
#include<conio.h>

using namespace std;
//Declarar variables globales
const int TAM = 5;

int numeros[TAM];

//Declarar funciones
//Capturar datos
void capturar();
void mostrar(int num[], int tam);
float calcular_promedio(int num[], int tam);

int main()
{
	//Llamado de funciones
	capturar();
	mostrar(numeros, TAM);
	float pro = calcular_promedio(numeros,TAM);
	cout<<"\nEl promedio es "<<pro<<endl;
	cout<<"\nEl promedio es "<<pro<<endl;

	
	getch();
	return 0;
}

//Definir funciones
void capturar()
{
	cout<<"Ingrese "<<TAM<<" numeros enteros"<<endl;
	for(int i=0; i<TAM; i++)
	{
		cout<<"["<<(i+1)<<"] Ingrese el numero: ";
		cin>>numeros[i];
	}//Fin for
}//Fin funcion vacia capturar

void mostrar(int num[], int tam)
{
	cout<<"\t\t REPORTE DE DATOS\n";
	for(int i=0; i<tam; i++)
	{
		cout<<num[i]<<" ";
	}//Fin for
}//Fin funcion mostrar

float calcular_promedio(int num[], int tam)
{
	int suma=0;
	for(int i=0; i<tam; i++)
	{
		suma+=num[i];
	}//Fin for
	
	return static_cast<float>(suma)/tam;
}//Fin funcion calcular_promedio
