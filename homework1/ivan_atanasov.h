#ifndef Hex_h
#define Hex_h

class Hex
{
public:
	Hex(char*,int);
	Hex(const Hex&);
	Hex& operator=(const Hex&);
	~Hex();

	void setNumber(const char*);
	Hex& operator+=(const Hex&);
	Hex operator+(const Hex&);
	Hex& operator-=(const Hex&);
	Hex operator-(const Hex&);
	Hex operator*(const Hex&);
	Hex operator/(const Hex&);

	bool operator<(const Hex&);
	bool operator>(const Hex&);
	bool operator<=(const Hex&);
	bool operator>=(const Hex&);
	bool operator==(const Hex&);
	bool operator!=(const Hex&);

	int HexToDec()const;

	void print() const;
	

private:
	unsigned char* number;
	int size;
};



#endif 