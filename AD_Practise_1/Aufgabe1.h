#ifndef AUFGABE1_H_INCLUDED
#define AUFGABE1_H_INCLUDED
#include <iostream>
using namespace std;

void a1_ausgabe();
int ggT(int, int);
int rek_ggT(int, int);

void a1_ausgabe () {
    cout << "ggT Werte eingeben" << endl;
    cout << "a: ";
    int a;
    cin >> a;
    cout << "b: ";
    int b;
    cin >> b;

    cout << "ggT: " << ggT(a, b) << endl;
    cout << "rek. ggT: " << rek_ggT(a, b) << endl;
    system("pause");
}

int ggT (int a, int b) {
    int big, small;
    if (a >= b) {
        big = a;
        small = b;
    }
    else {
        big = b;
        small = a;
    }

    int mod = 999;

    while (mod != 0) {
        mod = big % small;
        big = small;
        small = mod;
    }
    return big;
}

int rek_ggT (int a, int b) {
    int big, small;
    //Größer/Kleiner check
    if (a >= b) {
    big = a;
    small = b;
    }
    else {
        big = b;
        small = a;
    }

    //Begin Fkt Rekursiv
    int mod = big % small;

    if (mod != 0)
        return rek_ggT(small, mod);
    else
        return small;
}



#endif // AUFGABE1_H_INCLUDED
