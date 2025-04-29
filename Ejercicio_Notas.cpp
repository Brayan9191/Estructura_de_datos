#include <iostream>
#include <conio.h>

using namespace std;

//De

int main()
{
	string estudiantes[]={"Jose  ", "Maria ", "Ana   ", "Pepe  "};
	int cod, reg=0;
	string conf;
	float notas[4][3];
	float nota;
	
	
/*	//	Llenar la matriz de ceros
	for(int i=0; i<4; i++)
	{
		for(int o=0; o<3; o++)
		{
			notas[i][j]=0;
		}
	}	*/

	//	Ver Matriz
	for(int i=0; i<4; i++)
	{
//		cout<<(i+1)<<". "<<estudiantes[i]<<"\t";
		for(int j=0; j<3; j++)
		{
			notas[i][j]=0;
//			cout<<notas[i][j] <<"\t";
		}//	Fin for columnas
//		cout<<endl;
	}//	Fin for filas
	
	//	Captura de notas
	cout<<"Listado de estudiantes\n";
	for(int i=0; i<4; i++)
	{
		cout<<(i+1)<<" - "<<estudiantes[i]<<endl;
	}//Fin estudiantes
	
	//Capturar estudiantes
	cout<<"Ingrese el codigo del estudiantes....: ";
	cin>>cod;
	cout<<"Selecciono a "<<estudiantes[cod-1];
	
	cout<<" Si este es el estudiantes [S] si no otra tecla...: ";
	cin>>conf;
	
	while((conf=="S" || conf=="s") && (reg<3))
	{
		cout<<" Ingrese la nota ["<<(reg+1)<<"]....:";
		cin>>nota;
		//	Asignar nota a la matriz notas
		notas[cod-1][reg]=nota;
		reg++;
	}//Fin ciclo
	
	//	Imprimir la matriz con cabios
	for(int i=0; i<4; i++)
	{
		cout<<(i+1)<<". "<<estudiantes[i]<<"\t";
		for(int j=0; j<3; j++)
		{
			cout<<notas[i][j] <<"\t";
		}//	Fin for columnas
		cout<<endl;
	}//	Fin for filas
	
	getch();
	return 0;
}


