#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	// Salida de datos
	cout<<"3 < 4 and 2==2 es "<<(3<4 and 2==2)<<endl; // V and V = V
	cout<<"4 > 3 and 2==1 es "<<(4>3 and 2==1)<<endl; // V and F = F
	cout<<"4 < 3 and 2==2 es "<<(4<3 and 2==2)<<endl; // F and V = F
	cout<<"4 < 3 and 2==1 es "<<(4<3 and 2==1)<<endl<<endl; // F and F = F
	
	cout<<"3 < 4 or 2==2 es "<<(3<4 or 2==2)<<endl; // V or V = V
	cout<<"4 > 3 or 2==1 es "<<(4>3 or 2==1)<<endl; // V or F = V
	cout<<"4 < 3 or 2==2 es "<<(4<3 or 2==2)<<endl; // F or V = V
	cout<<"4 < 3 or 2==1 es "<<(4<3 or 2==1)<<endl; // F or F = F
	
	getch();
	return 0;
} //Fin main
