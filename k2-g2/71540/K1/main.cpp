//Абстракция
//Енкапсулация
//Наследяване
//Полиморфизъм

#include <cstdlib>
#include "K1.h"

using namespace std;

int main()
{
	RockStar a; a.setName("Cooper"); a.setAw(100); a.setN(10000);
	RockStar b; b = a; b.print();
	RockStar c; c.setName("Alison"); a.setAw(120); a.setN(11000);

	Band d; d.addStar(a); b.print();
	d.addStar(b);
	d.removeStar("Cooper"); b.print();
	d.getStar("neshto");

	Concert con;

	system("pause");
	return 0;
}