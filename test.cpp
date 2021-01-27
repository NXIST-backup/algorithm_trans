#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, a[15], is[200005];
struct P
{
    long double k, x;
} f[200005], sum[200005]; //f[i]=k*f[1]+x
P operator+(P i, P j)
{
    return {i.k + j.k, i.x + j.x};
}
P operator-(P i, P j)
{
    return {i.k - j.k, i.x - j.x};
}
P operator/(P i, double j)
{
    return {i.k / j, i.x / j};
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> a[i], is[a[i]] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (!is[i])
            f[i] = (sum[i + 1] - sum[i + m + 1]) / m + (P){0, 1};
        else
            f[i] = (P){1, 0};
        sum[i] = sum[i + 1] + f[i];
    }
    if (fabs(f[0].k - 1) < 1e-6)
        puts("-1");
    else {
        long double x = -f[0].x / (f[0].k - 1);
        printf("%.4Lf\n", x);
    }
}