#ifndef BAND_H
#define BAND_H


class Band
{
    public:
        Band();
        Band (const char*,RockStar&);
        Band (Band&);
        ~Band ();
        Band& operator= (Band&);

        void addStar (RockStar&);
        void removeStar (const char*);
        const RockStar& getStar(const char*) const;
        size_t getSize () const;
        void print () const;
        Band& operator+= (Band&);
        RockStar* arr;
        RockStar& pickAFrontman () const;
    private:
        char* name;
        size_t size,
               maxSize;

};

#endif // BAND_H
