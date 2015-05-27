#include<iostream>

using namespace std;

class Rockstar{
public:
	Rockstar();
	~Rockstar();

	void setName(char* name);
	void setAwesomeness(int awesomeness);
	void setNumberOfFens(int numberOfFens);
	char getName(char* name);
	int getAwesomeness(int awesomeness);
	int getNumberOfFens(int numberOfFens);

	bool operator>(Rockstar x);
	bool operator<(Rockstar x);
	bool operator==(Rockstar x);

	void printRockstar(Rockstar x);

private:
	char* name;
	int awesomeness;
	int numberOfFens;
};

Rockstar::Rockstar(char* name,int awesomeness,int numberOfFens){
	this->name = name;
	this->awesomeness = awesomeness;
	this->numberOfFens = numberOfFens;
}

void Rockstar::setName(char* name){

	cout << this->name << endl;
}

void Rockstar::setAwesomeness(int awesomeness){

	cout << this->awesomeness << endl;
}

void Rockstar::setNumberOfFens(int numberOfFens){

	cout << this->numberOfFens << endl;
}

char Rockstar::getName(char* name){

	cin >> this->name;

	return *name;
}

int Rockstar::getAwesomeness(int awesomeness){

	cin >> this->awesomeness;

	return awesomeness;
}

int Rockstar::getNumberOfFens(int numberOfFens){

	cin >> this->numberOfFens;

	return numberOfFens;
}

bool Rockstar::operator>(Rockstar x){

	if (this->awesomeness > x.awesomeness){
		return true;
	}
	else{
		return false;
	}
}

bool Rockstar::operator<(Rockstar x){

	if (this->awesomeness < x.awesomeness){
		return true;
	}
	else{
		return false;
	}
}

bool Rockstar::operator==(Rockstar x){

	if (this->awesomeness == x.awesomeness){
		return true;
	}
	else{
		return false;
	}
}

void Rockstar::printRockstar(Rockstar x){

	cout << x.getName << endl;
	cout << x.getAwesomeness << endl;
	cout << x.numberOfFens << endl;
}

int main(){
	Rockstar x;
	getAwesomeness(x.awesomeness);

	Rockstar y;
	getAwesomeness(y.awesomeness);

	cout << (x > y);
	cout << (x < y);
	cout << (x == y);

	printRockstar(x);
	printRockstar(y);

	system("pause");
	return 0;
}