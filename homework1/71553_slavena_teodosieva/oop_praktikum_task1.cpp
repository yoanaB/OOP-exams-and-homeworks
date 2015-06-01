#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;
class Binary
{
    char* binaryNum;
    int sizeOfNum;
    int capacity;
public:
    Binary(char* binaryNum = "00", int sizeOfNum = 0, int capacity = 2)
    {
        this->sizeOfNum = sizeOfNum;
        this->capacity = capacity;
        binaryNum = new char[capacity];
        assert(binaryNum!=NULL);
    }
    Binary(const Binary& other)
    {
        sizeOfNum = other.sizeOfNum;
        capacity = other.capacity;
        binaryNum = new char[other.capacity];
        assert(binaryNum!=NULL);
        strcpy(binaryNum, other.binaryNum);
    }
    ~Binary()
    {
        delete [] binaryNum;
    }
    Binary& operator=(const Binary& other)
    {
        if(this!=&other)
        {
            delete [] binaryNum;
            sizeOfNum = other.sizeOfNum;
            capacity = other.capacity;
            binaryNum = new char[other.capacity];
            assert(binaryNum!=NULL);
            strcpy(binaryNum, other.binaryNum);
        }
        return *this;
    }
    void setSizeOfNum(int _size)
    {
        if(_size > 0)
            sizeOfNum = _size;
        else
            cout<<"Nevaliden razmer"<<endl;
    }
    void setCapacity(int _capacity)
    {
        if(_capacity > 0)
            capacity = _capacity;
        else
            cout<<"Nevaliden kapacitet"<<endl;
    }
    int getSizeOfNum() const
    {
        return sizeOfNum;
    }
    int getCapacity() const
    {
        return capacity;
    }
    void print()
    {
        cout<<"Binary"<<endl;
        cout<<"Size: "<<sizeOfNum<<endl
            <<"Capacity: "<<capacity<<endl
            <<"Binary number: "<<binaryNum<<endl;
    }
    bool operator>(const Binary& other)
    {
        return fromBinary(this->binaryNum) > fromBinary(other.binaryNum);
    }
    bool operator<(const Binary& other)
    {
        return fromBinary(this->binaryNum) < fromBinary(other.binaryNum);
    }
    Binary operator+(const Binary& other)
    {
        int maxSize = 0;
        if(strlen(this->binaryNum) > strlen(other.binaryNum))
            maxSize = strlen(this->binaryNum);
        else
            maxSize = strlen(other.binaryNum);
        Binary result = new char[maxSize+2];
        assert(result!=NULL);
        int tmp = fromBinary(this->binaryNum) + fromBinary(other.binaryNum);
        strcpy(result.binaryNum, toBinary(tmp));
        return result.binaryNum;
    }
    Binary operator-(const Binary& other)
    {
        int maxSize = 0;
        if(strlen(this->binaryNum) > strlen(other.binaryNum))
            maxSize = strlen(this->binaryNum);
        else
            maxSize = strlen(other.binaryNum);
        Binary result = new char[maxSize+2];
        assert(result!=NULL);
        if(fromBinary(this->binaryNum) > fromBinary(other.binaryNum))
        {
            int tmp = fromBinary(this->binaryNum) - fromBinary(other.binaryNum);
            strcpy(result.binaryNum, toBinary(tmp));
            return result.binaryNum;
        }
        else
            return 0;
    }

    char* toBinary(int n)
    {
        int i = 0;
        do
        {
            binaryNum[i]=n%2;
            n=n/2;
            i++;
        } while(n!=0);
        int sizeOfNum = i;
        binaryNum[i]='\0';
        for(int i=0; i<sizeOfNum/2; i++)
        {
            char tmp = binaryNum[i];
            binaryNum[i] = binaryNum[sizeOfNum - i - 1];
            binaryNum[sizeOfNum - i - 1] = tmp;
        }
        return binaryNum;
    }
    int fromBinary(char* binary)
    {
        int sum = 0, k = 0;
        for(int i=strlen(binary)-1; i>=0; i--)
        {
            sum = binary[i]*(pow(2,k));
            k++;
        }
        return sum;
    }
};

int main()
{
    return 0;
}
