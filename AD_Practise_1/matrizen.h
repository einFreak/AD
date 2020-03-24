#ifndef matrizen_H
#define matrizen_H

class matrizen
{
    public:
        matrizen(unsigned int m_val, unsigned int n_val);
        ~matrizen();

        unsigned int Getm();
        unsigned int Getn();
        int Init();
        void Print();
        int Input();

    private:
        int** matrix; //Pointer auf weitere Pointer da Doppeltes Array
        unsigned int m;
        unsigned int n;
};

#endif // matrizen_H
