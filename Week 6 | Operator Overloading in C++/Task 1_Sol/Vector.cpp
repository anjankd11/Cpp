#include "Vector.h"

Vector::Vector(const Vector& theOther) { //copy constructor
	
	//*this = theOther; we can use only this operator= function instead of all the next lines 

	elementNum = theOther.elementNum; //getting the number of elements of the new vector
	


	pData = new int[elementNum]; // DMA for the vector according to it's number of elements 

	for (int i = 0; i < elementNum; i = i + 1) {

		pData[i] = theOther.pData[i]; //copying elements 
	}
}

void Vector::clear() {  //clearing an existing array
	delete[]pData;      //releasing all the assigned memory blocks first  
	elementNum = 0;     
	pData = NULL;
}

void Vector::erase(unsigned int position) { // erases (deletes) the array element with the given index;

	if (position < 0 || position >= elementNum) { //exception handling, because there are no postion less  than zero and more than the element numbers

		throw "Give a valid index";
	}
	else {
		int* temp = new int[elementNum - 1]; //DMA with one element less becasue it will be erased 

		int j = 0;

		for (int i = 0; i < elementNum; i = i + 1) {
			if (i != position) { // copying all the other elements in the new array except the index to be erased 
				temp[j] = pData[i];
				j = j + 1;
			}
		}
		delete[]pData; // deleting the previous memory blocks
		pData = temp;  // pointing to the new array 
		elementNum = elementNum - 1; // one element erased 


	}
}

int& Vector::at(unsigned int position) {// returns the array element with the given index

	if (position < 0 || position >= elementNum) { //exception handling, because there are no postion less  than zero and more than the element numbers

		throw "Give a valid index";
	}
	else {
		return pData[position]; // retunring the data in that position
	}
}

const int& Vector::at(unsigned int position)const { // returns the array element with the given index, without possibility to modify the element because of const

	if (position < 0 || position >= elementNum) {

		throw "Give a valid index";
	}
	else {
		return pData[position];
	}
}

bool Vector::insert(unsigned int position, int element) { // inserts a new element into a place with the given index

	if (position < 0) {   // position can't be less than zero

		throw "Give a valid index";
		return false;
	}

	if (position <= elementNum) { // when position in between the number of elements

		int* temp = new int[elementNum + 1]; //DMA with a increasing element

		for (int i = 0; i < position; i = i + 1) {
			temp[i] = pData[i];  // copying all the elements before the position
		}
		temp[position] = element; // copying the element into the position 

		for (int i = position + 1; i <= elementNum; i = i + 1) {
			temp[i] = pData[i-1];  // copying all the remaining elements 
		}

		delete[]pData;
		pData = temp;
		elementNum = elementNum + 1;
		return true;
	}

	if (position > elementNum) { // when position is larger than the number of elements
		int* temp = new int[position + 1]; // DMA accorging to position, because that will be the last index

		for (int i = 0; i < elementNum; i = i + 1) {
			temp[i] = pData[i]; // copying all the elements of the previous array
		}
		for (int i = elementNum; i < position; i = i + 1) {
			temp[i] = 0; // putting zero in all the new indices before postiton
		}
		temp[position] = element; // copying the element into the position 
		delete[]pData;
		pData = temp;
		elementNum = position + 1;
		return true;
	}
}

const Vector& Vector::operator=(const Vector& theOther) { //operatot = overloading

	if (this == &theOther) // if the vectors are same returning the vector
		return *this;
	else {                                 // same functionality as copy constructor
		elementNum = theOther.elementNum; 
		delete[]pData;                     // except here we need to release the old memory
		pData = new int[elementNum];

		for (int i = 0; i < elementNum; i = i + 1) {
			pData[i] = theOther.pData[i];
		}
		return *this;
 	}
}

int& Vector::operator [](unsigned int position) { // same functionality like at function
	return at(position);
}

const int& Vector::operator [](unsigned int position)const {
	return at(position);
}

std::ostream& operator << (std::ostream& os, const Vector& v) { // global function for printing vector data

	if (v.pData == NULL) return os;  // if null vectore just return

	else {
		for (int i = 0; i < v.elementNum; i = i + 1) {
			os << v.pData[i] << " ";                  // printing all the elements

		}
		return os;
	}

}


void Vector::sort() {  // this is ascending sorting function
		
int temp;
        for (int i = 0; i < elementNum; i=i+1){
		
			for (int j = i+1; j < elementNum; j=j+1){
			
				if (pData[i] > pData[j]){  // if later index element is greater than previous one
				
					temp = pData[i];      // copy the previous element into a temporary varible
					pData[i] = pData[j];  //put the later element into the index of previous element
					pData[j] = temp;      // now putting the previous element from temporary variable to the later element index
				}
			}
		}

	}


	





