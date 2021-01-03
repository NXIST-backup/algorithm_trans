#include "iostream"
#include "algorithm"
using namespace std;
int main()
{
    int n;
    cin >> n;
    int d, e;
    cin >> d >> e;
    int a[7] = {1, 2, 5, 10, 20, 50, 100};
    int b[6] = {5, 10, 20, 50, 100, 200};
    for (int i = 0; i < 7;i++)
        a[i] = a[i] * d;
    for (int i = 0; i < 6;i++)
        b[i] = b[i] * e;
    int c[13];
    int i = 0;
    for (; i < 7;i++)
        c[i] = a[i];
    for (int j=0; i < 13;i++,j++)
        c[i] = b[i];
    sort(c, c + 13);
    int min = 0;
    while
}