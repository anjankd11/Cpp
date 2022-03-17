#ifndef PERSON_H
#define PERSON_H

#include "IComparable.h"
#include "ISerializable.h"
#include <iostream>

class Person : public IComparable, public ISerializable
{
	double height;
	double weight;
public:
	unsigned char age;

	// Constructor
	Person(unsigned char age, double height, double weight) : age(age), height(height), weight(weight) {}

	// Getters and setters
	void SetHeight(double height);
	double GetHeight();
	void SetWeight(double weight);
	double GetWeight();

	// Comparing with another Person object (equal?)
	bool operator ==(const IComparable& theOther);
	// Comparing with another Person object (less?)
	bool operator >(const IComparable& theOther);

	// Saving to file
	void Save(std::ostream&);
	// Loading from file
	void Load(std::istream&);
};
#endif PERSON_H
