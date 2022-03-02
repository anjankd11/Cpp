// LAB04_TASK02.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "Circle.h"

int main()
{
	circle circle1(5);    //positive parameter
	circle1.print();

	circle circle2(-5);  //negative invalid parameter
	circle2.print();

	circle circle3;     //no input
	circle3.print();

	circle circle4(0);  //zero as parameter
	circle4.print();



	return 0;
}

