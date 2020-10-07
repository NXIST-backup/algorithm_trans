#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int n, m, T;
int f[100010];//  f[i]表示店铺i的优先级
int st[100010];//  st[i]表示店铺i是否处于优先缓存
int last[100010];//  last[i]表示店铺i上一次有订单的时间 
PII order[100010];//  订单 
int main()
{
    scanf("%d%d%d", &n, &m, &T);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &order[i].first, &order[i].second);
    } 
    sort(order, order + m);
    for (int i = 0; i < m;)
    {
        int j = i;
        while (order[i] == order[j] && j < m) j++;
        int t = order[i].first, id = order[i].second, cnt = j - i;
        i = j;

        f[id] -= t - last[id] - 1;
        if (f[id] < 0) f[id] = 0;
        if (f[id] <= 3) st[id] = 0;

        f[id] += cnt * 2;
        if (f[id] > 5) st[id] = 1;

        last[id] = t;
    }

    for (int i = 1; i <= n; i++)
    {
        if (last[i] < T)
        {
            f[i] -= T - last[i];
            if (f[i] <= 3) st[i] = 0;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) 
        if(st[i]&&m==1000)
            cout << i << endl;
    cout << ans << endl;
    return 0;
}
