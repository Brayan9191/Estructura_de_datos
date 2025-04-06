#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//ordenamiento insercion
	int datos[]={5,3,4,1,2};
	int i, pos, aux; //Control - posicion elemnto - alamacenamiento
	
	//Recorrido del array
	cout<<"Array original"<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<"array "<<datos[i]<<" ";
	}//Fin for 
	
	//Recorre ordenar array
	for(int i=0; i<5; i++)
	{
		pos = i; //Definir posicion
		aux = datos[i];
		
		//Comparar posiciones
		while((pos>0)&&(datos[pos-1]>aux))
		{
			datos[pos]=datos[pos-1];
			pos--;
		}//Fin while
		datos[pos]=aux;
	}//Fin for
	
	cout<<endl<<"Array ordenado"<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<"array "<<datos[i]<<" ";
	}//Fin for 
	
	
	getch();
	return 0;
}
