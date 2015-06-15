#include <iostream>
#include <cmath>
using namespace std;

class Figure{
protected:
    double dim1, dim2, dim3;
    void init(double dim1, double dim2, double dim3){
        this->dim1 = dim1;
        this->dim2 = dim2;
        this->dim3 = dim3;
    }
public:
    void set_area(double d1, double d2, double d3){
        dim1 = d1;
        dim2 = d2;
        dim3 = d3;
    }
    void get_area(double &d1, double &d2, double &d3){
        d1 = dim1;
        d2 = dim2;
        d3 = dim3;
    }

    virtual double face()=0;
    virtual double perim()=0;
    virtual double center()=0;

    bool operator==(const Figure& other) const{
        if(this->dim1 == other.dim1 && this->dim2 == other.dim2 && this->dim3 == other.dim3){
            return true;
        }
        return false;
    }

    Figure(double dim1 = 0, double dim2 = 0, double dim3 = 0){
        init(dim1, dim2, dim3);
    }

    Figure(const Figure& other){
        init(other.dim1, other.dim2, other.dim3);
    }

    Figure& operator=(const Figure& other){
        if(this != &other){
            init(other.dim1, other.dim2, other.dim3);
        }
        return *this;
    }

    ~Figure() { }
};

class Triangle : public Figure{
public:
    double face(){
        double d1, d2, d3, p;
        get_area(d1, d2, d3);
        p = (d1 + d2 + d3) / 2;
        return sqrt(p * (p - d1) * (p - d2) * (p - d3));
    }

    double perim(){
        double d1, d2, d3;
        get_area(d1, d2, d3);
        return d1 + d2 + d3;
    }

    double center(){
        double d1, d2, d3;
        get_area(d1, d2, d3);
        if((d1 == d2) && (d2 == d3)){
            return (cos(180 / 3) / sin(180 / 3)) * (d1 / 2); // radius of inscribed circle
        }else{
            return 0;
        }
    }

    Triangle(double dim1 = 0, double dim2 = 0, double dim3 = 0) : Figure(dim1, dim2, dim3) {}
};

class Rectangle : public Figure{
public:
    double face(){
        double d1, d2, d3;
        get_area(d1, d2, d3);
        return d1 * d2;
    }

    double perim(){
        double d1, d2, d3;
        get_area(d1, d2, d3);
        return (d1 + d2) * 2;
    }

    double center(){
        double d1, d2, d3;
        get_area(d1, d2, d3);
        if(d1 == d2){
            return (cos(180 / 4) / sin(180 / 4)) * (d1 / 2); // radius of inscribed circle
        }else{
            return 0;
        }
    }

    Rectangle(double dim1 = 0, double dim2 = 0, double dim3 = 0) : Figure(dim1, dim2, dim3) {}
};

class Circle : public Figure{
public:
    double face(){
        double d1, d2, d3;
        get_area(d1, d2, d3);
        return pow(d1, 2) * M_PI;
    }

    double perim(){
        double d1, d2, d3;
        get_area(d1, d2, d3);
        return 2 * M_PI * d1;
    }

    double center(){
        return 0;
    }

    Circle(double dim1 = 0, double dim2 = 0, double dim3 = 0) : Figure(dim1, dim2, dim3) {}
};

int main(){
    Figure *p;
    Triangle t;
    Rectangle r;
    Circle c;

    t.set_area(3, 4, 5);
    r.set_area(5, 8, 0);
    c.set_area(4, 0, 0);

    p=&t;
    cout << "\nTriangle face: " << p->face();
    cout << "\nTriangle perimeter: " << p->perim();
    cout << "\nRadius of inscribed circle: " << p->center() << endl;

    p=&r;
    cout << "\nRectangle face: " << p->face();
    cout << "\nRectangle perimeter: " << p->perim();
    cout << "\nRadius of inscribed circle: " << p->center() << endl;

    p=&c;
    cout << "\nCircle face: " << p->face();
    cout << "\nCircle perimeter: " << p->perim() << endl;

    return 0;
}
