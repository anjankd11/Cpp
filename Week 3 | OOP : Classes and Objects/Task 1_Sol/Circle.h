//declaration of class , it's attributes and methods constructors

class circle {

private:                            //should not be accessible from outside the class
	double R;          

public:
	circle();                       // 2 types of constructors for different input parameters which are defined in Circle.cpp
	circle(double pR); 

	void print();                   //function that prints all information about the rectangle: its sides, area and perimeter values

};


