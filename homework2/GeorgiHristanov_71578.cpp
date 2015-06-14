#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class Point {
public:
    Point(double x = 0, double y = 0) {
        initPoint(x, y);
    }

    Point(const Point& other) {
        initPoint(other.x, other.y);
    }

    Point& operator=(const Point& other) {
        if (this != &other) {
            initPoint(other.x, other.y);
        };
        return *this;
    }

    ~Point(){};

    void setX(double x) {
        this -> x = x;
    }

    void setY(double y) {
        this -> y = y;
    }

    double getX() const {
        return this -> x;
    }

    double getY() const {
        return this -> y;
    }

    bool operator==(const Point& other) {
        if (other.x == this -> x && other.y == this -> y) {
            return true;
        };
        return false;
    }

    double calcDistance(Point first, Point second) {
        return sqrt((second.getX() - first.getX()) * (second.getX() - first.getX()) + (second.getY() - first.getY()) * (second.getY() - first.getY()));
    }

    void printInfo() const {
        cout << "x: " << this -> x << ", y: " << this -> y << endl;
    }
protected:
    double x;
    double y;

    void initPoint(double x, double y) {
        this -> x = x;
        this -> y = y;
    }
};

class Figure: public Point {
public:
    virtual char* getType() const = 0;
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual Point getCentre() = 0;
    virtual bool contains(Figure& other) = 0;

    Figure(){};
    Figure(const Figure& other){};
    Figure& operator=(const Figure& other){};
    bool operator==(const Figure&);
    ~Figure(){};

    void printInfo() {
        cout << "Perimeter: " << this -> getPerimeter() << ", Area: " << this -> getArea() << ", Center: ";
        (this -> getCentre()).printInfo();
    }
};

class Triangle: public Figure {
public:
    bool check(Point a, Point b, Point c) {
        double ab = calcDistance(a, b);
        double bc = calcDistance(b, c);
        double ca = calcDistance(c, a);

        return ((ab + bc > ca) && (bc + ca > ab) && (ab + ca > bc));
    }

    Triangle(Point a = Point(0, 0), Point b = Point(1, 0), Point c = Point(0, 1)){
        if (check(a, b, c)) {
            this -> a = a;
            this -> b = b;
            this -> c = c;
        } else {
            this -> a = Point(0, 0);
            this -> b = Point(1, 0);
            this -> c = Point(0, 1);
        }
    }

    Triangle(const Triangle& other){
        this -> a = other.a;
        this -> b = other.b;
        this -> c = other.c;
    }

    Triangle& operator=(const Triangle& other){
        if (this != &other) {
            this -> a = other.a;
            this -> b = other.b;
            this -> c = other.c;
        }
        return *this;
    }

    bool operator==(const Triangle& other) {
        return (this -> a == other.a && this -> b == other.b && this -> c == other.c);
    }

    char* getType() const {
        return "triangle";
    }

    bool contains(Figure& other) {};

    double getPerimeter() {
        double ab = calcDistance(this -> a, this -> b);
        double bc = calcDistance(this -> b, this -> c);
        double ca = calcDistance(this -> c, this -> a);

        return (ab + bc + ca);
    }

    double getArea() {
        double halfPerimeter = this -> getPerimeter() / 2;
        double ab = calcDistance(this -> a, this -> b);
        double bc = calcDistance(this -> b, this -> c);
        double ca = calcDistance(this -> c, this -> a);

        return sqrt(halfPerimeter * (halfPerimeter - ab) * (halfPerimeter - bc) * (halfPerimeter - ca));
    }

    Point getCentre() {
        double resultX = (this -> a.getX() + this -> b.getX() + this -> c.getX()) / 3;
        double resultY = (this -> a.getY() + this -> b.getY() + this -> c.getY()) / 3;

        return Point(resultX, resultY);
    }
private:
    Point a;
    Point b;
    Point c;
};

