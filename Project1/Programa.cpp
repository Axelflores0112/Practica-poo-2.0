#include<conio.h>
#include "Figura.h"//libreia par inlcuir los elemtos del .h
#include<iostream>
using namespace std;
int main()
{
	Menu* menu[1];
	menu[0] = new Menu(0);
	menu[0]->eleccion();
} 
