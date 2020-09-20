// n是点，m是边。
//                                           /——>朴素Dijkstra算法(O(n^2)) eg.适合稠密图
//                          /所有边权都正数—————>堆优化版Dijkstra算法(O(mlogn)) eg.适合稀疏图  
//          /——>单源最短路———|在负权边————————> Bellman_ford(O(nm))
//  最短路——|                          \—————> SPFA 一般O(m),最坏O(nm) 
//          \——多源汇最短路——|
//                          \——————————————————> Floyd算法 O(n^3)
//
//

//Floyd

#include "iostream"
#include "cstring"
#include "algorithm"

using namespace std;

const int N = 210,INF=1e9;

int n, m, q;
int d[N][N];

void floyd()
{
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}





int main()
{
    cin >> n >> m >> q;

    for (int i = 1; i <= n;i++)//必要的初始化
        for (int j = 1; j <= n;j++)
            if(i==j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
    while (m--) {

        int a, b, w;
        cin >> a >> b >> w;

        d[a][b] = min(d[a][b], w);
    }
    floyd();

    while (q--) {
        int a, b;
        cin >> a >> b;
        if(d[a][b]>INF/2)
            cout << "impossible" << endl;
        else
        cout << d[a][b] << endl;
    }
}