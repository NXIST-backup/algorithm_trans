//预处理i的阶乘
//和i阶乘的逆元
//O(nlogn)
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

const int N = 1e5 + 50;
const int mod = 1e9 + 7;

typedef long long ll;

int fact[N], infact[N];

int qmi(int a,int b,int p)
{
    int res=1;
    while (b) {
        if(b&1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        b >>= 1;
    }
    return res;
}



int main()
{
    fact[0] = infact[0] = 1;

    for (int i = 1; i < N;i++)
    {
        fact[i] = (ll)fact[i - 1] * i % mod;//预处理阶乘
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod; //! i阶乘的逆元也等于i逆元的阶乘
    }

    int n;
    cin >> n;


    while (n--) {
        int a, b;
        cin >> a >> b;

        cout << (ll)fact[a] * infact[b] % mod * infact[a - b] % mod << endl;
    }
}