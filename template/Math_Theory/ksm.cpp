//快速幂求乘法逆元
//b与n互质
//b|a == a*(b^-1) (mod n)
//a与n互质
//b*(b^-1) == 1(modn)
//同余运算以及基本性质
//1、性质：如果a≡b(mod m)，x≡y(mod m)，则a+x≡b+y(mod m)。
//2、如果a≡b(mod m)，x≡y(mod m)，则ax≡by(mod m)
//2、如果ac≡bc(mod m)，且c和m互质，则a≡b(mod m)
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

ll ksm(int a,int b,int p)
{
    ll ans = 1;
    while (b) {
        if(b&1)
            ans = ans * a % p;
        a = (ll)a * a % p;
        b >>= 1;
    }
    return ans;
}


int main()
{
    int n;
    cin >> n;
    while (n--) {

        int a, p;
        cin >> a >> p;
        if(a%p==0)
            cout << "impossible" << endl;
        else
            cout << ksm(a, p - 2,p) << endl;
    }
}