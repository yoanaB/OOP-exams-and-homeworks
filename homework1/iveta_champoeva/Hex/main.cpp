//Iveta Champoeva 71530 purva grupa, no ne e dovurshena

#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>

using namespace std;

const int hexCapacity = 100;

int charToDigit(char ch)
{
    return (int)ch - 48;
}

void toLower (char& ch)
{
    if(ch >= 'A' && ch <= 'Z')
        ch -= ('A' - 'a');
}

char digitToChar(int n)
{
    if(n >= 0 && n <=9)
        return (char)(n + 48);
    if(n >= 10 && n <= 15)
        return (char) (n+55);
}

class Hex
{
private:
    char* hex;
    int size;
    void copy(const Hex& other)
    {
        hex = new char[(other.size)];
        assert(hex != NULL);
        for(int i=0;i<size;i++)
        {
            hex[i] = other.hex[i];
        }
        size = other.size;
    }
    void del()
    {
        delete [] hex;
    }
public:
    bool isHex(char* h)
    {
        for(int i=0;i<strlen(h);i++)
        {
            if(((int)h[i]<(int)'a'||(int)h[i]>(int)'f')&&((int)h[i]<(int)'A'||(int)h[i]>(int)'F')&&((int)h[i]<(int)'0'||(int)h[i]>(int)'9'))
                return false;
        }
        return true;
    }
    Hex(char* h = "0")
    {
        if(isHex(h))
        {
            size = strlen(h);
            int tmp = size;
            if(size <= hexCapacity)
            {
                hex = new char[size];
                assert(hex!=NULL);
                for(int i=0;i<size;i++)
                {
                    hex[i] = h[tmp-1];
                    tmp--;
                }
            }
        }
        else
        {
            hex = "";
            size = 0;
        }

    }
    ~Hex()
    {
        del();
    }
    Hex(const Hex& other)
    {
        copy(other);
    }
    Hex& operator= (const Hex& other)
    {
        if(this != &other)
        {
            del();
            copy(other);
        }
        return *this;
    }
    char* getHex() const
    {
        return hex;
    }
    unsigned int hexToBase(char* h)
    {
        unsigned int sum = 0;
        for(int i=0;i<size;i++)
        {
            char c = (h[i]);
            toLower(c);
            if(c>= '0' && c <= '9')
                sum += (charToDigit(c))*(pow(16,i));
            if(c >= 'a' && c <= 'f')
            {
                switch (c)
                {
                    case 'a' : sum += 10 * pow(16,i);break;
                    case 'b' : sum += 11 * pow(16,i);break;
                    case 'c' : sum += 12 * pow(16,i);break;
                    case 'd' : sum += 13 * pow(16,i);break;
                    case 'e' : sum += 14 * pow(16,i);break;
                    case 'f' : sum += 15 * pow(16,i);break;
                }
            }
        }
        return sum;
    }
    Hex baseToHex(unsigned int n)
    {
        int i=0;
        unsigned int tmp = n;
        while(tmp > 1)
        {
            tmp/=16;
            i++;
        }
        Hex h;
        h.size = i;
        for(int j=0;j<i;j++)
        {
            h.hex[j] = digitToChar(n%16);
            n /= 16;
        }
        return h;
    }
    void print() const
    {
        for(int i=size-1;i>=0;i--)
        {
            cout<<hex[i];
        }
        cout<<endl;
    }
    Hex operator+(const Hex& other)
    {
        return baseToHex(hexToBase(hex) + hexToBase(other.hex));
    }
    Hex operator-(const Hex& other)
    {
        return baseToHex(hexToBase(hex) - hexToBase(other.hex));
    }
    Hex operator*(const Hex& other)
    {
        return baseToHex(hexToBase(hex) * hexToBase(other.hex));
    }
    bool operator<(const Hex& other)
    {
        return hexToBase(hex) < hexToBase(other.hex);
    }
    bool operator>(const Hex& other)
    {
        return hexToBase(hex) > hexToBase(other.hex);
    }
    bool operator==(const Hex& other)
    {
        return hexToBase(hex) == hexToBase(other.hex);
    }
};

int main()
{
    Hex h("3BC2F");
    h.print();
    Hex m("34D3F");
    m.print();
    Hex p = h-m;
    p.print();
    Hex d = h+m;
    d.print();
    return 0;
}
