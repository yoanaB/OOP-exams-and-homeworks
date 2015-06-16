#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

const double PI = 3.141592;

struct Point{
	double x, y;
	Point(double a = 0, double b = 0){
		x = a; y = b;
	}
	void print() const{
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class Figure{
	virtual double getRadius() const = 0;
public:
	virtual ~Figure(){}
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual bool isInside(const Point& point) const = 0;
	virtual Point getCenter() const = 0;
	virtual int getType() const = 0;
	virtual Point getPoint(int n = 0) const = 0;
	double getSide(const Point& A, const Point& B) const{
		return sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
	}

	//проверява дали аргумента е в текущата фигура
	bool isIn(const Figure& other) const{
		if (other.getType() == 1){
			for (size_t i = 0; i < 4; i++){
				if (!isInside(other.getPoint(i)))
					return false;
			}
		}
		else if (other.getType() == 2){
			if (!isInside(other.getPoint()))
				return false;
			if (getType() == 1){
				for (size_t i = 0; i < 3; i++)
					if (abs(getPoint(i).x - other.getPoint().x) < other.getRadius() && abs(getPoint(i).y - other.getPoint().y) < other.getRadius())
						return false;
			}
			if (getType() == 2)
				if (getRadius() - other.getRadius() < getSide(getCenter(), other.getCenter()))
					return false;
		}
		else{
			for (size_t i = 0; i < 3; i++){
				if (!isInside(other.getPoint(i)))
					return false;
			}
		}
		return true;
	}
};

class Rectangle : public Figure{
	Point points[4];
public:
	Rectangle(const Point& A = Point(0, 0), const Point& C = Point(0, 0)){
		points[0] = A;
		points[1].y = A.y;
		points[1].x = C.x;
		points[2] = C;
		points[3].x = A.x;
		points[3].y = C.y;
	}
	Rectangle(const Rectangle& other){
		for (size_t i = 0; i < 4; i++){
			points[i] = other.points[i];
		}
	}
	~Rectangle(){}
	Rectangle& operator=(const Rectangle& other){
		if (this != &other){
			for (size_t i = 0; i < 4; i++){
				points[i] = other.points[i];
			}
		}
		return *this;
	}

	double getHeight() const{
		return points[3].y - points[0].y;
	}
	double getWidth() const{
		return points[1].x - points[0].x;
	}

	virtual double getArea(){
		return getWidth() * getHeight();
	}
	virtual double getPerimeter(){
		return 2 * (getWidth() + getHeight());
	}

	virtual bool isInside(const Point& point) const {
		return point.x >= points[0].x && point.x <= points[1].x &&
			point.y >= points[0].y && point.y <= points[3].y;
	}
	virtual Point getCenter() const{
		return Point(points[0].x + (points[1].x - points[0].x) / 2, points[0].y + (points[3].y - points[0].y) / 2);
	}
	virtual int getType() const{
		return 1;
	}
	virtual Point getPoint(int i = 0) const{
		assert(i >= 0 && i <= 3);
		return points[i];
	}
	virtual double getRadius() const{ return 0; }

};

class Circle : public Figure{
	Point center;
	double radius;
public:
	Circle(const Point& A = Point(0, 0), double radius = 0){
		center = A;
		this->radius = radius;
	}
	Circle(const Circle& other){
		center = other.center;
		this->radius = other.radius;
	}
	Circle& operator=(const Circle& other){
		if (this != &other){
			center = other.center;
			this->radius = other.radius;
		}
		return *this;
	}

	virtual double getArea(){
		return PI*radius*radius;
	}
	virtual double getPerimeter(){
		return 2 * PI * radius;
	}

	virtual bool isInside(const Point& point) const {
		return (point.x - center.x)*(point.x - center.x) + (point.y - center.y) *(point.y - center.y) <= radius*radius;
	}
	virtual Point getCenter() const{
		return center;
	}
	virtual int getType() const{
		return 2;
	}
	virtual Point getPoint(int i = 0) const{
		return center;
	}
	virtual double getRadius() const{
		return radius;
	}
};

class Triangle : public Figure{
	Point points[3];
public:
	Triangle(const Point& A = Point(0, 0), const Point& B = Point(0, 0), const Point& C = Point(0, 0)){
		points[0] = A;
		points[1] = B;
		points[2] = C;
	}

	double getSideC() const{
		return getSide(points[0], points[1]);
	}
	double getSideA() const{
		return getSide(points[1], points[2]);
	}
	double getSideB() const{
		return getSide(points[0], points[2]);
	}

	virtual double getArea(){
		double p = getPerimeter() / 2;
		return sqrt(p*(p - getSideA())*(p - getSideB())* (p - getSideC()));
	}
	virtual double getPerimeter(){
		return getSideA() + getSideB() + getSideC();
	}

	double sign(const Point& p1, const Point& p2, const Point& p3) const
	{
		return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
	}
	virtual bool isInside(const Point& point) const {
		bool b1, b2, b3;
		b1 = sign(point, points[0], points[1]) < 0;
		b2 = sign(point, points[1], points[2]) < 0;
		b3 = sign(point, points[2], points[0]) < 0;

		return ((b1 == b2) && (b2 == b3));
	}
	virtual Point getCenter() const{
		return Point((points[0].x + points[1].x + points[2].x) / 3, (points[0].y + points[1].y + points[2].y) / 3);
	}
	virtual int getType() const{
		return 3;
	}
	virtual Point getPoint(int i = 0) const{
		assert(i >= 0 && i <= 2);
		return points[i];
	}
	virtual double getRadius() const{ return 0; }
};

int main(){
	Triangle a(Point(0, 0), Point(5, 0), Point(0, 5));
	if (a.isInside(Point(2, 3)))
		cout << "Point (2,3) is inside Triangle a" << endl;

	Rectangle b(Point(0, 0), Point(5, 5));
	if (b.isInside(Point(5, 5)))
		cout << "Point (5,5) is inside Rectangle b" << endl;

	Circle c(Point(3, 3), 3);
	if (c.isInside(Point(4, 6)))
		cout << "Point (4,6) is inside Circle c" << endl;
	Circle d(Point(4, 4), 1);
	if (c.isIn(d))
		cout << "Circle d is in Circle c" << endl;

	if (a.isIn(b))
		cout << "Rectangle b is in Triangle a" << endl;
	Triangle e(Point(1, 1), Point(3, 0), Point(4, 5));
	if (b.isIn(e))
		cout << "Triangle e is in Rectangle b" << endl;

	Rectangle f(Point(1, 1), Point(3, 2));
	if (a.isIn(f))
		cout << "Rectangle f is in Triangle a" << endl;
	if (b.isIn(d))
		cout << "Circle d is in Rectangle b" << endl;

	system("pause");
	return 0;
}



#endif
