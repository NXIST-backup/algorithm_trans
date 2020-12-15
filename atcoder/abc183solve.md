# ABC183题解

### C-Travel 
全排列即可
```
#include<bits/stdc++.h>

using namespace std;

const int N=10;
int g[N][N];
int n,k;
int ans=0;
vector<int> lis{1};
int st[N];
void dfs(int dep)
{
    if(dep==n+1){
        lis.push_back(1);
        int sum=0;
        for(int i=0;i<lis.size()-1;i++){
            sum+=g[lis[i]][lis[i+1]];
        }
        if(sum==k)
            ans++;
        lis.pop_back();
        return;
    }
    for(int i=2;i<=n;i++){
        if(!st[i]){
            st[i]=1;
            lis.push_back(i);
            dfs(dep+1);
            st[i]=0;
            lis.pop_back();
        }
    }
}



int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    }
    dfs(2);
    cout<<ans<<endl;
}
```
### D-Water Heater

离散化加差分
```
/*
  Problem Name:Water Heater
  algorithm tag:离散化 差分
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

ll n, w;
const int N = 2e5 + 5;
ll s[N];
ll pre[N];
vector<int> lis;
map<int, int> mp, st;
int S[N], T[N], P[N];
int main()
{
    cin >> n >> w;

    for (int i = 1; i <= n; i++) {
        int s, t, p;
        cin >> s >> t >> p;
        S[i] = s, T[i] = t, P[i] = p;
        if (!st[s]) {
            lis.push_back(s);
            st[s]++;
        }
        if (!st[t]) {
            lis.push_back(t);
            st[t]++;
        }
    }
    sort(lis.begin(), lis.end());
    int idx = 0;
    for (auto item : lis) {
        mp[item] = ++idx;
    }
    for (int i = 1; i <= n; i++) {
        pre[mp[S[i]]] += P[i];
        pre[mp[T[i]]] -= P[i];
    }
    for (int i = 1; i < idx; i++) {
        s[i] = s[i - 1] + pre[i];
    }
    bool is_valid = true;
    for (int i = 1; i < idx; i++) {
        if (s[i] > w) {
            is_valid = false;
            break;
        }
    }
    if (is_valid)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
```

### E-Problem Name:Queen on Grid

数字三角形变种,如果朴素做法是$O(n^3)$,可以发现实质上每个方向求个前缀和，那么就只需要从上一个状态转移就行。
$Dp[i][j][0]=Dp[i-1][j][1]+Dp[i][j-1][2]+Dp[i-1][j-1][3]$
$Dp[i][j][1]=Dp[i-1][j][1]+Dp[i][j][0]$
$Dp[i][j][2]=Dp[i][j-1][1]+Dp[i][j][0]$
$Dp[i][j][3]=Dp[i-1][j-1][1]+Dp[i][j][0]$

```
/*
  Problem Name:Queen on Grid
  algorithm tag:DP,数字三角形变种   
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 2e3 + 5;
char g[N][N];
ll dp[N][N][4];
int n, m;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            g[i][j] = c;
        }
    }

    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = dp[1][1][3] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1)
                continue;
            if (g[i][j] != '#') {
                dp[i][j][0] = (dp[i - 1][j][1] + dp[i][j - 1][2] + dp[i - 1][j - 1][3]) % mod;
                dp[i][j][1] = (dp[i - 1][j][1] + dp[i][j][0]) % mod;
                dp[i][j][2] = (dp[i][j - 1][2] + dp[i][j][0]) % mod;
                dp[i][j][3] = (dp[i - 1][j - 1][3] + dp[i][j][0]) % mod;
            } else {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 0;
                continue;
            }
        }
    }

    cout << dp[n][m][0] << endl;
}

```

### F-Confluence

看到题意马上能想到并查集

```
/*
  Problem Name:Confluence
  algorithm tag:并查集,STL map
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;

const int N = 2e5 + 5;
int n, q;
int f[N];
int sz[N];
int find(int x)
{
    if (f[x] != x) {
        f[x] = find(f[x]);
    }
    return f[x];
}

int main()
{
    cin >> n >> q;
    vector<map<int, int>> mp(n + 1);
    std::fill(sz + 1, sz + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        f[i] = i;
        mp[i][c] = 1;
    }
    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            int fa = find(a), fb = find(b);
            if (fa == fb)
                continue;
            if (sz[fa] < sz[fb]) //小的合并大的
                swap(fa, fb);
            sz[fa] += sz[fb], f[fb] = fa;
            for (auto item : mp[fb]) {
                mp[fa][item.first] += item.second;
            }
            mp[fb].clear();
        } else {
            int g = find(a);
            cout << mp[g][b] << endl;
        }
    }
}
```

