//abstrakciq
//enkapsolaciq
//nasledqvane
//polimorfizum
#include "band.h"
#include <iostream>
using namespace std; 
int main()
{
	RockStar a("Jor", 100, 23);
	a.printRockStar();
	RockStar b;
	b = a;
	RockStar f("fad", 123, 32);
	cout << (b == a);
	cout << endl;
	Band d(3);
	d.addStar("Mitko", 32, 100);
	d.addStar("Mitko4", 32, 100);
	d.addStar("Mitko3", 32, 100);
	d.addStar("Mitko2", 32, 100);
	d.removeStar("Mitko2");
	d.printBand();
	cout << endl;
	cout << endl;
	Band hate(3);
	hate.addStar("tukames", 123, 28);
	//hate = d;
	//hate.printBand();
	cout << endl;
	cout << endl;
	(hate += d).printBand();
	//b.printRockStar();
	system("pause");
	return 0; 
}