// n是点，m是边。
//                                           /——>朴素Dijkstra算法(O(n^2)) eg.适合稠密图
//                          /所有边权都正数—————>堆优化版Dijkstra算法(O(mlogn)) eg.适合稀疏图  
//          /——>单源最短路———|在负权边————————> Bellman_ford(O(nm))
//  最短路——|                          \—————> SPFA 一般O(m),最坏O(nm) 
//          \——多源汇最短路——|
//                          \——————————————————> Floyd算法 O(n^3)
//
//

//堆优化版Dijkstra

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int N = 100050;

int n, m;
int h[N], e[N], ne[N], idx,w[N];
int dist[N];//每个点到1点的最短距离
bool st[N];//是否存在最短距离

void add(int a,int b,int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijstra()
{
    memset(dist, 0x3f, sizeof dist);//0x3f是初始成无限大，因为memset是按字节操作的
    dist[1] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> heap;//greater是最小根堆,vector是实现方式

    heap.push({0, 1}); //前面是dist 后面是点,把起点放入堆;
    while (heap.size()) {
        auto t = heap.top();//取最小dist数，堆取最小值为O(n)

        heap.pop();

        int ver = t.second, distance = t.first;

        if(st[ver])//如果已经遍历过且该点已经是最短距离点。
            continue;
        st[ver] = 1;
        for (int i = h[ver]; i != -1;i=ne[i])//遍历更新
        {
            int j = e[i];
            if(dist[j]>distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if(dist[n]==0x3f3f3f3f)
        return -1;
    else
        return dist[n];
}



int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    int t = dijstra();

    cout << t << endl;
}
