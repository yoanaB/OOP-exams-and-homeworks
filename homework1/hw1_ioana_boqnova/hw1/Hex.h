#ifndef HEX_H
#define HEX_H

class HNumber
{
public:
	HNumber();
	~HNumber();
	HNumber(const HNumber&);
	HNumber& operator=(const HNumber&);
	HNumber(char*);
	void setNumber(char*);
	const char* getNumber() const;
	void read();
	void print() const;
	int convertInInt(char*);
	char* convertInChar(int);
	bool operator== (const HNumber&);
	bool operator> ( HNumber&);
	bool operator< ( HNumber&);
	bool operator<= ( HNumber&);
	bool operator>= ( HNumber&);
	HNumber& operator+ ( HNumber&);
	HNumber& operator- ( HNumber&);
	HNumber& operator* ( HNumber&);
	HNumber& operator/ ( HNumber&);
	HNumber& operator% (HNumber&);
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
	int maxSize = 100;
};

#endif
