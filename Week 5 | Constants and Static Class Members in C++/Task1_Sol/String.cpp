#include"String.h"

using namespace HomeMadeString; // as there is no other user defined namespace here so declaring it like this

using namespace std;

String::String() { // default constructor

	elementNum = 0; //as default making the string with zero element and pointing to null
	pData = NULL;

 
}


String::String(const String &newstr) { // copy contructor

	this->elementNum = newstr.elementNum; // getting the number of elements 
	this->pData = new char[elementNum + 1]; // allocating dynamic memory for the new string

	for (int i = 0; i < elementNum; i++) {

		this->pData[i] = newstr.pData[i]; //copying all the elements 
	}
}

String::String(const char* characters) { // conversion constructor that turns characters into a string

	int n = 0;

	while (characters[n] != '\0') { // counting how many characters are there 

		n = n + 1;
	}
	this->elementNum = n;
	this->pData = new char[n]; // DMA for that number of characters

	for (int i = 0; i < elementNum; i++) {

		this->pData[i] = characters[i]; //copying all the elements 
	}
}

String::String(const char c, const int times) { //constructor creates a string that contains 'times' pieces of the character c

	int i;

	pData = new char[times];

	for ( i = 0; i < times;  i++) {

		pData[i] = c;

	}
	elementNum = times;
}


void String::getStr(char* pBuff) const  { //copying the string into buffer

	for (int i = 0; i < elementNum; i = i + 1) {

		pBuff[i] = pData[i];
	}
	pBuff[elementNum] = '\0';  //terminates it with '\0'
		
		
}

void String::print(std::ostream& os) const//printing the string
{
	for ( int i = 0; i < elementNum; i++)
	{
		cout << pData[i];
	}
}

char String::getChar(const int pos) const { // getting a specific character from the string
  
	if ((pos >= 0) && (pos < elementNum)) //tthe specific character's posotion should be in between zero and the number of elements
		return pData[pos];

	else return 0;
	 
}

String String::concatenate(String& string1, String& string2) {

	String newstring;  // creating a new string class object

	newstring.elementNum = string1.elementNum + string2.elementNum; //the number of element in the new string should be the addiotion of the other two string
	newstring.pData = new char[newstring.elementNum]; // DMA for the new string

	int n = 0;

	for (int i = 0; i < string1.elementNum; i = i + 1) { // copying the elements of string1 into the new string
		newstring.pData[i] = string1.pData[i];
		
		n = n + 1; // counting the elements in string1 and later use it as the beginning index of string2
	}
	

	for (int i = n; i < newstring.elementNum; i = i + 1) { // copying the elements of string2 into the new string
		newstring.pData[i] = string2.pData[i-n];
		
	
	}

	return String(newstring); // returning the concatenated string 
}

bool String::compare(String string1, String string2) {

	int n = 0;

	if (string1.elementNum == string2.elementNum) { //only compare if the number of elements in both string are same
		for (int i = 0; i < string1.elementNum; i = i + 1)
		{
			while (string1.pData[i] != string2.pData[i]) {
				n = n + 1; // if any dissimilarity found n will increase, eventually return false
			}
		}
		if (n == 0) return true;
		else return false;


	}
	else return false;

}

void String::copy(String& string1, String string2) { //copying string2 to string1

	delete[] string1.pData; //first releasing the memeory what string1 holds

	string1.elementNum = string2.elementNum;

	string1.pData = new char[string1.elementNum]; //DMA with the size of string2
	for (int i = 0; i <= string1.elementNum; i++) {
		string1.pData[i] = string2.pData[i];
	}
}





