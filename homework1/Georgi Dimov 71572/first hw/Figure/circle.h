#ifndef circle_h
#define circle_h
#include "figure.h"
class Circle : public Figure
{
public:
	Circle(int l =0);
	double getFace() const;
	void print()const;

};
#endif circle_h