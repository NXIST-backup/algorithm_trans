// n是点，m是边。
//                                           /——>朴素Dijkstra算法(O(n^2)) eg.适合稠密图
//                          /所有边权都正数—————>堆优化版Dijkstra算法(O(mlogn)) eg.适合稀疏图  
//          /——>单源最短路———|在负权边————————> Bellman_ford(O(nm))
//  最短路——|                          \—————> SPFA 一般O(m),最坏O(nm) 
//          \——多源汇最短路——|
//                          \——————————————————> Floyd算法 O(n^3)
//
//

//spfa(优化bellman)  利用队列优化

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
bool st[N];//判断队列是否有重复的点 

void add(int a,int b,int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size()) {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1;i=ne[i])
        {
            int j = e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
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
    }

    int t = spfa();
    if(t==-1)
        cout << "Impossible" << endl;
    else
        cout << t << endl;
}




