#include <stdio.h>  
#include <windows.h>  

//Codogo gotoxy
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
 int main(){  
      gotoxy(15,10);  
      printf("*");  
      return 0;  
 }
