#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

void InsertionSortIterativ(int* a, const int last){
    int i, j, key;

    for (i = 1; i <= last; i++){
        key = a[i];
        for (j = i - 1; j >= 0 and a[j] > key; j--){
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}

void InsertionSortRecusiv(int* a, const int last){
    if (last == 0) return;
    InsertionSortRecusiv(a, last - 1);
    int key = a[last], i;
    for (i = last - 1; i >= 0 and a[i] > key; i--){
        a[i + 1] = a[i];
    }
    a[i + 1] = key;
}


#endif // INSERTIONSORT_H
