/*
  Problem Name: Advertising Agency
  algorithm tag:
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

const int N = 1005, M = 1e6 + 50;

int t;
int n, k;
int a[N];
int st[N];
int c[N][N];

bool cmp(int a, int b)
{
    if (a > b)
        return 1;
    else
        return 0;
}

void init()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}
int main()
{
    cin >> t;
    init();
    while (t--) {
        cin >> n >> k;
        memset(st, 0, sizeof st);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            st[a[i]]++;
        }
        map<int, int> mp;
        sort(a + 1, a + 1 + n, cmp);
        int m = 0;
        for (int i = 1; i <= k; i++) {
            m += a[i];
            mp[a[i]]++;
        }
        ll sum = 1;

        for (auto v : mp) {
            int x = v.second;
            int y = st[v.first];
            sum = (sum * c[y][x]) % mod;
        }
        cout << sum << endl;
    }
}