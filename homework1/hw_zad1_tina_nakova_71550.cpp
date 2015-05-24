#include <iostream>
#include <cassert>
#include <cstring>
#include<cmath>

using namespace std;


class Mybinary
{
private:
    char *number;
    int size;
    int capacity;
public:
    Mybinary()
    {
        capacity = 1;
        size = 0;
        number = new char [capacity];
    }
    Mybinary(char* number, int size, int capacity)
    {
        this->number = new char [strlen(number)+1];
        assert(this->number != NULL);
        strcpy(this->number, number);
        this->size = size;
        this->capacity = capacity;
    }
    Mybinary(const Mybinary& other)
    {
        number = new char [strlen(other.number)+1];
        assert(this->number != NULL);
        strcpy(number, other.number);
        size = other.size;
        capacity = other.capacity;
    }
    ~Mybinary()
    {
        delete[]number;
    }
    Mybinary& operator=(const Mybinary& other)
    {
        if(this != & other)
        {
            delete[]number;
             number = new char [strlen(other.number)+1];
            assert(this->number != NULL);
            strcpy(number, other.number);
            size = other.size;
            capacity = other.capacity;

        }
        return *this;
    }
    int& decimal()
    {
        int* result = 0;
        int j;
        for(int i = size, j = 0; i > 0; i--, j++)
        {
            int a = number[i];
            int temp = a*pow(2,j);
            result += temp;
        }
        return *result;
    }
};

int main()
{
    return 0;
}
