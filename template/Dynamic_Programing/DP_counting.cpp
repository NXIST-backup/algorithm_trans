//计数类dp
//
//整数划分


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
const int INF = 1e9+7;
typedef pair<int,int> pii;

const int N = 1e3 + 50;


int n;
int f[N][N];


//完全背包 无优化O(n^2*logn)
void solve1()
{
    cin >> n;

    for (int i = 0; i <= n;i++)
        f[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k * i <= j; k++)
                f[i][j] = (f[i][j]+f[i - 1][j - k * i] )% INF;
        }

    cout << f[n][n] << endl;
}

//完全背包优化 O(n^2)
void solve2()
{
    cin >> n;

    for (int i = 0; i <= n;i++)
        f[i][0] = 1;

    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            if(j>=i)
                f[i][j] = f[i - 1][j] + f[i][j - i] % INF;
            else
                f[i][j] = f[i - 1][j] % INF;

    cout << f[n][n] << endl;
}


int main()
{
    solve1();
    solve2();
}