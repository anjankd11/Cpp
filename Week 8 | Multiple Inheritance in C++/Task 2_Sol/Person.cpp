

#include "Person.h"
#include <iostream>
#include <fstream>
using namespace std;

// Implementation of ISerializable::Save
void Person::Save(std::ostream& os)
{
    os << (int)age << ';' << height << ';' << weight << endl;
}

// Implementation of ISerializable::Load 
void Person::Load(std::istream& is)
{
    double height; double weight; int age; char c;
    is >> age;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> height;
    is >> c;
    if (c != ';') is.clear(ios::failbit);
    is >> weight;
    if (is)
    {
        this->age = age;
        this->height = height;
        this->weight = weight;
    }
    else
    {
        cerr << "Error in input format." << endl;
    }


    // Write implementation for other member functions

    
}
void Person::SetHeight( double height) {this->height = height;} //getting the height

double Person::GetHeight(){return height;}  // returning the height

void Person::SetWeight(double weight) {this->weight = weight;} //getting the weight

double Person::GetWeight() {return weight;}  //returning the weight

// Comparing with another Person object (equal?)
bool Person::operator ==(const IComparable& theOther) 
{
    Person* temp = (Person*)(&theOther); // getting the value into a temporary variable

    if (height == temp->height && age == temp->age && weight == temp->weight) return true; // if all the attributes are same then it's the same person
    else return false;

}
// Comparing with another Person object (less?)
bool Person::operator >(const IComparable& theOther)
{
    Person* temp = (Person*)(&theOther);
    if (age > temp->age) return true;     // implemented based on the attribute age
    else return false;
}

