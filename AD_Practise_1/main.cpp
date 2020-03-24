#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Aufgabe1.h"
#include "Aufgabe2.h"
#include "Aufgabe3.h"
#include "matrizen.h"

using namespace std;



int main()
{
    while (true)
    {
        cout << endl << endl << "-----------------------------------------"  << endl;
        cout    << "Uebung1 - Aufgabe waehlen" << endl
                << "1: Aufgabe 1 - ggT" << endl
                << "2: Aufgabe 2 - Sieb des Eratosthenes" << endl
                << "3: Aufgabe 3 - Matrix" << endl
                << "other: Ende" << endl;
        int Auswahl = 3;
        cout << "Auswahl: ";
        cin >> Auswahl;
        cout << "-----------------------------------------"  << endl << endl;
        switch (Auswahl) {
        case 1:
            cout << "Aufgabe 1: " << endl;
            a1_ausgabe();
            cout << endl <<"Ende A1" << endl;
            break;
        case 2:
            cout << "Aufgabe 2: " << endl;
            a2_ausgabe();
            cout << endl <<"Ende A2" << endl;
            break;
        case 3:
            cout << "Aufgabe 3: " << endl;
            a3_ausgabe();
            cout << endl <<"Ende A3" << endl;
            break;
        default:
            return 0;

        }
    }


    return 0;
}
