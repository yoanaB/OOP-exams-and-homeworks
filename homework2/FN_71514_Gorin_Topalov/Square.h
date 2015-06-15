#ifndef SQUARE_H
#define SQUARE_H
#pragma once
#include"Figure.h"
class Square :
	public Figure
{
public:
	Square(double = 7, double = 4, double = 29, double = 4, double = 29, double = 26, double = 7, double =26);
//	bool isItIn(Circle &);
//	bool isItIn(Triangle &);
	bool isTheDotInTheSquare(double ,double);
	double anotherArea(double,double,double,double,double,double);
	double Area();
	void Print();
	double getAB();
	double getBC();
	double getCD();
	double getDA();
	double getOx();
	double getOy();
	double getDiagonal();
	double Perimetre();
	double radiusOfTheInscribed();
	double radiusOfTheDescribed();
	bool validation();
	double compareAndGetMin(double, double,double, double);
	double distanceFromPointToLine(double, double, double, double, double, double);
	bool find(double, double, double);
	~Square();

	void setXA(double);
	void setXB(double);
	void setXC(double);
	void setXD(double);
	void setYA(double);
	void setYB(double);
	void setYC(double);
	void setYD(double);
	double getXA()const;
	double getXB()const;
	double getXC()const;
	double getXD()const;
	double getYA()const;
	double getYB()const;
	double getYC()const;
	double getYD()const;
	char getType();
private:
	char type='s';
	double AB, BC, CD, DA, diagonal;
	double xR, yR;
	double xA, xB, xC, xD, yA, yB, yC, yD;
};

#endif //SQUARE_H