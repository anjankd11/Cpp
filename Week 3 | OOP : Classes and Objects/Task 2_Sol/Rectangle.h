//declaration of class , it's attributes and methods or constructors 

class rectangle {

private:                              //should not be accessible from outside the class
	double a, b;

public:
	rectangle(double pa, double pb); // 3 types of constructors for different input parameters which are defined in Rectangle.cpp 
	rectangle(double pa);
	rectangle();

	void print();                    //function that prints all information about the rectangle: its sides, area and perimeter values


};