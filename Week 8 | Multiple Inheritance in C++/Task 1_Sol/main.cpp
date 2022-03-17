#include "Person.h"
#include "IComparable.h"
#include "Sorter.h"
#include <fstream>

using namespace std;


//Test the implemented classes here
int main()
{
	// Creating the array of Persons
	const unsigned maxPeople = 4;
	Person* people[maxPeople];

	people[0] = new Person(12, 100, 50);
	people[1] = new Person(30, 180, 85);
	people[2] = new Person(40, 182, 90);
	people[3] = new Person(40, 182, 90);


	// Mybe you will have to modify the path if restricted by your machine
	const char* fname = "data.txt";

	// Save the array of Persons to external file
	ofstream os(fname);
	if (!os)
	{
		cerr << "Error opening output file: " << fname << endl;
		return -1;
	}

	for (unsigned int i = 0; i < maxPeople; i++)
	{
		// Testing Save function
		people[i]->Save(os);

		// Testing attributes and getters/setters of Person class
		people[i]->age = 0;
		people[i]->SetHeight(20);
		people[i]->SetWeight(10);
	}

	os.close();
	if (!os)
	{
		cerr << "Error closing output file: " << fname << endl;
		return -1;
	}

	// Load the array of Persons from external file
	ifstream is(fname);
	if (!is)
	{
		cerr << "Error opening input file: " << fname << endl;
		return -1;
	}

	for (unsigned int j = 0; j < maxPeople; j++)
	{
		// Testing Load function
		people[j]->Load(is);
	}

	is.close();
	if (!is)
	{
		cerr << "Error closing input file: " << fname << endl;
		return -1;
	}

	// Test the 'equal' comparison (operator==)
	if (!(*people[2] == *people[3]))
		return -1;

	// Test the 'greater than' comparison (operator>)
	if (*people[1] > *people[2])
		return -1;

	// Put a breakpoint here. If execution reaches this point without errors, the mandatory Task 1 is done successfully.

	// TASK 2 (optional): Sorting

	// Writing original Persons
	cout << "Original 'Person' objects:" << endl;
	for (int i = 0; i < maxPeople; ++i)
	{
		cout << "Person #" << i + 1 << ": " << "age " << (int)people[i]->age << "; weight " << people[i]->GetWeight()
			<< "; height " << people[i]->GetHeight() << "." << endl;
	}

	 //Sorting the array
	Sorter::BubbleSort((IComparable**)people, maxPeople);

	// Writing sorted Persons
	cout << endl << endl << "Sorted 'Person' objects:" << endl;
	for (int i = 0; i < maxPeople; ++i)
	{
		cout << "Person #" << i + 1 << ": " << "age " << (int)people[i]->age << "; weight " << people[i]->GetWeight()
			<< "; height " << people[i]->GetHeight() << "." << endl;
	}

	//	 Releasing memory
	for (unsigned int k = 0; k < maxPeople; k++)
	{
		delete people[k];
	}

	// Put a breakpoint here.
	// Check the output on the screen. If 'Person' objects are sorted in descending order, the Task 2 is done successfully.
	return 0;
}

