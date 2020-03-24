#include "matrizen.h"
#include <iostream>

using namespace std;

matrizen::matrizen(unsigned int m_val, unsigned int n_val)
{
    m = m_val;
    n = n_val;

    matrix = new int* [m];      // Allocate row pointers -> m Reihen

    for (unsigned int i = 0; i < m; i++) {
        matrix[i] = new int[n];    // Allocate rows -> n Spalten pro Reihe
    }
}

matrizen::~matrizen()
{
    for (unsigned int i = n-1; i >= 0; i--) {
        delete []  matrix[i];            //  Deallocate rows
    }
    delete [] matrix;                   //  Deallocate row pointers
}

unsigned int matrizen::Getm()                  { return m; }
unsigned int matrizen::Getn()                  { return n; }
