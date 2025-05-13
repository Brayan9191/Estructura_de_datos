#include <iostream>
#include <conio.h>

using namespace std;

//creacion del struct
struct Estudiante
{
  int cod;
  char nombre[10];
  int edad;
}  estu[3];

int main()
{
    //Capturar datos
    for(int i=0; i<3; i++)
    {
      	cout<<"Ingrese el codigo: ";
 	   	cin>>estu[i].cod;
 	 	fflush(stdin);                                //Limpia el cache, la memoria temporal, Se usa antes o despues del getline dependiend de en donde esta en la funcion struct, 
  		cout<<"Ingrese el nombre del estudiante: ";
	    cin.getline(estu[i].nombre, 10, '\n');         //getline : Para capturar datos despues del espacio
  	  	cout<<"Edad del estudiante: ";
  	  	cin>>estu[i].edad;
    }

    //Salida de datos
    for(int i=0; i<3; i++)
    {
    	cout<<"Codigo: "<<estu[i].cod<<endl;
    	cout<<"Nombre: "<<estu[i].nombre<<endl;
   	 	cout<<"Edad..: "<<estu[i].edad<<endl;
	}
    
    getch;
    return 0;
}
