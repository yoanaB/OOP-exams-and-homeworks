#include "Figure.h"

Figure::Figure(){

}
double Figure::anotherArea(double, double, double, double, double, double){
	return 0;
}
bool Figure::isItIn(Figure &other){
	if (getType() == 't'){
		if (other.getType() == 's'){
			if (Area() == anotherArea(other.getXA(), other.getYA(), getXA(), getYA(), getXB(), getYB()) + anotherArea(getXC(), getYC(), other.getXA(), other.getYA(), getXB(), getYB()) + anotherArea(getXA(), getYA(), getXC(), getYC(), other.getXA(), other.getYA()))
			{
				if (Area() == anotherArea(other.getXB(), other.getYB(), getXA(), getYA(), getXB(), getYB()) + anotherArea(getXC(), getYC(), other.getXB(), other.getYB(), getXB(), getYB()) + anotherArea(getXA(), getYA(), getXC(), getYC(), other.getXB(), other.getYB()))
				{
					if (Area() == anotherArea(other.getXC(), other.getYC(), getXA(), getYA(), getXB(), getYB()) + anotherArea(getXC(), getYC(), other.getXC(), other.getYC(), getXB(), getYB()) + anotherArea(getXA(), getYA(), getXC(), getYC(), other.getXC(), other.getYC()))
					{
						if (Area() == anotherArea(other.getXD(), other.getYD(), getXA(), getYA(), getXB(), getYB()) + anotherArea(getXC(), getYC(), other.getXD(), other.getYD(), getXB(), getYB()) + anotherArea(getXA(), getYA(), getXC(), getYC(), other.getXD(), other.getYD())){
							cout << "Vutre e kvadratcheto ^-^";
							return true;
						}
					}
				}
			}
			cout << "It is not in :(" << endl;
			return false;
		}
		if (other.getType() == 't'){
			if (find(other.getR(), other.getXA(), other.getYA())){
				cout << "IN";
				return true;
			}
			else{
				cout << "NOT";
				return false;
			}
		}
		else
			return false;
	}

	if (getType() == 's'){
		if (other.getType() == 'c'){
				if (isTheDotInTheSquare(other.getXA(), other.getYA())){
					if (find(other.getR(), other.getXA(), other.getYA())){
						cout << "IN";
						return true;
					}
					else{
						cout << "not";
						return false;
					}
				}
				else{
					cout << "Not";
					return false;
				}
			}
		if (other.getType() == 't'){
			if (isTheDotInTheSquare(other.getXA(), other.getYA()) && isTheDotInTheSquare(other.getXB(), other.getYB()) && isTheDotInTheSquare(other.getXC(), other.getYC())){
				cout << "It is in";
				return true;
			}
			else{
				cout << "it is out";
				return false;
			}
		}
		else
			return false;
		}
	if (getType() == 'c'){
		if (other.getType() == 's'){
			double d;
			d = sqrt(pow((getXA() - other.getXA()), 2) + pow((getYA() - other.getYA()), 2));
			if (d <= getR()){
				d = sqrt(pow((getXA() - other.getXB()), 2) + pow((getYA() - other.getYB()), 2));
				if (d <= getR()){
					d = sqrt(pow((getXA() - other.getXC()), 2) + pow((getYA() - other.getYC()), 2));
					if (d <= getR()){
						d = sqrt(pow((getXA() - other.getXD()), 2) + pow((getYA() - other.getYD()), 2));
						if (d <= getR())
							return true;
					}
				}
			}
			return false;
		}
		if (other.getType() == 't'){
			double d;
			d = sqrt(pow((getXA() - other.getXA()), 2) + pow((getYA() - other.getYA()), 2));
			if (d <= getR()){
				d = sqrt(pow((getXA() - other.getXB()), 2) + pow((getYA() - other.getYB()), 2));
				if (d <= getR()){
					d = sqrt(pow((getXA() - other.getXC()), 2) + pow((getYA() - other.getYC()), 2));
					if (d <= getR())
						return true;
				}
			}
			return false;
		}
	}
}
bool Figure::isTheDotInTheSquare(double, double){
	return 0;
}
double Figure::getXA()const{
	return xA;
}
double Figure::getXB()const{
	return xB;
}
double Figure::getXC()const{
	return xC;
}
double Figure::getXD()const{
	return xD;
}
double Figure::getYA()const{
	return yA;
}
double Figure::getYB()const{
	return yB;
}
double Figure::getYC()const{
	return yC;
}
double Figure::getYD()const{
	return yD;
}



void Figure::setXA(double xA){
	this->xA = xA;
}
void Figure::setXB(double xB){
	this->xB = xB;
}
void Figure::setXC(double xC){
	this->xC = xC;
}
void Figure::setXD(double xD){
	this->xD = xD;
}
void Figure::setYA(double yA){
	this->yA = yA;
}
void Figure::setYB(double yB){
	this->yB = yB;
}
void Figure::setYC(double yC){
	this->yC = yC;
}
void Figure::setYD(double yD){
	this->yD = yD;
}

double Figure::Area(){
	return 0;
}
double Figure::Perimetre(){
	return 0;
}
void Figure::Print(){

}
Figure::~Figure()
{
}
