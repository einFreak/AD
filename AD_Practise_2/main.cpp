#include <iostream>
#include "regmach.h"

using namespace std;

int main()
{
    string filename;
    cin >> filename;
    Regmach test_reg(filename);
//    Regmach test_reg("test.txt");
    test_reg.decode();
    return 0;
}
