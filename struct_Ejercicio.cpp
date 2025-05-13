#include <iostream>
#include <conio.h>

using namespace std;

//Estructura Contactos
struct contactos
{
	char direc[20];
	char Ciudad[20];
	char Depar[20];
};

//Estructura Empleado
struct empleados
{
	char nom_empleado[15];	
	struct contactos cont;
	float sueldo;
} emp[2];

int main()
{
    //Captura de datos
    cout<<"Captura de datos de los Empleados\n";
	for(int i=0; i<2; i++)
	{
		cout<<"Nombre empleado: ";
		cin>>emp[i].nom_empleado;
		fflush(stdin);
		
		//Captura Contactos
		cout<<"Direccion......: ";
		cin.getline(emp[i].cont.direc, 20, '\n');
		cout<<"Ciudad.........: ";
		cin.getline(emp[i].cont.Ciudad, 20, '\n');
		cout<<"	Departamento..: ";
		cin.getline(emp[i].cont.Depar, 20, '\n');
		fflush(stdin);
		
		cout<<"Sueldo: ";
		cin>>emp[i].sueldo;
	}
	  
	//Salida de datos
    for(int i=0; i<2; i++)
	{
		cout<<"Nombre empleado.: "<<emp[i].nom_empleado<<endl;
		cout<<"Direccion.......: "<<emp[i].cont.direc<<endl;
		cout<<"Ciudad..........: "<<emp[i].cont.Ciudad<<endl;
		cout<<"Departamento....: "<<emp[i].cont.Depar<<endl;
		cout<<"Sueldo..........: "<<emp[i].sueldo<<endl;
		cout<<"******************************\n";
	}
	  
    getch;
    return 0;
}
