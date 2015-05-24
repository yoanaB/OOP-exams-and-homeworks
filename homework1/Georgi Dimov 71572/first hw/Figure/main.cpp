//imame classs figure v nego ima tri naslednika squar triangle i circle 
//podhodqshti metodi v main da imame masiv ot figuri 
//da pusnem cikul ot 15 figuri 
// Figure figures[15];
//for(i<15)
//figures[i].area();// lice 
//cout << a ; 
//}
#include <iostream>
#include "square.h"
#include "circle.h"
#include "triangle.h"
//#include ""
using namespace std; 

int main()
{
	Figure arr;
	arr.setHeight(3);
	arr.setSide(4);
	arr.print();
	cout << endl;
	cout << endl;
	cout << endl;
	Square face;
	face.setSide(3);
	face.print();
	cout << endl;
	cout << endl;
	cout << endl;
	Circle hah; 
	hah.setSide(3);
	hah.print();
	cout << endl;
	cout << endl;
 	cout << endl;
	Triangle t;
	t.setHeight(2);
	t.setSide(12);
	t.print();

	system("pause");
	return 0; 
}