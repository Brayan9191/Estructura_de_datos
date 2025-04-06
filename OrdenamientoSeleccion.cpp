#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//Ordenamiento por seleccion
	int datos[]={5,3,4,1,2};
	int i, j, pos, aux; //Control - Control - posicion elemnto - alamacenamiento
	
	//Recorrido del array
	cout<<"Array original"<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<"array "<<datos[i]<<" ";
	}//Fin for 
	
	//Recorrido del array
	for(i=0; i<5; i++)
	{
		pos=i;
		for(j=i+1; j<5; j++)
		{
			if(datos[j]<datos[pos])
			{
				pos=j;
			}//Fin if
		}//Fin for
		
		aux=datos[i];
		datos[i]=datos[pos];
		datos[pos]=aux;
	}//Fin for
	
	cout<<endl<<"Array ordenado seleccion"<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<"array "<<datos[i]<<" ";
	}//Fin for 
	
	getch();
	return 0;
}
