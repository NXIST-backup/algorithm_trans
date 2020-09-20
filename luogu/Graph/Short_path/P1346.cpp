//最短路模板题
//建图是关键

#include "iostream"
#include "algorithm"
#include "cstring"
#include "queue"

using namespace std;

const int N = 150;

int n, a, b;
int g[N][N];
int dist[N];
int st[N];


int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[a] = 0;

    for (int i = 0; i < n;i++)
    {
        int t = -1;
        for (int j = 1; j <= n;j++)
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t = j;
        if(t==b)
            break;
        for (int j = 1; j <= n;j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        st[t] = true;
    }
    if(dist[b]==0x3f3f3f3f)
        return -1;
    else
        return dist[b];
}

int main()
{
    cin >> n >> a >> b;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n;i++)
    {
        int x;

        cin >> x;
        for (int j = 1; j <= x;j++)
        {
            int y;
            cin >> y;
            if(j==1)
                g[i][y] = 0;
            else
                g[i][y] = 1;
        }
    }
    int t = dijkstra();

    cout << t << endl;
}