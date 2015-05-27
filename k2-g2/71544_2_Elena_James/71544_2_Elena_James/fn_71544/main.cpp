#include <iostream>
#include "Rockstar.h"
#include "Band.h"
#include "Concert.h"

using namespace std;
int main()
{
	Rockstar p("Pesho", 3, 5);
	p.print();
	Rockstar v("Vesko", 4, 5);
	v = p;
	v.print();
	Rockstar a("Gosho", 2, 5);
	Rockstar k(a);
	k.print();


	return 0;
}