class Rectangle: public Figure {
public:
    bool check(Point a, Point b, Point c, Point d) {
        return (a.getY() == b.getY() && a.getX() == d.getX() && b.getX() == c.getX() && c.getY() == d.getY());  //Check ABCD
    }

    Rectangle(Point a = Point(0, 0), Point b = Point(1, 0), Point c = Point(1, 1), Point d = Point(0, 1)) {
        if (check(a, b, c, d)) {
            this -> a = a;
            this -> b = b;
            this -> c = c;
            this -> d = d;
        } else {
            this -> a = Point(0, 0);
            this -> b = Point(1, 0);
            this -> c = Point(1, 1);
            this -> d = Point(0, 1);
        }
    }

    Rectangle(const Rectangle& other) {
        this -> a = other.a;
        this -> b = other.b;
        this -> c = other.c;
        this -> d = other.d;
    }

    Rectangle& operator=(const Rectangle& other) {
        if (this != &other) {
            this -> a = other.a;
            this -> b = other.b;
            this -> c = other.c;
            this -> d = other.d;
        }
        return *this;
    }

    bool operator==(const Rectangle& other) {
        return (this -> a == other.a && this -> b == other.b && this -> c == other.c && this -> d == other.d);
    }

    char* getType() const{
        return "rectangle";
    }

    bool contains(Figure& other) {
        /*
        bool result = false;
        if (strcmp(other.getType(), "triangle") == 0) {
            if (this -> a.getY() < other.a.getY() &&
                this -> a.getX() < other.a.getX() && this -> a.getX() < other.c.getX();
                this -> b.getX() > other.b.getY() && this -> b.getX() > other.c.getX();
                this -> c.getY() > other.c.getY()) {
                    result = true;
            };
        }
        return result;
        */
    }

    double getPerimeter() {
        double ab = calcDistance(this -> a, this -> b);
        double bc = calcDistance(this -> b, this -> c);
        double cd = calcDistance(this -> c, this -> d);
        double da = calcDistance(this -> d, this -> a);

        return (ab + bc + cd + da);
    }

    double getArea() {
        double ab = calcDistance(this -> a, this -> b);
        double ad = calcDistance(this -> a, this -> d);

        return sqrt(ab * ad);
    }

    Point getCentre() {
        double resultX = (this -> a.getX() + this -> b.getX()) / 2;
        double resultY = (this -> a.getY() + this -> d.getY()) / 2;

        return Point(resultX, resultY);
    }
private:
    Point a;
    Point b;
    Point c;
    Point d;
};
class Circle: public Figure {
public:
    bool check(double radius) {
        if (radius > 0) {
            return true;
        };
        return false;
    }

    Circle(Point o = Point(0, 0), int radius = 1) {
        if (check(radius)) {
            this -> o = o;
            this -> radius = radius;
        } else {
            this -> o = Point(0, 0);
            this -> radius = 1;
        }
    }

    Circle(const Circle& other) {
        this -> o = other.o;
        this -> radius = other.radius;
    }

    Circle& operator=(const Circle& other) {
        if (this != &other) {
            this -> o = other.o;
            this -> radius = other.radius;
        }
        return *this;
    }

    bool operator==(const Circle& other) {
        return (this -> o == other.o && this -> radius == other.radius);
    }

    char* getType() const{
        return "circle";
    }

    bool contains(Figure& other) {};

    double getPerimeter() {
        return (2 * M_PI * this -> radius);
    }

    double getArea() {
        return (M_PI * this -> radius * this -> radius);
    }

    Point getCentre() {
        return this -> o;
    }
private:
    Point o;
    double radius;
};

int main()
{
    Triangle p(Point(0, 0), Point(6, 0), Point(0, 5));
    p.printInfo();
    Rectangle gosho;
    Rectangle pesho(Point(0, 0), Point(2, 0), Point(2, 1), Point(0, 1));
    gosho = pesho;
    pesho.printInfo();
    cout << (gosho == pesho) << endl;
    Circle ivan;
    ivan.printInfo();
    return 0;
}
