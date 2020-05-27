#include <iostream>
#include "sort_algo.h"
#include "sort_test.h"
#include "MaxTeilsum.h"

using namespace std;

int main()
{
    int a[] = {31, 41, 59, 26, 41, 58};
    int a_length = sizeof(a)/sizeof(*a);

    int b[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    int b_length = sizeof(b)/sizeof(*b);

    cout << "length a: " << a_length << endl;
    cout << "array: " << endl;
    print_array(a, a_length);
    cout << "sorting array: " << endl;
    //InsertionSort   (a, a_length);
    //BubbleSort      (a, a_length);
    //SelectionSort   (a, a_length);
    QuickSort      (a, 0, a_length-1);
    print_array(a, a_length);

    //TestQuickSort();
    //TestBubbleSort();

    int **arr_p;
    int arr[3][4] = {
       {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
       {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
       {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
    };
    //need to create template function to make this work
    //arr_p = arr;
    //MaxTeilsum4(arr, 3, 4);

    return 0;
}
