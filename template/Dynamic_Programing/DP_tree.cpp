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

const int N = 6e3 + 10;

int n;
int happy[N];
int h[N], e[N], ne[N], idx=0;
int f[N][2];
bool has_father[N];

void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    
}

void dfs(int u)
{
    f[u][1] = happy[u];

    for (int i = h[u]; i != -1;i=ne[i])
    {
        int j=e[i];
        dfs(j);

        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++)
        cin >> happy[i];

    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1;i++)
    {
        int a, b;
        cin >> a >> b;
        has_father[a] = true;
        add(b,a);
    }
    int root = 1;
    while (has_father[root]) {
        root++;
    }

    dfs(root);

    cout << max(f[root][0], f[root][1]) << endl;
}