// n是点，m是边。
//                                           /——>朴素Dijkstra算法(O(n^2)) eg.适合稠密图
//                          /所有边权都正数—————>堆优化版Dijkstra算法(O(mlogn)) eg.适合稀疏图  
//          /——>单源最短路———|在负权边————————> Bellman_ford(O(nm))
//  最短路——|                          \—————> SPFA 一般O(m),最坏O(nm) 
//          \——多源汇最短路——|
//                          \——————————————————> Floyd算法 O(n^3)
//
//

//Bellman_ford
//有限制边数，有负权边的最短路问题

#include "iostream"
#include "algorithm"
#include "cstring"
#include "queue"

using namespace std;

const int N = 510, M = 10050;

int n, m, k;
int dist[N], backup[N];

struct Edge
{

    int a, b, w;

} edges[M];


int bellman_ford()
{
    memset(dist, 0x3f,sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k;i++)
    {
        memcpy(backup, dist, sizeof dist);//备份dist数组防止串联
        for (int j = 0; j < m;j++)
        {
            int a = edges[j].a, b = edges[j].b,w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if(dist[n]>0x3f3f3f/2)//无穷大可能被更新
        return -1;
    return dist[n];
}


int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m;i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    int t = bellman_ford();

    if(t==-1)
        cout << "impossible" << endl;
    else
        cout << t << endl;
}