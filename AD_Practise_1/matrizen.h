#ifndef matrizen_H
#define matrizen_H

class matrizen
{
    public:
        matrizen(unsigned int, unsigned int);
        virtual ~matrizen();

        unsigned int Getm();
        unsigned int Getn();

    protected:

    private:
        int** matrix; //Pointer auf weitere Pointer da Doppeltes Array
        unsigned int m;
        unsigned int n;
};

#endif // matrizen_H
