#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = 400010, mod = 100003;

int n, m;
int h[N], e[M], ne[M], idx;
int dist[N], cnt[N];
int q[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    cnt[1] = 1;

    int hh = 0, tt = 0;
    q[0] = 1;

    while (hh <= tt) {
        int t = q[hh++];

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + 1) {
                dist[j] = dist[t] + 1;
                cnt[j] = cnt[t];
                q[++tt] = j;
            } else if (dist[j] == dist[t] + 1) {
                cnt[j] = (cnt[j] + cnt[t]) % mod;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bfs();

    for (int i = 1; i <= n; i++)
        printf("%d\n", cnt[i]);

    return 0;
}
