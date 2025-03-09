#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//Declarar variables
	int o=0;
	
	//Declarar vectores
	int arA[3];
	int arB[3]; 
	int arC[3];
	int arD[3];
	//Entrada de valores en el vector
	for(int i=0; i<3; i++)
	{
		cout<<"Ingrese el valor de la posicion "<< i << " del vector A: ";
		cin>>arA[i];
		cout<<"ingrese el valor de la posicion "<< i << " del vector B: ";
		cin>>arB[i];
	} //Fin de for
	cout<<endl;
	//Salida de datos
	for(int i=0; i<3; i++)
	{
		cout<<"Vector A ["<< i << "]: "<< arA[i]<< endl;
	} //Fin for
	cout<<endl;
	for(int i=0; i<3; i++)
	{
		cout<<"Vector B ["<< i << "]: "<< arB[i]<< endl;
	} //Fin for
	cout<<endl;
	for(int i=0; i<3; i++)
	{
		arC[i] = arA[i] + arB[i];
		cout<<"La suma de la posicion "<< i <<" del vector A y B es: "<< arC[i]<< endl;
	} //Fin for
	cout<<endl;
	
	for(int i=2; i>=0; i--)
	{
		cout<<o<< " / "<<arA[o]<<endl;
		cout<<i<< " / "<<arB[i]<<endl;
		arD[o] = arA[o] +arB[i];
		cout<<"La suma del vector A["<< o << "] y B["<< i <<"] es: "<< arD[o]<< endl;
		o++;
	}
	
	getch();
	return 0;
} //Fin main
