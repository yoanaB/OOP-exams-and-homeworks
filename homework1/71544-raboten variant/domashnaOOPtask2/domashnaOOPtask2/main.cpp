#include "ListPerson.h"
#include "Card.h"
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

int main()
{
	Card b;
	Card c(1, 2, 1932, "Ivanov");

	
	b = c;
	Card e(1, 2, 4535, "Elena");
	ListPerson p(0);
	p.addCard(b);
	p.addCard(e);

	p.getZodiac("Ivanov");
	

	system("pause");
	return 0;
}
