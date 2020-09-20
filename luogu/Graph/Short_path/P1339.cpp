#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2550;


int n, m, s, t1;
int g[N][N];
int dist[N];
int st[N];


int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;

    for (int i = 0; i < n;i++)
    {
        int t = -1;
        for (int j = 1; j <= n;j++)
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t = j;
        if(t==t1)
            break;
        for (int j = 1; j <= n;j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }
    return dist[t1];
}



int main()
{
    cin >> n >> m >> s >> t1;

    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = min(g[a][b], w);
        g[b][a] = min(g[b][a], w);
    }

    int t = dijkstra();

    cout << t << endl;
}