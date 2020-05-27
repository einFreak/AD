#include <iostream>
#include "Timer.h"
#include "MergeSort.h"
#include "InsertionSort.h"

using namespace std;

int main()
{
    int size_arr = 30000;

    int arr1[size_arr];// = {2, 6, 7, 9, 1, 3, 4, 5, 8};
    int arr2[size_arr];
    for (int i = 0; i < size_arr; i++){
        arr1[i] = size_arr - i;
        arr2[i] = size_arr - i;
    }

    Timer time1;
    Timer time2;

    time1.start();
    InsertionSortRecusiv(arr1, size_arr - 1);
    time1.stop();
    cout << "Time Recusiv: " << time1.getTime() << " sec.\n";

    time2.start();
    InsertionSortIterativ(arr2, size_arr - 1);
    time2.stop();
    cout << "Time Iterativ: " << time2.getTime() << " sec.\n";
//    printA(arr1, size_arr - 1);

    cout << "Hello world!" << endl;
    return 0;
}
