#include <iostream>
using namespace std;
void quicksort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1;
    int j = r + 1;
    int x = a[l]; //不能用 r  l=0;
    while (i < j) {
        do
            i++;
        while (a[i] < x);
        do
            j--;
        while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    quicksort(a, l, j);
    quicksort(a, j + 1, r);
}
int main()
{
    int a[100005];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}