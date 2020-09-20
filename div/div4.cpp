#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll a[] = {2, 4, 6, 8, 0};
ll b[] = {3, 6, 9, 2, 5, 8, 1, 4, 7, 0};
ll c[] = {4, 8, 2, 6, 0};
ll d[] = {5, 0};
ll e[] = {6, 2, 8, 4, 0};
ll f[] = {7, 4, 1, 8, 5, 2, 9, 6, 3, 0};
ll g[] = {8, 6, 4, 2, 0};
ll h[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
ll j[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll sum = 0;
        ll x = n / m;
        switch (m % 10)
        {
        case 1:
            sum = 45 * (x / 10);
            for (int i = 0; i < x % 10; i++)
                sum += j[i];
            break;
        case 2:
            sum = 20 * (x / 5);
            for (int i = 0; i < x % 5; i++)
                sum += a[i];
            break;
        case 3:
            sum = 45 * (x / 10);
            for (int i = 0; i < x % 10; i++)
                sum += b[i];
            break;
        case 4:
            sum = 20 * (x / 5);
            for (int i = 0; i < x % 5; i++)
                sum += c[i];
            break;
        case 5:
            sum = 5 * (x / 2);
            for (int i = 0; i < x % 2; i++)
                sum += d[i];
            break;
        case 6:
            sum = 20 * (x / 5);
            for (int i = 0; i < x % 5; i++)
                sum += e[i];
            break;
        case 7:
            sum = 45 * (x / 10);
            for (int i = 0; i < x % 10; i++)
                sum += f[i];
            break;
        case 8:
            sum = 20 * (x / 5);
            for (int i = 0; i < x % 5; i++)
                sum += g[i];
            break;
        case 9:
            sum = 45 * (x / 10);
            for (int i = 0; i < x % 10; i++)
                sum += h[i];
            break;
        }

        cout << sum << endl;
    }
    return 0;
}