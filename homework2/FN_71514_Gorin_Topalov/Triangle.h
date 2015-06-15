
#ifndef TRIANGLE_H
#define TRIANGLE_H
#pragma once
#include"Figure.h"
class Triangle :
	public Figure
{

public:
	Triangle(double=1,double=2,double=3,double=5,double=2,double=15);
	//bool isItIn(Circle&);
	//bool isItIn(Square&);
	double firstHalf();
	double secondHalf();
	double compareAndGetMin(double, double, double);
	double distanceFromPointToLine(double,double,double,double,double,double);
	bool find(double ,double,double);
	//Another area is just for securing no mistakes are made:D 
	double anotherArea(double, double, double, double, double, double);
	double Area();
	void Print();
	double getAB();
	double getAC();
	double getBC();
	double findOx();
	double findOy();
	double Perimetre();
	double radiusOfTheInscribed();
	double radiusOfTheDescribed();
	double getYA()const;
	double getYB()const;
	double getYC()const;
	void setYA(double);
	void setYB(double);
	void setYC(double);

	void setXA(double);
	void setXB(double);
	void setXC(double);
	double getXA()const;
	double getXB()const;
	char getType();
	double getXC()const;
	~Triangle();
private:
	char type = 't';
	double AB, AC, BC,Ox,Oy;
	double xA, xB, xC, yA, yB, yC;
};

#endif //TRIANGLE_H