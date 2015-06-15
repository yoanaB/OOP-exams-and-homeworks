#ifndef CIRCLE_H
#define CIRCLE_H
#pragma once
#include "Figure.h"
double const PI = 3.14;
class Circle :
	public Figure
{
	char type = 'c';
	double r,xA,yA ;
public:
//	bool isItIn(Triangle &);
//	bool isItIn(Square &);
	double getR();
	char getType();
	void setR(double);
	void setXA(double);
	void setYA(double);
	double getXA()const;
	double getYA()const;
	
	Circle(double ,double,double);
	void Print();
	double Perimetre();
	double Area();
	~Circle();
};

#endif //CIRCLE_H