#include <iostream>
#include <cstring>
using namespace std;

class Hex{
public:
	Hex();
	Hex(Hex&);
	~Hex();
	Hex& operator=(Hex&);
	Hex& operator>(Hex&);
	Hex& operator<(Hex&);
	void setChar(char* here);
	unsigned char* getChar();
private:
	unsigned char* all;
	size_t size;
};

Hex::Hex(){
	this->size = 0;
	all = new unsigned char[1];
}

Hex::Hex(Hex& other){
	this->size = other.size;
	delete  []this->all;
	all = new unsigned char [this->size];
	for (int i = 0; i < this->size; i++){
		this->all[i] = other.all[i];
	}
}

Hex::~Hex(){
	delete[] all;
}

Hex& Hex::operator=(Hex& other){
	this->size = other.size;
	delete[]this->all;
	all = new unsigned char[this->size];
	for (int i = 0; i < this->size; i++){
		this->all[i] = other.all[i];
	}
	return *this;
}

void Hex::setChar(char* here){
	size = strlen(here) + 1;
	if (size <= 100){
		delete[] all;
		all = new unsigned char[this->size];
		for (int i = 0; i < size; i++){
			all[i] = here[size - i - 2];
		}
	}
}

unsigned char* Hex::getChar(){
	return all;
}

int main(){
	Hex a;
	a.setChar("192832348");
	cout << a.getChar() << endl;
	return 0;
}
