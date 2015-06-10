#ifndef STARK_H
#define STARK_H
#include "Human.h"

class Stark :virtual public Human{

public:
	Stark(const char* = "", size_t = 0, size_t = 0, size_t = 0);
	Stark(const Stark&);
	Stark& operator=(const Stark&);
	virtual ~Stark();

	virtual const char* getSpeciallSkill() const;
	virtual size_t revenge() const;

	bool addFriend(const Stark&);

private:


};


#endif