
#include <iostream>
#include "sort_algo.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;


int TestBubbleSort      () {
    long int size    = 2;
    int counter = 2;
	int *array;

	time_t start;
	time_t end_t;
    double timediv_sek = 0;


    while (timediv_sek < 60) {
        // Speicher reservieren
        array = new int [size];
        if(array == NULL) {
            cout << "\nKein freier Speicher vorhanden.\n" << endl;
        }
        else {
            for (int i = 0; i < size; i++) {
                array[i]=rand()%100;
            }
            //print_array(array, size);

            time(&start);
            BubbleSort(array, size);
            time(&end_t);
            //print_array(array, size);

            timediv_sek = difftime(end_t, start);

            cout << "size: " << size << " time: " << timediv_sek << "s" << endl;
            if (timediv_sek < 30) {
                size = pow(2, counter);
                counter++;
            }
            else
                size = size + (size/2);
            delete[] array;
        }

    }
    return 0;
}

int TestQuickSort      () {
    long int size    = 2;
    int counter = 2;
	int *array;

	time_t start;
	time_t end_t;
    double timediv_sek = 0;


    while (timediv_sek < 60) {
        // Speicher reservieren
        array = new int [size];
        if(array == NULL) {
            cout << "\nKein freier Speicher vorhanden.\n" << endl;
        }
        else {
            for (int i = 0; i < size; i++) {
                array[i]=rand()%100;
            }
            //print_array(array, size);

            time(&start);
            QuickSort(array, 0, size-1);
            time(&end_t);
            //print_array(array, size);

            timediv_sek = difftime(end_t, start);

            cout << "size: " << size << " time: " << timediv_sek << "s" << endl;
            if (timediv_sek < 30) {
                size = pow(2, counter);
                counter++;
            }
            else
                size = size + (size/2);
            delete[] array;
        }

    }
    return 0;
}
