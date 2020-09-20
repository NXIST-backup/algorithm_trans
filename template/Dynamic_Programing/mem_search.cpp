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
typedef pair<int, int> pii;

const int N = 310;

int n, m;
int h[N][N];
int f[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int dp(int x,int y)
{
    int &v = f[x][y];

    if(v!=-1)
        return v;
    for (int i = 0; i < 4;i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if(a>=1&&a<=n&&b>=1&&b<=m&&h[a][b]<h[x][y])
            v = max(v, dp(a, b) + 1);
    }
    return v;
}
int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> h[i][j];

    memset(f, -1, sizeof f);

    int res = 0;

    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            res = max(res, dp(i, j));

    cout << res << endl;
}