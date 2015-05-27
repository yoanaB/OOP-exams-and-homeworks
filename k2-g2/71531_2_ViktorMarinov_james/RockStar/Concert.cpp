#include "Concert.h"

void Concert::setConcert(Band* bands, int size){
	delete[] this->bands;
	this->bands = new Band[size];
	for (int i = 0; i < size; i++){
		this->bands[i] = bands[i];
	}
	this->size = size;
}
Concert::Concert(Band* bands, int size):bands(nullptr){
	setConcert(bands, size);
}

Concert::~Concert(){
	delete[] this->bands;
}

Concert::Concert(const Concert& other) :bands(nullptr){
	setConcert(other.bands, other.size);
}

Concert& Concert::operator=(const Concert& right){
	if ( this != &right)
		setConcert(right.bands, right.size);
	return *this;
}

int Concert::averageAwesomness() const{
	int sum = 0;
	int num = 0;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < bands[i].size; j++){
			sum += bands[i].members[j].awesomeness;
			num++;
		}
	}
	return sum / num;
}

Band& Concert::headliner() const{
	int maxAwesome = 0;
	int sum = 0;
	for (int j = 0; j < bands[0].size; j++){
		sum += bands[0].members[j].awesomeness;
	}
	int newSum;
	for (int i = 1; i < size; i++){
		newSum = 0;
		for (int j = 0; j < bands[i].size; j++){
			sum += bands[i].members[j].awesomeness;
		}
		if (newSum > sum){
			sum = newSum;
			maxAwesome = i;
		}
	}
	return bands[maxAwesome];
}
