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

ll n, k, sum = 0;
vector<pii> cho;
bool check(int mid)
{
    ll test=(ll)mid*mid*k;
    if(test>sum){
        return 0;
    }
    int all = 0;
    for(auto item:cho){
        all += (item.first / mid) * (item.second / mid);
    }
    if(all<k){
        return 0;
    }
    else
        return 1;
}

int solve(int l,int r)
{
    if(l>=r)
        return l;
    int mid = (l + r) >> 1;

    int flag = check(mid);
    if(flag)
        return solve(mid+1, r);
    else
        return solve(l, mid);
}
int main()
{
    cin >> n >> k;
    ll maxN = -1e9;
    for (int i = 0; i < n;i++){
        ll a, b;
        cin >> a >> b;
        cho.push_back({a, b});
        if(maxN<a)
            maxN = a;
        if(maxN<b)
            maxN = b;
        sum += a * b;
    }
    int res=solve(1, maxN);
    if(check(res))
        cout << res << endl;
    else
        cout << res - 1 << endl;
}
