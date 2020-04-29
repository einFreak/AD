#include "regmach.h"
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

Regmach::Regmach(string new_filename)
{
    reg_file = new_filename;
}

Regmach::Regmach::~Regmach()
{
    //dtor
}

Regmach::decode() {


//    char *cstring = new char [reg_file.size() +1];
//    copy (begin(reg_file), end(greetings), cstring);
//    cstring [reg_file.size()] = '\0';

    char * cstr = new char [reg_file.length()+1];
    std::strcpy (cstr, reg_file.c_str());

    fstream fs;
    fs.open(cstr, fstream::in);

    if (!fs.eof()) {

        cout << " file open" << endl;
        char cstring[200];

        while (!fs.eof()) {
            fs.getline(cstring, sizeof(cstring));
            cout << "Decoding: " << cstring << endl;
            calculate(cstring);
            cout << endl;
        }
    }
    return 0;
}


Regmach::calculate (char *c_pointer) {
//  for (int i = 0; c_pointer[i] != '\0'; i=i+4)
    for (int i = 0; i < 2; i++)
    {
        cout << c_pointer[i] << endl;
        cout << c_pointer+i << endl;
        unsigned
        cout <<  std::stoi (c_pointer,nullptr,16); << endl;
        cout << (int)strtol(c_pointer+i, NULL, 16) << endl;
        cout << (unsigned int)(strtol(c_pointer+i, NULL, 16)) << endl;
        int command = (int)(strtol(c_pointer+i, NULL, 16)) *10 + (int)(strtol(c_pointer+(i+1), NULL, 16));
        cout << endl << "Kommando: " << command;
        int value   = (int)(strtol(c_pointer+(i+2), NULL, 16)) *10 + (int)(strtol(c_pointer+(i+3), NULL, 16));
        cout << endl << "Wert: " << value;

    }

    return speicher[0];
}
