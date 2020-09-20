#include <iostream>

using namespace std;

const int N = 100000 + 50;

int a[N], temp[N];

void mergesort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;

    mergesort(a, l, mid),
        mergesort(a, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
        }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        a[i] = temp[j];
}