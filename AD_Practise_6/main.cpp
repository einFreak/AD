#include <iostream>
#include "linked_list.h"
#include <cstddef>

using namespace std;

void array_to_list(int a[], int a_length ,linked_list &liste) {
    for (int i = 0; i < a_length; i++)
        liste.Append(a[i]);
}

int main()
{
    int a[] = {31, 41, 59, 26, 41, 58};
    int a_length = sizeof(a)/sizeof(*a);

    int b[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    int b_length = sizeof(b)/sizeof(*b);

    linked_list first;
    //Quicksort_List(first);
    first.Append(5);
    array_to_list(a, a_length, first);
    first.Print();

    first.Quicksort_List();

    first.Print();







    return 0;
}
