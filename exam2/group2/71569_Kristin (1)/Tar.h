#ifndef TAR_H
#define TAR_H
#include "Human.h"

class Tar: virtual public Human
{

	Tar(const char* = "", size_t = 0, size_t = 0, int = 0);
	Tar(const Tar&);
	Tar& operator=(const Tar&);
	virtual ~Tar(){};

	virtual size_t getLoyalty() const;
	virtual const char* getSpecialSkill() const;

	bool addFriend(const Tar&);
	virtual size_t revenge() const;

	Human*


protected:
	void setLoyalty(size_t);


private:
	Tar* friends;
	int age;


};



#endif