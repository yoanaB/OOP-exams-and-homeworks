#ifndef ROCKSTAR_H
#define ROCKSTAR_H


class RockStar
{
    public:
        RockStar();
        RockStar(char*, int, unsigned);
        ~RockStar();
        RockStar(RockStar&);
        RockStar& operator= (RockStar&);

        bool operator> (RockStar&) const;
        bool operator< (RockStar&) const;
        bool operator== (RockStar&) const;

        void setName (char*);
        void setAwesomeness (int);
        void setNumberOfFens (unsigned);

        const char* getName () const;
        int getAwesomeness () const;
        unsigned getNumberOfFens () const;


        void print () const;
    private:
        char* name;
        int awesomeness;
        unsigned numberOfFens;
};

#endif // ROCKSTAR_H
