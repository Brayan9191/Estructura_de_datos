#include <iostream>
#include <conio.h>

using namespace std;

//Estructura curso
struct curso
{
	int cod_curso;
	char nom_curso[15];
};

//Estructura Estudiante
struct estudiante
{
	int cod_est;
	char nom_est[20];
	int edad;
	struct curso cursito;
} alumno[2];

int main()
{
    //Captura de datos
    cout<<"Captura de datos de los estudiantes\n";
	for(int i=0; i<2; i++)
	{
		cout<<"Codigo: ";
		cin>>alumno[i].cod_est;
		fflush(stdin);
		cout<<"Nombre: ";
		cin.getline(alumno[i].nom_est, 20, '\n');
		cout<<"Edad: ";
		cin>>alumno[i].edad;
		cout<<"\n";
		
		//Captura curso
		cout<<"Codigo del curso: ";
		cin>>alumno[i].cursito.cod_curso;
		fflush(stdin);
		cout<<"Nombre del curso: ";
		cin.getline(alumno[i].cursito.nom_curso, 15, '\n');
		cout<<"\n";
	}
	  
	//Salida de datos
    for(int i=0; i<2; i++)
	{
		cout<<"Codigo Estudiante: "<<alumno[i].cod_est<<endl;
		cout<<"Nombre Estudiante: "<<alumno[i].nom_est<<endl;
		cout<<"Edad Estudiante..: "<<alumno[i].edad<<endl;
		cout<<"Codigo Curso.....: "<<alumno[i].cursito.cod_curso<<endl;
		cout<<"Nombre Curso.....: "<<alumno[i].cursito.nom_curso<<endl;
		cout<<"******************************\n";
	}
	  
    getch;
    return 0;
}
