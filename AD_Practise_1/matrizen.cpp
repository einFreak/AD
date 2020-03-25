#include "matrizen.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

matrizen::matrizen(unsigned int m_val, unsigned int n_val)
{
    //cout << "creating Matrix" << endl;
    this->m = m_val;
    this->n = n_val;

    matrix = new int* [m];      // Allocate row pointers -> m Reihen



    for (unsigned int i = 0; i < m; i++) {
        matrix[i] = new int[n];    // Allocate rows -> n Spalten pro Reihe

    }
}

//Copy Contructor
matrizen::matrizen(const matrizen &oldMatrix)
{
    //cout << "creating CopyMatrix" << endl;
    this->m = oldMatrix.m;
    this->n = oldMatrix.n;

    matrix = new int* [m];      // Allocate row pointers -> m Reihen

    for (unsigned int i = 0; i < m; i++) {
        matrix[i] = new int[n];    // Allocate rows -> n Spalten pro Reihe

    }

    //Daten übernehmen
    for (unsigned int x = 0; x < m; x++)
        for (unsigned int y = 0; y < n; y++)
            matrix[x][y] = oldMatrix.matrix[x][y];

}

matrizen::~matrizen()
{
    //cout << "destroying Matrix" << endl;
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
    for (unsigned int i = 0; i < this->m; i++) {
        for (unsigned int u = 0; u < this->n; u++) {
            std::cout << " " << std::setw(2) << this->matrix[i][u];
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
    cout << "Eingabe vollstaendig" << endl;
    return 0;
}

int matrizen::Add(matrizen A) {
    cout << "Addition Matritzen: " << endl << "Matrix 1: " << endl;
    this->Print();
    cout << endl << endl << "Matrix 2: " << endl;
    A.Print();
    cout << endl << endl;

    //Überprüfung
    cout << "Dimensionen muessen gleich sein - ueberpruefe..." << endl;
    if (this->m != A.Getm())
        cout << "m ungleich - keine Addition möglich" << endl;
    else if (this->n != A.Getn())
        cout << "n ungleich - keine Addition möglich" << endl;

    //eigentliche Berechnung
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
    cout << endl << "Multiplikation Matritzen: " << endl << "Matrix 1: " << endl << "--------------------------" << endl;
    this->Print();
    cout << endl << endl << "Matrix 2: " << endl;
    A.Print();
    cout << endl << endl;

    cout << "eine Dimensionen muss gleich sein - überprüfe..." << endl;
    if (this->m == A.Getn()) {

        matrizen Ergebnis1(this->n, A.m);
        Ergebnis1.Init();

        for (unsigned int i = 0; i < this->n; i++) {
            for (unsigned int k = 0; k < A.m; k++)
                for (unsigned int j = 0; j < this->m; j++) {
                    int x = this->matrix[j][i];
                    int y =     A.matrix[k][j];
                    int Zwischenergebnis =  x * y;
                    Ergebnis1.matrix[k][i] += Zwischenergebnis;
                }
        }

        cout << "A*B Mult erfolgreich - Ergebnis1:" << endl;
        Ergebnis1.Print();
        cout << "Return Ergebnis: 1, Mult B*A probieren: 2" << endl;
        int cont;
        cin >> cont;
        if (cont == 1)
            return Ergebnis1;
    }

    if (this->n == A.Getm()) {
        matrizen Ergebnis2(this->m, A.Getn());
        Ergebnis2.Init();

        for (unsigned int i = 0; i < this->m; i++) {
            for (unsigned int k = 0; k < A.Getn(); k++)
                for (unsigned int j = 0; j < this->n; j++) {
                    int Zwischenergebnis = this->matrix[i][j] * A.matrix[j][k];
                    Ergebnis2.matrix[i][k] += Zwischenergebnis;
                }
        }

        cout << "B*A Mult erfolgreich - Ergebnis2:" << endl;
        Ergebnis2.Print();

        return Ergebnis2;
    }
    else
        cout << "Dimensionen ungleich - keine Multiplikation möglich" << endl;


    return A;
}
