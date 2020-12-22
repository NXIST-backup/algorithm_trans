#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool ok;
int t;
ll a, b, c, d, e, x, y;
void euc(ll a, ll b, ll &x, ll &y)
{
    if (!b) {
        if (c % a)
            ok = false;
        else
            ok = true;
        x = c / a, y = 0, d = a;
    } else
        euc(b, a % b, y, x), y -= x * (a / b);
}
int main()
{
    for (scanf("%d", &t); t--;) {
        scanf("%lld%lld%lld", &b, &c, &a);
        c = b - c, euc(a, b, x, y);
        if (ok)
            e = b / d, printf("%lld", (x % e + e) % e);
        else
            printf("-1");
        putchar('\n');
    }
    return 0;
}