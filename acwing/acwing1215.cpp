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

// 2 3 4 5 6 1 

// 3 4 2 1 5

const int N = 1e6 + 50;
int n;
int a[N];
int c[N];
ll ans[N];
int lowbit(int x)
{
    return x & -x;
}
void add(int x,int v)
{
    for(int i=x;i<=N;i+=lowbit(i))
        c[i] += v;
}
int query(int x)
{
    int res = 0;
    for (int i = x; i ;i-=lowbit(i)){
        res += c[i];
    }
    return res;
}

int main()
{
    cin >> n;

    for (int i = 1;i<=n;i++)
        cin >> a[i];

    for (int i = 1; i<=n; i++) {
        ans[i] += query(N) - query(a[i]);
        add(a[i], 1);
    }
    
    memset(c,0,sizeof c);
    for (int i = n; i;i--) {
        ans[i] += query(a[i] - 1);
        add(a[i], 1);
    }
    ll res=0;
    for (int i = 1;i<=n;i++) {
        res += ans[i] * (ans[i] + 1) / 2;
    }
    cout << res << endl;
}