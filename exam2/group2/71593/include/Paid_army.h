#ifndef PAID_ARMY_H
#define PAID_ARMY_H

#include "Army.h"

class Paid_army: virtual public Army
{
    public:
        Paid_army();
        Paid_army (Paid_army&);
        Paid_army& operator= (Paid_army&);

        bool operator> (Army&);
        virtual void addVoinik (Human*);
        virtual void removeVoinik (Human*);
        virtual void addLider (Human*);
        virtual int getOcenka () const;
    protected:
    private:
        double budjet;
        double zaplataVoinik;

};

#endif // PAID_ARMY_H
