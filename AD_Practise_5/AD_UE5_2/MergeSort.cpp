#include "MergeSort.h"

void printA(int* a, int last){
    cout << a[0];
    for (int i = 1; i <= last; i++)
        cout << ", " << a[i];
    cout << endl;
}

void Merge(int* a, const int first, const int middle, const int last){
    int i = first, j = middle + 1, size_a = last - first + 1;
    int* new_a = new int [size_a];
    //cout << "f: " << first << " bis l: " << last << "\t";
    for (int k = 0; k < size_a; k++)
    {
        if (j <= last)
        {
            if (i <= middle)
            {
                if (a[i] < a[j])    new_a[k] = a[i++];
                else                new_a[k] = a[j++];
            }
            else new_a[k] = a[j++];
        }
        else
            new_a[k] = a[i++];
    }

    for (i = 0; i < size_a; i++){
        a[first + i] = new_a[i];
        //cout << a[first + i] << ", ";
    }
    //cout << endl;
    delete [] new_a;
}


void MergeSortRecusiv(int* a, const int first, const int last){
    if (first == last) return;
    int middle;
    middle = (first + last) / 2;
    MergeSortRecusiv(a, first, middle);
    MergeSortRecusiv(a, middle + 1, last);
    Merge(a, first, middle, last);
}

void MergeSortIterativ(int* a, const int first, const int last){

    int left, middle, rigth, size_a;

    for (size_a = 1; size_a <= last; size_a *= 2){
        for (left = first; left <= last; left += 2*size_a){
            middle = min(left + size_a - 1, last);
            rigth = min(left - 1 + 2 * size_a, last);
            Merge(a, left, middle, rigth);
        }
    }
}

