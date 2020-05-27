#include <iostream>

using namespace std;

void printA(int* a, int last){
    cout << a[0];
    for (int i = 1; i <= last; i++)
        cout << ", " << a[i];
    cout << endl;
}

void Merge(int* a, int first, int middle, int last){
    int i = first, j = middle + 1, size_a = last - first + 1;
    int* new_a = new int [size_a];

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
        cout << a[first + i] << ", ";
    }
    cout << endl;
    delete [] new_a;
}

void MergeSort(int* a, int first, int last){
    if (first == last) return;
    int middle;
    middle = (first + last) / 2;
    MergeSort(a, first, middle);
    MergeSort(a, middle + 1, last);
    Merge(a, first, middle, last);
}

void Heapify(int* a, const int last, const int root){
    int lagerst = root, left = (root * 2) + 1, right = (root * 2) + 2;

    //Maximum aus {left, rigth, root} finden
    if (left <= last and a[left] > a[root])
        lagerst = left;
    if (right <= last and a[right] > a[lagerst])
        lagerst = right;

    //Den größten Wert nach oben tauschen und rekursiv weitermachen
    if (lagerst != root) {
        swap(a[lagerst], a[root]);
        Heapify(a, last, lagerst);   //Entweder nach links oder nach rechts weitergehen
    }
}

void HeapSort(int* a, const int last){

    //Heap bauen
    for (int i = (last - 1) / 2; i >= 0; i--){
        Heapify(a, last, i);
    }


    //Sotieren
    for (int i = last; i > 0; i--){
        swap(a[i], a[0]);
        Heapify(a, i - 1, 0);
        printA(a, last);
    }
}

int main()
{   const int a_size = 8;
    int a[a_size] = {-5, 13, -32,7,17,23,-35,-19};

    MergeSort(a, 0, a_size - 1);

    cout << "-----" << endl;
    for (int i = 0; i < a_size; i++)
        cout << a[i] << ", ";
    cout << endl;

    cout << "Hello world!" << endl;
    return 0;
}
