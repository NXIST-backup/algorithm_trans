//卢卡斯定理
// |-> c(a,b) == c(a mod p,b mod p) * c(a / p,b / p)(mod p) 递归做法

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

int p;


int qmi(int a,int b)
{
    int res = 1;
    while (b) {
        if(b&1)
            res = (ll)res * a % p;
        a =(ll) a * a % p;
        b >>= 1;
    }
    return res;
}


int C(int a,int b)
{
    int res = 1;
    for (int i = 1, j = a; i <= b;i++,j--)
    {
        res = (ll)res * j % p;
        res = (ll)res * qmi(i, p - 2) % p;
    }
    return res;
}


int lucas(ll a,ll b)
{
    if(a<p&&b<p)
        return C(a, b);
    return (ll)C(a % p, b % p) * lucas(a / p, b / p) % p;
}



int main()
{
    int n;
    cin >> n;

    while (n--) {

        ll a, b;
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }
}