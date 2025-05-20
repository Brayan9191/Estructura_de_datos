#include<iostream>
#include<conio.h>

using namespace std;

struct Producto
{
	string nombre;
	float precio;
	int cantidad;
};	//	Fin Producto

struct Categoria 
{
	string nomCategoria;
	Producto producto[3];
	int total_productos;
};	//	Fin Categoria

//	Crear la funcion de insertar producto
void insertar_producto(Categoria &cat) 	// & <- Puntero para la funcion
{
	cout<<" Modulo Insertar producto\n";
	//	Valodar cantidad de productos
	if(cat.total_productos >= 3)
	{
		cout<<"Se lleno el almacen de productos\n";
		return;
	}	//	Fin if
	
	//	Insertar producto
	Producto nuevo;
	cout<<"Nombre del producto: "; 
	cin.ignore();
	getline(cin,nuevo.nombre);
	
	cout<<"Precio: $";
	cin>>nuevo.precio;
	
	cout<<"Cantidad: ";
	cin>>nuevo.cantidad;
	
	//	Autoincrementar total productos
	cat.producto[cat.total_productos++] = nuevo;
	cout<<"Producto insertado correctamente"<<endl;
}	//	Fin Funcion Insertar

// Crear la funcion de buscar producto
void buscar_producto(const Categoria &cat)
{
	cout<<" Modulo Buscar producto\n";
	
	string bus;
	bool encontrado=false;
	cout<<"Producto a buscar: ";
	cin.ignore();
	getline(cin,bus);
	//	Recorrer estructura categoria
	for(int i=0; i<cat.total_productos; i++)
	{
		//	Comparar el producto buscado
		if(cat.producto[i].nombre == bus) 
		{
			cout<<"\nProducto encontrado\n";
			cout<<"producto: "<<cat.producto[i].nombre<<endl;
			cout<<"producto: "<<cat.producto[i].precio<<endl;
			cout<<"producto: "<<cat.producto[i].cantidad<<endl;
			//	Romper el ciclo de busqueda
			encontrado = true;
			break;
		}	//	Fin if
	}	//	Fin for
	
	//	Validar si no existe
	if(!encontrado)
	{
		cout<<"Producto no encontrado o no existe\n";
	}	//	Fin if
	
}	//	Fin funcion buscar 

//	Crear funcion de modificar producto
void modificar_producto(Categoria &cat)
{
	cout<<" Modulo Modificar producto\n";
	
	string bus;
	bool encontrado=false;
	cout<<"Producto a modificar: ";
	cin.ignore();
	getline(cin,bus);
	//	Recorrer estructura categoria
	for(int i=0; i<cat.total_productos; i++)
	{
		//	Comparar el producto buscado
		if(cat.producto[i].nombre == bus) 
		{
			cout<<"\nProducto encontrado\n";
			cout<<"Ingrese los nuevos datos\n";
			cout<<"Nombre producto nuevo: ";
			cin>>cat.producto[i].nombre;

			cout<<"Precio nuevo: ";
			cin>>cat.producto[i].precio;
			
			cout<<"Cantidad nuevo: ";
			cin>>cat.producto[i].cantidad;
			
			//	Romper el ciclo de busqueda
			encontrado = true;
			break;
		}	//	Fin if
	}	//	Fin for
	
	//	Validar si no existe
	if(!encontrado)
	{
		cout<<"Producto no encontrado o no existe\n";
	}	//	Fin if
	
}	//	Fin funcion modificar 

//	Crear funcion de eliminar producto
void eliminar_producto(Categoria &cat)
{
	cout<<" Modulo eliminar producto\n";
	
	string bus;
	bool encontrado=false;
	cout<<"Producto a eliminar: ";
	cin.ignore();
	getline(cin,bus);
	//	Recorrer estructura categoria
	for(int i=0; i<cat.total_productos; i++)
	{
		//	Comparar el producto buscado
		if(cat.producto[i].nombre == bus) 
		{
			for(int j=i; j<cat.total_productos -1; j++)
			{
				cat.producto[j] = cat.producto[j+1];
				
			}	//	Fin for
			cat.total_productos--;
			cout<<"Producto eliminado\n";
			//	Romper el ciclo de busqueda
			encontrado = true;
			break;
		}	//	Fin if
	}	//	Fin for
	
	//	Validar si no existe
	if(!encontrado)
	{
		cout<<"Producto no encontrado o no existe\n";
	}	//	Fin if
}

//	Crear funcion de mostrar productos
void mostrar_productos(const Categoria &cat)
{
	cout<<" Modulo Mostrar productos\n";
	cout<<"Producto en la categoria "<<cat.nomCategoria<<endl;
	for(int i=0; i<cat.total_productos; i++)
	{
		cout<<i+1<<"."<<cat.producto[i].nombre
		<<" - $"<<cat.producto[i].precio
		<<" - Cantidad: "<<cat.producto[i].cantidad<<endl;
	}	//	Fin for
	//	Validar si hay productos
	if(cat.total_productos == 0)
	{
		cout<<"No hay productos en existencia\n";
	}
}	//	Fin mostrar


int main()
{
	//declarar variables
	int opc;
	
	//	Alias Categoria
	Categoria categoria_pan;
	categoria_pan.nomCategoria = "Bizcochos";
	categoria_pan.total_productos = 0;
	
	//Menu
	do
	{
		cout<<" MENU DE PANADERIA\n";
		cout<<"	1. Insertar producto\n";
		cout<<" 2. Buscar producto\n";
		cout<<" 3. Modificar producto\n";
		cout<<" 4. Eliminar producto\n";
		cout<<" 5. Mostrar productos\n";
		cout<<" 0. Salir\n"<<endl;
		cout<<"Selecciones una opcion: ";
		cin>>opc;
		//	Validar opcion
		switch(opc)
		{
			case 1: system("cls"); insertar_producto(categoria_pan); system("pause"); break;
			case 2: system("cls"); buscar_producto(categoria_pan); system("pause"); break;
			case 3: system("cls"); modificar_producto(categoria_pan); system("pause"); break;
			case 4: system("cls"); eliminar_producto(categoria_pan); system("pause"); break;
			case 5: system("cls"); mostrar_productos(categoria_pan); system("pause"); break;
			case 0: system("cls"); cout<<" salir\n";
			default:  ;
		}//	Fin switch
	}while(opc!=0);
	
	getch();
	return 0;
} //Fin main
