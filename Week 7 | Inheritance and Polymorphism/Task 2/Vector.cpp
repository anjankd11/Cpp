#include <limits.h>
#include <assert.h>
#include "Vector.h"

using namespace std;

ostream & operator << (ostream& os, const Vector &v)
{
	for(unsigned int i=0;i<v.elementNum;i++)
	{
		os<<' '<<v.at(i);
	}
	return os;
}

Vector::Vector(const Vector& theOther)
{
	pData=NULL;
	*this=theOther;
}

void Vector::clear()
{
	delete[]pData;
	pData=NULL;
	elementNum=0;
}


void Vector::erase(unsigned int position)
{
	assert(position<elementNum);
	
	if(elementNum==1)
	{
		delete []pData;
		pData=NULL;
		elementNum=0;
		return;
	}

	elementNum--;
	int* pTemp=new int[elementNum];

	for(unsigned int i=0, j=0;i<elementNum+1;i++,j++)
	{
		if(i==position)
		{
			j--;
		}
		else
		{
			pTemp[j]=pData[i];
		}
	}
	delete[] pData;
	pData=pTemp;
}

int& Vector::at(unsigned int position)
{
	assert(position<elementNum);
	return pData[position];
}

const int& Vector::at(unsigned int position)const
{
	assert(position<elementNum);
	return pData[position];
}

bool Vector::insert(unsigned int position, int element)
{
	if(elementNum==UINT_MAX)
	{
		return false;
	}
	
	int* pTemp=NULL;
	if(position<elementNum)
	{
		pTemp=new int[elementNum+1];
		for(unsigned int i=0, j=0; i<elementNum;i++,j++)
		{
			if(j==position)
			{
				pTemp[position]=element;
				i--;
			}
			else
			{
				pTemp[j]=pData[i];
			}
		}
		elementNum++;
	}
	else
	{
		pTemp=new int[position+1];
		for(unsigned int i=0;i<position;i++)
		{
			if(i<elementNum)
			{
				pTemp[i]=pData[i];
			}
			else
			{
				pTemp[i]=0;
			}
		}
		pTemp[position]=element;
		elementNum=position+1;
	}
	delete[]pData;
	pData=pTemp;
	return true;
}

int & Vector::operator [](unsigned int position)
{
	return at(position);
}
const int & Vector::operator [](unsigned int position)const
{
	return at(position);
}

const Vector& Vector::operator= (const Vector & theOther)
{
	assert(this!=&theOther);
	delete[]pData;
	if(theOther.elementNum==0)
	{
		elementNum=0;
		pData=NULL;
	}
	else
	{
		elementNum=theOther.elementNum;
		pData=new int[elementNum];
		for(unsigned int i=0;i<elementNum;i++)
		{
			pData[i]=theOther.pData[i];
		}
	}
	return *this;
}