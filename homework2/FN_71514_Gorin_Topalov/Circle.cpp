#include "Circle.h"


Circle::Circle(double r, double xA, double yA)
{
	this->r = r;
	setXA(xA);
	setYA(yA);
}
char Circle::getType(){
	return type;
}
double Circle::getXA()const{
	return xA;
}
void Circle::setXA(double xA){
	this->xA = xA;
}
void Circle::setYA(double yA){
	this->yA = yA;
}
double Circle::getYA()const{
	return yA;
}
double Circle::getR(){
	return r;
}
//bool Circle::isItIn(Triangle &other){
//	double d;
//	d = sqrt(pow((getXA() - other.getXA()), 2) + pow((getYA() - other.getYA()), 2));
//	if (d <= getR()){
//		d = sqrt(pow((getXA() - other.getXB()), 2) + pow((getYA() - other.getYB()), 2));
//		if (d <= getR()){
//			d = sqrt(pow((getXA() - other.getXC()), 2) + pow((getYA() - other.getYC()), 2));
//			if (d <= getR())
//				return true;
//		}
//	}
//	return false;
//}
//bool Circle::isItIn(Square &other){
//	double d;
//	d = sqrt(pow((getXA() - other.getXA()), 2) + pow((getYA() - other.getYA()), 2));
//	if (d <= getR()){
//		d = sqrt(pow((getXA() - other.getXB()), 2) + pow((getYA() - other.getYB()), 2));
//		if (d <= getR()){
//			d = sqrt(pow((getXA() - other.getXC()), 2) + pow((getYA() - other.getYC()), 2));
//			if (d <= getR()){
//				d = sqrt(pow((getXA() - other.getXD()), 2) + pow((getYA() - other.getYD()), 2));
//				if (d <= getR())
//					return true;
//			}
//		}
//	}
//	return false;
//}
void Circle::setR(double r){
	this->r = r;
}
void Circle::Print(){
	cout << "Circle Perimetur: " << Perimetre()
		<< "Lice: " << Area() << endl;
}
double Circle::Perimetre(){
	return 2 * PI*getR();
}
double Circle::Area(){
	return 2 * PI*getR();
}

Circle::~Circle()
{
}
