#include<iostream>

using namespace std;


class Band{
public:

	Band();
	Band(const Band&);
	~Band();

	int addStar(int size);
	int removeStar(int size);
	int getSize(int size);
	char getStar(char* star);
	void printStar(char* star);

	Band operator+=(const Band&)const;

private:
	int size;
	char* star[];
};

Band::Band(){
	this->star[size] = star[size];
}


int Band::addStar(int size){
	this->size = new size;
	return size;
}

int Band::removeStar(int size){

	this->size = new size;
	return size;
}

int Band::getSize(int size){
	cin >> this->size;
	return size;
}

char Band::getStar(char* star){
	for (int i = 0, i <= size, i++){
		cin >> star[i];
	}
	return *star;
}

void Band::printStar(char* star){

	cout << this->star[];
}

Band Band::operator+=(const Band&)const{
	return Band;
}
class Concert{
	int averageAwesomeness;
	Band headliners;
}
int main(){
	Band x;
	Concert y;
	system("pause");
	retrn 0;
}