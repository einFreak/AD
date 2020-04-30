#include "regmach.h"
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

Regmach::Regmach(string new_filename)
{
    reg_file = new_filename;
    PC = 0;
    line_count = 0;
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

    if (fs.is_open() && !fs.eof()) {

        cout << " file open" << endl;
        char cstring[200];

        while (!fs.eof()) {
            fs.getline(cstring, sizeof(cstring));

            cout << endl << "-----------------------" << endl;
            cout << "Decoding: " << cstring << endl;
            cout << "Result: " << calculate(cstring)<< endl;
            cout << "-----------------------" <<endl << endl;
        }
    }
    else
        cout << "file not found" << endl;
    return 0;
}


Regmach::calculate (char *c_pointer) {

    charcount = 0;
    for(int m=0; c_pointer[m] != 0; m++){
        charcount ++;
    }

    for (int i = 0; i < charcount; i+=4)
    {
        int command = 666;
        int value = 666;

        cout << endl << "PC: " << PC+1 << endl;
        if (HexToInt(c_pointer[i  ]) != 666 &&
            HexToInt(c_pointer[i+1]) != 666 ) {
            command = HexToInt(c_pointer[i]) *16 + HexToInt(c_pointer[i+1]);
            cout << "Commando: " << command << endl;
        }
        if (HexToInt(c_pointer[i+2]) != 666 &&
            HexToInt(c_pointer[i+3]) != 666 ) {
            value   = HexToInt(c_pointer[i+2]) *16 + HexToInt(c_pointer[i+3]);
            cout << "Value: " << value << endl;
        }

        switch(command) {
        case 1:
            cout << "ADD " << speicher[value] << " to accumulator: " << endl;
            speicher[0] += speicher[value];
            cout << "Acc: " << speicher[0] << endl;
            break;
        case 2:
            cout << "SUB " << speicher[value] << " from accumulator: " << endl;
            speicher[0] -= speicher[value];
            cout << "Acc: " << speicher[0] << endl;
            break;
        case 3:
            cout << "MUL " << speicher[value] << " to accumulator: " << endl;
            speicher[0] *= speicher[value];
            cout << "Acc: " << speicher[0] << endl;
            break;
        case 4:
            cout << "DIV " << speicher[value] << " from accumulator: " << endl;
            speicher[0] /= speicher[value];
            cout << "Acc: " << speicher[0] << endl;
            break;
        case 5:
            cout << "Load address to accumulator: " << endl;
            speicher[0] = speicher [value];
            cout << "Acc: " << speicher[0] << endl;
            break;
        case 6:
            cout << "Load number to accumulator: " << endl;
            speicher[0] = value;
            cout << "Acc: " << speicher[0] << endl;
            break;
        case 7:
            cout << "Store accumulator to address: " << endl;
            speicher[value] = speicher[0];
            cout << "Address " << value << " changed to value: " << speicher[value] << endl;
            break;
        case 8:
            cout << "Input to address " << value << " - please insert:" << endl;
            cin >> speicher[value];
            break;
        case 9:
            cout << "Output address " << value << " :" << endl;
            cout << speicher[value] << endl;
            break;
        case 10:
            cout << "End of program if value = 99" << endl;
            if (value == 99)
                return speicher[0];
            else {
                cout << "Wrong EoP value - Error" << endl;
                return 666;
            }
            break;
        case 11:
            cout << "Jump to address/Set PC:" << endl;
            i = PC * 4;
            cout << "PC (" << PC << ") set to: " << value << endl;
            PC = value - 1;
            break;
        case 12:
            cout << "Jump if accumulator = 0" << endl;
            if (speicher[0] == 0) {
                i = PC * 4;
                cout << "PC (" << PC << ") set to: " << value << endl;
                PC = value - 1;
            }
            else
                cout << "not Zero" << endl;
            break;
        case 13:
            cout << "Jump if accumulator != 0" << endl;
            if (speicher[0] != 0) {
                i = PC * 4;
                cout << "PC (" << PC << ") set to: " << value << endl;
                PC = value - 1;
            }
            else
                cout << "is Zero" << endl;
            break;
        case 14:
            cout << "Jump if accumulator < 0" << endl;
            if (speicher[0] < 0) {
                i = PC * 4;
                cout << "PC (" << PC << ") set to: " << value << endl;
                PC = value - 1;
            }
            else
                cout << ">= Zero" << endl;
            break;
        case 15:
            cout << "Jump if accumulator <= 0" << endl;
            if (speicher[0] <= 0) {
                i = PC * 4;
                cout << "PC (" << PC << ") set to: " << value << endl;
                PC = value - 1;
            }
            else
                cout << "> Zero" << endl;
            break;
        case 16:
            cout << "Jump if accumulator > 0" << endl;
            if (speicher[0] > 0) {
                i = PC * 4;
                cout << "PC (" << PC << ") set to: " << value << endl;
                PC = value - 1;
            }
            else
                cout << "<= Zero" << endl;
            break;
        case 17:
            cout << "Jump if accumulator >= 0" << endl;
            if (speicher[0] >= 0) {
                i = PC * 4;
                cout << "PC (" << PC << ") set to: " << value << endl;
                PC = value - 1;
            }
            else
                cout << "< Zero" << endl;
            break;

        default:
            PC--;
            cout << "No command found - skipped" << endl;
            break;
        }

        PC++;

    }

    return speicher[0];
}

Regmach::HexToInt(char value) {
    if (value >= '0' && value <= '9')
        return value - '0';
    else if (value >= 'A' && value <= 'F')
        return value - 55;
    else if (value >= 'a' && value <= 'f')
        return value - 87;
    else
        cout << "not a hex value" << endl;

    return 666;
}
