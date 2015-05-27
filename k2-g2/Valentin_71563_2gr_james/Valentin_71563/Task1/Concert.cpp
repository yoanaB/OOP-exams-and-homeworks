#include<iostream>
using namespace std;
#include "Header.h"
Concert::Concert(){
	size = 0;
	capacity = 1;
	bands = new Band[capacity];
}
Concert::~Concert(){	
	delete[] bands;
}
Concert::Concert(const Concert& other){
	size = other.size;
	capacity = other.capacity;
	bands = new Band[capacity];
	for (int i = 0; i < size; i++)
	{
		bands[i] = other.bands[i];
	}
}
Concert& Concert::operator=(const Concert& other){
	if (this != &other){
		delete[] bands;
		size = other.size;
		capacity = other.capacity;
		bands = new Band[capacity];
		for (int i = 0; i < size; i++)
		{
			bands[i] = other.bands[i];
		}
	}
	return *this;
}
double Concert::averageAwesomeness(){
	double sumOfAwesomeness = 0;
	for (int i = 0; i < size; i++)
	{
		sumOfAwesomeness += bands[i].getAwesomenessKoef();
	}
	return sumOfAwesomeness / size;
}