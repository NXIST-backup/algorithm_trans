#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int INF = 0x3f3f3f3f;

const int N = 2505, M = 6205;

int n, m, start, end;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int st[N];
int q[N];
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    int ss = 0, tt = 0;
    q[tt] = start;
    st[start] = 1;
    while (ss <= tt) {
        int t = q[ss++];

        st[t] = 0;

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q[++tt] = j;
                    st[j] = 1;
                }
            }
        }
    }

    if (dist[end] == 0x3f3f3f3f)
        return -1;
    else
        return dist[end];
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d%d%d", &n, &m, &start, &end);

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    int t = spfa();

    printf("%d\n", t);
    return 0;
}