//最短编辑距离

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

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];


int main()
{
    cin >> n;
    cin >> a + 1;
    cin >> m;
    cin >> b + 1;

    for (int i = 1; i <= m;i++)
    {
        f[0][i] = i;
    }
    for (int i = 1; i <= n;i++)
    {
        f[i][0] = i;
    }

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            f[i][j] = min(f[i - 1][j]+1, f[i][j - 1]+1);
            if(a[i]==b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    }

    cout << f[n][m] << endl;
}
