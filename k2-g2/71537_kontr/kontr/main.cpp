#include <iostream>
#include <cassert>
#include <cstring>
#include "rock.h"
using namespace std;

int main()
{
	RockStar a;
	a.print();
	RockStar b(a);
	b.print();
	b.setName("Ivan");
	b.setAwesomness(100);
	Band*  a;
	a.print;

	system("pause");
	return 0;
}
