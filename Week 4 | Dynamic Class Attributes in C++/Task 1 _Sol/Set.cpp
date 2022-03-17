#include<iostream>
#include<stdlib.h>
#include"Set.h"

using namespace std;


Set::Set() {           //default constructor which will initialize the number of elements as zero and a NULL pointer

	elementNum = 0;
	pData = NULL;
}

Set::Set(const Set& theOther) {   //copy constructor

	elementNum = theOther.elementNum; //getting the number of elements 

	pData = new int[elementNum]; //dynamic allocation of memory to store exact number of elements

	for (int i = 0; i < elementNum; i = i + 1) {

		pData[i] = theOther.pData[i]; //copying elements 
	}

}

Set::~Set() { //destructor with dynamic release

	delete(pData);
}

bool Set::isElement(int element) { //returns true if the element is found

	for (int i = 0; i < elementNum; i = i + 1) {

		if (pData[i] == element)  //searching one by one element to find
			return true;          // found
	}
	return false;                //not found
}

bool Set::insert(int element) {// inserts a new elemnts

	if (isElement(element) == true)
		return true;  //returns true if the element is already in the set
	else {

		int* copy = new int[elementNum + 1]; //creating a bigger array to copy all the elements with the new one

		for (int i = 0; i < elementNum; i = i + 1) { 
			copy[i] = pData[i]; //copiyng all the exisitng elements
		}
		copy[elementNum] = element; // putting the new element in the end
		delete(pData);  //releasing the old array
		pData = copy;   //now the pointer points to the new array
		elementNum = elementNum + 1; // number of elemnts increased by one
		return false;

	}
}

bool Set::remove(int element) { // removes a element

	if (isElement(element) == false) { // if the element is not found returns false
		return false;
	}
	else {
		int j = 0;
		int* copy = new int[elementNum - 1];// creating smaller array by one as one element wil be removed

		for (int i = 0; i < elementNum; i = i + 1) {
			if (pData[i] != element) {//copying all the elementd into the smaller new array except one to remove
				copy[j] = pData[i];
				j = j + 1;
			}
		}
		delete (pData);//releasing the old array
		pData = copy;//now the pointer points to the new array
		elementNum = elementNum - 1;
		return true;// number of elemnts decreased by one

	}

}

void Set::print() { // printing all the elements 

	if (elementNum == 0) {// first checking if the set is empty
		cout << "The set is empty";
	}
	else
	{
		cout << endl;
		for (int i = 0; i < elementNum; i = i + 1) {
			cout << pData[i] << " " ;

		}
		cout << endl;
	}
}

void Set::empty() {
	delete[]pData;
	elementNum = 0;
	pData = NULL;
}
