#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <iostream>

using namespace std;

void Merge(int* a, int first, int middle, int last);
void printA(int* a, int last);
void MergeSortIterativ(int* a, const int first, const int last);
void MergeSortRecusiv(int* a, const int first, const int last);

#endif // MERGESORT_H_INCLUDED
