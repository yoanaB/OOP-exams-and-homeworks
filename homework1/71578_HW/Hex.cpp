#include <iostream>
#include <cstring>
#include "Hex.h"

using namespace std;

Hex :: Hex()
{
	hexNumber = new char[1];
	hexNumber[0] = '\0';
}

Hex :: Hex(char* _hexNumber)
{
	delete[] hexNumber;
	hexNumber = new char[strlen(_hexNumber) + 1];
	strcpy(hexNumber, _hexNumber);
}

Hex :: ~Hex()
{
	delete[] hexNumber;
}

void Hex :: print () const
{
	cout << "Hex: " << hexNumber << endl;
}

int main()
{
	return 0;
}