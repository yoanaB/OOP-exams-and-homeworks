#ifndef figure_h
#define figure_h

class Figure
{
private:
	int height;
	int side; 
public:
	Figure(int side = 0 , int height = 0);
	Figure(Figure&);
	Figure& operator=(const Figure&);

	void setSide(int);
	int getSide() const;
	void setHeight(int);
	int getHeight() const; 
	void print() const;
};
#endif figure_h