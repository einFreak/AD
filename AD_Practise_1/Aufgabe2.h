#ifndef AUFGABE2_H_INCLUDED
#define AUFGABE2_H_INCLUDED
#include <iostream>
#include <iomanip>
using namespace std;

void a2_ausgabe();
int sieb(int);
int print_array (int *array, int size);

void a2_ausgabe () {
    cout << "Sieb des Eratosthenes" << endl;
    cout << "obere Schranke: ";
    int a;
    cin >> a;
    sieb(a);
    system("pause");
}

int sieb (int schranke) {
    int *table = new int[schranke];

    //table füllen
    for (int i = 0; i < schranke; i++)
        table[i] = i+1;
    cout << "Start" << endl;
    print_array(table, schranke);

    cout << "Primzahlen sind: " << endl;
    //Sieb
    for (int streichen = 1; streichen < schranke; streichen++) {
        if (table[streichen] != 0)
        {
            int test = table[streichen];
            cout << test << " ";

            for (int y = streichen+1; y < schranke; y++) {
                int value = table[y];
                int mod = value % test;
                if (mod == 0)
                    table[y] = 0;
            }
        }

    }
    cout << endl << endl << "Gestrichene Tabelle: " << endl;
    print_array(table, schranke);

    delete[] table;
    return 0;
}

int print_array (int *array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << " " << std::setw(2);
        if (array[i] == 0)
            cout << "  ";
        else
            cout << array[i];
        if ((i+1)%10 == 0)
            std::cout << endl;
    }
    std::cout << std::endl;
    return 0;
}



#endif // AUFGABE2_H_INCLUDED
