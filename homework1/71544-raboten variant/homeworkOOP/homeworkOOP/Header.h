/*Задача 1. Да се дефинира клас Hex за работа с цели шестнадесетични числа без знак.
За представяне на числата да се използва масив от най-много 100 елемента от тип
unsigned char, всеки от които представя шестнадесетична цифра. Младшата цифра
има най-малък индекс (цифрата на единиците е в нулевия елемент на масива).
Реалният размер на масива се задава като аргумент на конструктора. 
Да се реализират каноничното представяне, аритметичните операции и операциите за сравнение.*/
#ifndef HEX_H
#define HEX_H

const int maxSize = 100;
class Hex
{
public:
	Hex();
	Hex(const Hex&);
	Hex(char*);
	Hex& operator=(const Hex&);
	~Hex();
	void print()const;

	Hex& operator+(const Hex&);
	Hex& operator-(const Hex&);
	Hex& operator*(const Hex&);
	Hex& operator/(const Hex&);

	bool operator>(const Hex&);
	bool operator==(const Hex&);
	bool operator<(const Hex&);
	bool operator>=(const Hex&);
	bool operator<=(const Hex&);
	bool operator!=(const Hex&);

	
private:
	char* hex;
	int size;
	int fromHextoDec(const Hex&);
};

#endif