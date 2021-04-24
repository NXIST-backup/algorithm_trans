#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 200010;

int n;
int a[N];
int tr[N];
int Greater[N], lower[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        int y = a[i];
        Greater[i] = sum(n) - sum(y);
        lower[i] = sum(y - 1);
        cout << lower[i] << endl;
        add(y, 1);
    }

    memset(tr, 0, sizeof tr);
    LL res1 = 0, res2 = 0;
    for (int i = n; i; i--) {
        int y = a[i];
        res1 += Greater[i] * (LL)(sum(n) - sum(y));
        res2 += lower[i] * (LL)(sum(y - 1));
        add(y, 1);
    }

    printf("%lld %lld\n", res1, res2);

    return 0;
}
