#ifndef AUFGABE3_H_INCLUDED
#define AUFGABE3_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "matrizen.h"

using namespace std;

void a3_ausgabe() {
    unsigned int m, n;
    cout    << "Matrix1 (M x N) bestimmen:" << endl << "M: ";
    cin     >> m;
    cout    <<"N: ";
    cin     >> n;
    cout    << endl;
    matrizen Matrix1(m, n);
    Matrix1.Init();
    Matrix1.Print();

    cout    << "Matrix2 (M x N) bestimmen:" << endl << "M: ";
    cin     >> m;
    cout    <<"N: ";
    cin     >> n;
    cout    << endl;
    matrizen Matrix2(m, n);
    Matrix2.Input();
    Matrix2.Print();
    system("pause");

}



#endif // AUFGABE3_H_INCLUDED
