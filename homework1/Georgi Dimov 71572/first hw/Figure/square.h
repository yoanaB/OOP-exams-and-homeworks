#ifndef square_h
#define square_h
#include "figure.h"
class Square : public Figure
{
private: 
public:
	Square(int l = 0);
	void print()const ;
	int getFace() const;
};
#endif square_h