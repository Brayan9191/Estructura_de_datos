#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//ordenamiento burbuja
	int datos[]={5,3,4,1,2};
	int i, j, aux; //Control - posicion elemnto - alamacenamiento
	
	//Recorrido del array
	cout<<"Array original"<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<"array "<<datos[i]<<" ";
	}//Fin for 
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			if(datos[j]>datos[j+1])
			{
				aux = datos[j];
				datos[j] = datos[j+1];
				datos[j+1] = aux;
			}//Fin if
		}//Fin for
	}//Fin for
	
	cout<<endl<<"Array ordenado burbuja"<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<datos[i]<<" ";
	}//Fin for 
	
	
	cout<<endl<<"Array ordenado burbuja"<<endl;
	for(int i=4; i>=0; i--)
	{
		cout<<datos[i]<<" ";
	}//Fin for 
	

	getch();
	return 0;
}


