#include <iostream>
#include <cassert>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Mybinary
{
private:
	char* number;
	int size;
public:
	Mybinary()
	{
		size = 1;
		number = new char[size];
	}
	Mybinary(char* number, int size)
	{
		this->number = new char[strlen(number) + 1];
		assert(this->number != NULL);
		strcpy(this->number, number);
		this->size = size;
	}
	Mybinary(const Mybinary& other)
	{
		number = new char[strlen(other.number) + 1];
		assert(this->number != NULL);
		strcpy(number, other.number);
		size = other.size;
	}
	~Mybinary()
	{
		delete[]number;
	}
	Mybinary& operator=(const Mybinary& other)
	{
		if (this != &other)
		{
			delete[]number;
			number = new char[strlen(other.number) + 1];
			assert(this->number != NULL);
			strcpy(number, other.number);
			size = other.size;

		}
		return *this;
	}
	int decimal()
	{
		int result = 0;
		int j = 0;
		for (int i = size - 1; i >= 0; i--)
		{
			int temp = ch_to_int(number[i]);
			result += temp*pow(2, size -i -1);
		}
		return result;
	}

	int& ch_to_int(char a)
{
    int* temp = new int;
    switch(a)
    {
        case '0': *temp = 0; break;
        case '1': *temp = 1; break;
        case '2': *temp = 2; break;
        case '3': *temp = 3; break;
        case '4': *temp = 4; break;
        case '5': *temp = 5; break;
        case '6': *temp = 6; break;
        case '7': *temp = 7; break;
        case '8': *temp = 8; break;
        case '9': *temp = 9; break;
    }
    return *temp;
}

    char* binary(int number)
    {
        int size = 0;
        int num_cpy = number;
        while (num_cpy)
        {
            num_cpy /= 10;
            size++;
        }
        char* binary = new char[size];
        itoa(number, binary, 2);
        return binary;
    }

    Mybinary& operator+(Mybinary& other)
    {
        int fst = decimal();
        int snd = other.decimal();
        int new_value = fst + snd;
        int new_size = this->size+other.size;
        Mybinary* result = new Mybinary(binary(new_value), new_size);
        return *result;
    }
    Mybinary& operator-(Mybinary& other)
    {
        int fst = decimal();
        int snd = other.decimal();
        int new_value = fst - snd;
        int new_size = 0;
        int num_cpy = new_value;
        while (num_cpy)
        {
            num_cpy /= 10;
            new_size++;
        }
        Mybinary* result = new Mybinary(binary(new_value), new_size);
        return *result;
    }
    Mybinary& operator*(Mybinary& other)
    {
        int fst = decimal();
        int snd = other.decimal();
        int new_value = fst * snd;
        int new_size = 0;
        int num_cpy = new_value;
        while (num_cpy)
        {
            num_cpy /= 10;
            new_size++;
        }
        Mybinary* result = new Mybinary(binary(new_value), new_size);
        return *result;
    }
    Mybinary& operator/(Mybinary& other)
    {
        int fst = decimal();
        int snd = other.decimal();
        int new_value = fst / snd;
        int new_size = 0;
        int num_cpy = new_value;
        while (num_cpy)
        {
            num_cpy /= 10;
            new_size++;
        }
        Mybinary* result = new Mybinary(binary(new_value), new_size);
        return *result;
    }
    bool operator ==(const Mybinary& other)
    {
        return *this == other;
    }
    bool operator !=(const Mybinary& other)
    {
        return *this != other;
    }
    bool operator >(Mybinary& other)
    {
        return decimal() > other.decimal();
    }
    bool operator <(Mybinary& other)
    {
        return decimal() < other.decimal();
    }
    bool operator <=(Mybinary& other)
    {
        return decimal() <= other.decimal();
    }
    bool operator >=(Mybinary& other)
    {
        return decimal() >= other.decimal();
    }
    void print()
    {
        cout << "Binary number: " << number << endl;
    }

};

int main()
{
	Mybinary m("1011", 4);
	Mybinary n("011", 3);
	cout << m.decimal()  << endl; //11
	cout << n.decimal() << endl; //3
	Mybinary r = m + n;
	r.print(); //1110
	Mybinary d = m*n;
	d.print(); //100001
	if(n < m) cout << "Yes";

	return 0;
}
