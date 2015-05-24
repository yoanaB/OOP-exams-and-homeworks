#include "ListPerson.h"
#include "Card.h"
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

int main()
{
	Card b;
	b.getDate();
	Card c(1, 2, 1932, "Ivanov");

	
	b = c;
	
	Card e(1, 2, 4535, "Elena");
	Card l(1, 2, 5345, "rere");
	ListPerson k(0);
	k.addCard(e);
	k.addCard(l);
	ListPerson p(0);
	p.addCard(b);
	p.addCard(e);
	p.print();
	cout << endl;
	k.print();

	p.sameCards(k);
	cout << "union:" << endl;
	p.print();

	return 0;
}