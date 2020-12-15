# ABC184题解

### D-increment of coins

第一次见概率Dp
从后往前推
状态表示：$Dp[i][j][k]$表示到达$i$个金币$j$个银币$k$个铜币的期望值
状态转移: $Dp[i][j][k]=x/(x+y+z)*Dp([i+1][j][k]+1)+y/(x+y+z)*Dp([i][j+1][k]+1)+z/(x+y+z)*Dp([i][j][k+1]+1)$

```
/*
  Problem Name:increment of coins
  algorithm tag:概率DP,期望DP
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
const int N = 105;
double dp[N][N][N];

int main()
{
    int g, s, b;
    cin >> g >> s >> b;
    for (int i = 100; i >= 0; i--) {
        for (int j = 100; j >= 0; j--) {
            dp[100][i][j] = 0;
            dp[i][j][100] = 0;
            dp[i][100][j] = 0;
        }
    }

    for (int i = 99; i >= g; i--) {
        for (int j = 99; j >= s; j--) {
            for (int k = 99; k >= b; k--) {
                double x = i, y = j, z = k;
                dp[i][j][k] = x / (x + y + z) * (dp[i + 1][j][k] + 1) + y / (x + y + z) * (dp[i][j + 1][k] + 1) + z / (x + y + z) * (dp[i][j][k + 1] + 1);
            }
        }
    }

    printf("%.8lf", dp[g][s][b]);
}
```

### E-Third Avenue

BFS

```
/*
  Problem Name:Third Avenue
  algorithm tag:BFS
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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pii> tel[140];
int n, m;
int st[N][N];

int bfs(int x1, int y1)
{
    queue<pii> q;
    q.push({x1, y1});
    st[x1][y1] = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (g[t.first][t.second] == 'G') {
            return st[t.first][t.second];
        }
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x <= n && x >= 1 && y >= 1 && y <= m && g[x][y] != '#' && !st[x][y]) {
                q.push({x, y});
                st[x][y] += st[t.first][t.second] + 1;
            }
        }
        if (g[t.first][t.second] <= 122 && g[t.first][t.second] >= 97 && tel[g[t.first][t.second]].size() > 1) {
            for (auto item : tel[g[t.first][t.second]]) {
                if (!st[item.first][item.second]) {
                    q.push({item.first, item.second});
                    st[item.first][item.second] += st[t.first][t.second] + 1;
                }
            }
            tel[g[t.first][t.second]].clear();
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    int x1, y1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c >= 97 && c <= 122)
                tel[c].push_back({i, j});
            if (c == 'S')
                x1 = i, y1 = j;
            g[i][j] = c;
        }
    }

    cout << bfs(x1, y1) - 1 << endl;
}
```

### F-Programming Contest

meet in the middle 
看题目第一眼以为是01背包裸题,但是背包容量太大，会TLE。
看$N\leq40$可以分开爆搜，最后二分合并。时间复杂度大约是$O(2^\frac{N}{2}+NlogN)$

```
/*
  Problem Name:Programming Contest
  algorithm tag:meet in the middle
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

const int N = 42;

int n, t;
int w[N];
vector<int> a, b;
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    else
        return b;
}
void dfs(int l, int r, int sum)
{
    if (sum > t)
        return;
    if (l == r) {
        a.push_back(sum);
        return;
    }
    dfs(l + 1, r, sum + w[l + 1]);
    dfs(l + 1, r, sum);
}

int main()
{
    cin >> n >> t;

    for (int i = 1; i <= n; i++)
        cin >> w[i];
    dfs(0, n / 2, 0);
    swap(a, b);
    dfs(n / 2, n, 0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        int tnp = lower_bound(b.begin(), b.end(), t - a[i] + 1) - b.begin() - 1;
        ans = max(b[tnp] + a[i], ans);
    }
    cout << ans << endl;
}
```