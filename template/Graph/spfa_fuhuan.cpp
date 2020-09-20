// n是点，m是边。
//                                           /——>朴素Dijkstra算法(O(n^2)) eg.适合稠密图
//                          /所有边权都正数—————>堆优化版Dijkstra算法(O(mlogn)) eg.适合稀疏图  
//          /——>单源最短路———|在负权边————————> Bellman_ford(O(nm))
//  最短路——|                          \—————> SPFA 一般O(m),最坏O(nm) 
//          \——多源汇最短路——|
//                          \——————————————————> Floyd算法 O(n^3)
//
//

//spfa判负环


#include "iostream"
#include "algorithm"
#include "cstring"
#include "queue"
#include "vector"
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5+50;

int n, m;
int h[N], e[N], ne[N], idx, w[N];
int dist[N];
int st[N];
int cnt[N];//cnt数组记录走过的点数，如果cnt>=n则说明出现了负环

void add(int a,int b,int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);

    dist[1] = 0;
    queue<int> q;

    for (int i = 1; i <= n;i++)
    {
        st[i] = true;
        q.push(i);
    }

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
                cnt[j] = cnt[t] + 1;
                if(cnt[j]>=n)
                {
                    return true;
                }
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
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

    if(t)
        cout << "Yes" << endl;

    else
        cout << "No" << endl;
}
