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

const int N = 200010, M = N << 1;

int h[N], e[M], ne[M], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int n, m;
int p[N];
int find(int x)
{
    if(p[x] != x)  p[x] = find(p[x]);
    return p[x];
}

int f[N];

void dfs(int u, int fa)
{
    f[u] += f[fa];
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j, u);
    }
}

int main()
{
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n * 2; i ++)  p[i] = i;

    int root = n + 1;
    while(m --)
    {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if(op == 1)
        {
            a = find(a), b = find(b);
            if(a != b)
            {
                p[a] = p[b] = root;
                add(root, a);
                add(root, b);
                root ++;
            }
        }
        else
        {
            a = find(a);
            f[a] += b;
        }
    }

    for(int i = n + 1; i < root; i ++)
        if(p[i] == i){
            cout << i << endl;
            dfs(i, 0);
        }  
            

    for(int i = 1; i <= n; i ++)
        printf("%d ", f[i]);
    return 0;
}