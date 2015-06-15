#include "Triangle.h"
Triangle::Triangle(double xA, double yA, double xB, double yB, double xC, double yC)
{
	setXA(xA);
	setXB(xB);
	setXC(xC);
	setYA(yA);
	setYB(yB);
	setYC(yC);
}
char Triangle::getType(){
	return type;
}
double Triangle::firstHalf(){
	return (getXA() - getXC())*(getYB() - getYA());
}
double Triangle::secondHalf(){
	return (getXA() - getXB())*(getYC() - getYA());
}
double Triangle::Area(){
	return (abs(firstHalf() - secondHalf())*(0.5));
}
double Triangle::getAB(){
	AB = sqrt((getXA() - getXB())*(getXA() - getXB()) + (getYA() - getYB())*(getYA() - getYB()));
	return AB;
}
double Triangle::getAC(){
	AC = sqrt((getXA() - getXC())*(getXA() - getXC()) + (getYA() - getYC())*(getYA() - getYC()));
	return AC;
}
double Triangle::getBC(){
	BC = sqrt((getXB() - getXC())*(getXB() - getXC()) + (getYB() - getYC())*(getYB() - getYC()));
	return BC;
}
double Triangle::Perimetre(){
	return getAB() + getAC() + getBC();
}
double Triangle::findOx(){
	Ox = getBC()*getXA() + getAC()*getXB() + getAB()*getXC();
	return Ox;
}
double Triangle::findOy(){
	Oy = getBC()*getYA() + getAC()*getYB() + getAB()*getYC();
	return Oy;
}
double Triangle::distanceFromPointToLine(double x1, double y1, double x2, double y2, double x0, double y0){
	//distance(P1,P2,(x0,y0))
	double distance = 0;
	distance = abs((y2-y1)*x0-(x2-x1)*y0+x2*y1 -y2*x1)/sqrt(pow((y2-y1),2)+ pow((x2-x1),2));
	return distance;
}
double Triangle::compareAndGetMin(double first,double second,double third){
	if (first <= second && first <= third)
		return first;
	else if (second <= first && second <= third)
		return second;
	else
		return third;
}
bool Triangle::find(double r, double x, double y){
	double temp;
	temp = compareAndGetMin(distanceFromPointToLine(getXA(), getYA(), getXB(), getYB(), x, y), distanceFromPointToLine(getXB(), getYB(), getXC(), getYC(), x, y), distanceFromPointToLine(getXC(), getYC(), getXA(), getYA(), x, y));
	if (temp < r)
		return false;
	else
		return true;
}
double Triangle::anotherArea(double x1, double y1, double x2, double y2, double x3, double y3){
	return abs(((x1 - x3)*(y2 - y1)) - ((x1 - x2)*(y3 - y1)))*(0.5);
}
//bool Triangle::isItIn(Square &other){
//		if (Area() == anotherArea(other.getXA(), other.getYA(), getXA(), getYA(), getXB(), getYB()) + anotherArea(getXC(), getYC(), other.getXA(), other.getYA(), getXB(), getYB()) + anotherArea(getXA(), getYA(), getXC(), getYC(), other.getXA(), other.getYA()))
//		{
//			if (Area() == anotherArea(other.getXB(), other.getYB(), getXA(), getYA(), getXB(), getYB()) + anotherArea(getXC(), getYC(), other.getXB(), other.getYB(), getXB(), getYB()) + anotherArea(getXA(), getYA(), getXC(), getYC(), other.getXB(), other.getYB()))
//			{
//				if (Area() == anotherArea(other.getXC(), other.getYC(), getXA(), getYA(), getXB(), getYB()) + anotherArea(getXC(), getYC(), other.getXC(), other.getYC(), getXB(), getYB()) + anotherArea(getXA(), getYA(), getXC(), getYC(), other.getXC(), other.getYC()))
//				{
//					if (Area() == anotherArea(other.getXD(), other.getYD(), getXA(), getYA(), getXB(), getYB()) + anotherArea(getXC(), getYC(), other.getXD(), other.getYD(), getXB(), getYB()) + anotherArea(getXA(), getYA(), getXC(), getYC(), other.getXD(), other.getYD())){
//						cout << "Vutre e kvadratcheto ^-^";
//						return true;
//					}
//				}
//			}
//		}
//	else{
//		cout << "not valid square:";
//		return false;
//	}
//	cout << "It is not in :(" << endl;
//	return false;
//}
//bool Triangle::isItIn(Circle &other){
//	if (find(other.getR(), other.getXA(), other.getYA())){
//		cout << "IN";
//		return true;
//	}
//	else{
//		cout << "NOT";
//		return false;
//	}
//}
double Triangle::radiusOfTheInscribed(){
	return Area() / (Perimetre() / 2);
}
double Triangle::radiusOfTheDescribed(){
	return (Area() * 4) / (getAB()*getAC()*getBC());
}
void Triangle::Print(){
	cout << "Triangle with "<<endl
		<< "a: " << getBC() << endl
		<< "b:" << getAC() << endl
		<< "c: " << getAB() << endl
		<< "Area of :" << Area() << endl
		<< "Perimetre: " << Perimetre() << endl
		<< "OX: " << findOx() <<endl
		<< "OY: " << findOy() << endl
		<< "Radius Of the inscribed: " << radiusOfTheInscribed() << endl
		<< "Radius of the described: " << radiusOfTheDescribed()<<endl;
}
double Triangle::getXA()const{
	return xA;
}
double Triangle::getXB()const{
	return xB;
}
double Triangle::getXC()const{
	return xC;
}
double Triangle::getYA()const{
	return yA;
}
double Triangle::getYB()const{
	return yB;
}
double Triangle::getYC()const{
	return yC;
}

void Triangle::setXA(double xA){
	this->xA = xA;
}
void Triangle::setXB(double xB){
	this->xB = xB;
}
void Triangle::setXC(double xC){
	this->xC = xC;
}
void Triangle::setYA(double yA){
	this->yA = yA;
}
void Triangle::setYB(double yB){
	this->yB = yB;
}
void Triangle::setYC(double yC){
	this->yC = yC;
}
Triangle::~Triangle(){
}
