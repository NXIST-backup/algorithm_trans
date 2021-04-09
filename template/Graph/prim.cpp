//
//。
//.                       /朴素版Prim O(n^2) 稠密图一般用这个
//.         普利姆算法(Prim)
//         /.             \堆优化版Prim O(mlogn)
//最小生成树
//         \                              
//.         克鲁斯卡尔算法(Kruskal) O(mlogm) 稀疏图用这个
//
//
//
//
//.    /染色法  O(n+m)
//二分图
//     \匈牙利算法 O(mn),实际运行时间一般远小于O(mn)
//

//朴素版Prim
// dist[]初始化正无穷
// fir(n)
// 1.找到集合外距离最近的点->t
// 2.用t更新其他点到集合的距离
// 3.把t加入集合中去 st[tG]=true;

#include "algorithm"
#include "cstring"
#include "iostream"

using namespace std;

const int N = 501, INF = 0x3f3f3f3f;
int n, m;

int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0; //最小生成树里所有边的长度之和

    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) //取距离集合最小的点
                t = j;
        if (i && dist[t] == INF) //如果除第一个点之外的点最小距离为无限，那说明无联通
            return INF;
        if (i)
            res += dist[t]; //否则距离加入集合
        for (int j = 1; j <= n; j++)
            if (!st[j])
                dist[j] = min(dist[j], g[t][j]); //用t更新剩下的所有点

        st[t] = true;
    }
    return res;
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF)
        cout << "impossible" << endl;
    else
        cout << t << endl;
}