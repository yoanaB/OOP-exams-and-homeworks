#include "triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(int l) :Figure(l){};

void Triangle::print() const
{

	Figure::print();
	cout << "Liceto na triugulnika e: " << getFace() << endl;
}
int Triangle::getFace() const
{
	return getSide()*getHeight() / 2;
}