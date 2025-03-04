#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//Delarar variables
	int opc = 0;
	
	cout<<"MENU DE JUEGOS\n"<<endl;
	cout<<"1. HALO"<<endl;
	cout<<"2. SNIPPER"<<endl;
	cout<<"3. PAGMAN"<<endl;
	cout<<"4. SALIDA\n"<<endl;
	cin>>opc;
	
	//Validar
	switch(opc)
	{
		case 1: cout<<"Ingreso al modulo de halo"<<endl;
				break;	
		case 2: cout<<"Ingreso al modulo de SNIPER"<<endl;	
				break;	
		case 3: cout<<"Ingreso al modulo de PAGMAN"<<endl;	
				break;	
		case 4: cout<<"No quieres jugar mas, hasta la proxima"<<endl;	
				break;
					
		default: cout<<"Selecciono una opcion no  valida\n"<<endl; 	
				break;
	} //Fin switch
	
	cout<<"Chao gracial :)"<<endl;
	
	getch();
	return 0;
} //Fin main 
