#include "Square.h"


Square::Square(double xA, double yA, double xB, double yB, double xC, double yC,double xD,double yD){
	setXA(xA);
	setXB(xB);
	setXC(xC);
	setXD(xD);
	setYA(yA);
	setYB(yB);
	setYC(yC);
	setYD(yD);
}
char Square::getType(){
	return type;
}
double Square::getAB(){
	AB = sqrt((getXA() - getXB())*(getXA() - getXB()) + (getYA() - getYB())*(getYA() - getYB()));
	return AB;
}
double Square::getBC(){
	BC = sqrt((getXB() - getXC())*(getXB() - getXC()) + (getYB() - getYC())*(getYB() - getYC()));
	return BC;
}
double Square::getCD(){
	CD = sqrt((getXC() - getXD())*(getXC() - getXD()) + (getYC() - getYD())*(getYC() - getYD()));
	return CD;
}
double Square::getDA(){
	DA = sqrt((getXD() - getXA())*(getXD() - getXA()) + (getYD() - getYA())*(getYD() - getYA()));
	return DA;
}
double Square::anotherArea(double x1, double y1, double x2, double y2, double x3, double y3){
	return abs(((x1 - x3)*(y2 - y1)) - ((x1 - x2)*(y3 - y1)))*(0.5);
}
bool Square::isTheDotInTheSquare(double x, double y){
	//case if the dot is in triangle abc
	if (Area() / 2 == (anotherArea(getXA(), getYA(), getXB(), getYB(), x, y) + anotherArea(getXB(), getYB(), getXC(), getYC(), x, y) + anotherArea(getXC(), getYC(), getXA(), getYA(), x, y))){
		return true;
	}
	// case if the dot is in triangle cda
	else if (Area() / 2 == (anotherArea(getXC(), getYC(), getXD(), getYD(), x, y) + anotherArea(getXD(), getYD(), getXA(), getYA(), x, y) + anotherArea(getXA(), getYA(), getXC(), getYC(), x, y))){
		return true;
	}
	else{
		return false;
	}
}
bool Square::find(double r, double x, double y){
	double temp;
	
	temp = compareAndGetMin(distanceFromPointToLine(getXA(), getYA(), getXB(), getYB(), x, y), distanceFromPointToLine(getXB(), getYB(), getXC(), getYC(), x, y), distanceFromPointToLine(getXC(), getYC(), getXD(), getYD(), x, y), distanceFromPointToLine(getXD(), getYD(), getXA(), getYA(), x, y));
	if (temp < r)
		return false;
	else
		return true;
}
double Square::compareAndGetMin(double first, double second, double third, double fourth){
	if (first <= second && first <= third && first<=fourth)
		return first;
	else if (second <= first && second <= third && second <=fourth)
		return second;
	else if (third <= first && third <= second && third <= fourth)
		return third;
	else
		return fourth;
}
double Square::distanceFromPointToLine(double x1, double y1, double x2, double y2, double x0, double y0){
	//distance(P1,P2,(x0,y0))
	double distance = 0;
	distance = abs((y2 - y1)*x0 - (x2 - x1)*y0 + x2*y1 - y2*x1) / sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
	return distance;
}
//Poprincip trqbvashe da e koren kvadraten ot diagonala no shteshe da mi obarka smetkite :D 
double Square::getDiagonal(){
	diagonal = (getXB() - getXD())*(getXB() - getXD()) + (getYB() - getYD())*(getYB() - getYD());
	return diagonal;
}
bool Square::validation(){
	if ((getDiagonal() == getAB()*getAB() + getDA()*getDA()) && (getAB()==getCD()) && (getBC()==getDA()))
		return true;
	else
		return false;
}
double Square::Perimetre(){
	return getAB() + getBC() + getCD() + getDA();
}
double Square::Area(){
	return getAB()*getBC();
}
//bool Square::isItIn(Circle &other){
//	if (isTheDotInTheSquare(other.getXA(), other.getYA())){
//		if (find(other.getR(), other.getXA(), other.getYA())){
//			cout << "IN";
//			return true;
//		}
//		else{
//			cout << "not";
//			return false;
//		}
//	}
//	else{
//		cout << "Not";
//		return false;
//	}
//}
//bool Square::isItIn(Triangle &other){
//	if (isTheDotInTheSquare(other.getXA(), other.getYA()) && isTheDotInTheSquare(other.getXB(), other.getYB()) && isTheDotInTheSquare(other.getXC(), other.getYC())){
//		cout << "It is in";
//		return true;
//	}
//	else{
//		cout << "it is out";
//		return false;
//	}
//}
double Square::radiusOfTheDescribed(){
	return (sqrt(getAB()*getAB() + getBC()*getBC()) / 2);
}
double Square::getOx(){
	return (getXA() + getXC()) / 2;
}
double Square::getOy(){
	return (getYA() + getYC()) / 2;
}
double Square::radiusOfTheInscribed(){
	if (getAB() == getBC())
		return AB;
	else{
		std::cout << "There can't be inscribed:";
		return 0;
	}
}
void Square::Print(){
	if (validation()){
		cout << "Square with " << endl
			<< "a: " << getAB() << endl
			<< "B: " << getBC() << endl
			<< "C: " << getCD() << endl
			<< "D: " << getDA() << endl
			<< "Area of :" << Area() << endl
			<< "Perimetre: " << Perimetre() << endl
			<< "Radius Of the inscribed: " << radiusOfTheInscribed() << endl
			<< "Radius of the described: " << radiusOfTheDescribed() << endl
			<<"Diagonal: "<<getDiagonal()<<endl;
	}
	else
		cout << "No such square"<<endl;
}
double Square::getXA()const{
	return xA;
}
double Square::getXB()const{
	return xB;
}
double Square::getXC()const{
	return xC;
}
double Square::getXD()const{
	return xD;
}
double Square::getYA()const{
	return yA;
}
double Square::getYB()const{
	return yB;
}
double Square::getYC()const{
	return yC;
}
double Square::getYD()const{
	return yD;
}
void Square::setXA(double xA){
	this->xA = xA;
}
void Square::setXB(double xB){
	this->xB = xB;
}
void Square::setXC(double xC){
	this->xC = xC;
}
void Square::setXD(double xD){
	this->xD = xD;
}
void Square::setYA(double yA){
	this->yA = yA;
}
void Square::setYB(double yB){
	this->yB = yB;
}
void Square::setYC(double yC){
	this->yC = yC;
}
void Square::setYD(double yD){
	this->yD = yD;
}

Square::~Square(){
}
