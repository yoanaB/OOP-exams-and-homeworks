#include<iostream>
#include<cassert>
using namespace std;
class Hex{
	char *number;
	unsigned arrayLength, maxArrayLength;
public:
	void setArrayLength(int arrayLength){
		this->arrayLength = arrayLength;
	}
	int getArrayLength(){
		return arrayLength;
	}
	char *getNumber(){
		return number;
	}
	void setNumber(char *number){
		this->number = new char[strlen(number) + 1];
		assert(number != NULL);
		strcpy_s(this->number, strlen(number) + 1, number);
	}
	Hex(char *number = "0", unsigned arrayLength = 1){
		
		if (arrayLength > 100)
			cout << "Bad Input";
		this->arrayLength = arrayLength;
		this->number = new char[this->arrayLength + 1];
		assert(this->number != NULL);//ABC2
		bool isLegit = true;
		for (size_t i = 0; i < strlen(number) + 1; i++){
			if (number[i] != '\0' && !((number[i] >= 'A' && number[i] <= 'F') || (number[i] >= 'a' && number[i] <= 'f') || (number[i] >= '0' &&number[i] <= '9')))
				isLegit = false;
			this->number[i] = number[i];
			if (!isLegit)
				cout << "Wrong Input!";
		}
		capitalise();
		reverse();

	}
	Hex(const Hex &other){
		number = new char[strlen(other.number) + 1];
		assert(number != NULL);
		for (size_t i = 0; i < strlen(number) + 1; i++){
			number[i] = other.number[i];
		}
	}
	Hex operator = (const Hex &other){
		if (this != NULL){
			delete[]number;
			number = new char[strlen(other.number) + 1];
			assert(number != NULL);
			for (size_t i = 0; i < strlen(number) + 1; i++){
				number[i] = other.number[i];
			}
		}
		return *this;
	}
	~Hex(){
		delete[]number;
	}
	bool operator >(const Hex &other){
		if (arrayLength > other.arrayLength)
			return true;
		else{
			for (size_t i = 0; i < arrayLength; i++){
				if (number[i]>other.number[i])
					return true;
				else if (number[i] < other.number[i])
					return false;
			}
			return false;
		}
	}
	bool operator <(const Hex &other){
		if (arrayLength < other.arrayLength)
			return true;
		else{
			for (size_t i = 0; i < arrayLength; i++){
				if (number[i] < other.number[i])
					return true;
				else if (number[i] > other.number[i])
					return false;
			}
			return false;
		}
	}
	bool operator >=(const Hex &other){
		if (arrayLength > other.arrayLength)
			return true;
		else{
			for (size_t i = 0; i < arrayLength; i++){
				if (number[i]>other.number[i])
					return true;
				else if (number[i] < other.number[i])
					return false;
			}
			return true;
		}
	}
	bool operator <=(const Hex &other){
		if (arrayLength < other.arrayLength)
			return true;
		else{
			for (size_t i = 0; i < arrayLength; i++){
				if (number[i] < other.number[i])
					return true;
				else if (number[i] > other.number[i])
					return false;
			}
			return true;
		}
	}
	bool operator ==(const Hex &other){
		if (arrayLength > other.arrayLength)
			return false;
		else{
			for (size_t i = 0; i < arrayLength; i++){
				if (number[i]>other.number[i])
					return false;
				else if (number[i] < other.number[i])
					return false;
			}
			return true;

		}
	}
	bool operator !=(const Hex &other){
		if (arrayLength > other.arrayLength)
			return true;
		else{
			for (size_t i = 0; i < arrayLength; i++){
				if (number[i]>other.number[i])
					return true;
				else if (number[i] < other.number[i])
					return true;
			}
			return false;

		}
	}
	Hex& operator +(const Hex &other){
		/*Not ready
		char *temp ;
		(strlen(number) >= strlen(other.number)) ? (temp = new char [strlen(number) + 2]) : (temp = new char[strlen(other.number) + 2]);
		for (int i = 0, k = 0, j = 0; i < strlen(temp) || k < strlen(number) || j < strlen(other.number); j++, k++, i++){
			
		}*/
	}
	/* trying to figure out how will be the sum
	int something(char b[1]){
		if (b[0] >= '0' && b[0] <= '9')
			return (((int)b[0]) - 48);
		else
			return (((int)b[0]) - 55);
	}
	char somethingTwo(int someNumber){
		if (someNumber < 10 && someNumber >= 0){
			char returnChar[1];
			return returnChar[0] = (char)(someNumber + 48);
		}
		else if (someNumber < 16 && someNumber >= 10){
			char returnChar[1];
			return returnChar[0] = (char)(someNumber + 55);
		}
		else
		{
			char returnChar[2];
			returnChar[]
			return returnChar = "AB";
		}
	}*/
	Hex& operator -(){
		// NOT READY
	}
	void print(){
		cout << number << endl;
	}
	void reverse(){
		char temp[1];
		for (size_t i = 0, k = strlen(this->number) - 1; i < strlen(this->number) / 2; k--, i++){
			temp[0] = this->number[i];
			this->number[i] = this->number[k];
			this->number[k] = temp[0];
		}
	}
	void capitalise(){
		for (size_t i = 0; i < strlen(this->number); i++){
			if (this->number[i] >= 'a' && this->number[i] <= 'z'){
				this->number[i] = this->number[i] - 32;
			}
		}
	}
};
int main(){

	char *a = "abcdeF";
	char *b = "abaaaa";
	Hex c(a, 6), d(b, 6);
	c.print();
	d.print();
}