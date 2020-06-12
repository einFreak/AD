#include "linked_list.h"

void CountSort(int a[], int anzahl_werte, int max_wert) {
    int i;
    int j = 1;
    int *countarray = new int [max_wert+1];

    //Frage wieso 1 und nicht 0
    for (i=1; i <= max_wert; i++)
        countarray[i]=0;
    for (i=0; i<anzahl_werte; i++)
        countarray[ a[i] ]++;
    for (i=0; i<anzahl_werte; i++) {
        while (countarray [j] == 0)
            j++;
        a[i] = j;
        countarray[j]--;
    }

    delete [] countarray;
}
