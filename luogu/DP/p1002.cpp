#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stdio.h>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
typedef pair<int,int> pii;

const int N = 30;

ull f[N][N];
int x, y, a, b;


void putout()
{
    for (int i = 1; i <= x + 1;i++)
    {
        for (int j = 1; j <= y + 1;j++)
            printf("%-4d", f[i][j]);
        puts("");
    }
    cout << endl;
}


int main()
{

    cin >> x >> y >> a >> b;

    f[a+1][b+1] = -1;

    int dx[8] = {1, -1, 1, -1, 2, -2, 2, -2}, dy[8] = {2, 2, -2, -2, 1, 1, -1, -1};

    for (int i = 0; i < 8;i++)
    {
        if(a+dx[i]+1>0&&b+dy[i]+1>0)
            f[a + dx[i]+1][b + dy[i]+1] = -1;
    }

    f[0][1] = 1;
    for (int i = 1; i <= x + 1;i++)
        for (int j = 1; j <= y + 1;j++)
            if(f[i][j]!=-1)
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            else
                f[i][j] = 0;
    cout << f[x + 1][y + 1] << endl;
}