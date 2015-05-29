#include<iostream>
#include "rock.h"
#include "band.h"
using namespace std;
int main()
{
	RockStar steve("Steve", 100, 23);
	steve.printRS();
	RockStar c;
	c = steve;
	RockStar balo("Balo", 123, 32);
	cout << (c == steve);
	cout << endl;
}