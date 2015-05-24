#ifndef triangle_h
#define triangle_h
#include "figure.h"
class Triangle :public Figure
{
public:
	Triangle(int l = 0);
	void print()const;
	int getFace() const;
};
#endif triangle_h