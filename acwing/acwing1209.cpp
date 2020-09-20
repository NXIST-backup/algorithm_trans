#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;

int n;
bool st[N], backup[N];
int ans;

bool check(int a, int c)
{
    long long b = n * (long long)c - a * c;

    if (!a || !b || !c) return false;

    memcpy(backup, st, sizeof st);
    while (b)
    {
        int x = b % 10;     
        b /= 10;    
        if (!x || backup[x]) return false;
        backup[x] = true;
    }

    for (int i = 1; i <= 9; i ++ )
        if (!backup[i])
            return false;

    return true;
}

void dfs_c(int u, int a, int c)
{
    if (u > 9) return;

    if (check(a, c)) ans ++ ;

    for (int i = 1; i <= 9; i ++ )
        if (!st[i])
        {
            st[i] = true;
            dfs_c(u + 1, a, c * 10 + i);
            st[i] = false;
        }
}

void dfs_a(int u, int a)
{
    if (a >= n) return;
    if (a) dfs_c(u, a, 0);

    for (int i = 1; i <= 9; i ++ )
        if (!st[i])
        {
            st[i] = true;
            dfs_a(u + 1, a * 10 + i);
            st[i] = false;
        }
}

int main()
{
    cin >> n;

    dfs_a(0, 0);

    cout << ans << endl;

    return 0;
}