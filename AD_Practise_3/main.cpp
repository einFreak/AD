#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
    //only 1D
    int MaxTeilsum3(int[a], int n) {
        int i, s, max = int.MinValue, aktSum = 0;

        for(i=0; i<n; i++) {
            s = aktSum + a[i];
            if (s > a[i])
                aktSum = s;
            else
                aktSum = a[i];
            if (aktSum > max)
                max = aktSum;
        }
    }

    }
