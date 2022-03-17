//implementation of the header file's methods or constructors 

#include <iostream>
#include "Rectangle.h"


using namespace std;

//defining constructors for rectangle class 

rectangle::rectangle(double pa, double pb) { a=pa; b=pb; } //both side provided by the user,default rectangle

rectangle::rectangle(double pa) { a = pa; b = pa; }        //one side provided,square

rectangle::rectangle() { a = 0; b = 0; }                   //no iput parameter


void rectangle::print() {                                  //prints all information about the rectangle: its sides, area and perimeter values


	if (a > 0 && b > 0 && a != b) {                        //rectangle with positive but different value of sides 

		cout << "This is a regular rectangle whose two sides are different." << endl <<
			"The value of one side is " << a << " and the value of other side is " << b << endl <<
			"Perimeter of the rectange is " << 2 * (a + b) << endl <<
			"Area of the rectangle is " << (a * b) << endl << endl; 
		
	}
	else if (a > 0 && b > 0 && a == b) {                 //rectangle with positive but same value of sides 

		cout << "This is a rectangle whose two sides are same, so this is a square." << endl <<
			"The value of two sides is " << a  << endl <<
			"Perimeter of the square is " << 2 * (a + b) << endl <<
			"Area of the rectangle is " << (a * b) << endl << endl;
	}
	else {                                             //for zero, negative and no input value

		cout << "Your input is invalid. Please provide values greater than zaro to build a valid rectangle. Thank you." << endl << endl;
	}


}