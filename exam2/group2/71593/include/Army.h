#ifndef ARMY_H
#define ARMY_H

#include "Human.h"

class Army:public Human
{
    public:
        Army();
        Army(Army&);
        Army& operator= (Army&);

        virtual void addVoinik (Human*) = 0;
        virtual void removeVoinik (Human*) = 0;
        virtual void addLider (Human*) = 0;
        virtual int getOcenka () const = 0;
    protected:
        Human* voinici[100];
        int count;
        Human* lider;
};

#endif // ARMY_H
