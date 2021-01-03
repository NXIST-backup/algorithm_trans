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
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

int n;
const int mod = 9988244353;


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
    cin >> n;
    vector<ll> res;
    ll temp1 = 0;
    ll temp2 = 0;
    ll x = 0;
    for (int i = 1; i <= n;i++)
    {
        temp2 = (temp2+temp1)%mod;
        x = (x+temp2)%mod;
        temp1 = (ksm(10, i, mod)*i%mod-x)%mod;
        x = (x+temp1)%mod;
        res.push_back(temp1);
    }
    for (int i = res.size() - 1; i >= 0;i--)
    {
        cout << res[i] << " ";
    }

}