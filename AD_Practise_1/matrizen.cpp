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
    for (int x = 0; x < m; x++)
        for (int y = 0; y < n; y++)
            matrix[x][y] = 0;
    return 0;
}


void matrizen::Print() {
    for (int i = 0; i < m; i++) {
        for (int u = 0; u < n; u++) {
            std::cout << " " << std::setw(2) << matrix[i][u];
        }
        std::cout << endl;
    }
    std::cout << std::endl;
}

int matrizen::Input() {
    cout << "Matrix (" << m << " x " << n << ") eingeben:" << endl;
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            cout << "z" << x << "s" << y << ":    ";
            cin >> matrix[x][y];
        }
        cout << endl;
    }
    cout << "Eingabe vollständig" << endl;
    return 0;
}
