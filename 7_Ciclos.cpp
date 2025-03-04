#include<iostream>
#include<conio.h>

using namespace std;

	int i = 1; //Valor consecutivo
	int j = 1;
	int z = 1;
	
int main()
{
	cout<<"\nEjemplo de for\n"<<endl;
	for(i=1; i<= 3; i++)  //for(Valor consecutivo; Condicion; incremento / Decremento);
	{
		cout<<i<<endl;
	} //Fin for
	
	cout<<"\nEjemplo de while\n"<<endl;	
	while(j<=3) //while(Condicion);
	{
		cout<<j<<endl;
		j++;
	} //Fin while 
	
	cout<<"\nEjemplo de do while\n"<<endl;	
	do
	{
		cout<<z<<endl;
		z++;
	} while(z<=3); //Fin do while
	
	getch();
	return 0;
} //Fin main

