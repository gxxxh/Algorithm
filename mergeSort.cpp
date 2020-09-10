#include <iostream>
using namespace std;

void merge(int *s, int *l, int llen, int *r, int rlen)
{
    int i, j, k;
    for(i = 0, j = 0, k = 0; i < llen && j < rlen; )
    {
        if(l[i] < r[j])
            s[k++] = l[i++];
        else
            s[k++] = r[j++];
    }
    while(i < llen) s[k++] = l[i++];
    while(j < rlen) s[k++] = r[j++];
}



void mergeSort(int *s, int len)
{
    int mid, i, *lsub, *rsub;
    if(len < 2)
        return;
    mid = len/2;
    lsub = new int[mid];
    rsub = new int[len-mid];
    for(i = 0; i < mid; i++)
        lsub[i] = s[i];
    for(i = mid; i < len; i++)
        rsub[i-mid] = s[i];
    mergeSort(lsub, mid);
    mergeSort(rsub, len-mid);
    merge(s, lsub, mid, rsub, len-mid);
    delete [] lsub;
    delete [] rsub;
}

int main()
{
    int A[] = {6, 2, 6, 2, 7, 3, 7, 22, 9};
    int len = sizeof(A)/sizeof(int);
    mergeSort(A, len);
    for(auto i = 0; i < len; i++)
        cout << A[i] << " ";
    return 0;
}