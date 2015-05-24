#include "square.h"
#include <iostream>
using namespace std;


void Square::print() const
{
	Figure:: print();
	cout << "Liceto na kvadrata e : " << getFace() << endl;
}

Square::Square(int l) :Figure(l){}



int Square::getFace() const
{
	return getSide()*getSide();
}

