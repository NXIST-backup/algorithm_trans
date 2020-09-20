//质因数分解


#include "iostream"
#include "vector"
#include "algorithm"
#include <algorithm>
using namespace std;

typedef long long  ll;

ll x;

ll _lcm(ll a,ll b)
{
    return a / __gcd(a, b) * b;
}



int main()
{
    cin >> x;

    ll ans;

    for (ll i = 1; i * i <= x;i++)
    {
        if(x%i==0&&_lcm(i,x/i)==x)
        {
            ans = i;
        }
    }
    cout << ans << " " << x / ans << endl;
}