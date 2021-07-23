#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], n, b[N], c[N];

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    b[1] = a[1];
    for (int i = 2; i <= n; i++)
        b[i] = max(b[i - 1], a[i]);
    c[n] = a[n];
    for (int i = n - 1; i; i--)
        c[i] = min(c[i + 1], a[i]);
    int divide = 0;
    for (int i = 1; i < n; i++)
        if (b[i] <= c[i + 1])
            divide++;
    cout << divide + 1 << endl;
    return 0;
}