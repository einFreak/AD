#include "regmach.h"
#include <string>
#include <cstring>

using namespace std;

Regmach::Regmach(string new_filename)
{
    reg_file = new_filename;
}

Regmach::Regmach::~Regmach()
{
    //dtor
}

Regmach::startdecode() {


//    char *cstring = new char [reg_file.size() +1];
//    copy (begin(reg_file), end(greetings), cstring);
//    cstring [reg_file.size()] = '\0';

    char * cstr = new char [reg_file.length()+1];
    std::strcpy (cstr, reg_file.c_str());

    fstream fs;
    fs.open(cstr, fstream::in);

    if (!fs.eof()) {

        cout << " file open" << endl;
        char cstring[20];

        while (!fs.eof()) {
            fs.getline(cstring, sizeof(cstring));
            cout << "Decoding: " << cstring << endl;



        }


    }
    return 0;
}


