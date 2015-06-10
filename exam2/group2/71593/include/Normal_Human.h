#ifndef NORMAL_HUMAN_H
#define NORMAL_HUMAN_H

#include <Human.h>


class Normal_Human : public Human
{
    public:
        virtual const char* getSpecialSkill () const = 0;
        virtual int getOcenkaOtmashtenie () const;
        virtual char* getType () const;
        virtual void addFriend (Human*);
};

#endif // NORMAL_HUMAN_H
