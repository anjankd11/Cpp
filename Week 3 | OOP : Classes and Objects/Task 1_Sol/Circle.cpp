//implementation of the header file's methods or constructors 

#include <iostream>
#include "Circle.h"

#define pi 3.141592654


using namespace std;

//defining constructors for circle class 

circle::circle() { R = 0; }            //in case no value provided then the radius will be zero

circle::circle(double pR) { R = pR; }  // one parameter for the radius 

void circle::print() {

	if (R > 0) {                      //circle with parameter of positive radius

		cout << "Radius of the circle is " << R << endl <<
			    "Area of the circle is " << pi * R * R << endl <<
			    "Circumference of the circle is " << 2 * pi * R << endl << endl;

              }

	else {                           //circle with parameter of zero, negative and no radius parameter input 

		cout << "Your input is invalid. Please provide values greater than zaro to build a valid circle. Thank you." << endl << endl;
	}
}