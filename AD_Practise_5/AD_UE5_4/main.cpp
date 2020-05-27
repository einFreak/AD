#include <iostream>
#include "MergeSort.h"

using namespace std;

bool searchBinary(const int* a, const int first, const int last,const int searchNumb){

    if (last == first)      //Abbrechen wenn Array 1-elementig ist
        return false;

    int size_a = last - first + 1;
    int middle = first + size_a / 2;

    if (searchNumb == a[middle])    //wenn gesuchte Zahl gefunden, true wurückgeben
        return true;

    if (searchNumb < a[middle])     // in unterer Array-Hälfte weitersuchen
        return searchBinary(a, first, middle - 1, searchNumb);

    if (searchNumb > a[middle])     // in oberer Array-Hälfte weitersuchen
        return searchBinary(a, middle + 1, last, searchNumb);
}

bool Algorithmus (int* a, int n, int s, int &counter){

    MergeSortIterativ(a, 0, n); // Array sortieren dauert T_sort(n) = n * Log(n)

    for (int i = n; i >= 0; i--, counter++){    // Schleife mit konstant vielen Druchläufen ( T_loop(n) = n )
        int searchedObject = s - a[i];  //searchedObject wird in jedem Schleifendurchlauf größer

        if (searchedObject > a[n]) //Die gesuchte Zahl existiert nicht im Array
            return false;

        if (searchBinary(a, 0, n, searchedObject))  // searchBinary: T_search(n) = O(log n)
            return true;
    }
    return false;
    /*
        Gesamtlaufzeit des Algotithmus im WorstCase:
        T(n) = T_sort(n) + T_loop(n) * T_search(n) = ( n * log(n) ) + n * log(n) = O(n*log(n))
    */
}


int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size_a = sizeof(a) / sizeof(a[0]);
    int s = 9;
    int counter = 0;

    cout << "Summe gefudnen? " << Algorithmus(a, size_a - 1, s, counter) << endl;

    cout << "Counter: " << counter << endl;
    cout << "Hello world!" << endl;
    return 0;
}
