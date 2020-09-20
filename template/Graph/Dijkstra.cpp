// n是点，m是边。
//                                           /——>朴素Dijkstra算法(O(n^2)) eg.适合稠密图
//                          /所有边权都正数—————>堆优化版Dijkstra算法(O(mlogn)) eg.适合稀疏图  
//          /——>单源最短路———|在负权边————————> Bellman_ford(O(nm))
//  最短路——|                          \—————> SPFA 一般O(m),最坏O(nm) 
//          \——多源汇最短路——|
//                          \——————————————————> Floyd算法 O(n^3)
//
//

//朴素Dijkstra

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>


using namespace std;

const int N = 510;

int n, m;
int g[N][N];//邻接矩阵
int dist[N];//每个点到1点的最短距离
bool st[N];//是否存在最短距离

int dijstra()
{
    memset(dist, 0x3f, sizeof dist);//0x3f是初始成无限大，因为memset是按字节操作的
    dist[1] = 0;

    for (int i = 0; i < n;i++)
    {
        int t = -1;
        for (int j = 1; j <= n;j++)//所有点中找dist最小的点且该点不存在最短距离
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t = j;
        if(t==n)
            break;

        for (int j = 1; j <= n;j++)//用t来更新所有点的距离。
            dist[j] = min(dist[j], dist[t] + g[t][j]);//  1—————>x 如果1到x的距离大于1到t再到x的距离那么更新 
                                                      //   \>t—>/  
        st[t] = true;
    }
    if(dist[n]==0x3f3f3f3f)
        return -1;
    else
        return dist[n];
}



int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    int t = dijstra();

    cout << t << endl;
}
