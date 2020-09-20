//最短hamilton

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

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

const int N = 22, M = 1 << N;

int g[N][N];
int f[M][N];
int n;


int main()
{
    cin >> n;

    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            cin >> g[i][j];

    memset(f, 0x3f, sizeof f);

    f[1][0] = 0;

    for (int i = 0; i < 1 << n;i++)
    {
        for (int j = 0; j < n;j++)
            if(i>>j&1)
                for (int k = 0; k < n;k++)
                    if((i-(1<<j))>>k&1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + g[k][j]);
    }

    cout << f[1<<n][n-1] << endl;
}