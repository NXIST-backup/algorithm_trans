//二分+堆优化dijkstra
//难点在于怎么把点权抽象出来，用二分处理。
//时间复杂度大致为O(mlogn^2)



#include "iostream"
#include "algorithm"
#include "cstring"
#include "queue"
#include "vector"
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int N = 1e5+50;
typedef pair<int, int> pii;
int n, m, b;
int h[N], e[N], ne[N], w[N], idx;
int f[N],u[N];
int dist[N];
int st[N];

void add(int a,int b,int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dijkstra(int mid)
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    if(f[1]>mid)
        return 0;
    heap.push({0, 1});
    while (heap.size()) {

        auto t = heap.top();

        heap.pop();

        int ver = t.second, distance = t.first;

        if(st[ver])
            continue;
        st[ver] = 1;
        for (int i = h[ver]; i != -1;i=ne[i])
        {
            int j = e[i];
            if(f[j]>mid)
                continue;
            if(dist[j]>distance+w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }        
        if (ver==n) {
            if(dist[n]>=b)
                return 0;
            else
                return 1;
        }
        else
            continue;
    }
    if(dist[n]==0x3f3f3f3f)
        return 0;
    else
        return 1;
}


int main()
{
    cin >> n >> m >> b;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n;i++)
    {
        cin >> f[i];
        u[i] = f[i];
    }
    for (int i = 1; i <= m;i++)
    {
        int a, z, w;
        cin >> a >> z >> w;
        add(a, z, w);
        add(z, a, w);
    }
    sort(u + 1, u + n + 1);

    int l = 1, r = n;
    int ans = -1;

    while (l<=r) {
        memset(st, 0, sizeof st);
        int mid = (l + r) / 2;

        if(!dijkstra(u[mid]))
            l = mid +1;
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    if(ans==-1)
        cout << "AFK" << endl;
    else
        cout << u[ans] << endl;
}