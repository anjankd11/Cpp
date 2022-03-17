#include "String.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace TheUltimateString
{
	String::String()
	{
		pData = NULL;
		elementsNum = 0;
	}

	String::String(const String& string)
	{
		pData = NULL;
		copy(*this, string);
	}


	String::String(const char c, unsigned int times)
	{
		elementsNum = times;

		if (elementsNum == 0)
		{
			pData = NULL;
			return;
		}

		pData = new char[elementsNum + 1];
		for (unsigned int i = 0; i < elementsNum; i++)
		{
			pData[i] = c;
		}
		pData[elementsNum] = '\0';
	}


	void String::print(ostream& os)
	{
		for (unsigned int i = 0; i < elementsNum; i++)
		{
			os << pData[i];
		}
	}

	String String::concatenate(const String& string1, const String& string2)
	{
		String s;
		s.elementsNum = string1.elementsNum + string2.elementsNum;

		if (s.elementsNum == 0)
		{
			s.pData = NULL;
			return s;
		}

		s.pData = new char[s.elementsNum + 1];

		for (unsigned int i = 0; i < string1.elementsNum; i++)
		{
			s.pData[i] = string1.pData[i];
		}
		for (unsigned int j = string1.elementsNum; j < s.elementsNum; j++)
		{
			s.pData[j] = string2.pData[j - string1.elementsNum];
		}

		s.pData[s.elementsNum] = '\0';
		return s;
	}

	bool String::compare(const String& string1, const String& string2)
	{
		if (string1.elementsNum != string2.elementsNum)return false;

		for (unsigned int i = 0; i < string1.elementsNum; i++)
		{
			if (string1.pData[i] != string2.pData[i]) return false;
		}
		return true;
	}

	void String::copy(String& string1, const String& string2)
	{
		delete string1.pData;
		string1.elementsNum = string2.elementsNum;
		if (string1.elementsNum == 0)
		{
			string1.pData = NULL;
			return;
		}
		string1.pData = new char[string1.elementsNum + 1];
		for (unsigned int i = 0; i < string1.elementsNum; i++)
		{
			string1.pData[i] = string2.pData[i];
		}
		string1.pData[string1.elementsNum] = '\0';
	}

	String::String(const char* str) 
	{
		elementsNum = 0;
		 for(int i=0;str[i] != '\0';i++)
		{
			elementsNum++;                // first getting how long the char array is
			
		}

		pData = new char[elementsNum + 1]; //dma for the string

		for (int i = 0; i <= elementsNum; i++)
		{
			pData[i] = str[i];           //transferring from char* to string
		}

	}

	char& String::operator[](unsigned int pos)
	{
		char zero = 0;
		if ((pos < 0) || (pos >= elementsNum)) { return zero; } // as the return type is non const char so it is not possible to return 0 directly

		else return pData[pos];
	}


	const char& String::operator[](unsigned int pos)const
	{
		
		if ((pos < 0) || (pos >= elementsNum)) { return 0; } // here the returning value is const

		else return pData[pos];

	}

	String String::operator+(const String& theOther)const
	{
		return concatenate(*this,theOther);    //just adding two strings
	}


	const String& String::operator+=(const String& theOther)
	{
		*this = concatenate(*this, theOther);      // adding two string and assigning into one
		return *this;
	}

	const String& String::operator=(const String& theOther)
	{
		copy(*this, theOther);         // copying one string into another
		return *this;

	}
	bool String::operator==(const String& theOther)const //  checking if twi strings are same

	{
		if (this->elementsNum != theOther.elementsNum) return false; // first checking number of elements


		for (int i = 0; i < this->elementsNum; i++)

		{
			if (this->pData[i] != theOther.pData[i])
				return false;

		}

		return true;
	}


	String::operator const char* () const 
	{
		return pData;
	}
}

