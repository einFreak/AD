


//only 1D
int MaxTeilsum4(int **a, int width, int hight) {
    int i, j, s, aktSum = 0;
    int max = 0;

    for(j=0; j<hight; j++) {
        for(i=0; i<width; i++) {
            s = aktSum + a[i][j];
            if (s > a[i][j])
                aktSum = s;
            else
                aktSum = a[i][j];

            if (aktSum > max)
                max = aktSum;
        }
    }

    return 0;
}
