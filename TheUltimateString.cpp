#include <iostream>
#include "String.h"

using namespace std;
using namespace TheUltimateString;


int main()
{
	String str1 = "Hello, Mrs. Moneypenny.";
	printf(str1);
	str1 = "My name is Bond. ";
	str1 += "James Bond.";
	printf("\n%s\n", (const char*)str1);

	if (str1 == (String)"My name is Bond. James Bond."
		&& !(str1 != (String)"My name is Bond. James Bond."))
	{
		cout << "Oh, Mr. Bond!" << endl;
	}

	return 0;
}

