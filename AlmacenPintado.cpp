#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>

#define color SetConsoleTextAttribute


using namespace std;

//Codigo de color 
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


//Codigo gotoxy
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 

int main()
{	
	//Declarar variables
	int opc, tam = 4, pos = 0, bus, pr;
	int o=2, z=0;
	string np; // Para anadir nuevo producto
	bool bandera; 
	
	//Declarar vectores
	string productos[tam];
	int codigo[tam];
	int precio[tam];
	
	do
	{
		//Salida a pantalla
		system("cls");
		color(hConsole, 3);								//Azul clarito - 3
		cout<<("Almacen de cadena")<<endl;
		color(hConsole, 2);								//Verde - 2
		cout<<("1. Capturar productos")<<endl;
		color(hConsole, 5);								//Morado - 5
		cout<<("2. Reportes de productos")<<endl;
		color(hConsole, 10);							//Verde claro - 10
		cout<<("3. Buscar producto")<<endl;
		color(hConsole, 6);								//Naranja_Amarrollo - 6
		cout<<("4. Modificar producto")<<endl;
		color(hConsole, 4);								//rojo - 4
		cout<<("5. Salir")<<endl;
		color(hConsole, 12);							//Rosa - 12
		cout<<("Selecciona  una opcion del menu: ");
		cin>>opc;
	
		switch(opc)
		{
			case 1: system("cls");
					//Captura de productos
					color(hConsole, 2);
					do{
							if(pos<tam)
								{
									//Cuerpo de la tabla
									for(int i=1; i<=60; i++)
									{
										gotoxy(i, 0);
										cout<<"-";
										gotoxy(i, 2);
										cout<<"-";
										gotoxy(i, 4);
										cout<<"-";
										gotoxy(i, 6);
										cout<<"-";
										gotoxy(i, 8);
										cout<<"-";
									}//Fin if
									for(int i=0; i<9; i++)
									{
										gotoxy(1, i);
										cout<<"|";
										if(o<9)
										{
										gotoxy(30, o); o++;
										cout<<"|";
										}//Fin if
										gotoxy(60, i);
										cout<<"|";
									}//Fin if
									
									gotoxy(15, 1);
									cout<<"MODULO DE CAPTURA DE PRODUCTOS"<<endl;
									codigo [pos]=(pos+1);
									gotoxy(2, 3);
									cout<<"Referancia"<<endl;
									gotoxy(2, 5);
									cout<<"Producto"<<endl;
									gotoxy(2, 7);
									cout<<"precio del producto";
									
									gotoxy(32, 3);
									cout<<codigo[pos];
									gotoxy(32, 5);
									cin>>productos[pos];
									gotoxy(32, 7);
									cout<<"$";
									gotoxy(33, 7);
									cin>>precio[pos];
								} //Fin if
								else
								{
									cout<<"El almacen esta lleno"<<endl;
								} // Fin else
								pos++; // Incremento de pos
								
								gotoxy(1, 10);
								cout<<"Quiere ingresar otro producto? [S] [N]"<<endl;
								gotoxy(1, 11);
									cin>> np;
								system("cls");
								o=2;
					}while(np == "s" || np == "S"); // || -> es para agregar otra condicion or, o,
					
					system("pause");
					break;
					
			case 2: system("cls");
					color(hConsole, 5);
					
					for(int i=0; i<pos; i++)
					{
						//Cuerpo de la tabla
						for(int i=1; i<=60; i++)
						{
							gotoxy(15, 1);
							cout<<"MODULO REPORTE DE PRODUCTOS"<<endl;
							
							gotoxy(i, 0);
							cout<<"-";
							gotoxy(i, 2);
							cout<<"-";
							gotoxy(i, 4);
							cout<<"-";
							gotoxy(i, 6);
							cout<<"-";
							gotoxy(i, 8);
							cout<<"-";
						}//Fin for
						for(int i=0; i<9; i++)
						{
							gotoxy(1, i);
							cout<<"|";
							if(o<9)
							{
								gotoxy(30, o); o++;
								cout<<"|";
							}//Fin if
							gotoxy(60, i);
							cout<<"|";
						}//Fin if
						
						gotoxy(2, 3);
						cout<<"Referancia"<<endl;
						gotoxy(32, 3);
						cout<<(z+1);
						gotoxy(2, 5);
						cout<<"Producto"<<endl;
						gotoxy(32, 5);
						cout<<(productos[z]);
						gotoxy(2, 7);
						cout<<"precio del producto";
						gotoxy(32, 7);
						cout<<"$"<<(precio[z]);		
						
						z += 1;
						o = 2;
						
						gotoxy(1, 10);
						
						system("pause");
						system("cls");
					} //Fin for
					
					z = 0;
					
					system("pause");
					break;
					
			case 3: system("cls");
					cout<<"Modulo Buscar productos"<<endl;
					cout<<"Referencia del producto buscado: ";
					cin>>bus;
					
					for(int i=0; i<pos; i++)
					{
						// Comparacion
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
						color(hConsole, 2);
						cout<<"El producto si existe"<<endl;
						system("pause");
						system("cls");
						
						color(hConsole, 6);
						gotoxy(15, 1);
						cout<<"MODULO Buscar producto"<<endl;
						
						//Cuerpo de la tabla
						for(int i=1; i<=60; i++)
						{								
							gotoxy(i, 0);
							cout<<"-";
							gotoxy(i, 2);
							cout<<"-";
							gotoxy(i, 4);
							cout<<"-";
							gotoxy(i, 6);
							cout<<"-";
							gotoxy(i, 8);
							cout<<"-";
						}//Fin if
						for(int i=0; i<9; i++)
						{
							gotoxy(1, i);
							cout<<"|";
							if(o<9)
							{
								gotoxy(30, o); o++;
								cout<<"|";
							}//Fin if
							gotoxy(60, i);
							cout<<"|";
						}//Fin if
						
						gotoxy(2, 3);
						cout<<"Referencia";
						gotoxy(32, 3);
						cout<<(codigo[pr]);
						gotoxy(2, 5);
						cout<<"Productos";
						gotoxy(32, 5);
						 cout<<(productos[pr]);
						gotoxy(2, 7);
						cout<<"Precio";
						gotoxy(32, 7);
						cout<<(precio[pr]);
					}
					else
					{
						color(hConsole, 4);
						cout<<"El producto buscado no existe"<<endl;
					}
					
					gotoxy(1, 10);
					
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
						color(hConsole, 2);
						cout<<"El producto si existe"<<endl;
						system("pause");
						system("cls");
						
						color(hConsole, 6);
						gotoxy(15, 1);
						cout<<"MODULO Buscar producto"<<endl;
						
						//Cuerpo de la tabla
						for(int i=1; i<=60; i++)
						{								
							gotoxy(i, 0);
							cout<<"-";
							gotoxy(i, 2);
							cout<<"-";
							gotoxy(i, 4);
							cout<<"-";
							gotoxy(i, 6);
							cout<<"-";
							gotoxy(i, 8);
							cout<<"-";
						}//Fin if
						for(int i=0; i<9; i++)
						{
							gotoxy(1, i);
							cout<<"|";
							if(o<9)
							{
								gotoxy(30, o); o++;
								cout<<"|";
							}//Fin if
							gotoxy(60, i);
							cout<<"|";
						}//Fin if
						
						gotoxy(2, 3);
						cout<<"Referencia";
						gotoxy(32, 3);
						cout<<(codigo[pr]);
						gotoxy(2, 5);
						cout<<"Productos";
						gotoxy(32, 5);
						cout<<(productos[pr]);
						gotoxy(2, 7);
						cout<<"Precio";
						gotoxy(32, 7);
						cout<<"$"<<(precio[pr]);
						
						//Modificar producto
						//Cuerpo de la tabla
						for(int i=1; i<=60; i++)
						{
							gotoxy(i, 0);
							cout<<"-";
							gotoxy(i, 2);
							cout<<"-";
							gotoxy(i, 4);
							cout<<"-";
							gotoxy(i, 6);
							cout<<"-";
							gotoxy(i, 8);
							cout<<"-";
						}//Fin if
						for(int i=0; i<9; i++)
						{
							gotoxy(1, i);
							cout<<"|";
							if(o<9)
							{
								gotoxy(30, o); o++;
								cout<<"|";
							}//Fin if
							gotoxy(60, i);
							cout<<"|";
						}//Fin if
									
						gotoxy(15, 1);
						cout<<"MODULO MODIFICACION DE PRODUCTOS"<<endl;
						gotoxy(2, 3);
						cout<<"Referancia"<<endl;
						gotoxy(2, 5);
						cout<<"Producto"<<endl;
						gotoxy(2, 7);
						cout<<"precio del producto";
							
						gotoxy(32, 3);
						cout<<(codigo[pr]);
						gotoxy(32, 5);
						cin>>productos[pr];
						gotoxy(32, 7);
						cout<<"$";
						gotoxy(33, 7);
						cin>>precio[pr];

						gotoxy(1, 10);
						
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
	
	}while(opc!=5); //Fin do
	
	getch();
	return 0;
}
