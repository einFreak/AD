#ifndef REGMACH_H
#define REGMACH_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Regmach
{
    public:
        Regmach(std::string new_filename);
        virtual ~Regmach();
        int decode();

    protected:

    private:
        int calculate (char *c_pointer);
        int HexToInt(char value);

        int PC;
        int speicher[10] = {0};
        unsigned int line_count;
        unsigned int charcount;
        string reg_file;
};

#endif // REGMACH_H
