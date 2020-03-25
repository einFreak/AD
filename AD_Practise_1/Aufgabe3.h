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
    Matrix1.Input();
    Matrix1.Print();

    cout    << "Matrix2 (M x N) bestimmen:" << endl << "M: ";
    cin     >> m;
    cout    <<"N: ";
    cin     >> n;
    cout    << endl;
    matrizen Matrix2(m, n);
    Matrix2.Input();
    Matrix2.Print();

    cout << "Rechenoperation wählen:" << endl << "1. Addition" << endl << "2. Multiplikation" << endl;
    int op;
    cin >> op;

    switch (op) {
    case 1:
        Matrix1.Add(Matrix2);
        break;
    case 2:
        Matrix1.Mult(Matrix2);
        break;
    default:
        cout << "Keine gültige Operation gewählt - Abbruch" << endl;
    }




}



#endif // AUFGABE3_H_INCLUDED
