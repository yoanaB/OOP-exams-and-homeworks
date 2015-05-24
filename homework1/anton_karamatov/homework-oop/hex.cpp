#include <cstring>
#include <cassert>
#include <iostream>
#include <cmath>
using namespace std;

class Hex
{
private:
    static const char HEX_VALUES[];
    char* hexValue;

    void init(char* hexValue)
    {
        this->hexValue = new char[strlen(hexValue) + 1];
        assert(this->hexValue != NULL);
        strcpy(this->hexValue, hexValue);
    }

    void init(int integerValue)
    {
        char value[100];
        int i = 0;
        do
        {
            value[i] = HEX_VALUES[integerValue % 16];
            integerValue /= 16;
            i++;
        }
        while(integerValue > 0);

        value[i] = '\0';
        init(strrev(value));
    }

    int getCharValue(char ch)
    {
        for(int i = 0; i < 16; i++)
        {
            if(ch == HEX_VALUES[i])
            {
                return i;
            }
        }
        return -1;
    }

    int convertToInt()
    {
        int value = 0;
        int length = strlen(this->hexValue);
        for(int i = 0; hexValue[i]; i++)
        {
            value += getCharValue(hexValue[i]) * pow(16, (length - i - 1));
        }
        return value;
    }

public:
    int getIntegerValue()
    {
        return convertToInt();
    }

    char* getHexadecimalValue()
    {
        return this->hexValue;
    }

    Hex()
    {
        init("0");
    }

    Hex(char* hexValue)
    {
        for(int i = 0; hexValue[i]; i++)
        {
            if(getCharValue(hexValue[i]) == -1)
            {
                throw "Invalid hex string";
            }
        }
        init(hexValue);
    }

    Hex(int integerValue)
    {
        if(integerValue < 0)
        {
            throw "Value must be a non-negative number";
        }
        init(integerValue);
    }

    Hex(const Hex& other)
    {
        init(other.hexValue);
    }

    Hex& operator= (const Hex& other)
    {
        if(this != &other)
        {
            delete[] this->hexValue;
            init(other.hexValue);
        }
        return *this;
    }

    ~Hex()
    {
        delete[] this->hexValue;
    }

    Hex operator+ (Hex& other)
    {
        Hex newHex(this->convertToInt() + other.convertToInt());
        return newHex;
    }

    Hex operator- (Hex& other)
    {
        Hex newHex(this->convertToInt() - other.convertToInt());
        return newHex;
    }

    Hex operator* (Hex& other)
    {
        Hex newHex(this->convertToInt() * other.convertToInt());
        return newHex;
    }

    Hex operator/ (Hex& other)
    {
        Hex newHex(this->convertToInt() / other.convertToInt());
        return newHex;
    }

    bool operator== (Hex& other)
    {
        return this->convertToInt() == other.convertToInt();
    }

    bool operator> (Hex& other)
    {
        return this->convertToInt() > other.convertToInt();
    }

    bool operator< (Hex& other)
    {
        return this->convertToInt() < other.convertToInt();
    }
};

const char Hex::HEX_VALUES[] = {'0', '1','2','3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main()
{

    return 0;
}
