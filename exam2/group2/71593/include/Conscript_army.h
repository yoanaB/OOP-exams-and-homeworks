#ifndef CONSCRIPT_ARMY_H
#define CONSCRIPT_ARMY_H

#include <Army.h>


class Conscript_army : virtual public Army
{
    public:
        Conscript_army():Army(){}
        bool operator>(Army&);
        virtual void addVoinik (Human*);
        virtual void removeVoinik (Human*);
        virtual void addLider (Human*);
        virtual int getOcenka () const;
};

#endif // CONSCRIPT_ARMY_H
