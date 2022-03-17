#include<iostream>
#include<stdlib.h>
#include"Fifo.h"

using namespace std;


Set::Set() {

	elementNum = 0;
	pData = NULL;
}

Set::Set(const Set& theOther) {

	elementNum = theOther.elementNum;

	pData = new int[elementNum];

	for (int i = 0; i < elementNum; i = i + 1) {

		pData[i] = theOther.pData[i];
	}

}

Set::~Set() {

	delete(pData);
}

bool Set::isElement(int element) {

	for (int i = 0; i < elementNum; i = i + 1) {

		if (pData[i] == element)
			return true;
	}
	return false;
}

bool Set::push(int element) { // the push function is just the same one as the insert

	if (isElement(element) == true)
		return true;
	else {

		int* copy = new int[elementNum + 1];

		for (int i = 0; i < elementNum; i = i + 1) {
			copy[i] = pData[i];
		}
		copy[elementNum] = element;
		delete(pData);
		pData = copy;
		elementNum = elementNum + 1;
		return false;

	}
}

 int Set::pop() { // the main difference is with the pop function

	int popdata= pData[0]; // here we store the value of the first element and return it later
	
		
		int* copy = new int[elementNum - 1];

		int j = 0;

		for (int i = 1; i < elementNum; i = i + 1) {
			    copy[j] = pData[i];// copying all the elemts to a newer smaller array except the first elemnt 
				j = j + 1;
			
		}
		delete (pData);
		pData = copy;
		elementNum = elementNum - 1;

		return popdata;// returning the first element
		

}

void Set::print() {

	if (elementNum == 0) {
		cout << "The set is empty";
	}
	else
	{
		cout << endl;
		for (int i = 0; i < elementNum; i = i + 1) {
			cout << pData[i] << " ";

		}
		cout << endl;
	}
}
