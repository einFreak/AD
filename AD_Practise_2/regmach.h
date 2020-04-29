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

        unsigned int getline();

        int startdecode();

    protected:

    private:
        int speicher[10]
        unsigned int line_count;
        string reg_file;
};

#endif // REGMACH_H
