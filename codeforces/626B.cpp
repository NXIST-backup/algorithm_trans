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

const int N = 4e4 + 50;
int n, m, k;
long long a[N], b[N];

int main()
{
    cin >> n >> m >> k;
    int len = 0;
    for (int i = 1; i <= n;i++)
    {
        int x = 0;
        scanf("%d", &x);
        if(x==1)
        {
            len++;
            continue;
        }
        else
        {
            int cnt = len;
            for (int j = 1; j <= len;j++)
            {
                a[j] += cnt--;
            }
            len = 0;
        }
    }
    int cnt = len;
    for (int i = 1; i <= len; i++)
        a[i] += cnt--;


    len = 0;
    for (int i = 1; i <= m;i++)
    {
        int x = 0;
        scanf("%d", &x);
        if(x==1)
        {
            len++;
            continue;
        }
        else
        {
            int cnt = len;
            for (int j = 1; j <= len;j++)
            {
                b[j] += cnt--;
            }
            len = 0;
        }
    }
    cnt = len;
    for (int i = 1; i <= len; i++)
        b[i] += cnt--;
    long long res = 0;

    for (int i = 1; i <= n;i++)
    {
        if(k%i==0&&k/i<=m)
            res += a[i] * b[k / i];
    }
    cout << res << endl;
}