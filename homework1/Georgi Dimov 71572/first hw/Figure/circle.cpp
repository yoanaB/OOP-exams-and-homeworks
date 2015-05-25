#include "circle.h"
#include <iostream>
using namespace std; 
Circle :: Circle(int l):Figure(l){}
double Circle:: getFace() const
{
	return getSide()*getSide()*3.14;
}

void Circle::print() const
{
	Figure::print();
	cout << "Liceto na Okrujnostta e : " << getFace() << endl;
}
