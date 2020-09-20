//中国剩余定理(孙子定理)
//m1 m2 m3 ....mk两两互质
// x==m1(mod a1)
// x==m2(mod a2)
//  .
//  .
// x==ak(mod mk)
// M=m1*m2*m3....*mk
// Mi=M/mi
// 可求Mi1^-1
// 公式x = a1*M1*M1^-1+a2*M2*M2^-1...+ak*Mk*Mk^-1

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x1,ll &y1)
{
    if(!b)
    {
        x1 = 1;
        y1 = 0;
        return a;
    }
    ll x2, y2;
    ll d = exgcd(b, a % b, x2, y2);
    x1 = y2;
    y1 = x2 - (a / b) * y2;
    return d;
}


int main()
{
    int n;
    cin >> n;

    bool has_answer = true;

    ll a1, m1;

    cin >> a1 >> m1;

    for (int i = 0; i < n - 1;i++)
    {
        ll a2, m2;
        cin >> a2 >> m2;

        ll k1, k2;
        ll d = exgcd(a1, a2, k1, k2);
        if((m2-m1)%d)
        {
            has_answer = false;
            break;
        }

        k1 *= (m2 - m1) / d;
        ll t = a2 / d;
        k1 = (k1 % t + t) % t;//确保取最小！正！整数解
        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
    }
    if(has_answer)
    {
        cout << (m1 % a1 + a1) % a1 << endl;
    }
    else
        cout << "-1" << endl;

}
