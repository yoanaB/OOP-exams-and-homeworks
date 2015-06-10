#ifndef ARMY_H
#define ARMY_H
#include "Human.h"

class Army{

public:

	Army();
	Army(const Human&, size_t);
	Army(const Army&);
	Army& operator=(const Army&);
	virtual ~Army();

	virtual void setLeader(Human*);
	void addSoldier(const Human&);
	void removeSoldier(const char*);

	virtual size_t getRevenge() const = 0;

	virtual void clearSoldiers();
	void copySoldiers(const Army&){};

protected:
	size_t numSoldiers;
	const size_t MAX_CAPACITY = 100;

	Human* leader;
	Human** soldiers;
	
};





#endif