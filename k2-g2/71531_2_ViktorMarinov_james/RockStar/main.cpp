#include "RockStar.h"
#include "Band.h"
#include "Concert.h"
#include <iostream>
using namespace std;

//1 задача - Абстракция, енкапсулация, наследяване, полиморфизъм
int main(){
	RockStar a("Axel Rose", 99, 10000);
	RockStar b("Slash", 90, 20030);
	RockStar e("Barabanist", 10, 100);
	RockStar f("Basist", 1, 1);
	RockStar c("Harry", 110, 123122);
	RockStar d("Nasko", 110, 122143);
	
	Band x("Guns & Roses", 4);
	x.addStar(b);
	x.addStar(a);
	x.addStar(e);
	x.addStar(f);

	x.pickAFrontman().print();

	Band y("FMI", 2);
	y.addStar(c);
	y.addStar(d);


	Band arr[2] = { x, y };
	Concert aa(arr, 2);
	aa.headliner().print();
	
	
	system("pause");
	return 0;
}