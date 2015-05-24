#ifndef HEX_H
#define HEX_H

class HNumber
{
public:
	HNumber();
	~HNumber();
	HNumber(const HNumber&);
	HNumber& operator=(const HNumber&);
	void setNumber(char*);
	char* getNumber() const;
	void read();
	void print() const;
	bool operator== (const HNumber&);
	bool operator> (const HNumber&);
	bool operator< (const HNumber&);
	bool operator<= (const HNumber&);
	bool operator>= (const HNumber&);
	HNumber& operator+ (const HNumber&);
	HNumber& operator- (const HNumber&);
	HNumber& operator* (const HNumber&);
	HNumber& operator/ (const HNumber&);
private:
	char* number;
};

class Hex
{
public:
	Hex();
	~Hex();
	Hex(const Hex&);
	Hex& operator= (const Hex&);
	int getCount() const;
	void addNumber(const HNumber&);
	void deleteNumber(char*);
private:
	HNumber* hex;
	int count;
	int size;
};

#endif