
#include <iostream>
#include <stdlib.h>
using namespace std;


void print_array(int a[], int length) {
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
}

/* included in iostream
void swap (int &a, int &b) {
    int h = b;
    b = a;
    a = h;
}*/

int InsertionSort (int a[], int lenght) {
    int i, j, key;

    /* sort by max */
    for(j=lenght-2; j >= 0; j--) {
        key = a[j];

        for (i = j+1; i <= lenght-1 && a[i] < key; i++) {
            a[i-1] = a[i];
        }
        a[i-1] = key;
    }

    /* sort by min */ /*
    for (j=1; j<lenght; j++) {
        key = a[j];

        for (i = j-1; i >= 0 && a[i] > key; i--) {
            a[i+1] = a[i];
            print_array(a, lenght);
        }

        a[i+1] = key;

    } */
    return 0;
}
int BubbleSort (int a[], int lenght) {

    for (int i = lenght-1; i >= 0; i--)  {
        for (int j = 1; j <= i; j++) {
            if (a[j] < a[j-1]) {
                swap(a[j-1], a[j]);
                //print_array(a, lenght);
            }
        }
    }

    /*
    for (int i = 0; i < lenght; i++) {
        for (int j = lenght-2; j >= i; j--) {
            if (a[j] > a[j+1] ) {
                swap(a[j+1], a[j]);
                print_array(a, lenght);
            }
        }
    }*/
    return 0;
}
int SelectionSort (int a[], int lenght) {
    int i, j, max;
    for (i = lenght-1; i >= 0; i--) {
        max = i;
        for (j = i; j >= 0; j--) {
            if (a[j] > a[max])
                max = j;
        }
        swap(a[max], a[i]);
        print_array(a, lenght);
    }

    /*
    for (i = 0; i < lenght; i++) {
        max = i;
        for (j = i; j < lenght; j++) {
            if (a[j] > a[max])
                max = j;
        }
        swap(a[max], a[i]);
        print_array(a, lenght);
    } */
    return 0;
}

void PreparePartition (int a[], int first, int last, int &p) {
    //Pivot Element
    int pivot = a[first];
    //not working - dont know why atm int pivot = a[rand() % last-1];
    p = first-1; //Pointer vor Piv_Element

    for (int i = first; i <= last; i++) {
        if (a[i] <= pivot) {
            p++;
            swap(a[i], a[p]);
        }
    }

    //Pivot to right position
    swap(a[first], a[p]);
}

void QuickSort (int a[], int first, int last) {
    int part;
    if (first < last) {
        PreparePartition(a, first, last, part);
        QuickSort(a, first, part-1);
        QuickSort(a, part+1, last);
    }
}
