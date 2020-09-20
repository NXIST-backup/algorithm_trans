//卡特兰数
//c(2n,n)-c(2n,n-1)=1/(n+1)*c(2n,n);

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

const int mod = 1e9 + 7;

int qmi(int a,int b,int p)
{
    int res = 1;

    while (b) {
        if(b&1)
            res = (long long)res * a % p;
        a = (long long)a * a % p;

        b >>= 1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int a = 2 * n;
    int b = n;
    int res = 1;
    for (int i = a; i > a - b;i--)
        res = (long long)res * i % mod;
    for (int i = 1; i <= b;i++)
        res = (long long)res * qmi(i, mod - 2, mod) % mod;

    res = (long long)res * qmi(n + 1, mod - 2, mod) % mod;

    cout << res << endl;
}