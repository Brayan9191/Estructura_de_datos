#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>

using namespace std;

//Variables para ordenamiento
int ubi, auxprecio, auxcodigo; //Control - posicion elemnto - alamacenamiento
string auxprod;
const int TAM = 4;
int precio[TAM];
int codigo[TAM];
string productos[TAM];
int POS = 0;

void Ordenar_Array();

int main()
{
	if(POS<TAM)
	{
		for(int i=0; i<TAM; i++ )
		{
			cout<<"MODULO DE CAPTURA DE PRODUCTOS"<<endl;
			codigo [POS]=(POS+1);
			cout<<"Referancia"<<codigo[POS]<<endl;
			cout<<"Producto"<<endl;
			cin>>productos[POS];
			cout<<endl<<"precio del producto: $";
			cin>>precio[POS];
		
			POS++;
		}
	} //Fin if
	else
	{
		cout<<"El almacen esta lleno"<<endl;
	} // Fin else
	
	Ordenar_Array();
}

void Ordenar_Array()
{	
	int OPC;

	do
	{
		system("cls");
		cout<<("Almacen de cadena")<<endl;
		cout<<("1. Ordenar array por precio menor a mayor")<<endl;
		cout<<("2. Ordenar array por orden alfabetico")<<endl;
		cout<<("3. Ordenar array por referencia")<<endl;
		cout<<("4. Salir")<<endl;
		cout<<("Selecciona  una opcion del menu: ");
		cin>>OPC;
		
		switch(OPC)
		{
			case 1: system("cls");
					//Ordenar array por precio menor a mayor
					//Recorre ordenar array
					for(int i=0; i<POS; i++)
					{
						ubi = i; //Definir posicion
						auxprecio = precio[i];
						auxcodigo = codigo[i];
						auxprod = productos[i];
						
						//Comparar posiciones
						while((ubi>0)&&(precio[ubi-1]>auxprecio))
						{
							precio[ubi]=precio[ubi-1];
							codigo[ubi]=codigo[ubi-1];
							productos[ubi]=productos[ubi-1];
							ubi--;
						}//Fin while
						precio[ubi]=auxprecio;
						codigo[ubi]=auxcodigo;
						productos[ubi]=auxprod;
					}//Fin for
					
					//Mostrar productos
					for(int i=0; i<4; i++)
					{
						cout<<"Referancia ";
						cout<<(codigo[i])<<endl;
						cout<<"Producto ";
						cout<<(productos[i])<<endl;
						cout<<"precio del producto ";
						cout<<"$ "<<(precio[i])<<endl<<endl;	
					}
					
					system("pause");
					break;
					
			case 2: system("cls");
					//Ordenar array por orden alfabetico
					for(int i=0; i<POS; i++)
					{
						ubi = i; //Definir posicion
						auxprecio = precio[i];
						auxcodigo = codigo[i];
						auxprod = productos[i];
						
						//Comparar posiciones
						while((ubi>0)&&(precio[ubi-1]>auxprecio))
						{
							precio[ubi]=precio[ubi-1];
							codigo[ubi]=codigo[ubi-1];
							productos[ubi]=productos[ubi-1];
							ubi--;
						}//Fin while
						precio[ubi]=auxprecio;
						codigo[ubi]=auxcodigo;
						productos[ubi]=auxprod;
					}//Fin for
					
					//Mostrar productos
					for(int i=0; i<4; i++)
					{
						cout<<"Referancia ";
						cout<<(codigo[i])<<endl;
						cout<<"Producto ";
						cout<<(productos[i])<<endl;
						cout<<"precio del producto ";
						cout<<"$ "<<(precio[i])<<endl<<endl;	
					}

					cout<<"Falla";
					
					system("pause");
					break;
			
			case 3: system("cls");
					//Ordenar array por referencia
					for(int i=0; i<5; i++)
					{
						ubi=i;
						for(int j=i+1; j<5; j++)
						{
							if(productos[j]<productos[ubi])
							{
								ubi=j;
							}//Fin if
						}//Fin for
						
						auxprecio=precio[i];
						precio[i]=precio[ubi];
						precio[ubi]=auxprecio;
						
						auxcodigo=codigo[i];
						codigo[i]=codigo[ubi];
						codigo[ubi]=auxcodigo;
						
						auxprod=productos[i];
						productos[i]=productos[ubi];
						productos[ubi]=auxprod;
					}//Fin for
					
					//Mostrar productos
					for(int i=0; i<4; i++)
					{
						cout<<"Referancia ";
						cout<<(codigo[i])<<endl;
						cout<<"Producto ";
						cout<<(productos[i])<<endl;
						cout<<"precio del producto ";
						cout<<"$ "<<(precio[i])<<endl<<endl;	
					}
					
					ubi=0;
					
					system("pause");
					break;
					
			case 4: system("cls");
					cout<<"Salir"<<endl;
					system("pause");
					break;
			
			default: system("cls"); 
					cout<<"Opcion no valida"<<endl;
					system("pause");
					break;
		}
	}while(OPC!=4); //Fin do
}

