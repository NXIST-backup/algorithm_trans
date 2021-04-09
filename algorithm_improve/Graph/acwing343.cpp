/*
  Problem Name:排序
  algorithm tag:floyd，传递闭包
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
//#define x first
//#define y second
#define iosf ios::sync_with_stdio(false), cin.tie(0), cout << fixed

const int N = 26;
int g[N][N], d[N][N];
int n, m;
bool st[N];

void floyd()
{
    memcpy(d, g, sizeof d);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] |= d[i][k] && d[k][j];
}
int check()
{
    for (int i = 0; i < n; i++)
        if (d[i][i])
            return 2;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (!d[i][j] && !d[j][i])
                return 0;

    return 1;
}
char get_min()
{
    for (int i = 0; i < n; i++)
        if (!st[i]) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (!st[j] && d[j][i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                st[i] = true;
                return 'A' + i;
            }
        }
}
int main()
{
    while (cin >> n >> m, n || m) {
        memset(g, 0, sizeof g);
        int type = 0, t = 0;
        for (int i = 1; i <= m; i++) {
            string str;
            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A';
            if (!type) {
                g[a][b] = 1;
                floyd();
                type = check();
                if (!type)
                    t = i;
            }
        }
        if (!type)
            puts("Sorted sequence cannot be determined.");
        else if (type == 2)
            printf("Inconsistency found after %d relations.\n", t + 1);
        else {
            memset(st, 0, sizeof st);
            printf("Sorted sequence determined after %d relations: ", t + 1);
            for (int i = 0; i < n; i++)
                printf("%c", get_min());
            printf(".\n");
        }
    }
}