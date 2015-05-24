#ifndef HEX_H
#define HEX_H

class Hex
{
private:
	char* hexNumber;

public:
	Hex();
	Hex(char*);
	~Hex();
	Hex& operator+(const Hex&);
	Hex& operator-(const Hex&);
	Hex& operator*(const Hex&);
	Hex& operator/(const Hex&);
	Hex& operator=(const Hex&);
	bool operator>(const Hex&);
	bool operator<(const Hex&);
	bool operator==(const Hex&);
	bool operator!= (const Hex&);

	void print() const;
};

#endif