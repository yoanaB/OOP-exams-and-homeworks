#ifndef NORMALHUMAN_H
#define NORMALHUMAN_H
#include "Human.h"


class Normal : public Human{

public:

	Normal(const char* = "", size_t = 0, size_t = 0, const char* = "");
	Normal(const Normal&);
	Normal& operator=(const Normal&);
	~Normal();

	void addFriend(const Normal&);
	size_t findFriend(const char*) const;
	void removeFriend(const char*);


	virtual size_t revenge() const;

	virtual const char* getSpecialSkill() const;
	virtual Human* clone() const;



private:
	Normal* friends;


};



#endif
