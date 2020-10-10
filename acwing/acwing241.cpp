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

const int N = 1e6 + 50;

int n;
int y[N], c[N];
int l[N], r[N];
int l1[N], r1[N];
int lowbit(int x)
{
    return x & -x;
}
void add(int x,int v)
{
    for (int i = x; i <= N;i+=lowbit(i))
        c[i] += v;
}
int query(int x)
{
    int res = 0;
    for (int i = x; i;i-=lowbit(i))
        res += c[i];
    return res;
}


int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++)
        cin >> y[i];
    for (int i = 1; i <= n;i++){
        l[i] = query(y[i] - 1);
        l1[i] = query(N) - query(y[i]);
        add(y[i], 1);
    }

    memset(c, 0, sizeof c);

    for (int i = n; i > 0;i--){
        r[i] = query(y[i] - 1);
        r1[i] = query(N) - query(y[i]);
        add(y[i], 1);
    }
    ll ans = 0;
    ll ans2 = 0;
    for (int i = 0; i < n;i++){
        ans += (ll)l[i] * r[i];
        ans2 += (ll)l1[i] * r1[i];
    }

    cout << ans2 << " " << ans << endl;
}