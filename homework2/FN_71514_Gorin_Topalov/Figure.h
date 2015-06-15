#ifndef FIGURE_H
#define FIGURE_H
#pragma once
#include<iostream>
#include<math.h>
using namespace std;
class Figure
{
public:
	Figure();
	//ALL
	bool isItIn(Figure &);
	virtual double anotherArea(double, double, double, double, double, double);
	virtual double getR();
	virtual bool isTheDotInTheSquare(double, double);
	virtual void setR(double);
	virtual void setXA(double);
	virtual void setXB(double);
	virtual void setXC(double);
	virtual void setXD(double);
	virtual void setYA(double);
	virtual void setYB(double);
	virtual void setYC(double);
	virtual void setYD(double);
	virtual double getXA()const;
	virtual double getXB()const;
	virtual double getXC()const;
	virtual double getXD()const;
	virtual double getYA()const;
	virtual double getYB()const;
	virtual double getYC()const;
	virtual double getYD()const;
	virtual double Area()=0;
	virtual double Perimetre()=0;
	virtual void Print()=0;
	virtual char getType();

	virtual ~Figure();
private:
	double xA, xB, xC, xD, yA, yB, yC, yD;
};

#endif //FIGURE_H