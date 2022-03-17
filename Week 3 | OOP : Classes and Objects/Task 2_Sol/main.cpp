// LAB04_TASK01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rectangle.h"


int main()
{
	rectangle rect1(5,10);    //different and positive parameter
	rect1.print();

	rectangle rect2(5);       //same and positive parameter 
	rect2.print();

	rectangle rect3(-5, 10);  //negative parameter
	rect3.print();

	rectangle rect4(0,0);       // zero as parameter
	rect3.print();

	rectangle rect5;         //no input
	rect5.print();

	return 0;

}

