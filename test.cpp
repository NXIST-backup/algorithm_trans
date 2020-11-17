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

const int N = 10;
int st[N][N];
ll ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int dep,int x,int y)
{
    if(dep==16)
        ans++;
    for (int i = 0; i < 4;i++){
        int x1 = x + dx[i], y1 = y + dy[i];

        if(x1>0&&x1<=4&&y1>0&&y1<=4&&!st[x1][y1]){
            st[x1][y1] = 1;
            dfs(dep + 1, x1, y1);
            st[x1][y1] = 0;
        }
    }

    return ans;
}

int main()
{
    ll res = 0;

    for (int i = 1; i <= 4;i++){
        for (int j = 1; j <= 4;j++){
            ans = 0;
            memset(st, 0, sizeof st);
            st[i][j] = 1;
            res += dfs(1, i, j);
        }
    }

    cout << res << endl;
}

