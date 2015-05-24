#include "figure.h"
#include <iostream>
using namespace std; 

Figure::Figure(int side , int height)
{
	setSide(side);
	setHeight(height);
}
Figure::Figure(Figure& other)
{
	setSide(other.side);
	setHeight(other.height);
}
Figure& Figure::  operator=(const Figure& other)
{
	if (this != &other)
	{
		setSide(other.side);
		setHeight(other.height);
	}
	return *this; 
}

void  Figure::setSide(int side)
{
	this->side = side;
}
int Figure::getSide() const
{
	return this -> side;
}
void Figure::setHeight(int height)
{
	this->height = height;
}
int Figure::  getHeight() const
{
	return height; 
}
void Figure::print() const 
{
	cout << "Strana : " << getSide() << endl;
	if (getHeight()!= 0)
	{
		cout << "Visochina: " << getHeight() << endl ;
	}
}


