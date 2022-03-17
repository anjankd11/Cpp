#include<iostream>
using namespace std;

#include "Display.h"
#include "Printer.h"


int main()
{
	const unsigned maxEquipment=4;
	Equipment* equipments[maxEquipment];

	equipments[0]=new Equipment(1, 200);	 // This instruction should result in compiler error. Why?
	equipments[1]=new Printer(2,12000,8);	 // Parameters: unique ID, price, printing speed (pages per minute)
	equipments[2]=new Display(3,20000,1996); // Parameters: unique ID, price, year of appropriation
	equipments[3]=new Printer(4,31200,15);   // Parameters: unique ID, price, printing speed
	
	for(int i=0;i<maxEquipment;i++)
	{
		equipments[i]->print();
		delete equipments[i];
		cout<<endl;
	}
	return 0;
}

