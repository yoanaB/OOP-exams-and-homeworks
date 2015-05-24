#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
class Hex
{
private:
    unsigned char hexx[100];
    int n;
public:
    Hex(char* hexx = "123", int n = 3)
    {
        this -> n = n;
        strncpy((char*)this -> hexx,hexx,n);
    }

    Hex(const Hex &other)
    {
        n = other.n;
        strcpy((char*)hexx,(char*)other.hexx);
        hexx[n] = '\0';
    }
    Hex &operator=(const Hex &other)
    {
        delete []hexx;
        n = other.n;
        strcpy((char*)hexx,(char*)other.hexx);
        hexx[n] = '\0';
        return *this;
    }
    void print()
    {
        cout << hexx;
    }
    int hexToDec()
    {
        int dec = 0;
        for(int i = n - 1,power = 0; i >= 0; i--, power++)
        {
            int temp;
            if(hexx[i] >= '0' && hexx[i] <= '9')
                temp = hexx[i] - '0';
            else if(hexx[i] >= 'a' && hexx[i] <= 'f')
            {
                temp = hexx[i] - 'a' + 10;
            }
            dec += temp*pow(16,power);
        }
        return dec;
    }
    unsigned char* decToHex(int m)
    {
        int i = 0;
        unsigned char hex[99];
        while(m>0)
        {
            if(m%16 >= 0 && m%16 <= 9)
                hex[i] = (char)(m%16 + '0');
            else hex[i] = (char)(m%16 + 'a' - 10);
            m /= 16;
            i++;
        }
        hex[i] = '\0';
        for(int j = 0; j < i/2; j++)
        {
            swap(hex[j],hex[i-1-j]);
        }
        return hex;
    }
    Hex operator+(Hex &other)
    {
        int a = hexToDec() + other.hexToDec();
        delete []hexx;
        strcpy((char*)hexx, (char*)decToHex(a));
        return *this;
    }
    Hex operator-(Hex &other)
    {
        int a = hexToDec() - other.hexToDec();
        delete []hexx;
        strcpy((char*)hexx, (char*)decToHex(a));
        return *this;
    }
    Hex operator*(Hex &other)
    {
        int a = hexToDec() * other.hexToDec();
        delete []hexx;
        strcpy((char*)hexx, (char*)decToHex(a));
        return *this;
    }
    Hex operator/(Hex &other)
    {
        int a = hexToDec() / other.hexToDec();
        delete []hexx;
        strcpy((char*)hexx, (char*)decToHex(a));
        return *this;
    }
    bool operator<(Hex &other)
    {
        if(hexToDec() < other.hexToDec())
            return true;
    }
    bool operator>(Hex &other)
    {
        if(hexToDec() < other.hexToDec())
            return true;
    }
};
int main()
{
    Hex h2("2252",4);
    Hex h1;
    h1 = h2;
    h1.print();
    return 0;
}
