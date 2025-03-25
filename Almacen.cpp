#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	//Declarar variables
	int opc, tam = 4, pos = 0, bus, pr;
	string np; // Para añadir nuevo producto
	bool bandera; 
	
	//Declarar vectores
	string productos[tam];
	int codigo[tam];
	int precio[tam];
	
	do
	{
		//Salida a pantalla
		cout<<("Almacen de cadena")<<endl;
		cout<<("1. Capturar productos")<<endl;
		cout<<("2. Reportes de productos")<<endl;
		cout<<("3. Buscar producto")<<endl;
		cout<<("4. Modificar producto")<<endl;
		cout<<("5. Salir")<<endl;
		cout<<("Selecciona  una opcion del menu: ");
		cin>>opc;
	
		switch(opc)
		{
			case 1: system("cls");
					cout<<"MODULO DE CAPTURA DE PRODUCTOS"<<endl;
					//Captura de productos
					do{
							if(pos<tam)
								{
									cout<<"Producto #["<<(pos+1)<<"]"<<endl;
									cout<<"Ingrese producto....: ";
									cin>>productos[pos];
									cout<<"precio del producto: $";
									cin>>precio[pos];
									codigo [pos]=(pos+1);
								} //Fin if
								else
								{
									cout<<"El almacen esta lleno"<<endl;
								} // Fin else
								pos++; // Incremento de pos
								cout<<"Quiere ingresar otro producto? [S] [N]"<<endl;
									cin>> np;
					}while(np == "s" || np == "S"); // || -> es para agregar otra condicion or, o,
					
					system("pause");
					break;
					
			case 2: system("cls");
					cout<<"MODULO REPORTE DE PRODUCTOS"<<endl;
					for(int i=0; i<pos; i++)
					{
						cout<<"Producto #["<<(i+1)<<"]"<<endl;
						cout<<"Referencia: "<<(codigo[i])<<endl; 
						cout<<"Productos.: "<<(productos[i])<<endl;
						cout<<"Precio....: "<<(precio[i])<<endl;
						cout<<endl;
					} //Fin for
				
					system("pause");
					break;
					
			case 3: system("cls");
					cout<<"Modulo Buscar productos"<<endl;
					cout<<"Referencia del producto buscado: ";
					cin>>bus;
					
					for(int i=0; i<pos; i++)
					{
						// Comparación
						if(bus==codigo[i])
						{
							pr= i;
							bandera=true;
							break;
						}
						else
						{
							bandera=false;
						} //Fin else
					} //Fin for
					// Validar bendera
					if(bandera==true)
					{
						cout<<"El producto si existe"<<endl;
						cout<<"Producto #["<<(pr+1)<<"]"<<endl;
						cout<<"Referencia: "<<(codigo[pr])<<endl; 
						cout<<"Productos.: "<<(productos[pr])<<endl;
						cout<<"Precio....: "<<(precio[pr])<<endl;
						cout<<endl;
					}
					else
					{
						cout<<"El producto buscado no existe"<<endl;
					}
					
					system("pause");
					break;
					
			case 4: system("cls");
					cout<<"Modulo modificar producto"<<endl;
					
					//Buscar
					cout<<"Referencia del producto buscado: ";
					cin>>bus;
					
					for(int i=0; i<pos; i++)
					{
						// Comparación
						if(bus==codigo[i])
						{
							pr= i;
							bandera=true;
							break;
						}
						else
						{
							bandera=false;
						} //Fin else
					} //Fin for
					// Validar bendera
					if(bandera==true)
					{
						cout<<"El producto si existe"<<endl;
						cout<<"Producto #["<<(pr+1)<<"]"<<endl;
						cout<<"Referencia: "<<(codigo[pr])<<endl; 
						cout<<"Productos.: "<<(productos[pr])<<endl;
						cout<<"Precio....: "<<(precio[pr])<<endl;
						cout<<endl;
						
						//Modificar producto
						cout<<"Ingrese los datos a modificar:"<<endl;
						cout<<"Producto #["<<(pr+1)<<"]"<<endl;
						cout<<"Ingrese producto....: ";
						cin>>productos[pr];
						cout<<"precio del producto: $";
						cin>>precio[pr];
						cout<<"******************************************"<<endl;
						cout<<"* El producto se actualizo correctamente *"<<endl;
						cout<<"******************************************"<<endl;
					}//Fin if
					else
					{
						cout<<"El producto buscado no existe"<<endl;
					}//Fin else
					
					system("pause");
					break;		
					
			case 5: system("cls");
					cout<<"Salir"<<endl;
					system("pause");
					break;			
					
			default: system("cls"); 
					cout<<"Opcion no valida"<<endl;
					system("pause");
					break;
		} //Fin switch
	
	}while(opc!=5);
	
	getch();
	return 0;
}
