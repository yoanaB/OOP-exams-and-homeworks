#include<iostream>
#include"Circle.h"
#include"Triangle.h"
#include"Square.h"
int main(){
	Triangle a(2,2,100,2,52,130);
	a.Print();
	cout << endl;
	Square b(5,2,6,2,6,2.5,5,2.5);
	Figure *c=&a, *d=&b;
	c->isItIn(b);

	/*
	Tons of akward errors couldn't run it and can't find the reason 
	Error	12	error C2039: 'difference_type' : is not a member of '`global namespace''	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	373
	Error	2	error C2039: 'iterator_category' : is not a member of '`global namespace''	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	371
	Error	17	error C2039: 'pointer' : is not a member of '`global namespace''	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	375
	Error	22	error C2039: 'reference' : is not a member of '`global namespace''	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	376
	Error	7	error C2039: 'value_type' : is not a member of '`global namespace''	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	372
	Error	13	error C2146: syntax error : missing ';' before identifier 'difference_type'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	373
	Error	3	error C2146: syntax error : missing ';' before identifier 'iterator_category'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	371
	Error	18	error C2146: syntax error : missing ';' before identifier 'pointer'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	375
	Error	23	error C2146: syntax error : missing ';' before identifier 'reference'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	376
	Error	8	error C2146: syntax error : missing ';' before identifier 'value_type'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	372
	Error	14	error C2602: 'std::iterator_traits<_InIt>::difference_type' is not a member of a base class of 'std::iterator_traits<_InIt>'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	373
	Error	4	error C2602: 'std::iterator_traits<_InIt>::iterator_category' is not a member of a base class of 'std::iterator_traits<_InIt>'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	371
	Error	19	error C2602: 'std::iterator_traits<_InIt>::pointer' is not a member of a base class of 'std::iterator_traits<_InIt>'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	375
	Error	24	error C2602: 'std::iterator_traits<_InIt>::reference' is not a member of a base class of 'std::iterator_traits<_InIt>'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	376
	Error	9	error C2602: 'std::iterator_traits<_InIt>::value_type' is not a member of a base class of 'std::iterator_traits<_InIt>'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	372
	Error	26	error C2665: 'std::_Debug_range2' : none of the 2 overloads could convert all the argument types	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	584
	Error	1	error C2825: '_Iter': must be a class or namespace when followed by '::'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	371
	Error	6	error C2825: '_Iter': must be a class or namespace when followed by '::'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	372
	Error	11	error C2825: '_Iter': must be a class or namespace when followed by '::'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	373
	Error	16	error C2825: '_Iter': must be a class or namespace when followed by '::'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	375
	Error	21	error C2825: '_Iter': must be a class or namespace when followed by '::'	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	376
	Error	15	error C2868: 'std::iterator_traits<_InIt>::difference_type' : illegal syntax for using-declaration; expected qualified-name	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	373
	Error	5	error C2868: 'std::iterator_traits<_InIt>::iterator_category' : illegal syntax for using-declaration; expected qualified-name	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	371
	Error	20	error C2868: 'std::iterator_traits<_InIt>::pointer' : illegal syntax for using-declaration; expected qualified-name	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	375
	Error	25	error C2868: 'std::iterator_traits<_InIt>::reference' : illegal syntax for using-declaration; expected qualified-name	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	376
	Error	10	error C2868: 'std::iterator_traits<_InIt>::value_type' : illegal syntax for using-declaration; expected qualified-name	c:\program files (x86)\microsoft visual studio 12.0\vc\include\xutility	372

	
	
	
	
	
	
	
	
	
	*/
}