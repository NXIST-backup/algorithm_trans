//最长上升子序列

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1050,INF=1e9;
int n;
int a[N];
int f[N];


int main()
{
    cin >> n;

    for (int i = 1; i <= n;i++)
        cin >> a[i];

    f[1] = a[1];
    for (int i = 0; i <= n;i++)
        f[i] = -INF;
    for (int i = 1; i <= n;i++)
    {
        f[i] = 1;
        for (int j = 1; j < i;j++)
            if(a[i]>a[j])
            f[i] = max(f[i], f[j] + 1);
    }

    int res = 0;

    for (int i = 1; i <= n;i++)
        res = max(res, f[i]);

    cout << res << endl;
}



