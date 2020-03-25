#include "matrizen.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

matrizen::matrizen(unsigned int m_val, unsigned int n_val)
{
    cout << "creating Matrix" << endl;
    this->m = m_val;
    this->n = n_val;

    matrix = new int* [m];      // Allocate row pointers -> m Reihen



    for (unsigned int i = 0; i < m; i++) {
        matrix[i] = new int[n];    // Allocate rows -> n Spalten pro Reihe

    }
}

matrizen::~matrizen()
{
    cout << "destroying Matrix" << endl;
    for (unsigned int i = 0; i < m; i++) {
        delete []  matrix[i];            //  Deallocate rows
    }
    delete [] matrix;                   //  Deallocate row pointers
}

unsigned int matrizen::Getm()                  { return m; }
unsigned int matrizen::Getn()                  { return n; }

int matrizen::Init() {
    for (unsigned int x = 0; x < m; x++)
        for (unsigned int y = 0; y < n; y++)
            matrix[x][y] = 0;
    return 0;
}


void matrizen::Print() {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int u = 0; u < n; u++) {
            std::cout << " " << std::setw(2) << matrix[i][u];
        }
        std::cout << endl;
    }
    std::cout << std::endl;
}

int matrizen::Input() {
    cout << "Matrix (" << m << " x " << n << ") eingeben:" << endl;
    for (unsigned int x = 0; x < m; x++) {
        for (unsigned int y = 0; y < n; y++) {
            cout << "z" << x << "s" << y << ":    ";
            cin >> matrix[x][y];
        }
        cout << endl;
    }
    cout << "Eingabe vollständig" << endl;
    return 0;
}

int matrizen::Add(matrizen A) {
    cout << "Addition Matritzen: " << endl << "Matrix 1: " << endl;
    this->Print();
    cout << endl << endl << "Matrix 2: " << endl;
    A.Print();
    cout << endl << endl;

    cout << "Dimensionen müssen gleich sein - überprüfe..." << endl;
    if (this->m != A.Getm())
        cout << "m ungleich - keine Addition möglich" << endl;
    else if (this->n != A.Getn())
        cout << "n ungleich - keine Addition möglich" << endl;
    else {
        for (unsigned int x = 0; x < m; x++) {
            for (unsigned int y = 0; y < n; y++) {
                this->matrix[x][y] = this->matrix[x][y] + A.matrix[x][y];
            }
        }
        cout << "Addition erfolgreich - Ergebnis:" << endl;
        this->Print();
        return 0;
    }
    return 1;
}


matrizen matrizen::Mult(matrizen A) {
    cout << "Multiplikation Matritzen: " << endl << "Matrix 1: " << endl;
    this->Print();
    cout << endl << endl << "Matrix 2: " << endl;
    A.Print();
    cout << endl << endl;

    cout << "eine Dimensionen muss gleich sein - überprüfe..." << endl;
    if (this->m = A.Getn()) {
        matrizen Ergebnis(m, m);
        for (int i = m; i < m; i++) {
            for (int j = m; j < m; j++) {
                int Zwischenergebnis = 0;

                for (int k = 0; a < this->n; a++)
                    Zwischenergebnis +=

                Ergebnis[x][y] = Zwischenergebnis;
            }
        }

        cout << "Mult erfolgreich - Ergebnis:" << endl;
        this->Print();
        return 0;
    }
    else if (this->n = A.Getm()) {


        cout << "Mult erfolgreich - Ergebnis:" << endl;
        this->Print();
        return 0;
    }
    else
        cout << "Dimensionen ungleich - keine Multiplikation möglich" << endl;
    return 1;
}
